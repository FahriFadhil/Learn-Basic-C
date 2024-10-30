#include <stdio.h>

void countLeaves(int *trees, int n, int index, int curr)
{
    if (index > n)
        return;

    curr += trees[index];

    if (2 * index > n && 2 * index + 1 > n)
    {
        printf("%d\n", curr);
        return;
    }

    countLeaves(trees, n, 2 * index, curr);
    countLeaves(trees, n, 2 * index + 1, curr);
}

int main()
{
    int tc;
    scanf("%d", &tc);

    for (int t = 0; t < tc; t++)
    {
        int n;
        scanf("%d", &n);

        int trees[n + 1];
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &trees[i]);
        }
        printf("Case #%d:\n", t + 1);
        countLeaves(trees, n, 1, 0);
    }

    return 0;
}