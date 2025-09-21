#include <stdio.h>
#include <stdlib.h>
#include "ptypes.h"
#include "arrayQueue.h"

typedef char String[50];

int main() {
    Queue* priorityQ = initialize();
    Queue* regularQ = initialize();

    int nextCustomerID = 1; // sequential unique IDs
    int choice;

    String menu[4] = {
        "Add new customer",
        "Call next customer",
        "Display queues",
        "Exit"
    };

    do { 
        printf("\n--- Pharmacy Queueing System ---\n");
        for (int i = 0; i < 4; i++) {
            printf("%d. %s\n", i + 1, menu[i]);
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: { // Add new customer
                int type;
                printf("Enter 1 for Regular, 2 for Priority: ");
                scanf("%d", &type);

                if (type == 1) {
                    enqueue(regularQ, nextCustomerID);
                    printf("Customer %d added to REGULAR queue.\n", nextCustomerID);
                } else if (type == 2) {
                    enqueue(priorityQ, nextCustomerID);
                    printf("Customer %d added to PRIORITY queue.\n", nextCustomerID);
                } else {
                    printf("Invalid option.\n");
                }
                nextCustomerID++;
                break;
            }

            case 2: { // Call next customer
                int called = -1;
                if (!isEmpty(priorityQ)) {
                    called = dequeue(priorityQ);
                    printf("Calling PRIORITY customer %d.\n", called);
                } else if (!isEmpty(regularQ)) {
                    called = dequeue(regularQ);
                    printf("Calling REGULAR customer %d.\n", called);
                } else {
                    printf("No customers in queue.\n");
                }
                break;
            }

            case 3: // Display queues
                printf("\n===Priority Queue===\n");
                display(priorityQ);
                printf("===Regular Queue===\n");
                display(regularQ);
                break;

            case 4: 
                printf("Exiting system...\n");
                break;

            default:
                printf("Invalid choice, try again.\n");
        }

    } while (choice != 4);

    // Free memory
    free(priorityQ);
    free(regularQ);

    return 0;
}
