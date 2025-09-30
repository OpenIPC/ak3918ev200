#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static inline uint16_t rd_le16(const uint8_t *p) {
    return (uint16_t)p[0] | ((uint16_t)p[1] << 8);
}
static inline uint32_t rd_le32(const uint8_t *p) {
    return (uint32_t)p[0] | ((uint32_t)p[1] << 8) | ((uint32_t)p[2] << 16) | ((uint32_t)p[3] << 24);
}

static void hexdump_block(const uint8_t *buf, size_t off, size_t len) {
    for (size_t i = 0; i < len; i += 16) {
        printf("    %04zx: ", i);
        size_t j;
        for (j = 0; j < 16; j++) {
            if (i + j < len) {
                printf("%02x ", buf[off + i + j]);
            } else {
                printf("   ");
            }
        }
        printf(" ");
        for (j = 0; j < 16 && i + j < len; j++) {
            unsigned char c = buf[off + i + j];
            printf("%c", isprint(c) ? c : '.');
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    const char *path = "isp_sc1345_dvp.conf";
    int do_hexdump = 0;

    // argumentos
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-x") == 0) {
            do_hexdump = 1;
        } else {
            path = argv[i];
        }
    }

    FILE *f = fopen(path,"rb");
    if (!f) { perror(path); return 1; }

    fseek(f,0,SEEK_END);
    long n_long = ftell(f);
    fseek(f,0,SEEK_SET);

    size_t n = (size_t)n_long;
    uint8_t *buf = (uint8_t*)malloc(n ? n : 1);
    if (!buf) { perror("malloc"); fclose(f); return 1; }
    if (n && fread(buf,1,n,f) != n) { perror("fread"); free(buf); fclose(f); return 1; }
    fclose(f);

    const size_t PACK_HDR = 0x200;
    const uint32_t MAGIC  = 3;

    if (rd_le32(buf) != MAGIC) {
        fprintf(stderr,"magic inválido en 0x0\n");
        free(buf); return 2;
    }

    size_t pack_off = 0;
    unsigned pack_idx = 0;

    for (;;) {
        if (pack_off + PACK_HDR > n) break;
        size_t pos = pack_off + PACK_HDR;

        printf("=== Pack #%u en offset 0x%zx (magic@0x%zx) ===\n", pack_idx, pos, pack_off);

        while (pos + 4 <= n) {
            uint16_t id   = rd_le16(buf + pos + 0);
            uint16_t size = rd_le16(buf + pos + 2);

            if (size < 4) { pos++; continue; }
            if (pos + size > n) { pos = n; break; }

            size_t data_off = pos + 4;
            size_t data_len = size - 4;
            size_t data_end = pos + size;

            printf("  id=0x%02x size=%u data_off=0x%zx..0x%zx (data_len=%zu)\n",
                   id, size, pos, data_end, data_len);

            if (do_hexdump && data_len > 0) {
                hexdump_block(buf, data_off, data_len);
            }

            pos += size;

            if (id == 0x1c) {
                //uint32_t unk = rd_le32(buf + pos);

                //printf("unkown 32 bit word at offset 0x%zx: %d %d %d %d %d", pos, unk, buf[pos], buf[pos + 1], buf[pos +2], buf[pos + 3]);

                size_t next_magic = pos + 4;
                if (next_magic + 4 > n) { pack_off = n; break; }
                if (rd_le32(buf + next_magic) != MAGIC) {
                    pack_off = n; break;
                }
                pack_off = next_magic;
                pack_idx++;
                goto next_pack;
            }
        }
        break;
        next_pack: ;
    }

    free(buf);
    return 0;
}
