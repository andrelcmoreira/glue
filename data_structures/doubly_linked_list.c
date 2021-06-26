#include <stdio.h>
#include <stdlib.h>

#define for_each_node(curr, list) \
    for (struct node_t *curr = list->head; curr; curr = curr->next)

#define for_each_node_safe(curr, queue) \
    for (struct node_t *curr = queue->head, *tmp = curr ? curr->next : NULL; \
         curr; \
         curr = tmp, tmp = tmp ? tmp->next : NULL)

#define for_each_node_reverse(curr, list) \
    for (struct node_t *curr = list->tail; curr; curr = curr->prev)

struct node_t {
    struct node_t *next;
    struct node_t *prev;
    char value;
};

struct list_t {
    struct node_t *tail;
    struct node_t *head;
};

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

int main(void)
{
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

        del_from_list(list, char6);
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
    }

    destroy_list(list);

    return 0;
}
