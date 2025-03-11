#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 1007

typedef struct Book
{
    int isbnNum;
    char title[100];
    char author[100];
    int pageCount;
    struct Book *next, *prev;
} B;

B *head[TABLE_SIZE], *tail[TABLE_SIZE];

B *createNode(char title[], char author[], int pageCount, int isbnNum)
{
    B *newBook = (B *)malloc(sizeof(B));
    if (!newBook)
        return NULL;

    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->pageCount = pageCount;
    newBook->isbnNum = isbnNum;
    newBook->next = newBook->prev = NULL;
    return newBook;
}

void push(char title[], char author[], int pageCount, int isbnNum)
{
    int key = isbnNum % TABLE_SIZE;
    B *newBook = createNode(title, author, pageCount, isbnNum);
    if (!head[key])
    {
        head[key] = tail[key] = newBook;
    }
    else
    {
        newBook->prev = tail[key];
        tail[key]->next = newBook;
        tail[key] = newBook;
    }
}

void viewBook()
{
    printf("\n");
    printf("Viewing Books\n");
    printf("=====================\n");
    int found = 0;
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        B *curr = head[i];
        while (curr)
        {
            printf("ISBN: %d | Title: %s | Author: %s | Pages: %d\n",
                   curr->isbnNum, curr->title, curr->author, curr->pageCount);
            curr = curr->next;
            found = 1;
        }
    }
    if (!found)
    {
        printf("No books available.\n");
    }
}

void insertBook()
{
    printf("\nInserting Book's Data\n");
    printf("=====================\n");
    char title[100], author[100];
    int pageCount, isbnNum;

    do
    {
        printf("Input Book's Title [5-50 Characters]: ");
        getchar();
        scanf("%[^\n]", title);
    } while (strlen(title) < 5 || strlen(title) > 50);

    do
    {
        printf("Input Book's Author [3-25 Characters] [Start with Mr. / Mrs.] : ");
        getchar();
        scanf("%[^\n]", author);
    } while (strlen(author) < 3 || strlen(author) > 25);

    do
    {
        printf("Input ISBN Number [10-13 Digit Numeric]: ");
        getchar();
        scanf("%d", &isbnNum);
    } while (isbnNum < 1000000000);

    do
    {
        printf("Input Page Number [>=16]: ");
        getchar();
        scanf("%d", &pageCount);
    } while (pageCount < 16);

    push(title, author, pageCount, isbnNum);
    printf("Inserting Book Success!\n");
}

void removeBook()
{
    printf("\nRemoving Book's Data\n");
    printf("====================\n");
    int isbnNum;
    printf("Input Book's ISBN to Delete: ");
    scanf("%d", &isbnNum);

    int key = isbnNum % TABLE_SIZE;
    B *curr = head[key], *prev = NULL;

    while (curr)
    {
        if (curr->isbnNum == isbnNum)
        {
            if (!prev)
            {
                head[key] = curr->next;
                if (head[key])
                    head[key]->prev = NULL;
            }
            else
            {
                prev->next = curr->next;
                if (curr->next)
                    curr->next->prev = prev;
            }
            free(curr);
            printf("Book deleted successfully!\n");
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Book not found!\n");
}

int menu()
{
    printf("\nBluejack Library\n");
    printf("=================\n");
    printf("1. View Book\n");
    printf("2. Insert Book\n");
    printf("3. Remove Book\n");
    printf("4. Exit\n");
    printf(">> ");
    int choice;
    scanf("%d", &choice);

    system("clear");
    return choice;
}

int main()
{
    // int BOOKIDGENERATION = 0;
    int EXITSTATUS = 0;
    while (!EXITSTATUS)
    {
        int decision = menu();
        switch (decision)
        {
        case 1:
            viewBook();
            break;
        case 2:
            insertBook(/*&BOOKIDGENERATION*/);
            break;
        case 3:
            removeBook();
            break;
        case 4:
            EXITSTATUS = 1;
            break;
        default:
            EXITSTATUS = 1;
            break;
        }
    }
    printf("Program Terminated.\n");

    return 0;
}
