#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cbtypes.h"
#include "functions.h"

typedef char String[255];

int main() {
    VHeap base;
    int list = -1; // start with empty list
    int choice;
    int nextId = 1;

    initVHeap(&base);

    do {
        printf("\n--- Knowledge Base Menu ---\n");
        printf("1. Insert new article\n");
        printf("2. View list of articles\n");
        printf("3. Search for an article\n");
        printf("4. Delete an article\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Article a;
                a.id = nextId++;

                printf("Enter article title: ");
                scanf(" %[^\n]", a.title);

                printf("Enter article content: ");
                scanf(" %[^\n]", a.content);

                int pos;
                printf("Enter position to insert (-1 for end, 0 for beginning): ");
                scanf("%d", &pos);

                insertArticle(&base, &list, a, pos);
                break;
            }
            case 2:
                viewArticles(base, list);
                break;

            case 3: {
                int id;
                printf("Enter article ID to search: ");
                scanf("%d", &id);
                searchArticle(base, list, id);
                break;
            }
            case 4: {
                int id;
                printf("Enter article ID to delete: ");
                scanf("%d", &id);
                deleteArticle(&base, &list, id);
                break;
            }
            case 5:
                printf("Exiting system...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
