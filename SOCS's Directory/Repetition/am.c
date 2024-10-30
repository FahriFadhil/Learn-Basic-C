#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int n;
        scanf("%d", &n);
        printf("Case #%d:\n", tc + 1);
        for (int i = 1; i <= n; i++)
        {
            if (i % 3 == 0 || i % 5 == 0)
            {
                printf("%d %s\n", i, i % 15 == 0 ? "Lili" : "Jojo");
                continue;
            }
            printf("%d Lili\n", i);
        }
    }

    return 0;
}