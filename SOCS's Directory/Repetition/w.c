#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int n, even = 0, odd = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int p;
            scanf("%d", &p);
            p % 2 == 0 ? even++ : odd++;
        }
        printf("Odd group : %d integer(s).\n", odd);
        printf("Even group : %d integer(s).\n", even);
        printf("\n");
    }

    return 0;
}