#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void enqueue(Queue *q, Customer c) {
 if(isFull(q)){
     printf("Queue is full! Cannot add customer.\n");
     return;
 }
 
 q->rear = (q->rear + 1) % MAX;
 q->data[q->rear] = c;
 q->count++;
 
 printf("%s added to queue\n", c.name);
    
}

Customer dequeue(Queue *q) {
    
    Customer c;
    
    if(isEmpty(q)){
        printf("Queue is empty.\n");
    }
    
    c = q->data[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    
    return c;
    
}

void serveCustomer(Queue *q, int *tickets) {
  if(isEmpty(q)){
      printf("No customers to serve.\n");
      return;
  }
  
  Customer c = dequeue(q);
  
  printf("Serving %s...\n", c.name);
  
  if(*tickets == 0){
      printf("No tickets left for %s", c.name);
  } else if (*tickets >= c.ticketsRequested){
      *tickets -= c.ticketsRequested;
      printf("Booked %d tickets for %s", c.ticketsRequested, c.name);
  } else{
      printf("Only %d tickets left. Partial booking for %s", *tickets, c.name);
    *tickets = 0;
      
  }

printf("\nRemaining tickets: %d\n\n", *tickets);        
}
