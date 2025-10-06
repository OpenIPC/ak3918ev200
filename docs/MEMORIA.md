# Memoria de avances Codex (AK3918EV200)

## 2025-10-06 - Video dump
- Detectamos un SIGSEGV inmediato tras `isp_configure_runtime()` al llamar a `ak_isp_get_awb_attr` con un `uint32_t`.
- El driver devuelve un blob mucho mayor y sobreescribia la pila -> crash nada mas volver de la funcion.
- Ajustamos `isp_configure_runtime()` para leer el atributo en un bufer amplio y anotamos el TODO de reconstruir la estructura vendor antes de volver a escribirla.
- Siguiente paso: correlacionar el layout con los payloads del `.conf` y el tracer para poder reenviar `ak_isp_set_awb_attr` sin riesgos.

## 2025-10-07 - Video dump (fase UIO)
- Compilamos con el toolchain `x-tools/arm-shivaya-linux-uclibcgnueabi` y generamos binarios en `build-arm/bin/` para correr directamente en la cámara.
- Añadimos `AK_UIO_FORCE_MODE` para seleccionar el modo de espera del IRQ (`ak`, `driver`, `std`, `read`) y `AK_VENC_DEBUG=1` para volcar los registros críticos (`base`, `wp`, `len`, `irq`).
- Confirmamos que, sin el burst completo de ioctls ISP, el encoder sigue sin producir IRQs: los dumps muestran `len=0` y `irq` sin el bit 0 activo.
- Siguiente paso: reinyectar los ioctls `0x40044902..0x40044972` con sus payloads originales y observar si empiezan a aparecer frames en `/dev/uio0`.

## 2025-09-XX - Audio
- Activamos la ruta de audio (`/dev/akpcm_cdev0/1`) replicando la secuencia de ioctls del binario vendor.
- Inicializamos microfono y altavoz, dejamos los bucles de I/O deshabilitados por ahora para evitar consumo extra.
- Verificamos que los ioctls de setup no bloquean el pipeline de video (preludio necesario para integrar audio opcional).
