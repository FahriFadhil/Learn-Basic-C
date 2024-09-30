#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, d;
    scanf("%d %d %d", &a, &b, &c);
    d = b * b - 4 * a * c;
    if (d >= 0)
    {
        double x1 = (double)(-b + sqrt(d)) / 2 * a;
        double x2 = (double)(-b - sqrt(d)) / 2 * a;
        printf("%.2lf %.2lf\n", x1, x2);
    }
    return 0;
}