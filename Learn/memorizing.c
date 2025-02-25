#include <stdio.h>

int binarySearch(int arr[], int q, int n)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == q)
            return mid;
        if (q < arr[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int fibonacci(int x)
{
    if (x == 0 || x == 1)
        return 1;
    return fibonacci(x - 1) + fibonacci(x - 2);
}

int main()
{
    int arr[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    int n = 10;

    int q;
    scanf("%d", &q);
    printf("Index: %d\n", binarySearch(arr, q, n));
    printf("Fibonacci: %d\n", fibonacci(q));

    return 0;
}