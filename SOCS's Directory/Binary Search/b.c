#include <stdio.h>

long long int formula(long long int n)
{
    return (n * (n + 1) * ((2 * n) + 1)) / 6;
}

long long int findSmallestN(long long int n)
{
    long long int left = 1, right = 1442250, mid, result = 0;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (formula(mid) < n)
        {
            left = mid + 1;
        }
        else
        {
            result = mid;
            right = mid - 1;
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
        long long int n;
        scanf("%lld", &n);
        printf("Case #%d: %lld\n", tc, findSmallestN(n));
    }
    return 0;
}
