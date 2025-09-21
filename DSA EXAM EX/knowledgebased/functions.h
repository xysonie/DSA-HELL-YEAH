#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cbtypes.h"

void initVHeap(VHeap *V) {
    V->avail = 0;
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        V->H[i].next = i + 1;
    }
    V->H[MAX_SIZE - 1].next = -1;
}

int alloc(VHeap *V) {
    if (V->avail == -1) return -1;
    int idx = V->avail;
    V->avail = V->H[idx].next;
    return idx;
}

void dealloc(VHeap *V, int idx) {
    V->H[idx].next = V->avail;
    V->avail = idx;
}

/**
 * Insert article into the list
 * L = pointer to head index
 * pos = -1 → insert at end
 * pos = 0  → insert at beginning
 * pos > 0  → insert at that position
 */
int insertArticle(VHeap *V, int *L, Article art, int pos) {
    int newCell = alloc(V);
    if (newCell == -1) {
        printf("Error: Heap is full. Cannot insert new article.\n");
        return 0;
    }

    V->H[newCell].article = art;

    if (*L == -1) { // empty list
        V->H[newCell].next = -1;
        *L = newCell;
        return 1;
    }

    if (pos == 0) { // insert at beginning
        V->H[newCell].next = *L;
        *L = newCell;
    } else if (pos == -1) { // insert at end
        int trav = *L;
        while (V->H[trav].next != -1) {
            trav = V->H[trav].next;
        }
        V->H[trav].next = newCell;
        V->H[newCell].next = -1;
    } else { // insert at middle
        int curr = *L;
        for (int i = 0; i < pos - 1 && curr != -1; i++) {
            curr = V->H[curr].next;
        }
        if (curr == -1) { // invalid pos
            dealloc(V, newCell);
            printf("Invalid position.\n");
            return 0;
        }
        V->H[newCell].next = V->H[curr].next;
        V->H[curr].next = newCell;
    }
    return 1;
}

void viewArticles(VHeap V, int L) {
    if (L == -1) {
        printf("is emptyyy\n");
        return;
    }

    printf("\n--- List of Articles ---\n");
    int trav = L;
    while (trav != -1) {
        printf("ID: %d | Title: %s\n", V.H[trav].article.id, V.H[trav].article.title);
        trav = V.H[trav].next;
    }
    printf("------------------------\n\n");
}

void searchArticle(VHeap V, int L, int id) {
    if (L == -1) {
        printf("No articles available to search.\n");
        return;
    }

    int trav = L;
    while (trav != -1) {
        if (V.H[trav].article.id == id) {
            printf("\n--- Article Found ---\n");
            printf("ID: %d\n", V.H[trav].article.id);
            printf("Title: %s\n", V.H[trav].article.title);
            printf("Content: %s\n", V.H[trav].article.content);
            printf("---------------------\n\n");
            return;
        }
        trav = V.H[trav].next;
    }
    printf("Article with ID %d not found.\n\n", id);
}

int deleteArticle(VHeap *Base, int *L, int id) {
    int prev = -1, curr = *L;

    while (curr != -1 && Base->H[curr].article.id != id) {
        prev = curr;
        curr = Base->H[curr].next;
    }

    if (curr == -1) {
        printf("Article with ID %d not found.\n\n", id);
        return 0;
    }

    if (prev == -1) { // delete first
        *L = Base->H[curr].next;
    } else { // delete middle/last
        Base->H[prev].next = Base->H[curr].next;
    }

    printf("Article with ID %d deleted successfully.\n\n",
           Base->H[curr].article.id);

    dealloc(Base, curr);

    return 1;
}
