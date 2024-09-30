#include <stdio.h>

int main()
{
    int x, y, z, t;
    scanf("%d", &t);
    scanf("%d\n%d\n%d", &x, &y, &z);
    printf("%.2lf %.2lf %.2lf\n", x * (4.0 / 5), ((9.0 / 5) * x) + 32, (double)x + 273);
    printf("%.2lf %.2lf %.2lf\n", y * (4.0 / 5), ((9.0 / 5) * y) + 32, (double)y + 273);
    printf("%.2lf %.2lf %.2lf\n", z * (4.0 / 5), ((9.0 / 5) * z) + 32, (double)z + 273);
    return 0;
}