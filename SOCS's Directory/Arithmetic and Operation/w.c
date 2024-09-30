#include <stdio.h>

int main()
{
    int x, y, z;
    scanf("%d\n %d\n %d", &x, &y, &z);
    printf("%d\n%d\n%d\n", (x / 10) % 10, (y / 10) % 10, (z / 10) % 10);
    return 0;
}