#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int n, sum = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int a;
            scanf("%d", &a);
            sum += a;
        }
        printf("Case #%d: %d\n", tc + 1, sum);
    }

    return 0;
}