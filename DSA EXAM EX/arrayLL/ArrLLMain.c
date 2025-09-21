//Stack_LinkedList(initialization w/ parameter --void init)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void initialize(Stack *s);
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void push(Stack *s, int elem);
void pushUnique(Stack *s, int elem);
int pop(Stack *s);
void popUnique(Stack *s, int elem);
int peek(Stack *s);
void display(Stack *s);

int main() {
    Stack *S;
    initialize(S);
    
    printf("Push:\n");
    push(S, 10);
    push(S, 20);
    push(S, 30);
    display(S);
    
    printf("\nPop:\n");
    pop(S);
    display(S);
    
    printf("\nPush Unique:\n");
    pushUnique(S, 20);
    pushUnique(S, 40);
    display(S);
    
    printf("\nPop Unique:\n");
    popUnique(S, 80);
    popUnique(S, 10);
    display(S);
    
    
    return 0;
}

void initialize(Stack *s) {
    s->top = NULL;
}
bool isFull(Stack *s) {
    return false; //bec. linked list is never full
}
bool isEmpty(Stack *s) {
    return s->top == NULL;
}
void push(Stack *s, int elem) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = elem; //gets the element u wanna push
    newNode->next = s->top; 
    s->top = newNode;
}

void pushUnique(Stack *s, int elem) {
    Node *p;
    for (p = s->top; p && p->data != elem; p = p->next){}
    if (p == NULL) {
        push(s, elem);
    }
}
int pop(Stack *s) {
    if (!isEmpty(s)) {
        Node *temp = s->top;
        int val = temp->data;
        s->top = temp->next;
        return val;
    } return -1;
}
void popUnique(Stack *s, int elem) {
    Node **pp, *del;
    for(pp = &s->top; *pp && (*pp)->data != elem; pp = &(*pp)->next){}
    if (*pp) {
        del = *pp;
        *pp = del->next;
        free(del);
    }
}
int peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->top->data;
    } return -1;
}
void display(Stack *s) {
    if (!isEmpty(s)) {
        Node *temp;
        for (temp = s->top; temp; temp = temp->next) {
            printf("%d\n", temp->data);
        }
    }
}