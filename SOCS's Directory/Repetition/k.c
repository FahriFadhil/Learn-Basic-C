// #include <stdio.h>

// int main()
// {
//     int t, n;
//     scanf("%d", &t);
//     for (int i = 0; i < t; i++)
//     {
//         scanf("%d", &n);
//         printf("Case #%d:\n", i + 1);

//         for (int j = 1; j <= n; j++)
//         {
//             for (int slide = 0; slide < n - j; slide++)
//             {
//                 printf(" ");
//             }

//             for (int k = 0; k < j; k++)
//             {
//                 printf("%c", k % 2 == 0 ? '*' : '#');
//             }
//             printf("\n");
//         }
//     }

//     return 0;
// }

#include <stdio.h>

int main()
{

    int tc;
    scanf("%d", &tc);
    for (int q = 1; q <= tc; q++)
    {
        int n;
        scanf("%d", &n);
        printf("Case #%d:\n", q);
        for (int i = 1; i <= n; i++)
        {
            for (int j = n; j >= 1; j--)
            {
                int row = i + j;
                if (j <= i)
                {
                    if (n % 2 == 0)
                    {
                        row % 2 == 0 ? printf("#") : printf("*");
                    }
                    else
                    {
                        row % 2 == 0 ? printf("*") : printf("#");
                    }
                }
                else
                    printf(" ");
            }
            puts("");
        }
    }

    return 0;
}
