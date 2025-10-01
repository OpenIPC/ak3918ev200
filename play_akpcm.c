/*
 * play_akpcm_v4.c — Reproduce PCM S16LE en /dev/akpcm_cdev0 replicando tu log.
 *
 * Compilar:
 *   gcc -O2 -o play_akpcm_v4 play_akpcm_v4.c
 *
 * Usar (root):
 *   ./play_akpcm_v4 /dev/akpcm_cdev0 input.raw [chunk_bytes]
 *
 * input.raw: PCM S16LE (mono/estéreo) en la tasa que espera el driver (el setup pone 0x3e80=16000).
 * chunk_bytes: 384 por defecto (prueba 576 o 768 si prefieres).
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/ioctl.h>

static void msleep(unsigned ms){
    struct timespec ts;
    ts.tv_sec  = ms/1000;
    ts.tv_nsec = (long)(ms%1000)*1000000L;
    nanosleep(&ts, NULL);
}
static void hexdump(const unsigned char *b, size_t n){
    size_t i;
    for(i=0;i<n;i++){
        if((i & 15) == 0) printf("%08zx: ", i);
        printf("%02x ", b[i]);
        if((i & 15) == 15) putchar('\n');
    }
    if(n % 16) putchar('\n');
}

int main(int argc, char **argv){
    if(argc < 3){
        fprintf(stderr, "Uso: %s /dev/akpcm_cdev0 input.raw [chunk_bytes]\n", argv[0]);
        return 1;
    }
    const char *devpath = argv[1];
    const char *inpath  = argv[2];
    size_t CHUNK = (argc >= 4) ? (size_t)strtoul(argv[3], NULL, 0) : 384;

    /* Bloqueante: dejamos que write() espere al HW si hace falta */
    int fd = open(devpath, O_WRONLY);
    if(fd < 0){ perror("open device"); return 1; }

    FILE *in = fopen(inpath, "rb");
    if(!in){ perror("open input"); close(fd); return 1; }

    int rc;
    unsigned char params[64]; memset(params, 0, sizeof(params));

    /* ========= SETUP (según el log) ========= */

    /* (A) Enable ruta/salida */
    { unsigned long req=0x40045081UL; uint32_t v=1;
      rc=ioctl(fd,req,&v);
      if(rc<0) perror("ioctl 0x40045081 (enable=1)"); else printf("0x40045081 OK\n");
    }

    /* (B) 0x50e3 (opcional, suele ir antes de 0x40045030) */
    { unsigned long req=0x50e3UL;
      rc=ioctl(fd,req);
      if(rc<0) perror("ioctl 0x50e3"); else printf("0x50e3 OK\n");
    }

    /* (C) 0x40045030 = 5 (tu log lo hace primero a 5 y luego a 4) */
    { unsigned long req=0x40045030UL; uint32_t v=5;
      rc=ioctl(fd,req,&v);
      if(rc<0) perror("ioctl 0x40045030=5"); else printf("0x40045030=5 OK\n");
    }

    /* (D) 0x40045030 = 4 */
    { unsigned long req=0x40045030UL; uint32_t v=4;
      rc=ioctl(fd,req,&v);
      if(rc<0) perror("ioctl 0x40045030=4"); else printf("0x40045030=4 OK\n");
    }

    /* (E) 0x40045010 = 4 */
    { unsigned long req=0x40045010UL; uint32_t v=4;
      rc=ioctl(fd,req,&v);
      if(rc<0) perror("ioctl 0x40045010=4"); else printf("0x40045010=4 OK\n");
    }

    /* (F) 0x40045070 = 1 */
    { unsigned long req=0x40045070UL; uint32_t v=1;
      rc=ioctl(fd,req,&v);
      if(rc<0) perror("ioctl 0x40045070=1"); else printf("0x40045070=1 OK\n");
    }

    /* (G) 0x50e2 */
    { unsigned long req=0x50e2UL;
      rc=ioctl(fd,req);
      if(rc<0) perror("ioctl 0x50e2"); else printf("0x50e2 OK\n");
    }

    /* (H) 0x401c50f2 — 28 bytes (patrón de salida en tu log) */
    { unsigned long req=0x401c50f2UL;
      unsigned char b28[28] = {
        0x80,0x3e,0x00,0x00,  /* 0x3e80 = 16000 (el driver decide cómo usarlo) */
        0x02,0x00,0x00,0x00,
        0x10,0x00,0x00,0x00, 0x00,0x10,0x00,0x00,
        0x0c,0x00,0x00,0x00, 0x00,0x10,0x00,0x00,
        0x00,0x00,0x00,0x00
      };
      rc=ioctl(fd,req,b28);
      if(rc<0) perror("ioctl 0x401c50f2"); else printf("0x401c50f2 (28B) OK\n");
    }

    /* (I) 0x50e0 */
    { unsigned long req=0x50e0UL;
      rc=ioctl(fd,req);
      if(rc<0) perror("ioctl 0x50e0"); else printf("0x50e0 OK\n");
    }

    /* (J) 0x804050f0 — lee 64 bytes de params */
    { unsigned long req=0x804050f0UL;
      rc=ioctl(fd,req,params);
      if(rc<0) perror("ioctl 0x804050f0");
      else { printf("0x804050f0 OK (primeros 32B):\n"); hexdump(params, 32); }
    }

    /* (K) 0x801c50f2 — lee 28 bytes */
    { unsigned long req=0x801c50f2UL; unsigned char b28[28]; memset(b28,0,sizeof(b28));
      rc=ioctl(fd,req,b28);
      if(rc<0) perror("ioctl 0x801c50f2");
      else { printf("0x801c50f2 OK (28B):\n"); hexdump(b28, 28); }
    }

    /* (L) 0x80045010 y 0x80045030 — en tu log ambos devuelven 0x00000004 */
    { unsigned long req=0x80045010UL; uint32_t r=0;
      rc=ioctl(fd,req,&r); if(rc<0) perror("ioctl 0x80045010"); else printf("0x80045010 -> 0x%08x\n", r);
    }
    { unsigned long req=0x80045030UL; uint32_t r=0;
      rc=ioctl(fd,req,&r); if(rc<0) perror("ioctl 0x80045030"); else printf("0x80045030 -> 0x%08x\n", r);
    }

    /* (M) 0x50e3 — opcional otra vez: algunas trazas lo repiten */
    { unsigned long req=0x50e3UL;
      rc=ioctl(fd,req);
      if(rc<0) perror("ioctl 0x50e3 (2)"); else printf("0x50e3 (2) OK\n");
    }

    /* ========= REPRODUCCIÓN ========= */

    printf("Reproduciendo %s en bloques de %zu bytes…\n", inpath, CHUNK);

    unsigned char *buf = (unsigned char*)malloc(CHUNK);
    if(!buf){ fprintf(stderr,"malloc failed\n"); fclose(in); close(fd); return 1; }

    size_t total = 0;
    unsigned tick = 0;

    while(1){
        size_t n = fread(buf, 1, CHUNK, in);
        if(n == 0){
            if(ferror(in)) perror("fread");
            break; /* EOF */
        }

        /* En tu log, muchas veces escriben directamente; si quieres gatear, puedes consultar 0x800450e7:
           uint32_t ready=0; ioctl(fd, 0x800450e7, &ready); if(!ready) espera; */
        /* Trigger suave: varias trazas llaman 0x50e1; si falla sin arg, reintenta con params */
        {
            unsigned long req = 0x50e1UL;
            rc = ioctl(fd, req);
            if(rc < 0 && (errno == EFAULT || errno == EINVAL)){
                rc = ioctl(fd, req, params);
            }
            /* si sigue fallando, no abortes: muchas sesiones escriben sin 50e1 */
        }

        size_t off = 0;
        while(off < n){
            ssize_t w = write(fd, buf + off, n - off);
            if(w > 0){
                off   += (size_t)w;
                total += (size_t)w;
                if(((++tick) & 0x3f) == 0) printf("... escrito %zu bytes\n", total);
                continue;
            }
            if(w == -1 && (errno == EINTR)) continue;

            if(w == -1 && errno == EINVAL){
                /* Fallback a tamaños preferidos por el driver */
                size_t try1 = (n - off >= 576) ? 576 : (n - off);
                if(try1){
                    w = write(fd, buf + off, try1);
                    if(w > 0){ off += (size_t)w; total += (size_t)w; continue; }
                }
                size_t try2 = (n - off >= 384) ? 384 : (n - off);
                if(try2){
                    w = write(fd, buf + off, try2);
                    if(w > 0){ off += (size_t)w; total += (size_t)w; continue; }
                }
            }

            if(w == -1 && (errno == EAGAIN || errno == EWOULDBLOCK)){
                /* No debería con O_WRONLY bloqueante, pero por si acaso: */
                msleep(2);
                continue;
            }

            perror("write");
            free(buf);
            fclose(in);
            close(fd);
            return 1;
        }
    }

    free(buf);
    fclose(in);
    close(fd);
    printf("Listo. Total escrito: %zu bytes\n", total);
    return 0;
}
