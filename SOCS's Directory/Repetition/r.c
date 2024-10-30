#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        scanf("%d", &n);
        int house[n];
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &house[j]);
        }

        int minDiff = house[0] < house[1] ? house[1] - house[0] : house[0] - house[1];

        // if(house[0] < house[1]) {
        //     house[1] - house[0];
        // } else {
        //     house[0] - house[1];
        // }

        for (int j = 0; j < n - 1; j++)
        {
            int diff = house[j] < house[j + 1] ? house[j + 1] - house[j] : house[j] - house[j + 1];
            minDiff = minDiff < diff ? minDiff : diff;
        }
        printf("Case #%d: %d\n", i + 1, minDiff);
    }

    return 0;
}