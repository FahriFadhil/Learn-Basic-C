#include <stdio.h>

int main()
{
    int n, q;
    scanf("%d", &n);
    int arrN[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arrN[i]);
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        arrN[a - 1] = b;
        printf("Case #%d:", i + 1);
        for (int j = 0; j < n; j++)
        {
            printf(" %d", arrN[j]);
        }
        printf("\n");
    }

    return 0;
}