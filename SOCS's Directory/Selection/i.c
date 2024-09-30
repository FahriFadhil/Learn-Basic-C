#include <stdio.h>

int main()
{
    int t, p, c, m, ic;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d %d %d", &p, &c, &m);
        ic = (p / 100) * c;
        printf("Case #%d: %d\n", i + 1, ic >= m ? m : ic);
    }

    return 0;
}