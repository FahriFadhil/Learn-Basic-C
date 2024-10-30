#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int r, h;
        scanf("%d %d", &r, &h);
        printf("Case #%d: %.2lf\n", tc + 1, (2 * 3.14 * r) * (r + h));
    }

    return 0;
}