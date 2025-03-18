#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Movie {
    char title[64];
    char genre[64];
    int duration;
    struct Movie *prev, *next;
} M;

M *headPlaylist = NULL, *tailPlaylist = NULL, *headWatchLater = NULL,  *tailWatchLater = NULL;

M *createNode(char *title, char *genre, int duration) {
    M *newNode = (M *)malloc(sizeof(M));
    strcpy(newNode->title, title);
    strcpy(newNode->genre, genre);
    newNode->duration = duration;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

void push(char *title, char *genre, int duration, int headOpt) {
    M *newMovie = createNode(title, genre, duration);
    M **head, **tail;
    if (headOpt == 1)
    {
        head = &headPlaylist;
        tail = &tailPlaylist;
    } else {
        head = &headWatchLater;
        tail = &tailWatchLater;
    }

    if (!(*head))
    {
        (*head) = (*tail) = newMovie;
        return;
    } 

    M *curr = (*head);
    while (curr)
    {
        if (strcmp(curr->title, newMovie->title) > 0) {
            break;
        }
        curr = curr->next;
    }
    if (!curr)
    {
        (*tail)->next = newMovie;
        newMovie->prev = (*tail);
        (*tail) = newMovie;
    } else if (curr == (*head))
    {
        (*head)->prev = newMovie;
        newMovie->next = (*head);
        (*head) = newMovie;
    } else {
        newMovie->prev = curr->prev;
        newMovie->next = curr;
        curr->prev->next = newMovie;
        curr->prev = newMovie;
    }
}

void pop(int headOpt) {
    M **head, **tail;
    if (headOpt == 1)
    {
        head = &headPlaylist;
        tail = &tailPlaylist;
    } else {
        head = &headWatchLater;
        tail = &tailWatchLater;
    }

    M *curr = (*head);
    if (!(*head)) return;
    if ((*head) == (*tail)) {  
        (*head) = (*tail) = NULL;
    } else {
        (*head) = (*head)->next;
        (*head)->prev = NULL;
    }
    free(curr);
}

void insertMain() {
    char title[64];
    char genre[64];
    int duration;
    scanf("%s %s %d", title, genre, &duration);
    push(title, genre, duration, 1);
}

void insertWatchLater() {
    char title[64];
    char genre[64];
    int duration;
    scanf("%s %s %d", title, genre, &duration);
    push(title, genre, duration, 2);
}

void play() {
    M *curr = headPlaylist;
    if (!curr) {
        printf("Playlist is empty!\n");
        return;
    }
    printf("WATCHED: %s %s %d\n", curr->title, curr->genre, curr->duration);
    pop(1);
}

void merge() {
    M *curr = headWatchLater;
    if (!curr)
    {
        printf("Watch Later List is Empty!\n");
        return;
    }
    while (curr) {
        M *nextMovie = curr->next;
        push(curr->title, curr->genre, curr->duration, 1);
        pop(2);
        curr = nextMovie;
    }
}

void displayMain() {
    M *curr = headPlaylist;
    if (!curr) {
        printf("Playlist is empty!\n");
        return;
    }
    while (curr)
    {
        printf("%s %s %d\n", curr->title, curr->genre, curr->duration);
        curr = curr->next;
    }
}

int main() {
    int SESSION = 1;
    while (SESSION)
    {
        char decision[16];
        scanf("%s", decision);
        if (strcmp(decision, "insert_main") == 0)
        {
            insertMain();
        }
        else if (strcmp(decision, "insert_watch_later") == 0)
        {
            insertWatchLater();
        }
        else if (strcmp(decision, "play") == 0)
        {
            play();
        }
        else if (strcmp(decision, "merge") == 0)
        {
            merge();
        }
        else if (strcmp(decision, "display_main") == 0)
        {
            displayMain();
        }
        else if (strcmp(decision, "stop") == 0)
        {
            SESSION = 0;
            printf("Terminating Session!\n");
        } else {
            printf("Invalid Input");
        }
    }
    
    return 0;
}