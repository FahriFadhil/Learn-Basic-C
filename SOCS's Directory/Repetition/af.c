#include <stdio.h>

int countOnBits(num)
{
    int count = 0;
    while (num)
    {
        count += (num & 1);
        num >>= 1;
    }
    return count;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int n, m3 = 0, l3 = 0;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int xorValue = arr[i] ^ arr[j];
                int onBits = countOnBits(xorValue);
                onBits >= 3 ? m3++ : l3++;
            }
        }
        printf("Case #%d: %d %d\n", tc + 1, m3, l3);
    }

    return 0;
}