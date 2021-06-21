#ifndef THREAD_POOL_H_
#define THREAD_POOL_H_

#include <stdint.h>

#include "queue.h"

/*
 * \brief Handle to the pool.
 */
typedef struct thread_pool_t *thread_pool_t;

/**
 * \brief Enqueue a new task into the pool.
 *
 * \param pool Handle to the thread pool.
 * \param t The task to be enqueued.
 */
void enqueue_task(thread_pool_t pool, task_node_t *t);

/**
 * \brief Create a new thread pool.
 *
 * \param pool_size Size of the pool.
 * \return The pool handle.
 */
thread_pool_t create_pool(uint8_t pool_size);

/**
 * \brief Destroy the pool.
 *
 * \param pool Pointer to the pool handle.
 */
void destroy_pool(thread_pool_t *pool);

#endif  // THREAD_POOL_H_
