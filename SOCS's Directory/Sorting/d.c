#include <stdio.h>
#include <string.h>

typedef struct Video
{
    char name[1001];
    char author[1001];
    long long int viewer;
} V;

int countLines(FILE *fp)
{
    int lines = 0;
    char ch;

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '\n')
            lines++;
    }

    rewind(fp);
    return lines;
}

void swap(V *a, V *b)
{
    V temp = *a;
    *a = *b;
    *b = temp;
}

int partition(V arr[], int low, int high)
{
    long long int pivot = arr[high].viewer;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j].viewer > pivot || (arr[j].viewer == pivot && strcmp(arr[j].name, arr[high].name) < 0))
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(V arr[], int low, int high)
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

    int n = countLines(fp);
    V videoList[n];

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, " %[^#]#%[^#]#%lld", videoList[i].name, videoList[i].author, &videoList[i].viewer);
    }

    quickSort(videoList, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%s by %s - %lld\n", videoList[i].name, videoList[i].author, videoList[i].viewer);
    }

    fclose(fp);
    return 0;
}