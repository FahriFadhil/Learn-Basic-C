#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    printf("%s\n", x % 2 == 0 ? "EVEN" : "ODD");
    return 0;
}