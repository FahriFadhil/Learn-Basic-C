#include <stdio.h>
#include <stdlib.h>

// int compare(const void *a, const void *b)
// {
//     return (*(int *)a - *(int *)b);
// }

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // qsort(arr, n, sizeof(int), compare);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int highestDifference = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] - arr[i] > highestDifference)
        {
            highestDifference = arr[i + 1] - arr[i];
        }
    }

    int notFirst = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] - arr[i] == highestDifference)
        {
            if (notFirst == 1)
            {
                printf(" ");
            }
            printf("%d %d", arr[i], arr[i + 1]);
            notFirst = 1;
        }
    }
    printf("\n");

    return 0;
}