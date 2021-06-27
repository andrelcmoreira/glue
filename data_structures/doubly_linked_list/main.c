#include <stdio.h>
#include <stdlib.h>

#include "doubly_linked_list.h"

void test_1()
{
    printf("start %s\n\n", __FUNCTION__);

    struct list_t *list = NULL;

    init_list(&list);

    struct node_t *char1 = allocate_node('a');
    struct node_t *char2 = allocate_node('b');
    struct node_t *char3 = allocate_node('c');
    struct node_t *char4 = allocate_node('d');
    struct node_t *char5 = allocate_node('e');
    struct node_t *char6 = allocate_node('f');

    add_to_list(list, char1);
    add_to_list(list, char2);
    add_to_list(list, char3);
    add_to_list(list, char4);
    add_to_list(list, char5);
    add_to_list(list, char6);

    printf("size %d\n", list_size(list));

    printf("normal\n");
    for_each_node(curr, list) {
        printf("curr->value %c\n", curr->value);
    }

    printf("reverse\n");
    for_each_node_reverse(curr, list) {
        printf("curr->value %c\n", curr->value);
    }

    destroy_list(list);

    printf("end %s\n\n", __FUNCTION__);
}

void test_2()
{
    printf("start %s\n\n", __FUNCTION__);

    struct list_t *list = NULL;

    init_list(&list);
    destroy_list(list);

    printf("end %s\n\n", __FUNCTION__);
}

void test_3()
{
    printf("start %s\n\n", __FUNCTION__);

    struct list_t *list = NULL;

    init_list(&list);

    struct node_t *char1 = allocate_node('a');
    struct node_t *char2 = allocate_node('b');
    struct node_t *char3 = allocate_node('c');
    struct node_t *char4 = allocate_node('d');
    struct node_t *char5 = allocate_node('e');
    struct node_t *char6 = allocate_node('f');

    add_to_list(list, char1);
    add_to_list(list, char2);
    add_to_list(list, char3);
    add_to_list(list, char4);
    add_to_list(list, char5);
    add_to_list(list, char6);

    printf("size %d\n", list_size(list));

    printf("normal\n");
    for_each_node(curr, list) {
        printf("curr->value %c\n", curr->value);
    }

    printf("reverse\n");
    for_each_node_reverse(curr, list) {
        printf("curr->value %c\n", curr->value);
    }

    del_from_list(list, char1);
    del_from_list(list, char2);
    del_from_list(list, char3);
    del_from_list(list, char4);
    del_from_list(list, char5);
    del_from_list(list, char6);

    printf("size %d\n", list_size(list));

    printf("normal\n");
    for_each_node(curr, list) {
        printf("curr->value %c\n", curr->value);
    }

    printf("size %d\n", list_size(list));
    printf("reverse\n");
    for_each_node_reverse(curr, list) {
        printf("curr->value %c\n", curr->value);
    }

    destroy_list(list);

    printf("end %s\n\n", __FUNCTION__);
}

void test_4()
{
    printf("start %s\n\n", __FUNCTION__);

    struct list_t *list = NULL;

    init_list(&list);

    {
        struct node_t *char1 = allocate_node('a');
        struct node_t *char2 = allocate_node('b');
        struct node_t *char3 = allocate_node('c');
        struct node_t *char4 = allocate_node('d');
        struct node_t *char5 = allocate_node('e');
        struct node_t *char6 = allocate_node('f');

        add_to_list(list, char1);
        add_to_list(list, char2);
        add_to_list(list, char3);
        add_to_list(list, char4);
        add_to_list(list, char5);

        printf("size %d\n", list_size(list));

        printf("normal\n");
        for_each_node(curr, list) {
            printf("curr->value %c\n", curr->value);
        }

        printf("reverse\n");
        for_each_node_reverse(curr, list) {
            printf("curr->value %c\n", curr->value);
        }

        del_from_list(list, char5);
        del_from_list(list, char3);
        del_from_list(list, char1);

        printf("size %d\n", list_size(list));

        printf("normal\n");
        for_each_node(curr, list) {
            printf("curr->value %c\n", curr->value);
        }

        printf("reverse\n");
        for_each_node_reverse(curr, list) {
            printf("curr->value %c\n", curr->value);
        }

        add_to_list(list, char6);

        printf("size %d\n", list_size(list));

        printf("normal\n");
        for_each_node(curr, list) {
            printf("curr->value %c\n", curr->value);
        }

        printf("reverse\n");
        for_each_node_reverse(curr, list) {
            printf("curr->value %c\n", curr->value);
        }
    }

    destroy_list(list);

    printf("end %s\n\n", __FUNCTION__);
}

int main(void)
{
    test_1();
    test_2();
    //test_3();
    test_4();

    return 0;
}
