#include "list.h"

ListItem *list_item_insert(ListItem *item, void *value) {
    ListItem *temp_item = item;
    while (temp_item->next) {
        temp_item = temp_item->next;
    }
    ListItem *new_item = malloc(sizeof(ListItem));
    if (!new_item) {
        return NULL;
    }
    new_item->value = value;
    new_item->next = NULL;
    new_item->previous = temp_item;
    return new_item;
}

int list_item_free(ListItem *item) {
    if (!item) {
        return -1;
    }
    if (!item->previous && item->next) {
        item->next->previous = NULL;
        free(item);
        return 0;
    }
    if (!item->next && item->previous) {
        item->previous->next = item->next;
        free(item);
        return 0;
    }
    item->previous->next = item->next;
    item->next->previous = item->previous;
    free(item);
    return 0;
}
