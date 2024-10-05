#include <stdio.h>

int main()
{
    int t, x, p;
    scanf("%d", &t);
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d", &x, &p);
        printf("%d\n", (x >> p) & 1);
    }

    return 0;
}
