#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "arrayStack.h"

typedef char String[50];

int main() {
    Stack *S = (Stack *)malloc(sizeof(Stack) * 3);
    for (int i = 0; i < 3; i++) {
        initialize(&S[i]);
    }
    
    String menu[5] = {"Push a container", "Pop a container", "Check if a container exists",
                        "Display all stacks", "Exit"};
    
    int choice, value, popped;
    
    do {
        printf("\n--- Warehouse Inventory Management System ---\n");
        for (int i = 0; i < 5; i++) {
            printf("%d. %s\n", i + 1, menu[i]);
        }
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: // Push
                printf("Enter container ID to push: ");
                scanf("%d", &value);
                {
                    int pushed = 0;
                    for (int i = 0; i < 3; i++) {
                        if (!isFull(&S[i])) {
                            push(&S[i], value);
                            printf("Container %d pushed successfully into Stack %d.\n\n", value, i+1);
                            pushed = 1;
                            break;
                        }
                    }
                    if (!pushed) {
                        printf("Error: All stacks are full. Cannot push container.\n\n");
                    }
                }
                break;
                
            case 2: // Pop
                {
                    int foundp = 0;
                    for (int i = 0; i < 3; i++) {
                        if (!isEmpty(&S[i])) {
                            popped = pop(&S[i]);
                            foundp = 1;
                            printf("Container %d popped successfully from Stack %d.\n\n", popped, i+1);
                            break;
                        }
                    }
                    
                    if (!foundp) {
                        printf("Error: All stacks are empty. Cannot pop container.\n\n");
                    }
                }
                break;
                
            case 3: // Search
                printf("Enter container ID to check: ");
                scanf("%d", &value);
                {
                    int exists = 0;
                    for (int i = 0; i < 3 && !exists; i++) {
                        for (int j = 0; j <= top(&S[i]); j++) {
                            if (S[i].items[j] == value) {
                                exists = 1;
                                break;
                            }
                        }
                    }
                    
                    if (exists) {
                        printf("Container %d exists in a stack.\n\n", value);
                    } else {
                        printf("Container %d does not exist in any stack.\n\n", value);
                    }
                }
                break;
                
            case 4: // Display
                for(int i = 0; i < 3; i++) {
                    printf("\n--- Stack %d ---\n", i + 1);
                    display(&S[i]);
                }
                printf("\n");
                break;
                
            case 5:
                printf("Exiting program.\n");
                break;
                
            default:
                printf("Invalid choice. Try again.\n\n");
        }
    } while (choice != 5);

    free(S);
    return 0;
}
