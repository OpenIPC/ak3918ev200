Estos archivos contienen los parámetros para levantar el pipeline con el ISP y poder utilizar la cámara.

Básicamente, según el archivo para cada sensor, presentan estructuras diferentes. Aunque todos contienen un tipo de información reconocible.

El algoritmo que he encontrado para poder utilizarlos (en teoría porque solo he podido probar con mi hardware), es leer una secuencia de bloques.

Dichos bloques tienen una estructura como la siguiente:
[cabecera][payload]

siendo que [cabecera] está dividida en 2 palabras de 16 bits: id y size.

Normalmente en size está incluído el tamaño del bloque con la cabecera incluída.

Siguen una secuencia de 0 a 0x18 (24 bloques), después da un salto a 0x1b, 0x1c (y no sé cuales más).

El último bloque es la configuración del sensor.

La configuración del sensor se aplica con 4 bytes (en mi hardware y en teoría en todos) más de lo que ocupa el bloque si restamos el header.

Todos los payloads se suelen aplicar sin la cabecera (solo el payload), pero en el caso de la configuración (Ak_ISP_Load_Conf), se utiliza el tamaño
entero que dice la cabecera, lo cual confunde porque ese bloque tiene 4 bytes más (contando con la cabecera).

Normalmente se aplica la configuración llamando la rutina propia de libakispsdk.so que imagino estará disponible en el firmware del fabricante.
Imagino que dichas librerías dinámicas tendrán hardcodeados los raw req de ioctl necesarios para la operación abstraída con símbolos.
Se suelen utilizar offsets sobre el buffer del payload para según el id, llamar a uno o varios símbolos.

En el caso de Load_Conf se utiliza una estructura como parámetro de 2 palabras de 32 bits: [número de palabras (32bit) del payload][puntero al payload]

En el desarrollo de este proyecto se utiliza la estructura:
struct blob_desc desc = {
        .nwords = (uint32_t)((payload_len + 4) / 4), // como ves se suman 4 bytes para obtener 1 palabra más.
	.ptr    = payload,
};

Algunas llamadas, las he tenido que dumpear traceando el software ipc, porque realizan cálculos y rellenan estructuras que aun no he tenido tiempo
de aislar.
Pero básicamente, hasta la fecha he conseguido volcar raw frames de la cámara, (sin tener lista la limpieza), pero son frames que no sé si por el
formato que estoy utilizando para reproducirlos, o porque van así, se ven claramente en color verde.
Aunque he probado varios formatos, no he conseguido ver la imagen bien.

Podría ser por la mala implementación, dirás, pero en realidad, incluso volcando los frames desde una librería dinámica cargada en el software del
fabricante, no he podido; se ven mal (en verde).

Lo que me da que pensar que:
1) No he encontrado el formato correcto para reproducirlos
ó
2) Los frames en crudo que se obtienen con DQBUF a través de V4L2 no son utilizables directamente y hay que tirar del encoder H264 de hardware
/dev/uio0
