#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int n, count = 0, curr = 1;
        scanf("%d", &n);
        printf("Case %d: ", tc + 1);
        for (int i = 0; i < n; i++)
        {
            printf("%d", curr + count);
            if (i < n - 1)
            {
                printf(" ");
            }
            curr += count;
            count++;
        }

        // printf("Flush");
        printf("\n");
    }

    return 0;
}