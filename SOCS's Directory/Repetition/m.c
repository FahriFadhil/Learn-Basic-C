#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n, m, sum = 0;
        scanf("%d %d", &n, &m);
        for (int j = 0; j < n; j++)
        {
            int p;
            scanf("%d", &p);
            sum += p;
        }
        printf("Case #%d: %s\n", i + 1, m >= sum ? "No worries" : "Wash dishes");
    }

    return 0;
}