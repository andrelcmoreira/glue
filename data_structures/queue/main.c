#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#define RUN_TEST(test_name) \
  printf("starting %s\n\n", #test_name); \
  run_##test_name(); \
  printf("finishing %s\n\n", #test_name);

#define TESTCASE(test_name) \
  void run_##test_name()

TESTCASE(test_1) {
  struct queue_t *queue;

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
}

TESTCASE(test_2) {
  struct queue_t *queue;

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

  struct node_t *to_del;
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
}

TESTCASE(test_3) {
  struct queue_t *queue;

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

  struct node_t *to_del;
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
}

TESTCASE(test_4) {
  struct queue_t *queue;

  init_queue(&queue);

  printf("size %d\n", queue_size(queue));
  for_each_node(curr, queue) {
    printf("curr->value %c\n", curr->value);
  }

  struct node_t *to_del;
  for (int i = 0; i < 10; i++) {
    to_del = dequeue(queue);
    if (to_del) {
      printf("to_del->value: %c\n", to_del->value);
      free(to_del);
    }

  }

  destroy_queue(queue);
}

TESTCASE(test_5) {
  struct queue_t *queue;

  init_queue(&queue);
  destroy_queue(queue);
}

int main(void) {
  RUN_TEST(test_1);
  RUN_TEST(test_2);
  RUN_TEST(test_3);
  RUN_TEST(test_4);
  RUN_TEST(test_5);

  return 0;
}
