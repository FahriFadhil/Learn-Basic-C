#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        long long int n, sum = 0;
        scanf("%lld", &n);
        for (int j = 0; j < n; j++)
        {
            long long int num;
            scanf("%lld", &num);
            sum += num;
        }
        printf("Case #%d: %lld\n", i + 1, sum);
    }

    return 0;
}