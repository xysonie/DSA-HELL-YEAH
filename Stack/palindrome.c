#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 128

typedef struct node{
    char elem[MAX];
    int top;
}Stack;

void Push(Stack *S, char x);
void Pop(Stack *S);
char Peak(Stack S);
void initStack(Stack *S);

bool isFull(Stack S);
bool isEmpty(Stack S);
bool isPalindrome(char palindrome[]);

int main(){
    char palindrome[MAX];
    printf("Enter String: ");
    scanf("%s", palindrome);
    
    printf("Is it a palindrome? %s", (isPalindrome(palindrome)) ? "Yes!" : "No :<");
    
return 0;
    
}

void initStack(Stack *S){
    S->top = -1;
}

bool isFull(Stack S){
    return (S.top == MAX - 1) ? true : false;
}

bool isEmpty(Stack S){
    return (S.top == -1) ? true : false;
}

void Push(Stack *S, char x){
    if(!isFull(*S)){
        S->elem[++S->top] = x;
    }
}

void Pop(Stack *S){
    if(!isEmpty(*S)){
        S->top--;
    }
}

char Peak(Stack S){
    if(!isEmpty(S)){
        return S.elem[S.top];
    } else {
        return '\0';
    }
}

bool isPalindrome(char palindrome[]){
    
    Stack S;
    initStack(&S);
    int flag = 0;
    int i = 0;
    
    for(; palindrome[i] != '\0'; i++){
        Push(&S, palindrome[i]);
    }
    
    for(int j = 0; j < i; j++){
        if(Peak(S) == palindrome[j]){
            Pop(&S);
        } else {
            return false;
        }
    }
    return true;
    
}