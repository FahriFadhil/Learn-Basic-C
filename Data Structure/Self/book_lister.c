#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    char code[16];
    char name[64];
    char genre[16];
    struct Book *prev, *next;
} B;

B *head = NULL, *tail = NULL;

int generateID() {
    static int id = 0;
    return ++id;
}

B *createNode(char *name, char *genre) {
    B *newNode = (B *)malloc(sizeof(B));
    strcpy(newNode->name, name);
    strcpy(newNode->genre, genre);
    sprintf(newNode->code, "B%.3d", generateID());
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void pushTail(char *name, char *genre) {
    B *newBook = createNode(name, genre);
    if (!head) {
        head = tail = newBook;
    } else {
        tail->next = newBook;
        newBook->prev = tail;
        tail = newBook;
    }
}

void popBook(char *code) {
    B *curr = head;
    while (curr)
    {
        if (strcmp(curr->code, code) == 0)
        {
            break;
        }
        curr = curr->next;
    }
    if (!curr) {
        printf("No Data Found!\n");
        return;
    }
    if (curr == head && curr == tail) {
        head = tail = NULL;
    } else if (curr == head)
    {
        head = curr->next;
        head->prev = NULL;
    } else if (curr == tail)
    {
        tail = curr->prev;
        tail->next = NULL;
    } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    
    free(curr);
}

void viewList() {
    B *curr = head;
    if (!curr) {
        printf("No Data Found!\n");
        return;
    }

    while (curr)
    {
        printf("%s | %s | %s\n", curr->code, curr->name, curr->genre);
        curr = curr->next;
    }
}

void addList() {
    int inputAmount;
    do
    {
        printf("Insert book amount: ");
        scanf("%d", &inputAmount);
    } while (inputAmount < 1);
    
    for (int i = 0; i < inputAmount; i++)
    {
        char name[64];
        char genre[16];
        do
        {
            printf("Insert Book Name No.%d [3 Char Min.]: ", i+1);
            getchar();
            scanf("%[^\n]", name);
        } while (strlen(name) < 3);
        do
        {
            printf("Insert Book Genre No.%d [3 Char Min.]: ", i+1);
            getchar();
            scanf("%[^\n]", genre);
        } while (strlen(genre) < 3);
        pushTail(name, genre);
    }
}

void popList() {
    char code[16];
    do
    {
        printf("Insert Book Code (See book code at \"View Book List\"): ");
        getchar();
        scanf("%[^\n]", code);
    } while (strlen(code) < 4);
    popBook(code);
}

int menu() {
    printf("\nBook Lister\n");
    printf("===========\n");
    printf("1. View Book List\n");
    printf("2. Add Book\n");
    printf("3. Remove Book\n");
    printf("4. Exit Program\n");
    int decision;
    do
    {
        printf(">> ");
        scanf("%d", &decision);
    } while (decision < 0 && decision > 4);
    system("clear");
    return decision;
}

int main() {
    int SESSION = 1;
    while (SESSION)
    {
        int decision = menu();
        switch (decision)
        {
        case 1:
            viewList();
            break;
        case 2:
            addList();
            break;
        case 3:
            popList();
            break;
        case 4:
            SESSION = 0;
            break;
        default:
            break;
        }
    }
    return 0;
}