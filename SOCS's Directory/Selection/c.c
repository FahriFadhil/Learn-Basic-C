#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    int a, b;
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d", &a, &b);
        printf("Case #%d: %s\n", i + 1, a > b ? "Go-Jo" : "Bi-Pay");
    }

    return 0;
}