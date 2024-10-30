#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        long long int n, count = 0;
        scanf("%lld", &n);
        while (n > 9)
        {
            count++;
            n = n / 10;
        }
        count++;
        printf("Case #%d: %lld\n", tc + 1, count);
    }

    return 0;
}