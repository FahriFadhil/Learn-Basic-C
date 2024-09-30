#include <stdio.h>

int main()
{
    long long int A, B;
    scanf("%lld %lld", &A, &B);
    // Discount Prices: A as Initial Price and B Discount Percentage
    double percentage = ((double)(A - B) / A) * 100;
    printf("%.2f%%\n", percentage);
    return 0;
}