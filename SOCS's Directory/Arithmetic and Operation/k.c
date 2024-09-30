#include <stdio.h>

int main()
{
    long long int x;
    double y, sum;
    scanf("%lld %lf", &x, &y);
    // Use Compound Interest Formula = X * (1 + (Y / 100))^N (N: Number of Periods)
    sum = x * (1 + y / 100) * (1 + y / 100) * (1 + y / 100); // Could also wrote (x * (1 + y / 100)^3), needs pow func in math.h include
    printf("%.2lf\n", sum);
    return 0;
}