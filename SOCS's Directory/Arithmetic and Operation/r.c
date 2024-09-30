#include <stdio.h>

int main()
{
    long long int A, B, C, D;
    long long int result1, result2, result3;

    scanf("(%lld+%lld)x(%lld-%lld)\n", &A, &B, &C, &D);
    result1 = (A + B) * (C - D);

    scanf("(%lld+%lld)x(%lld-%lld)\n", &A, &B, &C, &D);
    result2 = (A + B) * (C - D);

    scanf("(%lld+%lld)x(%lld-%lld)", &A, &B, &C, &D);
    result3 = (A + B) * (C - D);

    printf("%lld %lld %lld\n", result1, result2, result3);

    return 0;
}
