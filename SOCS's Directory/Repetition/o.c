#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n, m, k, fp;
        scanf("%d %d %d", &n, &m, &k);
        fp = k;
        for (int j = 0; j < n; j++)
        {
            int p;
            scanf("%d", &p);

            if (p > k && p <= m)
            {
                if (p > fp)
                {
                    fp = p;
                }
            }
        }
        printf("Case #%d: %d\n", i + 1, fp);
    }

    return 0;
}