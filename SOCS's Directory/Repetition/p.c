#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int k, n = 0, sum = 0;
        scanf("%d", &k);
        while (k > sum)
        {
            n++;
            sum += n;
        }
        printf("Case #%d: %d\n", i + 1, n);
    }

    return 0;
}