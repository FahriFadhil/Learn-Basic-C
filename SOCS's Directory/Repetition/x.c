#include <stdio.h>

int main()
{
    int q, sum = 1;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        sum = (sum * 2) + 1;
    }

    printf("%d\n", sum);
    return 0;
}