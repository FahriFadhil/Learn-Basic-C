#include <stdio.h>

int main()
{
    double a, b, sum1, sum2, sum3, sum4;
    // Undiscount Prices: A as Discount Percentage and B Discounted Price
    scanf("%lf %lf", &a, &b);
    sum1 = (b / (1 - (a / 100.0)));
    scanf("%lf %lf", &a, &b);
    sum2 = (b / (1 - (a / 100.0)));
    scanf("%lf %lf", &a, &b);
    sum3 = (b / (1 - (a / 100.0)));
    scanf("%lf %lf", &a, &b);
    sum4 = (b / (1 - (a / 100.0)));
    printf("$%.2lf\n$%.2lf\n$%.2lf\n$%.2lf\n", sum1, sum2, sum3, sum4);
    return 0;
}