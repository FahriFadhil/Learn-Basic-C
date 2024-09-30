#include <stdio.h>

int main()
{
    int k, x, y;
    scanf("%d %d %d", &x, &y, &k);

    if (x <= k || y >= k)
    {
        if (k - x == y - k)
        {
            printf("%d\n", k - x);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}