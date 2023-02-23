#ifndef LIST_H_
#define LIST_H_

typedef struct ListItem {
    void *data;
    struct ListItem *next;
    struct ListItem *previous;
} ListItem;

ListItem *list_item_insert(ListItem *item, void *value);

int list_item_free(ListItem *item);

#endif // LIST_H_
