#include "NullPointerCheck.h"

typedef struct QueueNode {
    void* data;
    struct QueueNode* prev;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue {
    QueueNode* head;
    QueueNode* tail;
} Queue;

void enqueue(Queue* s, void* data) {
    NullPointerCheck(s, __func__);

    QueueNode* pushed = (QueueNode*)malloc(sizeof(QueueNode));

    NullPointerCheck(pushed, __func__);

    pushed->data = data;

    //Case - Empty
    if (s->head == NULL && s->tail == NULL) {
        pushed->next = NULL;
        pushed->prev = NULL;
        s->head = pushed;
        s->tail = pushed;
    }

    //Case - Not empty
    else {
        pushed->next = s->head;
        s->head->prev = pushed;
        pushed->prev = NULL;
        s->head = pushed;
    }
}

void* dequeue(Queue* s) {
    NullPointerCheck(s, __func__);

    //Case - Empty
    if (s->head == NULL && s->tail == NULL) return NULL;

    void* data = s->tail->data;

    //Case - single element
    if (s->tail == s->head) {
        free(s->head);
        s->head = NULL;
        s->tail = NULL;
    }


    //Case - multiple elements
    else {
        s->tail = s->tail->prev;
        s->tail->next->prev = NULL;
        free(s->tail->next);
        s->tail->next = NULL;
    }

    return data;
}

Queue* queue_init() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));

    NullPointerCheck(queue, __func__);
    queue->head = NULL;
    queue->tail = NULL;

    return queue;

}

void freeQueue(Queue** queue) {
    NullPointerCheck(queue, __func__);
    NullPointerCheck(*queue, __func__);

    while ((*queue)->head != NULL) {
        dequeue(*queue);
    }

    free(*queue);
    *queue = NULL;
}

