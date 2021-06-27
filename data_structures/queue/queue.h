#ifndef QUEUE_H_
#define QUEUE_H_

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

int queue_size(struct queue_t *queue);
struct node_t *allocate_node(char value);
void enqueue(struct queue_t *queue, struct node_t *elem);
struct node_t *dequeue(struct queue_t *queue);
void init_queue(struct queue_t **queue);
void destroy_queue(struct queue_t *queue);

#endif  // QUEUE_H_
