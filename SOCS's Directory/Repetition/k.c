#include <stdio.h>

int main()
{
    int t, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        printf("Case #%d:\n", i + 1);
        for (int j = 1; j <= n; j++)
        {
            for (int slide = 0; slide < n - j; slide++)
            {
                printf(" ");
            }

            for (int k = 0 + i; k < (j + i); k++)
            {
                printf("%c", k % 2 == 0 ? '*' : '#'); // If else
            }
            printf("\n");
        }
    }

    return 0;
}