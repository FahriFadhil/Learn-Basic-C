#include <stdio.h>

long long int numCounter(long long int *arr, long long int n, long long int m)
{
    long long int pivot = 0, finalCount = 0;
    while (pivot < n)
    {
        long long int currCount = 0;
        long long int minCount = m;
        for (long long int i = pivot; i < n; i++)
        {
            if ((minCount - arr[i]) >= 0)
            {
                currCount++;
                minCount = minCount - arr[i];
            }
            else
            {
                break;
            }
            if (currCount > finalCount)
            {
                finalCount = currCount;
            }
        }
        pivot++;
        // printf("%lld, %lld\n", pivot, currCount);
    }
    return finalCount;
}

int main()
{
    long long int n;
    scanf("%lld", &n);
    long long int arr[n];
    for (long long int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    long long int t;
    scanf("%lld", &t);
    for (int tc = 0; tc < t; tc++)
    {
        long long int m;
        scanf("%lld", &m);
        printf("Case #%d: %lld\n", tc + 1, numCounter(arr, n, m));
    }

    return 0;
}