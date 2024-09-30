#include <stdio.h>

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%.2f\n", ((a * .2) + (b * .3) + (c * .5)));
    return 0;
}