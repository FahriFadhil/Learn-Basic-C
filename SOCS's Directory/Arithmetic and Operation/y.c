#include <stdio.h>

int main()
{
    long long int t, a, b;
    double sum1, sum2, sum3;
    scanf("%lld", &t);
    // Deciding Number after Percentage : A as the initial number and B as the Percent Value
    scanf("%lld %lld", &a, &b);
    sum1 = (a / 100.0) * b;
    scanf("%lld %lld", &a, &b);
    sum2 = (a / 100.0) * b;
    scanf("%lld %lld", &a, &b);
    sum3 = (a / 100.0) * b;
    printf("%.2lf\n%.2lf\n%.2lf\n", sum1, sum2, sum3);
    return 0;
}