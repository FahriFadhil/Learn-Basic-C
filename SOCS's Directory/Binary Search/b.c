#include <stdio.h>

long long int calculateSumOfSquares(long long int n)
{
    return n * (n + 1) * (2 * n + 1) / 6;
}

long long int findSmallestN(long long int m)
{
    long long int left = 0, right = 1000000, mid, result = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (calculateSumOfSquares(mid) >= m)
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return result;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++)
    {
        long long int m;
        scanf("%d", &m);
        printf("Case #%d: %lld\n", tc, findSmallestN(m));
    }

    return 0;
}