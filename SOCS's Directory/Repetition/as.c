#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int n, sum = 0;
        scanf("%d", &n);
        char key[n], ans[n];
        scanf("%s", ans);
        scanf("%s", key);
        for (int i = 0; i < n; i++)
        {
            if (ans[i] == key[i])
                sum++;
        }
        printf("Case #%d: %d\n", tc + 1, (sum * 100.0) / n);
    }
    return 0;
}