#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        long long int n, m, small = 1000000;
        scanf("%lld %lld", &n, &m);
        for (int j = 0; j < n; j++)
        {
            long long int p;
            scanf("%lld", &p);
            if (p < small)
                small = p;
        }
        printf("Case #%d: %lld\n", i + 1, m / small);
    }

    return 0;
}