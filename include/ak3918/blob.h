/*
 * MIT License
 * 
 * Copyright (c) 2025 Abel Romero
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*
 * Author: Abel Romero
 * File  : blob.h
 * Brief : Helpers to build blob_desc for Sensor_Load_Conf and similar bulk ops.
 */
#ifndef BLOB_H
#define BLOB_H

#include <stddef.h>
#include <stdint.h>
#include "ak3918/sdk/akispsdk.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    void *data;    /* puntero a los bytes cargados (malloc) */
    size_t size;   /* tamaño en bytes */
} blob_t;

int  load_blob(const char *path, blob_t *out);
void free_blob(blob_t *b);

/* Build a blob from a raw payload (already without the 4-byte subpack header). */
static inline void blob_build_from_payload(struct blob_desc *b, const void *payload, size_t payload_len) {
    b->nwords = (uint32_t)(payload_len / 4u);
    b->ptr    = (void*)payload;
}

#ifdef __cplusplus
}
#endif

#endif /* BLOB_H */
