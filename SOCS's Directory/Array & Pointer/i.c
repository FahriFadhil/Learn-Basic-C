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
        printf("Case #%d:", tc + 1);
        for (int i = n; i > 0; i--)
        {
            printf(" %d", arr[i - 1]);
        }
        printf("\n");
    }

    return 0;
}