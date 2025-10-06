/*
 * parse_isp_conf.c
 * Autor: Abel Romero
 * Licencia: MIT
 *
 * Módulo de parseo para .conf de ISP (Little Endian).
 *
 * Idea clave (packs y bloques):
 *   - Escaneamos el archivo de 4 en 4 hasta encontrar un subpack con id==0.
 *   - Desde ahí seguimos saltando por 'size' exigiendo ids correlativos (prev_id+1).
 *   - El PRIMER subpack cuyo id NO sea prev_id+1 es el "bloque final" del pack.
 *   - El pack se define desde el primer subpack (id==0) HASTA el final del "bloque final".
 *   - Por cada subpack del pack (incluido el final), invocamos el callback del usuario:
 *        cb(pack_index, id, size_sin_cabecera, payload_ptr, user)
 *
 * Notas:
 *   - 'size' de cabecera incluye la propia cabecera (4 bytes). El 'payload' empieza en (subpack+4)
 *     y su longitud es (size-4) bytes.
 *   - Chequeo minimalista: solo que (off + size) no exceda el buffer; si size==0 se descarta el candidato.
 *   - Al cerrar un pack, se continúa buscando el siguiente justo después del pack encontrado.
 *
 * API pública:
 *   - typedef int (*isp_block_cb)(int pack, const struct isp_block *block, void *user);
 *   - struct parse_isp_conf_stats { int packs; int blocks; };
 *   - int parse_isp_conf(const uint8_t *buf, size_t len, isp_block_cb cb, void *user, struct parse_isp_conf_stats *out);
 *   - int parse_isp_conf_file(const char *path, isp_block_cb cb, void *user, struct parse_isp_conf_stats *out);
 *
 *   Retorno: 0 si OK, <0 en error de E/S o memoria. 'out' es opcional.
 */

#include "ak3918/isp_conf.h"

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ======================
 * Estructura de cabecera
 * ====================== */
#pragma pack(push,1)
struct lehdr {
    uint16_t id;    /* 0.. */
    uint16_t size;  /* bytes, incluye cabecera */
};
#pragma pack(pop)

/* ============
 * Utilidades IO
 * ============ */
static int load_file(const char *path, uint8_t **out_buf, size_t *out_len) {
    FILE *f = fopen(path, "rb");
    if (!f) { return -1; }
    if (fseek(f, 0, SEEK_END) != 0) { fclose(f); return -2; }
    long ln = ftell(f);
    if (ln < 0) { fclose(f); return -3; }
    if (fseek(f, 0, SEEK_SET) != 0) { fclose(f); return -4; }

    size_t n = (size_t)ln;
    uint8_t *buf = (uint8_t*)malloc(n ? n : 1);
    if (!buf) { fclose(f); return -5; }
    if (n && fread(buf, 1, n, f) != n) { free(buf); fclose(f); return -6; }
    fclose(f);

    *out_buf = buf;
    *out_len = n;
    return 0;
}

/* ===========================================
 * Núcleo: detectar packs y llamar a callbacks
 * ===========================================
 *
 * Implementación paso a paso con comentarios de bloque:
 * 1) Escaneo lineal de 4 en 4 para cazar un id==0 (candidato a inicio de pack).
 * 2) Validación del pack:
 *      - Recorremos subpacks saltando por 'size' y exigiendo id==prev+1;
 *      - Cuando encontramos el primer mismatch, incluimos ese subpack como "final";
 *      - Guardamos offsets de TODOS los subpacks en un vector temporal.
 * 3) Si la validación fue OK, iteramos el vector y llamamos a 'cb' por cada subpack.
 * 4) Actualizamos 'scan_off' al final del pack para buscar el siguiente.
 */
int parse_isp_conf(const uint8_t *buf, size_t len,
                   isp_block_cb cb, void *user,
                   struct parse_isp_conf_stats *out)
{
    if (!buf || !cb) return -1;

    int total_packs = 0;
    int total_blocks = 0;
    size_t scan_off = 0;

    /* Vector temporal para acumular subpacks de un pack (crece dinámicamente) */
    struct item { size_t off; uint16_t id; uint16_t size; };
    struct item *items = NULL;
    size_t items_cap = 0;

    while (scan_off + 4 <= len) {

        /* ---- 1) buscar id==0 candidato ---- */
        size_t candidate_off = (size_t)-1;
        for (size_t off = scan_off; off + 4 <= len; off += 4) {
            struct lehdr h;
            memcpy(&h, buf + off, 4);
            if (h.id == 0x0000) {
                /* size mínimo y no fuera de rango (chequeo único) */
                if (h.size != 0 && off + (size_t)h.size <= len) {
                    candidate_off = off;
                    break;
                }
            }
        }
        if (candidate_off == (size_t)-1) break; /* no hay más packs */

        /* ---- 2) validar pack y recolectar subpacks ---- */
        size_t p = candidate_off;
        uint16_t expect = 0;
        int ok = 0;

        /* reset vector */
        size_t items_len = 0;

        while (1) {
            if (p + 4 > len) { ok = 0; break; }
            struct lehdr h;
            memcpy(&h, buf + p, 4);
            if (p + (size_t)h.size > len || h.size == 0) { ok = 0; break; }

            /* push actual */
            if (items_len == items_cap) {
                size_t new_cap = items_cap ? items_cap * 2 : 32;
                void *new_ptr = realloc(items, new_cap * sizeof(*items));
                if (!new_ptr) { free(items); return -2; }
                items = (struct item*)new_ptr;
                items_cap = new_cap;
            }
            items[items_len].off  = p;
            items[items_len].id   = h.id;
            items[items_len].size = h.size;
            items_len++;

            size_t next = p + (size_t)h.size;

            /* ¿hemos completado id esperado y vamos a chequear el siguiente? */
            if (next + 4 > len) { ok = 0; break; }

            struct lehdr hn;
            memcpy(&hn, buf + next, 4);
            if (next + (size_t)hn.size > len || hn.size == 0) { ok = 0; break; }

            if (hn.id == (uint16_t)(expect + 1)) {
                /* correlativa continúa */
                p = next;
                expect++;
                continue;
            }

            /* mismatch: hn es el "bloque final" -> incluirlo y cerrar pack */
            if (items_len == items_cap) {
                size_t new_cap = items_cap ? items_cap * 2 : 32;
                void *new_ptr = realloc(items, new_cap * sizeof(*items));
                if (!new_ptr) { free(items); return -2; }
                items = (struct item*)new_ptr;
                items_cap = new_cap;
            }
            items[items_len].off  = next;
            items[items_len].id   = hn.id;
            items[items_len].size = hn.size;
            items_len++;

            ok = 1; /* pack válido */
            p = next; /* 'p' apunta al bloque final (no es necesario, pero deja consistente) */
            break;
        }

        if (!ok) {
            /* Falló candidato: seguir buscando detrás de candidate_off */
            scan_off = candidate_off + 4;
            continue;
        }

        /* ---- 3) invocar callback por cada subpack del pack ---- */
        for (size_t i = 0; i < items_len; ++i) {
            const size_t off  = items[i].off;
            const uint16_t id = items[i].id;
            const uint16_t sz = items[i].size;

            const uint8_t *header = buf + off;
            const uint8_t *payload = header + 4;
            const uint16_t payload_size = (sz >= 4) ? (uint16_t)(sz - 4) : 0;

            struct isp_block block = {
                .id = id,
                .size = sz,
                .payload_size = payload_size,
                .header = header,
                .payload = payload,
            };

            /* Si el callback devuelve !=0, interpretamos como “stop” */
            int rc = cb(total_packs, &block, user);
            if (rc != 0) { free(items); if (out) { out->packs = total_packs+1; out->blocks = total_blocks + (int)i + 1; } return 0; }
            total_blocks++;
        }

        total_packs++;

        /* ---- 4) buscar siguiente pack a partir del final de este ---- */
        size_t pack_end = items[items_len - 1].off + (size_t)items[items_len - 1].size;
        scan_off = pack_end;
    }

    free(items);
    if (out) { out->packs = total_packs; out->blocks = total_blocks; }
    return 0;
}

/* Conveniencia: parsear desde fichero */
int parse_isp_conf_file(const char *path,
                        isp_block_cb cb, void *user,
                        struct parse_isp_conf_stats *out)
{
    if (!path || !cb) return -1;
    uint8_t *buf = NULL; size_t n = 0;
    int rc = load_file(path, &buf, &n);
    if (rc != 0) return rc;
    rc = parse_isp_conf(buf, n, cb, user, out);
    free(buf);
    return rc;
}
