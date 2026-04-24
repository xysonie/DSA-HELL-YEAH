
#include <stdio.h>
#include <string.h>
#define MAX_SONGS 10

typedef struct {
    char song_name[50];
    char artist[50];
    int next;
} SongNode;

typedef struct {
    SongNode nodes[MAX_SONGS];
    int avail;
} VHeap;

typedef int List;

void initVHeap(VHeap *vh);
int allocSpace(VHeap *vh);
void freeSpace(VHeap *vh, int index);

void insertEnd(List *L, VHeap *vh, char song[], char artist[]);
void deleteSong(List *L, VHeap *vh, char song[]);
void displayList(List L, VHeap vh);

int main() {
    VHeap vh;
    List playlist = -1;
    int choice;
    char song[50], artist[50];

    initVHeap(&vh);

    do {
        printf("==== MUSIC PLAYLIST MENU ====\n");
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Display Playlist\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter song name: ");
                fgets(song, sizeof(song), stdin);
                song[strcspn(song, "\n")] = 0;

                printf("Enter artist: ");
                fgets(artist, sizeof(artist), stdin);
                artist[strcspn(artist, "\n")] = 0;

                insertEnd(&playlist, &vh, song, artist);
                break;

            case 2:
                printf("Enter song name to delete: ");
                fgets(song, sizeof(song), stdin);
                song[strcspn(song, "\n")] = 0;

                deleteSong(&playlist, &vh, song);
                break;

            case 3:
                displayList(playlist, vh);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}

void initVHeap(VHeap *vh) {
    for (int i = 0; i < MAX_SONGS - 1; i++) {
        vh->nodes[i].next = i + 1;
    }
    vh->nodes[MAX_SONGS - 1].next = -1;
    vh->avail = 0;
}

int allocSpace(VHeap *vh) {
    int index = vh->avail;
    if (index != -1) {
        vh->avail = vh->nodes[index].next;
    }
    return index;
}

void freeSpace(VHeap *vh, int index) {
    vh->nodes[index].next = vh->avail;
    vh->avail = index;
}

void displayList(List L, VHeap vh) {
    if (L == -1) {
        printf("Playlist is empty.\n");
        return;
    }

    printf("\n--- Playlist ---\n");
    int temp = L;
    while (temp != -1) {
        printf("%s by %s\n",
               vh.nodes[temp].song_name,
               vh.nodes[temp].artist);
        temp = vh.nodes[temp].next;
    }
}

void insertEnd(List *L, VHeap *vh, char song[], char artist[]) {
  int newNode = allocSpace(vh);

    if (newNode == -1) {
        printf("Playlist is full.\n");
        return;
    }

    strcpy(vh->nodes[newNode].song_name, song);
    strcpy(vh->nodes[newNode].artist, artist);
    vh->nodes[newNode].next = -1;

    if (*L == -1) {
        *L = newNode;  // first element
    } else {
        int trav = *L;
        while (vh->nodes[trav].next != -1) {
            trav = vh->nodes[trav].next;
        }
        vh->nodes[trav].next = newNode;
    }

    printf("Song added successfully.\n");
}

void deleteSong(List *L, VHeap *vh, char song[]) {
int *trav = L;

    while (*trav != -1) {
        if (strcmp(vh->nodes[*trav].song_name, song) == 0) {
            int temp = *trav;
            *trav = vh->nodes[temp].next;
            freeSpace(vh, temp);

            printf("Song deleted successfully.\n");
            return;
        } else {
            trav = &vh->nodes[*trav].next;
        }
    }

    printf("Song not found.\n");
}

