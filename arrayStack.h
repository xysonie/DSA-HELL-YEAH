#include <stdio.h>
#include <stdbool.h>
#include "types.h"


void initialize(Stack *s){
    
    s->top = -1; // initialize stack to empty using sentinel value
}
bool isFull(Stack *s){
    
    return s->top == MAX - 1; 
}


bool isEmpty(Stack *s){
    
    return s->top < 0; // or s->top == -1;
}

void push(Stack *s, int value){
    
    if(!isFull(s)){
        s->items[++s->top] = value;
        
    }
    
}
int pop(Stack *s){
    
    if(!isFull(s)){
        int val = s->items[s->top--];
    }
}



int peek(Stack *s){
    if(!isFull(s)){
        return s->items[s->top];
    }
}


int top(Stack *s){
    return s->top;
}

void display(Stack* s){
    
    if(isEmpty(s)){
        printf("Stack is empty!\n");
    }
    
    int i;
    for(i = s->top; i >= 0; i--){
        printf("%d\n", s->items[i]);
    }
    
}