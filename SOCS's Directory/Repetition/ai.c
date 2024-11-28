#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int n, truee = 0;
        scanf("%d", &n);

        int arr[n], sum = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        printf("Case #%d: ", tc + 1);

        if (sum % 2 != 0)
        {
            printf("No\n");
        }

        int halfSum = 0;
        for (int i = 0; i < n; i++)
        {
            halfSum += arr[i];
            if (halfSum == sum / 2)
            {
                printf("Yes\n");
                truee = 1;
                break;
            }
        }
        if (truee == 0)
        {
            printf("No\n");
        }
    }

    return 0;
}