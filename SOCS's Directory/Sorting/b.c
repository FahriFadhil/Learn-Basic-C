#include <stdio.h>
#include <string.h>

typedef struct Plant
{
    int num;
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
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (strcmp(arr[j].name, arr[high].name) < 0)
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
        perror("Error opening file");
        return 0;
    }

    int n;
    fscanf(fp, "%d", &n);
    L plantList[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d#%[^\n]\n", &plantList[i].num, plantList[i].name);
    }
    fclose(fp);

    quickSort(plantList, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d %s\n", plantList[i].num, plantList[i].name);
    }

    return 0;
}