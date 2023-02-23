#include <string.h>
#include "queue.h"

int queue_init(Queue *queue) {
    if (!queue) {
        return -1;
    }
    queue->items = (void **)malloc(0);
    if (!queue->items) {
        return -1;
    }
    queue->items_count = 0;
    if (pthread_mutex_init(&queue->mutex, NULL) < 0) {
        free(queue->items);
        return -1;
    }
    return 0;
}

int queue_insert(Queue *queue, void *item) {
    pthread_mutex_lock(&queue->mutex);
    if (!queue) {
        pthread_mutex_unlock(&queue->mutex);
        return -1;
    }
    queue->items = (void **)realloc(queue->items, (queue->items_count + 1) * sizeof(void **));
    if (!queue->items) {
        pthread_mutex_unlock(&queue->mutex);
        return -1;
    }
    queue->items[queue->items_count++] = item;
    pthread_mutex_unlock(&queue->mutex);
    return 0;
}

void *queue_extract(Queue *queue) {
    pthread_mutex_lock(&queue->mutex);
    if (!queue) {
        pthread_mutex_unlock(&queue->mutex);
        return NULL;
    }
    if (!queue->items) {
        pthread_mutex_unlock(&queue->mutex);
        return NULL;
    }
    if (queue->items_count == 0) {
        pthread_mutex_unlock(&queue->mutex);
        return NULL;
    }
    void *item = queue->items[0];
    void **items = (void **)malloc(--queue->items_count * sizeof(void *));
    if (!items) {
        pthread_mutex_unlock(&queue->mutex);
        return NULL;
    }
    memcpy(items, queue->items[1], queue->items_count);
    free(queue->items);
    queue->items = items;
    pthread_mutex_unlock(&queue->mutex);
    return item;
}

int queue_free(Queue *queue) {
    pthread_mutex_lock(&queue->mutex);
    if (!queue) {
        pthread_mutex_unlock(&queue->mutex);
        return -1;
    }
    if (!queue->items) {
        pthread_mutex_unlock(&queue->mutex);
        return -1;
    }
    free(queue->items);
    pthread_mutex_unlock(&queue->mutex);
    return 0;
}
