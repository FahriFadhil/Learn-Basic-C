#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%c", i % k == 0 ? '#' : '.');
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%c", j % k == 0 ? '#' : '.');
        }
        printf("\n");
    }

    return 0;
}