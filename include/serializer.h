#ifndef SERIALIZER_H_
#define SERIALIZER_H_

#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t *buffer;
    size_t offset;
    size_t buffer_size;
} Serializer;

int serializer_init(Serializer *stream);

int serializer_set_buffer_size(Serializer *stream, size_t buffer_size);

void serializer_free(Serializer *stream);

#endif // SERIALIZER_H
