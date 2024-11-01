#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int n;
        scanf("%d", &n);
        int arr[n][n]; // 2x2
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        printf("Case #%d: ", tc + 1);
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += arr[j][i];
            }
            printf("%d", sum);
            if (i < n - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}