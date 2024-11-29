#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);

    for (int tc = 0; tc < t; tc++)
    {
        int x;
        scanf("%d", &x);

        for (int i = 1; i <= x; i++)
        {

            for (int j = 0; j < x - i; j++)
            {
                printf(" ");
            }

            for (int k = 0; k < 2 * i - 1; k++)
            {
                printf("*");
            }

            printf("\n");
        }

        // if (tc != t - 1)
        // {
        //     printf("\n");
        // }
    }

    return 0;
}
