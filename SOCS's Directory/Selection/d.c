#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    long long int a, b;
    for (int i = 0; i < t; i++)
    {
        scanf("%lld %lld", &a, &b);
        printf("Case #%d: %s\n", i + 1, (a * b) % 2 == 0 ? "Party time!" : "Need more frogs");
    }

    return 0;
}