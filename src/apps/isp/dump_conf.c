/*
 * dump_isp_conf.c
 * Autor: Abel Romero
 * Licencia: MIT
 *
 * Programa de usuario que:
 *   - Usa parse_isp_conf.c para recorrer packs/bloques de un .conf
 *   - Lista contenido, con filtros por --pack y --id, y hexdump opcional
 *   - Prepara un “switch” para integrar más tarde llamadas AK_ISP_* (set/get)
 *
 * Compilación:
 *   gcc -O2 -Wall -Wextra -o dump_isp_conf dump_isp_conf.c parse_isp_conf.c
 *
 * Uso:
 *   dump_isp_conf <archivo.conf> [opciones]
 *
 * Opciones:
 *   --pack N          : sólo mostrar el pack N (0,1,2,...)  (por defecto: todos)
 *   --id HEX|DEC      : sólo mostrar ese id (p.ej. 0x1c o 28) (por defecto: todos)
 *   --hexdump N       : volcar hasta N bytes del payload de cada bloque (capado a 8192)
 *   --mode dump       : (por defecto) listar/dumpear
 *   --mode apply-set  : (stub) simular llamadas AK_ISP_set_* por id
 *   --mode apply-get  : (stub) simular llamadas AK_ISP_get_* por id
 *
 * Notas:
 *   - “apply” es un stub para dejar listo el enganche al SDK real.
 *   - El callback ahora entrega tanto el bloque completo (header+payload) como el
 *     payload ya aislado, para replicar con fidelidad el comportamiento del vendor.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "ak3918/isp_conf.h"

/* ========== Utilidades CLI ========== */
static int parse_u16_any(const char *s, uint16_t *out) {
    if (!s || !*s) return -1;
    char *endp = NULL;
    long v = strtol(s, &endp, 0); /* base 0: acepta 0x.. */
    if (endp && *endp) return -1;
    if (v < 0 || v > 0xFFFF) return -1;
    *out = (uint16_t)v;
    return 0;
}

/* Hexdump legible, capado a 8192 bytes */
static void hexdump_cap(const uint8_t *p, size_t n, size_t max_bytes, size_t base_off) {
    //const size_t LIMIT = 8192;
    //if (max_bytes > LIMIT) max_bytes = LIMIT;
    if (n > max_bytes) n = max_bytes;

    const size_t per_line = 16;
    for (size_t i = 0; i < n; i += per_line) {
        size_t chunk = (n - i > per_line) ? per_line : (n - i);
        printf("      %08zx  ", base_off + i);
        for (size_t j = 0; j < per_line; ++j) {
            if (j < chunk) printf("%02x ", p[i + j]);
            else           printf("   ");
        }
        printf(" |");
        for (size_t j = 0; j < chunk; ++j) {
            uint8_t c = p[i + j];
            printf("%c", (c >= 32 && c <= 126) ? (int)c : '.');
        }
        printf("|\n");
    }
}

/* ======= “Switch” de APPLY (stub) =======
 * Aquí mapearemos id -> llamada AK_ISP_* real (set/get).
 * Por ahora sólo imprimimos lo que *haríamos*.
 */
static int ak_isp_apply_stub(int is_set, uint16_t id, const uint8_t *payload, uint16_t size) {
    (void)payload; (void)size;
    if (is_set) {
        printf("    [APPLY-SET] id=0x%02x size=%u  (stub)\n", id, (unsigned)size);
    } else {
        printf("    [APPLY-GET] id=0x%02x         (stub)\n", id);
    }
    /* TODO: integrar con libakispsdk.so (AK_ISP_set_* / AK_ISP_get_*) usando tabla nr_map */
    return 0;
}

/* ====== Callback de DUMP / APPLY ====== */
struct opts {
    int   mode;          /* 0=dump, 1=apply-set, 2=apply-get */
    int   filter_pack;   /* -1 => todos */
    int   filter_id;     /* -1 => todos */
    size_t hexdump;      /* 0 => no hexdump, -1 => all */
    size_t cur_offset;   /* sólo informativo para el hexdump base */
};

static int on_block(int pack, const struct isp_block *block, void *user) {
    struct opts *o = (struct opts*)user;

    if (!block) return 0;

    if (o->filter_pack >= 0 && pack != o->filter_pack) return 0;
    if (o->filter_id   >= 0 && block->id != (uint16_t)o->filter_id) return 0;

    const uint16_t id = block->id;
    const uint16_t payload_size = block->payload_size;
    const uint16_t block_size = block->size;
    const uint8_t *payload = block->payload;

    switch (o->mode) {
        case 0: /* dump */
            printf("pack=%d id=0x%02x size=%u payload=%u\n",
                   pack, id, (unsigned)block_size, (unsigned)payload_size);
            if (o->hexdump > 0 && payload && payload_size > 0) {
                hexdump_cap(payload, payload_size, o->hexdump, 0);
            } else if (o->hexdump == (size_t)-1 && payload && payload_size > 0) {
                hexdump_cap(payload, payload_size, payload_size - 4, 0);
            }
            break;
        case 1: /* apply-set (stub) */
            printf("pack=%d id=0x%02x size=%u payload=%u -> set\n",
                   pack, id, (unsigned)block_size, (unsigned)payload_size);
            (void)ak_isp_apply_stub(1, id, payload, payload_size);
            break;
        case 2: /* apply-get (stub) */
            printf("pack=%d id=0x%02x -> get\n", pack, id);
            (void)ak_isp_apply_stub(0, id, payload, payload_size);
            break;
    }
    return 0;
}

/* ========== main ========== */
static void usage(const char *argv0) {
    fprintf(stderr,
        "Uso: %s <archivo.conf> [opciones]\n"
        "Opciones:\n"
        "  --pack N         Mostrar sólo el pack N\n"
        "  --id HEX|DEC     Mostrar sólo el id indicado (p.ej. 0x1c, 28)\n"
        "  --hexdump N      Hexdump de N bytes por bloque (capado a 8192)\n"
        "  --mode dump      (por defecto) listar/dumpear\n"
        "  --mode apply-set (stub) simular AK_ISP_set_*\n"
        "  --mode apply-get (stub) simular AK_ISP_get_*\n",
        argv0
    );
}

int main(int argc, char **argv) {
    if (argc < 2) { usage(argv[0]); return 1; }

    const char *path = argv[1];
    struct opts o;
    o.mode = 0;
    o.filter_pack = -1;
    o.filter_id = -1;
    o.hexdump = 0;
    o.cur_offset = 0;

    /* parse opciones */
    for (int i = 2; i < argc; ++i) {
        if (strcmp(argv[i], "--pack") == 0 && i+1 < argc) {
            o.filter_pack = atoi(argv[++i]);
            continue;
        }
        if (strcmp(argv[i], "--id") == 0 && i+1 < argc) {
            uint16_t v=0; if (parse_u16_any(argv[++i], &v) != 0) { fprintf(stderr, "Valor --id inválido.\n"); return 1; }
            o.filter_id = (int)v;
            continue;
        }
        if (strcmp(argv[i], "--hexdump") == 0 && i+1 < argc) {
            long v = strtol(argv[++i], NULL, 0);
            //if (v < 0) v = 0;
            o.hexdump = (size_t)v;
            continue;
        }
        if (strcmp(argv[i], "--mode") == 0 && i+1 < argc) {
            const char *m = argv[++i];
            if      (strcmp(m, "dump") == 0)      o.mode = 0;
            else if (strcmp(m, "apply-set") == 0) o.mode = 1;
            else if (strcmp(m, "apply-get") == 0) o.mode = 2;
            else { fprintf(stderr, "Modo desconocido: %s\n", m); return 1; }
            continue;
        }
        fprintf(stderr, "Opción desconocida: %s\n", argv[i]);
        usage(argv[0]);
        return 1;
    }

    struct parse_isp_conf_stats stats = {0,0};
    int rc = parse_isp_conf_file(path, on_block, &o, &stats);
    if (rc != 0) {
        fprintf(stderr, "Error al parsear %s (rc=%d)\n", path, rc);
        return 1;
    }

    printf("Resumen: packs=%d, bloques=%d\n", stats.packs, stats.blocks);
    return 0;
}
