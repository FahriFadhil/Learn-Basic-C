#include <stdio.h>

int main()
{
    long long int t, sum = 0;
    scanf("%lld", &t);
    for (int i = 0; i < t; i++)
    {
        long long int n;
        scanf("%lld", &n);
        if (n < 1)
        {
            continue;
        }
        sum += n;
    }
    printf("%lld\n", sum);

    return 0;
}