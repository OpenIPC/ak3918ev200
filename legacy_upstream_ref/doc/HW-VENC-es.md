# AK3918EV200 — Codificador H.264 (/dev/uio0) — Guía de Bring‑Up y Extracción de Bitstream

**Autor:** Abel Romero · **Licencia:** MIT

Este documento compila lo que hemos **deducido por trazas** (LD_PRELOAD de `/dev/uio0`) y lo que hemos **corroborado en el decompilado** del binario IPC para el SoC **AK3918EV200**. Su objetivo es servir de **mapa práctico** para inicializar el codificador H.264, entender su **organización de búferes** y **extraer el bitstream** directamente del ION/DMABUF **sin escanear** patrones de start code.

---

## Resumen rápido

- **MMIO vía `/dev/uio0`**: ventana de ~`0x500` bytes (en muchas placas `map0/size` ≈ `0x430`).  
- **Dos anillos de bitstream** (A/B), cada uno en una **ventana de 1 MiB** dentro del gran DMABUF de ION.  
- **Write pointers** por anillo: regs **`0x1C`** (A) y **`0x20`** (B). Programa y reinicializa ventanas con un `ioctl` de **triple palabra (REG, OFFSET, SIZE)**.  
- **Registro de IRQ**: **`0x38`** (leer y **ack** limpiando el bit).  
- **Tamaño del bloque producido**:  
  - A: reg **`0x98`** publica el tamaño en **unidades de 256 B** (observado en trazas).  
  - B: el “gemelo” no es obvio en el decompilado, pero los **saltos del `wp_B`** confirman su cuantización (p.ej. `0x1CC00` = 460×256).  
- **Cola RAW (VI/ISP→VENC)**: regs **`0x2C/0x30/0x34`** avanzan exactamente **`0x233000`** (2.306.048) por buffer (nuestro `enqueue_len` de V4L2).  
- **Bases de bitstream**: reg **`0x14`** (A) y **posible** `0x18` (B).  
- Reg **`0x60`**: se inicializa con `width>>1` y **en runtime** refleja **bytes de payload** del bloque (observado).

> Muchos registros aparecen **duplicados** a partir de `0x200` (vista espejo/sombra).

---

## MMIO y convención de offsets (bytes vs palabras)

El binario utiliza helpers `write32(ctx, off, val)` y `read32(ctx, off)` (nombres “amables” para el decompilado `FUN_000bb8f0` y `FUN_000bba64`).  
- El llamante, cuando parte de un **índice de registro** en **palabras**, aplica **`<< 2`** y pasa un **offset en bytes**.  
- La lectura alinea con `off & ~3` y accede como `*(base + off_en_bytes)`.

**Conclusión**: los offsets de esta guía (`0x14`, `0x1C`, `0x20`, `0x38`, `0x60`, `0x98`, …) son **en bytes** y coinciden con tus volcados MMIO.

---

## Tabla de registros (offset desde base MMIO)

| Off | R/W | Descripción                                                                                     |
|:---:|:---:|--------------------------------------------------------------------------------------------------|
| 0x14|  W  | **Base bitstream A** (dirección base en DMABUF)                                                  |
| 0x18|  W? | **Base bitstream B** (según build; verificar)                                                    |
| 0x1C| R/W | **Write pointer A** (dentro de ventana 1 MiB, en slots de 256 B)                                 |
| 0x20| R/W | **Write pointer B** (igual que 0x1C para segundo anillo)                                         |
| 0x38| R/W | **IRQ status**; leer tras evento y **ack** escribiendo `valor & ~1`                              |
| 0x60| R/W | **Parámetro multiuso**: init con `width>>1`; en runtime observado como **payload_len** (bytes)   |
| 0x98|  R  | **Unidades de 256 B del bloque A** (p.ej., `0x398` ⇒ `0x39800` bytes)                            |
|0x2C/0x30/0x34|R| **Punteros/ventana RAW**; avanzan/rotan en pasos de `0x233000` (tamaño de buffer V4L2)     |
|0x200..| – | **Espejo** de 0x000.. (duplicación de vista)                                                     |

> **Tamaño de ventana MMIO**: en UIO suele ser `map0/size` ≈ `0x430`. Evita leer fuera.

---

## Secuencia de inicialización (decompilado ↔ trazas)

**Funciones (nombres orientativos):**  
- `FUN_000b0ae4` → *encoder_reset_windows* (configura ventanas 1 MiB y reinicia write pointers).  
- `FUN_000b82a4` → *encoder_setup_base_and_params* (programa `0x14` y `0x60`).  
- `FUN_000bbc60` → *irq_ack* (lee/escribe `0x38`).  
- `FUN_000bb8f0` → *write32(ctx, off_en_bytes, val)*.  
- `FUN_000bba64` → *read32(ctx, off_en_bytes)*.

**Programación de anillos (observado como ioctl “3×32”):**

1. Definir ventana de 1 MiB (A y B) y preparar puntero:  
   ```text
   (REG=0x0800001C, OFFSET=0x00100000, SIZE=0x00100000)
   (REG=0x08000020, OFFSET=0x00100000, SIZE=0x00100000)
   (REG=0x0800001C, OFFSET=0x00000000, SIZE=0x00100000)  // reinicia wp
   (REG=0x08000020, OFFSET=0x00000000, SIZE=0x00100000)  // reinicia wp
   ```
2. Cargar **base del bitstream** y **parámetros**:  
   ```c
   write32(mmio, 0x14, base_A);            // desde estructura de setup
   write32(mmio, 0x60, width >> 1);        // en runtime refleja payload_len
   // (base_B por 0x18 si procede)
   ```

**Notas prácticas**  
- En algunas builds hay **dos mmaps** de `/dev/uio0`: uno R/O (~0x430) y otro R/W (~0x500) que devuelven la **misma VA**; respeta permisos.  
- Varios registros son **de solo lectura** (p.ej., `0x98`).

---

## Bucle de ejecución (IRQ → lectura → copia → ack)

1. **Esperar IRQ**: `select/epoll` sobre `/dev/uio0`.  
2. **Atender IRQ**: `ioctl(uio0, AKUIO_WAIT_IRQ)` (o `read(uio0)` según driver).  
3. **Leer registros clave**:  
   ```c
   baseA = RD32(mmio+0x14);
   wpA   = RD32(mmio+0x1C);
   unitsA= RD32(mmio+0x98) & 0xFFF;        // tamaño A en unidades de 256 B
   len   = RD32(mmio+0x60);                 // bytes efectivos del bloque
   // Para B: wpB = RD32(mmio+0x20); (y su “unitsB” si localizas el gemelo de 0x98)
   ```
4. **Calcular posición en ventana (1 MiB)** y **copiar** desde DMABUF:  
   ```c
   off   = wpA & 0xFFFFF;               // wp % 1MiB
   addr  = baseA + off;                 // base del bloque (ajustar si WP apunta tras el final)
   slotB = unitsA * 256;                // tamaño de “slot” del hardware para A
   // Si el WP avanza por slots, el payload real es 'len' y reside al final del bloque:
   src   = dmabuf + addr - len;         // ajusta según dirección de avance observada
   write(out_h264, src, len);
   ```
5. **Ack IRQ**: limpiar el bit en `0x38`.  
   ```c
   st = RD32(mmio+0x38);
   WR32(mmio+0x38, st & ~1);
   ```

> **Importante**: realiza la lectura del MMIO **tras** el `ioctl` de evento. Evita volcar justo al retorno de `select()`.

---

## Relación con la cola RAW (V4L2)

- Los userptr iniciales se encolan con **`len=0x233000`**, y los DQBUF posteriores con **`len≈0x151800` (1382400)**.  
- En MMIO, `0x2C/0x30/0x34` rotan **exactamente** cada `0x233000`, lo que cuadra con el **ring de captura** (VI/ISP) que alimenta al encoder.  
- No es necesario para extraer H.264, pero es útil para **depurar** sincronía de canal.

---

## Seguridad y buenas prácticas

- **No leer fuera** del `map0/size` (en tu placa ≈ `0x430`).  
- Antes de volcar, **verifica** que `[g_va..g_va+g_len)` sigue mapeado/legible (`/proc/self/maps`).  
- Evita leer MMIO en retorno de `select()`; **espera al `ioctl`** que atiende/arma la IRQ.  
- Si el proceso hace `munmap/mremap/exec`, invalida tu VA y re‑descubre el mapa.

---

## Conclusión

Con los registros **`0x14/0x18` (bases), `0x1C/0x20` (write pointers), `0x98` (slots 256 B, A), `0x60` (payload_len)** y el **IRQ en `0x38`**, se puede **extraer el bitstream H.264** directamente del DMABUF, **sin escanear NALs**, tanto para **main** (A) como para **substream** (B).  
El decompilado confirma la **programación de ventanas 1 MiB** mediante el `ioctl` de 3×32 y la **rutina de ack**. Los datos de **cola RAW** casan con V4L2 (`0x233000`). Con este mapa, falta solo **integrar el bucle de copia** en `stream_setup_test_CLEAN.c` tras `AKUIO_WAIT_IRQ`.

---

## Constantes útiles (C)

```c
#define MMIO_BASE_SIZE     0x500    // map0 suele ser ~0x430
#define REG_BASE_A         0x14
#define REG_BASE_B         0x18
#define REG_WP_A           0x1C
#define REG_WP_B           0x20
#define REG_IRQ_STATUS     0x38
#define REG_PARAM_LEN      0x60     // init: width>>1; runtime: payload_len
#define REG_UNITS256_A     0x98     // tamaño del bloque A = (RD32 & 0xFFF) * 256

#define RING_WINDOW_BYTES  0x100000
#define RAW_STEP_BYTES     0x233000
```

