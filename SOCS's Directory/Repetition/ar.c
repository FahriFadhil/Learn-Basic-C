#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    for (int tc = 0; tc < m; tc++)
    {
        int slide = n - 2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j > slide)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
            slide--;
        }
    }

    return 0;
}