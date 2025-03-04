#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node
{
    char str[100];
    struct Node *prev, *next;
} N;

N *head[10], *tail[10];

N *createNode(char str[])
{
    N *newNode = (N *)malloc(sizeof(N));
    strcpy(newNode->str, str);
    newNode->prev = newNode->next = NULL;
    return newNode;
    ;
}

int hashFunc(char str[])
{
    int sum = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        sum += str[i];
    }

    return sum % TABLE_SIZE;
}

void push(char str[])
{
    int key = hashFunc(str);
    N *newNode = createNode(str);
    if (!head[key])
    {
        head[key] = tail[key] = newNode;
    }
    else
    {
        newNode->prev = tail[key];
        tail[key]->next = newNode;
        tail[key] = newNode;
    }
}

int main()
{
    printf("%d\n", hashFunc("abcdef"));
}