#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    int arrArrange[t], arrRes[t];
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &arrArrange[i]);
    }
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &arrRes[arrArrange[i]]);
    }
    for (int i = 0; i < t; i++)
    {
        printf("%d", arrRes[i]);
        if (t != (i + 1))
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}