#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        int sum = a, eb = a;

        while (eb >= b)
        {
            int nb = eb / b;
            sum += nb;
            eb = eb % b + nb;
        }

        printf("Case #%d: %d\n", i + 1, sum);
    }

    return 0;
}