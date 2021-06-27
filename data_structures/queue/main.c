#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void test_1()
{
    printf("start %s\n\n", __FUNCTION__);

    struct queue_t *queue = NULL;

    init_queue(&queue);

    struct node_t *char1 = allocate_node('a');
    struct node_t *char2 = allocate_node('b');
    struct node_t *char3 = allocate_node('c');
    struct node_t *char4 = allocate_node('d');
    struct node_t *char5 = allocate_node('e');

    enqueue(queue, char1);
    enqueue(queue, char2);
    enqueue(queue, char3);
    enqueue(queue, char4);
    enqueue(queue, char5);

    printf("size %d\n", queue_size(queue));

    for_each_node(curr, queue) {
        printf("curr->value %c\n", curr->value);
    }

    destroy_queue(queue);

    printf("end %s\n\n", __FUNCTION__);
}

void test_2()
{
    printf("start %s\n\n", __FUNCTION__);

    struct queue_t *queue = NULL;

    init_queue(&queue);

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
    enqueue(queue, char6);

    printf("size %d\n", queue_size(queue));

    for_each_node(curr, queue) {
        printf("curr->value %c\n", curr->value);
    }

    struct node_t *to_del = NULL;
    {
        to_del = dequeue(queue);
        if (to_del) {
            printf("to_del->value: %c\n", to_del->value);
            free(to_del);
        }
    }

    {
        to_del = dequeue(queue);
        if (to_del) {
            printf("to_del->value: %c\n", to_del->value);
            free(to_del);
        }
    }

    {
        to_del = dequeue(queue);
        if (to_del) {
            printf("to_del->value: %c\n", to_del->value);
            free(to_del);
        }
    }

    {
        to_del = dequeue(queue);
        if (to_del) {
            printf("to_del->value: %c\n", to_del->value);
            free(to_del);
        }
    }

    {
        to_del = dequeue(queue);
        if (to_del) {
            printf("to_del->value: %c\n", to_del->value);
            free(to_del);
        }
    }

    {
        to_del = dequeue(queue);
        if (to_del) {
            printf("to_del->value: %c\n", to_del->value);
            free(to_del);
        }
    }

    printf("size %d\n", queue_size(queue));

    for_each_node(curr, queue) {
        printf("curr->value %c\n", curr->value);
    }

    destroy_queue(queue);

    printf("end %s\n\n", __FUNCTION__);
}

void test_3()
{
    printf("start %s\n\n", __FUNCTION__);

    struct queue_t *queue = NULL;

    init_queue(&queue);

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

    struct node_t *to_del = NULL;
    {
        to_del = dequeue(queue);
        if (to_del) {
            printf("to_del->value: %c\n", to_del->value);
            free(to_del);
        }
    }

    {
        to_del = dequeue(queue);
        if (to_del) {
            printf("to_del->value: %c\n", to_del->value);
            free(to_del);
        }
    }

    {
        to_del = dequeue(queue);
        if (to_del) {
            printf("to_del->value: %c\n", to_del->value);
            free(to_del);
        }
    }

    {
        to_del = dequeue(queue);
        if (to_del) {
            printf("to_del->value: %c\n", to_del->value);
            free(to_del);
        }
    }

    {
        to_del = dequeue(queue);
        if (to_del) {
            printf("to_del->value: %c\n", to_del->value);
            free(to_del);
        }
    }

    printf("size %d\n", queue_size(queue));

    for_each_node(curr, queue) {
        printf("curr->value %c\n", curr->value);
    }

    enqueue(queue, char6);

    printf("size %d\n", queue_size(queue));

    for_each_node(curr, queue) {
        printf("curr->value %c\n", curr->value);
    }

    {
        to_del = dequeue(queue);
        if (to_del) {
            printf("to_del->value: %c\n", to_del->value);
            free(to_del);
        }
    }

    printf("size %d\n", queue_size(queue));

    for_each_node(curr, queue) {
        printf("curr->value %c\n", curr->value);
    }

    destroy_queue(queue);

    printf("end %s\n\n", __FUNCTION__);
}

void test_4()
{
    printf("start %s\n\n", __FUNCTION__);

    struct queue_t *queue = NULL;

    init_queue(&queue);

    printf("size %d\n", queue_size(queue));
    for_each_node(curr, queue) {
        printf("curr->value %c\n", curr->value);
    }

    struct node_t *to_del = NULL;
    for (int i = 0; i < 10; i++) {
        to_del = dequeue(queue);
        if (to_del) {
            printf("to_del->value: %c\n", to_del->value);
            free(to_del);
        }

    }

    destroy_queue(queue);

    printf("end %s\n\n", __FUNCTION__);
}

void test_5()
{
    printf("start %s\n\n", __FUNCTION__);

    struct queue_t *queue = NULL;

    init_queue(&queue);
    destroy_queue(queue);

    printf("end %s\n\n", __FUNCTION__);
}

int main(void)
{
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();

    return 0;
}
