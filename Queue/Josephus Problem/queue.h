#ifndef QUEUE_H
#define QUEUE_H

#define MAX 10

// List structure
typedef struct {
    int items[MAX];
    int count;
} List;

// Circular Queue structure
typedef struct {
    List list;
    int front;
    int rear;
} CircularQueue;

// Function declarations
void init(CircularQueue *q);
int isEmpty(CircularQueue *q);
int isFull(CircularQueue *q);

void enqueue(CircularQueue *q, int value);
int dequeue(CircularQueue *q);
void rotate(CircularQueue *q);

int josephus(int n, int k);

#endif