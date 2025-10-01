// capture_akpcm_v3.c // ffplay -ar 16000 -f s16le capture.raw
// reversing of yoosee ipcam; mic recording
// by shiva
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <time.h>

static void hexdump(const void *buf, size_t len){
    const unsigned char *b = (const unsigned char*)buf;
    size_t i;
    for(i=0;i<len;i++){
        if((i & 15) == 0) printf("%08zx: ", i);
        printf("%02x ", b[i]);
        if((i & 15) == 15) putchar('\n');
    }
    if(len % 16) putchar('\n');
}
static void msleep(unsigned ms){
    struct timespec ts = { ms/1000, (long)(ms%1000)*1000000L };
    nanosleep(&ts, NULL);
}

int main(int argc, char **argv){
    if(argc < 3){
        fprintf(stderr, "Uso: %s /dev/akpcm_cdev1 salida.raw\n", argv[0]);
        return 1;
    }
    const char *dev = argv[1];
    const char *outpath = argv[2];

    /* Mejor abrir en O_RDWR: algunos drivers exigen escritura para ciertos ioctls */
    int fd = open(dev, O_RDWR | O_NONBLOCK);
    if(fd < 0){ perror("open device"); return 1; }

    FILE *out = fopen(outpath, "wb");
    if(!out){ perror("open output file"); close(fd); return 1; }

    int rc;

    /* === Secuencia según tu traza === */

    /* 0x40045010 (val=2) */
    { unsigned long req=0x40045010UL; uint32_t v=2;
      rc=ioctl(fd,req,&v); if(rc<0) perror("ioctl 0x40045010"); }

    /* 0x40045070 (val=1) */
    { unsigned long req=0x40045070UL; uint32_t v=1;
      rc=ioctl(fd,req,&v); if(rc<0) perror("ioctl 0x40045070"); }

    /* 0x40045030 (val=7) */
    { unsigned long req=0x40045030UL; uint32_t v=7;
      rc=ioctl(fd,req,&v); if(rc<0) perror("ioctl 0x40045030"); }

    /* 0x50e3 (no arg) */
    { unsigned long req=0x50e3UL;
      rc=ioctl(fd,req); if(rc<0) perror("ioctl 0x50e3"); }

    /* 0x40045088 (val=1) */
    { unsigned long req=0x40045088UL; uint32_t v=1;
      rc=ioctl(fd,req,&v); if(rc<0) perror("ioctl 0x40045088"); }

    /* 0x50e2 (no arg) */
    { unsigned long req=0x50e2UL;
      rc=ioctl(fd,req); if(rc<0) perror("ioctl 0x50e2"); }

    /* 0x401c50f2 (WRITE 28 bytes) — exactamente los bytes de tu log */
    { unsigned long req=0x401c50f2UL;
      unsigned char buf28[28] = {
        0x80,0x3e,0x00,0x00, 0x01,0x00,0x00,0x00, 0x10,0x00,0x00,0x00, 0x00,0x08,0x00,0x00,
        0x10,0x00,0x00,0x00, 0x00,0x08,0x00,0x00, 0x00,0x00,0x00,0x00
      };
      rc=ioctl(fd,req,buf28); if(rc<0) perror("ioctl 0x401c50f2"); }

    /* 0x50e0 (no arg) */
    { unsigned long req=0x50e0UL;
      rc=ioctl(fd,req); if(rc<0) perror("ioctl 0x50e0"); }

    /* params[64] — el buffer que usa la app para varios ioctls */
    unsigned char params[64]; memset(params, 0, sizeof(params));

    /* 0x804050f0 (READ 64) — llena params con cfg; en tu log hay 0x0000bb80 (=48000 Hz) */
    { unsigned long req=0x804050f0UL;
      rc=ioctl(fd,req,params);
      if(rc<0) perror("ioctl 0x804050f0");
      else { printf("0x804050f0 OK (primeros 48):\n"); hexdump(params, 48); }
    }

    /* 0x50e2 (otra vez, no arg) */
    { unsigned long req=0x50e2UL;
      rc=ioctl(fd,req); if(rc<0) perror("ioctl 0x50e2 (2)"); }

    /* *** AQUÍ ESTABA TU EFAULT ***: 0x50e1 DEBE RECIBIR EL MISMO PUNTERO (params) */
    { unsigned long req=0x50e1UL;
      rc=ioctl(fd,req,params);             /* <-- importante: NO NULL */
      if(rc<0) perror("ioctl 0x50e1"); }

    /* 0x80045085 (READ 4) — el driver escribe en los 4 primeros bytes del MISMO buffer */
    { unsigned long req=0x80045085UL;
      rc=ioctl(fd,req,params);             /* devuelve un u32 en params[0..3]; en tu run 0xc21e3ec4 */
      if(rc<0) perror("ioctl 0x80045085");
      else {
        uint32_t h; memcpy(&h, params, 4);
        printf("0x80045085 -> 0x%08x\n", h);
      }
    }

    /* 0x40045086 (WRITE 4) — la app manda 0 en esos 4 bytes (ack/reset?) */
    { unsigned long req=0x40045086UL; uint32_t zero=0;
      memcpy(params, &zero, 4);
      rc=ioctl(fd,req,params);
      if(rc<0) perror("ioctl 0x40045086");
    }

    printf("Entrando en captura (poll con 0x800450e8). Output: %s\n", outpath);

    const size_t BUFSZ = 4096;
    unsigned char *rbuf = (unsigned char*)malloc(BUFSZ);
    if(!rbuf){ fprintf(stderr,"malloc failed\n"); fclose(out); close(fd); return 1; }

    for(;;){
        /* 0x800450e8 (READ 4) — “avail” */
        unsigned long req=0x800450e8UL; uint32_t avail=0;
        rc = ioctl(fd, req, &avail);
        if(rc < 0){
            perror("ioctl 0x800450e8");
            msleep(10);
            continue;
        }
        /* muestra cada tanto */
        static int tick=0; if((tick++ % 50)==0) printf("avail=%u\n", avail);

        if(avail == 0){ msleep(10); continue; }

        size_t want = avail; if(want > BUFSZ) want = BUFSZ;
        ssize_t n = read(fd, rbuf, want);
        if(n < 0){
            if(errno==EAGAIN || errno==EWOULDBLOCK){ msleep(5); continue; }
            perror("read"); break;
        } else if(n == 0){
            msleep(10); continue;
        }
        if(fwrite(rbuf, 1, (size_t)n, out) != (size_t)n){ perror("fwrite"); break; }
        fflush(out);

        static int first=1;
        if(first){
            printf("Primera lectura %zd bytes (64 primeros):\n", n);
            hexdump(rbuf, (n<64)?(size_t)n:64);
            first=0;
        }
    }

    free(rbuf);
    fclose(out);
    close(fd);
    return 0;
}
