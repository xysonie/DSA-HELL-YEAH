#include <stdio.h>
#include <stdbool.h>
#include "types.h"

void initialize(Stack *s){
    s->top = -1; 
}

bool isFull(Stack *s){
    return s->top == MAX - 1; 
}

bool isEmpty(Stack *s){
    return s->top < 0;
}

void push(Stack *s, int value){
    if(!isFull(s)){
        s->items[++s->top] = value;
    }
}

int pop(Stack *s){
    if(!isEmpty(s)){
        return s->items[s->top--];
    }
    return -1;
}

int peek(Stack *s){
    if(!isEmpty(s)){
        return s->items[s->top];
    }
    return -1;
}

int top(Stack *s){
    return s->top;
}

void display(Stack* s){
    if(isEmpty(s)){
        printf("Stack is empty!\n");
        return;
    }
    for(int i = s->top; i >= 0; i--){
        printf("%d\n", s->items[i]);
    }
}
