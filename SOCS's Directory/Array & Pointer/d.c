#include <stdio.h>

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    int arr[x][y];
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        arr[a - 1][b - 1] = c;
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d", arr[i][j]);
            if (j < y - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}