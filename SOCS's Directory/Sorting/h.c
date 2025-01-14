#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char *arr, int low, int high)
{
    char pivot = arr[high];
    int i = i - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] > pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(char *arr, int low, int high)
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
    int r, c;
    scanf("%d %d", &r, &c);
    char arr[r][c];

    for (int i = 0; i < r; i++)
    {
        char str[r];
        scanf("%s", str);
        for (int j = 0; j < c; j++)
        {
            arr[i][j] = str[j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%c", arr[i][j]);
        }
    }
    quickSort(&arr, 0, r - 1);

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%c", arr[i][j]);
        }
    }

    return 0;
}