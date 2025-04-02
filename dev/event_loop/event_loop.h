#ifndef __EVENT_LOOP_H__
#define __EVENT_LOOP_H__

#include <pthread.h>

// Function pointer to event callback
typedef void (*event_cbk)(void *);

// typedef enum TASK_PRIORITY_ {

//     TASK_PRIORITY_HIGH,
//     TASK_PRIORITY_MEDIUM,
//     TASK_PRIORITY_LOW,
//     TASK_PRIORITY_MAX

// } TASK_PRIORITY_T;

// Defines the state of the event loop
typedef enum EVENT_LOOP_STATE_ {
    EVENT_LOOP_IDLE,
    EVENT_LOOP_BUSY
} EVENT_LOOP_STATE_T;

// Defines the current task, it's call back/arguments, and priority.
// It's implemented as a doubly-linked list so we add left/right ptrs.
struct task {
    event_cbk cbk;
    void *arg;
    struct task *left, *right;
    // TASK_PRIORITY_T priority;
};

struct event_loop {
    // Head to the start of the task array
    struct task *head;
    // Mutex used because we have two threads queue and dequeueing from task array
    pthread_mutex_t ev_mutex;
    // Event state
    EVENT_LOOP_STATE_T ev_state;
    // Event condition
    pthread_cond_t ev_cond;
    // Event loop thread
    pthread_t *thread;
    // Current task which event loop through is executing
    // NULL if event loop is resting
    struct task current_task;
};

#endif