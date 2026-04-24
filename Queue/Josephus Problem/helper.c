#include <stdio.h>
#include "queue.h"

void init(CircularQueue *q) {
    q->front = -1;
    q->rear = -1;
    q->list.count = 0;
}

int isEmpty(CircularQueue *q) {
    return q->list.count == 0;
}

int isFull(CircularQueue *q) {
    return q->list.count == MAX;
}

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) return;

    if (isEmpty(q)) {
        q->front = 0;
    }

    q->rear = (q->rear + 1) % MAX;
    q->list.items[q->rear] = value;
    q->list.count++;
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) return -1;

    int value = q->list.items[q->front];

    if (q->list.count == 1) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }

    q->list.count--;

    return value;
}