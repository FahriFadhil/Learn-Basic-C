#include <stdio.h>

int main()
{
    long long int n, p, c = 0;
    scanf("%lld %lld", &n, &p);
    for (int i = 0; i < n; i++)
    {
        long long int b;
        scanf("%lld", &b);
        if (b < p)
        {
            c++;
        }
    }
    printf("%lld\n", c);

    return 0;
}