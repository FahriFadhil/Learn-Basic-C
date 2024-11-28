#include <stdio.h>

int main()
{
    // For
    // While

    // Increment, Condition

    // int x = 1;

    // while (x <= 5) // Condition
    // {
    //     printf("%d\n", x);
    //     x++; // Increment
    // }

    // for (int x = 0; x < 5; x++)
    // {
    //     printf("%d\n", x);
    // }

    // int n, m; // 5 5
    // scanf("%d %d", &n, &m);

    // for (int i = 0; i < m; i++) // Counter
    // {
    //     printf("%d\n", n);
    //     n++; // Printout
    // }

    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; i++)
    {
        int k, n, m;
        scanf("%d %d %d", &k, &n, &m);

        if (k <= (n + m))
        {
            printf("Case #%d: yes\n", i);
        }
        else
        {
            printf("Case #%d: no\n", i);
        }
    }

    return 0;
}