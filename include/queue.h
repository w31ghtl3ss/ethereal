#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdlib.h>
#include <pthread.h>

typedef struct {
    pthread_mutex_t mutex;
    void **items;
    size_t items_count;
} Queue;

int queue_init(Queue *queue);

int queue_insert(Queue *queue, void *item);

void *queue_extract(Queue *queue);

int queue_free(Queue *queue);

#endif // QUEUE_H_
