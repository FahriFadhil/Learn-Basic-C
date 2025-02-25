#include <stdio.h>
#include <string.h>

typedef struct Student
{
    char nim[11];
    char name[255];
    float gpa;
} S;

void inputs(S *arr, int i)
{
    scanf("%s", arr[i].nim);
    getchar();
    scanf("%[^\n]", arr[i].name);
    scanf("%f", &arr[i].gpa);
}

void prints(S *arr, int i)
{
    printf("%s ", arr[i].nim);
    printf("%.2f ", arr[i].gpa);
    printf("%s \n", arr[i].name);
}

int main()
{
    int a, b;

    scanf("%d", &a);
    S arrA[a];
    for (int i = 0; i < a; i++)
    {
        inputs(arrA, i);
    }

    scanf("%d", &b);
    S arrB[b];
    for (int i = 0; i < b; i++)
    {
        inputs(arrB, i);
    }

    S arrC[a + b];

    int j = 0;

    for (; j < a; j++)
    {
        // strcpy(arrC[j].nim, arrA[j].nim);
        // strcpy(arrC[j].name, arrA[j].name);
        // arrC[j].gpa = arrA[j].gpa;
        arrC[j] = arrA[j];
    }
    for (; j - a < b; j++)
    {
        // strcpy(arrC[j].nim, arrB[j - a].nim);
        // strcpy(arrC[j].name, arrB[j - a].name);
        // arrC[j].gpa = arrB[j - a].gpa;
        arrC[j] = arrB[j - a];
    }

    for (int i = 0; i < a + b; i++)
    {
        prints(arrC, i);
    }

    // int a, b;

    // scanf("%d", &a);
    // int arrA[a];
    // for (int i = 0; i < a; i++)
    // {
    //     scanf("%d", &arrA[i]);
    // }

    // scanf("%d", &b);
    // int arrB[b];
    // for (int i = 0; i < b; i++)
    // {
    //     scanf("%d", &arrB[i]);
    // }

    // int arrC[a + b];
    // int j = 0;

    // for (; j < a; j++)
    // {
    //     arrC[j] = arrA[j];
    // }
    // for (; j - a < b; j++)
    // {
    //     arrC[j] = arrB[j - a];
    // }

    // for (int i = 0; i < a + b; i++)
    // {
    //     printf("%d", arrC[i]);
    //     if (i < (a + b - 1))
    //     {
    //         printf(" -> ");
    //     }
    //     else
    //     {
    //         printf("\n");
    //     }
    // }

    return 0;
}