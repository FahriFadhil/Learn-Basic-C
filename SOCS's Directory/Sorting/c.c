#include <stdio.h>
#include <string.h>

typedef struct Student
{
    char id[11];
    char name[255];
} L;

void swap(L *a, L *b)
{
    L temp = *a;
    *a = *b;
    *b = temp;
}

int partition(L arr[], int low, int high)
{
    char *pivot = arr[high].id;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (strcmp(arr[j].id, pivot) < 0)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(L arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    FILE *fp = fopen("testdata.in", "r");
    if (fp == NULL)
    {
        perror("No File Found");
        return 0;
    }

    int n;
    fscanf(fp, "%d", &n);
    L studentList[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%s %[^\n]", studentList[i].id, studentList[i].name);
    }
    fclose(fp);

    quickSort(studentList, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%s %s\n", studentList[i].id, studentList[i].name);
    }

    return 0;
}