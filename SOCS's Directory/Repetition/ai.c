#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("Case #%d: ", tc + 1);
        int divider = n / 2;
        int sumLeft, sumRight;
        for (int i = 0; i < divider; i++)
        {
            sumLeft += arr[i];
        }
        for (int i = n; i > divider; i--)
        {
            sumRight += arr[i - 1];
        }
        // printf("%d %d %d", sumLeft, sumRight, divider);
        if (sumLeft == sumRight)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}