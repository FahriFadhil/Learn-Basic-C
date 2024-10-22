#include <stdio.h>

long long int F(long long int n)
{

    if (n == 1)
        return 1;
    if (n % 2 != 0)
        return F(n - 1) + F(n + 1);
    if (n % 2 == 0)
        return F(n / 2);
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        long long int n;
        scanf("%lld", &n);
        printf("Case #%d: %lld\n", tc + 1, F(n));
    }

    return 0;
}