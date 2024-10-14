#include <stdio.h>

int main()
{
    long long int t, sum;
    scanf("%lld", &t);
    for (int i = 0; i < t; i++)
    {
        long long int n;
        scanf("%lld", &n);
        if (n < 0)
            continue;
        sum += n;
    }
    printf("%lld\n", sum);

    return 0;
}