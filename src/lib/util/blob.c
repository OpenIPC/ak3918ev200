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
 * File  : blob.c
 * Brief : (Intentionally minimal) - struct lives in akispsdk.h, helper is inline in blob.h
 */
#include "ak3918/blob.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int load_blob(const char *path, blob_t *out) {
    if (!path || !out) {
        errno = EINVAL;
        return -1;
    }
    out->data = NULL;
    out->size = 0;

    struct stat st;
    if (stat(path, &st) != 0) return -1;

    size_t size = (size_t)st.st_size;
    FILE *f = fopen(path, "rb");
    if (!f) return -1;

    if (size == 0) { fclose(f); return 0; }

    void *buf = malloc(size);
    if (!buf) { fclose(f); errno = ENOMEM; return -1; }

    size_t readn = 0;
    while (readn < size) {
        size_t r = fread((uint8_t*)buf + readn, 1, size - readn, f);
        if (r == 0) {
            if (feof(f)) break;
            if (ferror(f)) { int saved = errno; free(buf); fclose(f); errno = saved ? saved : EIO; return -1; }
        }
        readn += r;
    }
    fclose(f);

    if (readn != size) {
        void *shrunk = realloc(buf, readn ? readn : 1);
        if (shrunk || readn == 0) {
            buf = shrunk;
            out->data = buf;
            out->size = readn;
            return 0;
        } else {
            free(buf);
            errno = ENOMEM;
            return -1;
        }
    }

    out->data = buf;
    out->size = size;
    return 0;
}

void free_blob(blob_t *b) {
    if (!b) return;
    if (b->data) { free(b->data); b->data = NULL; }
    b->size = 0;
}
