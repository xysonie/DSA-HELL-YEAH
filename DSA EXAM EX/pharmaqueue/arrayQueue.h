#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ptypes.h"

// Initialize queue
Queue* initialize() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->list.count = 0;
    return q;
}

// Check if full
bool isFull(Queue* q) {
    return q->list.count == MAX;
}

// Check if empty
bool isEmpty(Queue* q) {
    return q->list.count == 0;
}

// Enqueue
void enqueue(Queue* q, int value) {
    if (!isFull(q)) {
        q->rear = (q->rear + 1) % MAX;
        q->list.items[q->rear] = value;
        q->list.count++;
    } else {
        printf("Queue is full! Cannot enqueue %d.\n", value);
    }
}

// Dequeue
int dequeue(Queue* q) {
    if (!isEmpty(q)) {
        int val = q->list.items[q->front];
        q->front = (q->front + 1) % MAX;
        q->list.count--;
        return val;
    } else {
        printf("Queue is empty!\n");
        return -1;
    }
}

// Display queue contents
void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: \n");
    int idx = q->front;
    for (int i = 0; i < q->list.count; i++) {
        printf("[Customer %d]\n", q->list.items[idx]);
        idx = (idx + 1) % MAX;
    }
    printf("\n");
}
