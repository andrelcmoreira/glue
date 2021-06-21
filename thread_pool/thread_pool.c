#include "thread_pool.h"

#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct thread_pool_t {
    uint8_t size;
    bool must_stop;
    sem_t semaphore;
    pthread_t *threads;
    task_queue_t *tasks;
};

static void *thread_routine(void *param)
{
    thread_pool_t pool = (thread_pool_t)param;

    while (!pool->must_stop) {
        sem_wait(&pool->semaphore);

        if (pool->must_stop) {
            break;
        }

        task_node_t *entry = dequeue(pool->tasks);
        if (entry) {
            entry->task(entry->param);
            free(entry);
        }
    }

    return NULL;
}

void enqueue_task(thread_pool_t pool, task_node_t *t)
{
    enqueue(pool->tasks, t);
    sem_post(&pool->semaphore);
}

thread_pool_t create_pool(uint8_t pool_size)
{
    thread_pool_t pool;

    pool = malloc(sizeof(*pool));
    if (!pool) {
        return NULL;
    }

    pool->size = pool_size;
    pool->must_stop = false;
    pool->threads = malloc(sizeof(pthread_t) * pool_size);

    if (!pool->threads) {
        return NULL;
    }

    init_queue(&pool->tasks);
    sem_init(&pool->semaphore, 0, 0);

    for (int i = 0; i < pool_size; i++) {
        pthread_create(
            &pool->threads[i],
            NULL,
            thread_routine,
            pool
        );
    }

    return pool;
}

void destroy_pool(thread_pool_t *pool)
{
    (*pool)->must_stop = true;
    for (int i = 0; i < (*pool)->size; i++) {
        sem_post(&(*pool)->semaphore);
    }

    for (int i = 0; i < (*pool)->size; i++) {
        pthread_join((*pool)->threads[i], NULL);
    }

    free((*pool)->threads);
    sem_destroy(&(*pool)->semaphore);
    destroy_queue((*pool)->tasks);

    free(*pool);
    *pool = NULL;
}
