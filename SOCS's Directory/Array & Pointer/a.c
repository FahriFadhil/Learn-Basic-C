#include <stdio.h>

int main()
{
    int n, q;
    scanf("%d", &n);
    int arrN[n];
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &arrN[i]);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int a, b, sum = 0;
        scanf("%d %d", &a, &b);
        for (int j = a - 1; j < b; j++)
        {
            sum += arrN[j];
        }
        printf("Case #%d: %d\n", i + 1, sum);
    }

    return 0;
}