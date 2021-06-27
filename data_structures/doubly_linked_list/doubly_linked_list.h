#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_

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

int list_size(struct list_t *list);
struct node_t *allocate_node(char value);
void add_to_list(struct list_t *list, struct node_t *elem);
void del_from_list(struct list_t *list, struct node_t *node);
void init_list(struct list_t **list);
void destroy_list(struct list_t *list);

#endif  // DOUBLY_LINKED_LIST_H_
