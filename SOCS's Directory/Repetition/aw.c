#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int n, high = 0, count = 0;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            int temp;
            scanf("%d", &temp);
            arr[i] = temp;
            if (temp > high)
                high = temp;
        }
        for (int i = 0; i < n; i++)
        {
            if (high == arr[i])
                count++;
        }
        printf("Case #%d: %d\n", tc + 1, count);
    }

    return 0;
}