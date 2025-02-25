#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Patient
{
    char name[26];
    int age;
    char symptomps[256];
    int code;
    struct Patient *next, *prev;
} P;

P *head = NULL, *tail = NULL;

P *createNode(char name[], int age, char symptomps[], int code)
{
    P *newPatient = (P *)malloc(sizeof(P));
    if (!newPatient)
        return NULL;

    strcpy(newPatient->name, name);
    strcpy(newPatient->symptomps, symptomps);
    newPatient->age = age;
    newPatient->code = code;
    newPatient->next = newPatient->prev = NULL;
    return newPatient;
}

void push(char name[], int age, char symptomps[], char code[])
{
    int codeNum;
    if (strcmp(code, "Red") == 0)
        codeNum = 3;
    else if (strcmp(code, "Yellow") == 0)
        codeNum = 2;
    else if (strcmp(code, "Green") == 0)
        codeNum = 1;
    else
        return;

    P *newPatient = createNode(name, age, symptomps, codeNum);
    if (!newPatient)
        return;

    if (!head)
    {
        head = tail = newPatient;
        return;
    }

    P *curr = head;
    while (curr && curr->code >= newPatient->code)
    {
        curr = curr->next;
    }

    if (!curr)
    {
        newPatient->prev = tail;
        tail->next = newPatient;
        tail = newPatient;
    }
    else if (curr == head)
    {
        newPatient->next = head;
        head->prev = newPatient;
        head = newPatient;
    }
    else
    {
        newPatient->prev = curr->prev;
        newPatient->next = curr;
        curr->prev->next = newPatient;
        curr->prev = newPatient;
    }
}

void popHead()
{
    if (!head)
        return;

    P *temp = head;
    head = head->next;
    if (head)
        head->prev = NULL;
    else
        tail = NULL;

    free(temp);
}

int menu()
{
    printf("\n");
    printf("Bluejack Hospital\n");
    printf("=================\n");
    printf("1. Insert\n");
    printf("2. View\n");
    printf("3. Next Queue\n");
    printf("4. Exit\n");
    printf(">> ");
    int choice;
    scanf("%d", &choice);
    system("clear");
    return choice;
}

void insert()
{
    printf("\n");
    printf("Inserting Patient's Data\n");
    printf("========================\n");
    char name[26], symptomps[256], code[16];
    int age;
    do
    {
        printf("Input Patient Name [4-25 Characters]: ");
        getchar();
        scanf("%[^\n]", name);
    } while (strlen(name) < 4 || strlen(name) > 25);

    do
    {
        printf("Input Patient Age: ");
        scanf("%d", &age);
    } while (age < 0);

    do
    {
        printf("Input Patient Symptoms [6 Characters Min.]: ");
        getchar();
        scanf("%[^\n]", symptomps);
    } while (strlen(symptomps) < 6);

    do
    {
        printf("Input Patient Code [Red, Yellow, Green]: ");
        getchar();
        scanf("%[^\n]", code);
    } while (!(strcmp(code, "Red") == 0 || strcmp(code, "Yellow") == 0 || strcmp(code, "Green") == 0));

    push(name, age, symptomps, code);
    printf("Insert Success!\n");
    printf("\n");
}

void view()
{
    printf("\n");
    printf("Patient List:\n");
    printf("=============\n");
    P *curr = head;
    if (!curr)
    {
        printf("No Patient Yet!, Use \"Insert\" to input Patient's Data\n");
        return;
    }
    printf("%-4s %-8s %-25s %-4s %s\n", "No.", "Code", "Name", "Age", "Symptopms");
    int i = 1;
    while (curr)
    {
        char codeStr[16];
        if (curr->code == 3)
            strcpy(codeStr, "Red");
        if (curr->code == 2)
            strcpy(codeStr, "Yellow");
        if (curr->code == 1)
            strcpy(codeStr, "Green");

        printf("%-4d %-8s %-25s %-4d %s\n", i, codeStr, curr->name, curr->age, curr->symptomps);
        curr = curr->next;
        i++;
    }
    printf("\n");
}

void nextQueue()
{
    printf("\n");
    printf("The Next Patient is: \n");
    printf("==================== \n");

    P *curr = head;
    if (!curr)
    {
        printf("No Patient Yet!, Use \"Insert\" to input Patient's Data\n");
        return;
    }
    char codeStr[16];
    if (curr->code == 3)
        strcpy(codeStr, "Red");
    if (curr->code == 2)
        strcpy(codeStr, "Yellow");
    if (curr->code == 1)
        strcpy(codeStr, "Green");

    printf("Name      : %s\n", curr->name);
    printf("Age       : %d\n", curr->age);
    printf("Symptopms : %s\n", curr->symptomps);
    printf("Code      : %s\n", codeStr);
    printf("\n");

    popHead();
}

int main()
{
    int EXITSTATUS = 0;
    while (EXITSTATUS == 0)
    {
        int decision = menu();
        switch (decision)
        {
        case 1:
            insert();
            break;
        case 2:
            view();
            break;
        case 3:
            nextQueue();
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