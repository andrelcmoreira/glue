#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int queue_size(struct queue_t *queue)
{
    int size = 0;

    for_each_node(curr, queue) {
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

void enqueue(struct queue_t *queue, struct node_t *elem)
{
    /* if the queue is empty */
    if (!queue->head && !queue->tail) {
        queue->tail = queue->head = elem;
    } else {
        queue->tail->prev = elem;
        elem->next = queue->tail;
        queue->tail = elem;
    }
}

struct node_t *dequeue(struct queue_t *queue)
{
    struct node_t *to_del = queue->head;

    /* if the list is not empty */
    if (to_del) {
        queue->head = to_del->prev;
        /* if the queue has only one element */
        if (to_del->prev) {
            to_del->prev->next = NULL;
            to_del->prev = NULL;
        } else {
            queue->head = queue->tail = NULL;
        }
    }

    return to_del;
}

void init_queue(struct queue_t **queue)
{
    *queue = (struct queue_t *)malloc(sizeof(struct queue_t));
    if (*queue) {
        (*queue)->head = (*queue)->tail = NULL;
    }
}

void destroy_queue(struct queue_t *queue)
{
    for_each_node_safe(curr, queue) {
        struct node_t *node = dequeue(queue);

        free(node);
    }

    free(queue);
}

