#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int *arr, int low, int high)
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
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        quickSort(arr, 0, n - 1);

        int q;
        scanf("%d", &q);
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (q == arr[i])
            {
                found = 1;
                if (i == n - 1)
                {
                    printf("CASE #%d: %d %d\n", tc, arr[i - 1], arr[i]);
                }
                else
                {
                    printf("CASE #%d: %d %d\n", tc, arr[i], arr[i + 1]);
                }
            }
        }

        if (!found)
        {
            printf("CASE #%d: %d %d\n", tc, -1, -1);
        }
    }

    return 0;
}