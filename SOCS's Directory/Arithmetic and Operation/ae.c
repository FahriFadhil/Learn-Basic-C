#include <stdio.h>

int main()
{
    long long int n, b = 0, sum = 0;
    scanf("%lld", &n);
    for (int i = 0; i < n; i++)
    {
        sum += 100 + b;
        b += 50;
    }
    printf("%lld\n", sum);
    return 0;
}