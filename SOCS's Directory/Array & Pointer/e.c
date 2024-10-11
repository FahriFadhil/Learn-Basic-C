#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int n;
        scanf("%d", &n);
        int arrN[n][n], sum[n];
        for (int i = 0; i < n; i++)
        {
            sum[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &arrN[i][j]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum[i] += arrN[j][i];
            }
        }
        printf("Case #%d:", tc + 1);
        for (int i = 0; i < n; i++)
        {
            printf(" %d", sum[i]);
        }
        printf("\n");
    }

    return 0;
}