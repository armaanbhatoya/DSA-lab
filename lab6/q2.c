// Music Playlist Manager

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char song[100];
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;
struct Node* current = NULL;

struct Node* createNode(char* song) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->song, song);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void addSong(char* song) {
    struct Node* newNode = createNode(song);
    if (head == NULL) {
        head = tail = newNode;
        current = head;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    printf("Song added: %s\n", song);
}


void playNext() {
    if (current == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    if (current->next != NULL) {
        current = current->next;
        printf("Playing next song: %s\n", current->song);
    } else {
        printf("You are at the last song. No next song.\n");
    }
}


void playPrev() {
    if (current == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    if (current->prev != NULL) {
        current = current->prev;
        printf("Playing previous song: %s\n", current->song);
    } else {
        printf("You are at the first song. No previous song.\n");
    }
}


void displayPlaylist() {
    if (head == NULL) {
        printf("Playlist is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("\n--- Playlist ---\n");
    while (temp != NULL) {
        if (temp == current)
            printf("-> %s (Currently Playing)\n", temp->song);
        else
            printf("   %s\n", temp->song);
        temp = temp->next;
    }
    printf("---\n");
}

int main() {
    int choice;
    char song[100];

    
    addSong("Song A");
    addSong("Song B");
    addSong("Song C");
    addSong("Song D");
    addSong("Song E");

    do {
        printf("\n Music Playlist Manager \n");
        printf("1. Play next song\n");
        printf("2. Play previous song\n");
        printf("3. Add a song at the end\n");
        printf("4. Display playlist\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); //consumes newline

        switch (choice) {
            case 1:
                playNext();
                break;
            case 2:
                playPrev();
                break;
            case 3:
                printf("Enter song name: ");
                fgets(song, sizeof(song), stdin);
                song[strcspn(song, "\n")] = '\0'; // remove newline
                addSong(song);
                break;
            case 4:
                displayPlaylist();
                break;
            case 5:
                printf("Exiting playlist manager...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
