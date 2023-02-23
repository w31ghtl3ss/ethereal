#include "serializer.h"

int serializer_init(Serializer *serializer) {
    if (!serializer) {
        return -1;
    }
    serializer->buffer = malloc(0);
    if (!serializer->buffer) {
        return -1;
    }
    serializer->offset = 0;
    serializer->buffer_size = 0;
    return 0;
}


int serializer_set_buffer_size(Serializer *serializer, size_t buffer_size) {
    if (!serializer) {
        return -1;
    }
    serializer->buffer = realloc(serializer->buffer, buffer_size);
    if (!serializer->buffer) {
        return -1;
    }
    serializer->buffer_size = buffer_size;
    return 0;
}

void serializer_free(Serializer *serializer) {
    if (!serializer && !serializer->buffer) {
        return;
    }
    free(serializer->buffer);
}
