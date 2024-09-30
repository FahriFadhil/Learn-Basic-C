#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d plus %d is %d\nminus one is %d\n", x, x, x + x, (x + x) - 1);
    return 0;
}