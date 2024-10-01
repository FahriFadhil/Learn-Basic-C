#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d %d %d", x / 10000, (x % 10000) / 5000, ((x % 10000) % 5000) / 2000);
    return 0;
}