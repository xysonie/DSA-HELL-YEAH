#include <stdio.h>
#include <string.h>
#define MAX 10

// Stack structure
typedef struct {
    int items[MAX];
    int top;
} Stack;

// Function declarations
void init(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);

void removeDuplicates(char *str, Stack *s);
void displayStack(Stack *s);

int main() {
    char str[MAX];
    Stack s;

    printf("Enter a string: ");
    scanf(" %[^\n]", str);   // reads full line with spaces

    removeDuplicates(str, &s);
    displayStack(&s);

    return 0;
}

void init(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->items[(s->top)--];
}

void displayStack(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }

    printf("Result (stack): ");
    for (int i = 0; i <= s->top; i++) {
        printf("%c", s->items[i]);
    }
    printf("\n");
}

int peek(Stack *s) {
    
    if(isEmpty(s)){
        printf("Stack is empty.\n");
    } else {
        return s->items[s->top];
    }
    
}

void removeDuplicates(char *str, Stack *s) {
    
    init(s);
    
    for(int i = 0; str[i] != '\0'; i++){
        
            if((!isEmpty(s)) && peek(s) == str[i]){
                pop(s);
            }else{
                push(s, str[i]);
            }
        }
    }