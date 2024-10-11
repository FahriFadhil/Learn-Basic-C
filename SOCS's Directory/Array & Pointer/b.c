#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int n;
        scanf("%d", &n);
        int arrX[n], arrY[n], arrZ[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arrX[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arrY[i]);
        }
        for (int i = 0; i < n; i++)
        {
            arrZ[i] = arrX[i] - arrY[i];
        }
        printf("Case #%d:", tc + 1);
        for (int i = 0; i < n; i++)
        {
            printf(" %d", arrZ[i]);
        }
        printf("\n");
    }

    return 0;
}