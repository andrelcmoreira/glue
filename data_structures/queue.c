#include <stdio.h>
#include <stdlib.h>

#define for_each_node(curr, queue) \
    for (struct node_t *curr = queue->head; curr; curr = curr->prev)

#define for_each_node_safe(curr, queue) \
    for (struct node_t *curr = queue->head, *tmp = curr ? curr->prev : NULL; \
         curr; \
         curr = tmp, tmp = tmp ? tmp->prev : NULL)

struct node_t {
    struct node_t *next;
    struct node_t *prev;
    char value;
};

struct queue_t {
    struct node_t *tail;
    struct node_t *head;
};

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

int main(void)
{
    struct queue_t *queue = NULL;

    init_queue(&queue);

    {
        struct node_t *char1 = allocate_node('a');
        struct node_t *char2 = allocate_node('b');
        struct node_t *char3 = allocate_node('c');
        struct node_t *char4 = allocate_node('d');
        struct node_t *char5 = allocate_node('e');
        struct node_t *char6 = allocate_node('f');

        enqueue(queue, char1);
        enqueue(queue, char2);
        enqueue(queue, char3);
        enqueue(queue, char4);
        enqueue(queue, char5);

        printf("size %d\n", queue_size(queue));

        for_each_node(curr, queue) {
            printf("curr->value %c\n", curr->value);
        }

        struct node_t *node = NULL;
        {
            node = dequeue(queue);
            if (node) {
                printf("%c\n", node->value);
                free(node);
            }
        }

        {
            node = dequeue(queue);
            if (node) {
                printf("%c\n", node->value);
                free(node);
            }
        }

        {
            node = dequeue(queue);
            if (node) {
                printf("%c\n", node->value);
                free(node);
            }
        }

        {
            node = dequeue(queue);
            if (node) {
                printf("%c\n", node->value);
                free(node);
            }
        }

        printf("size %d\n", queue_size(queue));

        printf("normal\n");
        for_each_node(curr, queue) {
            printf("curr->value %c\n", curr->value);
        }

        enqueue(queue, char6);

        printf("size %d\n", queue_size(queue));

        printf("normal\n");
        for_each_node(curr, queue) {
            printf("curr->value %c\n", curr->value);
        }

        {
            node = dequeue(queue);
            if (node) {
                printf("%c\n", node->value);
                free(node);
            }
        }

        printf("size %d\n", queue_size(queue));

        printf("normal\n");
        for_each_node(curr, queue) {
            printf("curr->value %c\n", curr->value);
        }

        {
            node = dequeue(queue);
            if (node) {
                printf("%c\n", node->value);
                free(node);
            }
        }
    }

    destroy_queue(queue);

    return 0;
}
