#include <stdio.h>

int main()
{
    long long int a, b, sum1, sum2, sum3, sum4;
    scanf("%lld %lld", &a, &b);
    sum1 = a * b;
    scanf("%lld %lld", &a, &b);
    sum2 = a * b;
    scanf("%lld %lld", &a, &b);
    sum3 = a * b;
    scanf("%lld %lld", &a, &b);
    sum4 = a * b;
    printf("%lld\n%lld\n%lld\n%lld\n", sum1, sum2, sum3, sum4);
    return 0;
}