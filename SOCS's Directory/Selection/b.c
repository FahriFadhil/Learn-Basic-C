#include <stdio.h>

int main()
{
    int t;
    long long int k, n, m;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%lld %lld %lld", &k, &n, &m);
        printf("Case #%d: %s\n", i + 1, k > (n + m) ? "no" : "yes");
    }
    return 0;
}