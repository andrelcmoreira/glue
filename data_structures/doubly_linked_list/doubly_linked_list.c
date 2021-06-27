#include <stdio.h>
#include <stdlib.h>

#include "doubly_linked_list.h"

int list_size(struct list_t *list)
{
    int size = 0;

    for_each_node(curr, list) {
        size++;
    }

    return size;
}

struct node_t *allocate_node(char value)
{
    struct node_t *node = NULL;

    node = (struct node_t *)malloc(sizeof(struct node_t));
    if (node) {
        node->next = node->prev = NULL;
        node->value = value;
    }

    return node;
}

void add_to_list(struct list_t *list, struct node_t *elem)
{
    /* if the list is empty */
    if (!list->head && !list->tail) {
        list->tail = list->head = elem;
    } else {
        list->tail->next = elem;
        elem->prev = list->tail;
        list->tail = elem;
    }
}

void del_from_list(struct list_t *list, struct node_t *node)
{
    for_each_node(curr, list) {
        if (curr == node) {
            if (!curr->prev) {
                /* deletion on head */
                list->head = curr->next;

                /* if the list has only one element */
                if (curr->next) {
                    curr->next->prev = NULL;
                    curr->next = NULL;
                }
            } else if (!curr->next) {
                /* deletion on tail */
                list->tail = curr->prev;
                curr->prev->next = NULL;
                curr->prev = NULL;
            } else {
                /* deletion on middle */
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                curr->next = curr->prev = NULL;
            }

            free(curr);
            break;
        }
    }
}

void init_list(struct list_t **list)
{
    *list = (struct list_t *)malloc(sizeof(struct list_t));
    if (*list) {
        (*list)->head = (*list)->tail = NULL;
    }
}

void destroy_list(struct list_t *list)
{
    for_each_node_safe(curr, list) {
        del_from_list(list, curr);
    }

    free(list);
}
