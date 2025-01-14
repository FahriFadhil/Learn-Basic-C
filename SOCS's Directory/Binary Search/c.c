#include <stdio.h>

void swap(long long int *a, long long int *b)
{
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

long long int partition(long long int *arr, long long int low, long long int high)
{
    long long int pivot = arr[high];
    long long int i = low - 1;
    for (long long int j = low; j < high; j++)
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

void quickSort(long long int *arr, long long int low, long long int high)
{
    if (low < high)
    {
        long long int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

long long int numCounter(long long int *arr, long long int n, long long int x)
{
    long long int num = x;
    long long int count = 0;
    for (long long int i = 0; i < n; i++)
    {
        if (num >= arr[i])
        {
            count++;
            num -= arr[i];
        }
    }
    return count;
}

int main()
{
    long long int n;
    scanf("%lld", &n);
    long long int arrN[n];
    for (long long int i = 0; i < n; i++)
    {
        scanf("%lld", &arrN[i]);
    }
    quickSort(arrN, 0, n - 1);

    long long int m;
    scanf("%lld", &m);
    for (long long int i = 0; i < m; i++)
    {
        long long int x;
        scanf("%lld", &x);
        printf("Case #%lld: %lld\n", i + 1, numCounter(arrN, n, x));
    }

    return 0;
}