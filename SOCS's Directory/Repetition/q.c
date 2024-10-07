#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        long long int n, x, flip = 0, pageTracker = 0;
        scanf("%lld %lld", &n, &x);
        printf("Case #%d: %lld\n", i + 1, (x / 2) < ((n / 2) - (x / 2)) ? (x / 2) : ((n / 2) - (x / 2)));
    }

    return 0;
}