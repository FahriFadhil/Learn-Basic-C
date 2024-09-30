#include <stdio.h>

int main()
{
    long long int A, B;
    scanf("%lld %lld", &A, &B);
    // Normal Percentage: A as Progress of Completion and B as Completion Point
    double percentage = ((double)A / B) * 100;
    printf("%.2f%%\n", percentage);
    return 0;
}