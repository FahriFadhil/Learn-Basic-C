#include <stdio.h>

int main()
{
    int a, b, c, d, t;
    float sum1, sum2, sum3;
    scanf("%d", &t);
    scanf("%d %d %d %d", &a, &b, &c, &d);
    sum1 = (float)a / 1 + (float)b / 2 + (float)d / 4 + (float)b / 2 + (float)c / 3 + (float)c / 3 + (float)c / 3 + (float)b / 2 + (float)d / 4 + (float)c / 3 + (float)b / 2 + (float)a / 1;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    sum2 = (float)a / 1 + (float)b / 2 + (float)d / 4 + (float)b / 2 + (float)c / 3 + (float)c / 3 + (float)c / 3 + (float)b / 2 + (float)d / 4 + (float)c / 3 + (float)b / 2 + (float)a / 1;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    sum3 = (float)a / 1 + (float)b / 2 + (float)d / 4 + (float)b / 2 + (float)c / 3 + (float)c / 3 + (float)c / 3 + (float)b / 2 + (float)d / 4 + (float)c / 3 + (float)b / 2 + (float)a / 1;
    printf("%.2f\n%.2f\n%.2f\n", sum1, sum2, sum3);
    return 0;
}