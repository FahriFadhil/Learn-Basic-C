#include <stdio.h>

int binarySearch(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            if (mid > 0 && arr[mid] == arr[mid - 1])
            {
                right = mid - 1;
                continue;
            }
            return mid + 1;
        }
        else
        {
            if (arr[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < m; i++)
    {
        int q;
        scanf("%d", &q);
        printf("%d\n", binarySearch(arr, n, q));
    }
    return 0;
}