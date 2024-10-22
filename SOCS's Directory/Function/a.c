#include <stdio.h>

int counter = 0;

int recursion(int n)
{
    if (n % 3 == 0 && n != 0)
        counter++;
    if (n == 0)
        return 1;
    if (n == 1)
        return 2;
    if (n % 5 == 0)
        return n * 2;

    return recursion(n - 1) + n + recursion(n - 2) + n - 2;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int n;
        scanf("%d", &n);

        int res = recursion(n);
        printf("Case #%d: %d %d\n", tc + 1, res, counter);
        counter = 0;
    }

    return 0;
}