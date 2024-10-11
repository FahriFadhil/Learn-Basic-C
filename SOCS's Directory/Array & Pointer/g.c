#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int n, sum = 0;
        scanf("%d", &n);
        int arrX[n], arrY[n];
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
            if (arrY[i] > arrX[i])
                sum++;
        }
        printf("Case #%d: %d\n", tc + 1, sum);
    }

    return 0;
}