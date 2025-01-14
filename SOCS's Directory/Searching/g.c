#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int n, m, count = 0;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            if (temp >= m)
            {
                count++;
            }
        }
        printf("Case #%d: %d\n", tc + 1, count);
    }

    return 0;
}