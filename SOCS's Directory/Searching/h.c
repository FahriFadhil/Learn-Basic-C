#include <stdio.h>

void swap(long long int *a, long long int *b)
{
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(long long int *arr, int low, int high)
{
    long long int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[high], &arr[i + 1]);
    return i + 1;
}

void quickSort(long long int *arr, int low, int high)
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
    int n, count = 0;
    scanf("%d", &n);
    long long int arrX[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arrX[i]);
    }
    long long int y;
    scanf("%lld", &y);

    quickSort(arrX, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        if (arrX[i] <= y)
        {
            count++;
            y -= arrX[i];
        }
    }
    printf("%d\n", count);
    return 0;
}