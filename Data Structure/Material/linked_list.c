#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Food
{
    char name[255];
    char type[255]; // Appetizer, Main, Dessert, Side
    int price;
    struct Food *next, *prev;
} F;

F *head = NULL, *tail = NULL;

F *createNode(char name[], char type[], int price)
{
    F *newFood = (F *)malloc(sizeof(F));
    if (!newFood)
        return NULL;

    strcpy(newFood->name, name);
    strcpy(newFood->type, type);
    newFood->price = price;
    newFood->next = newFood->prev = NULL;
    return newFood;
}

void insertHead(char name[], char type[], int price)
{
    F *newFood = createNode(name, type, price);
    if (!newFood)
        return;

    if (!head)
    {
        head = tail = newFood;
    }
    else
    {
        newFood->next = head;
        head->prev = newFood;
        head = newFood;
    }
}

void insertTail(char name[], char type[], int price)
{
    F *newFood = createNode(name, type, price);
    if (!newFood)
        return;

    if (!tail)
    {
        head = tail = newFood;
    }
    else
    {
        newFood->prev = tail;
        tail->next = newFood;
        tail = newFood;
    }
}

void popHead()
{
    if (!head)
        return;

    F *temp = head;
    head = head->next;
    if (head)
        head->prev = NULL;
    else
        tail = NULL;

    printf("[ %s ] Deleted.\n", temp->name);

    free(temp);
}

void popTail()
{
    if (!tail)
        return;

    F *temp = head;
    head = head->next;
    if (head)
        head->prev = NULL;
    else
        tail = NULL;

    free(temp);
}

void clearDatabase()
{
    while (head)
        popHead();
}

void printAll()
{
    F *curr = head;
    while (curr)
    {
        printf("[ %s -> %s -> Rp %d ]\n", curr->name, curr->type, curr->price);
        curr = curr->next;
    }
}

int main()
{
    insertTail("Pizza", "Main", 35000);
    insertTail("Mash Potato", "Appetizer", 17000);
    insertTail("Corn on a Cob", "Side", 14000);

    printAll();
    popHead();
    printAll();
    return 0;
}