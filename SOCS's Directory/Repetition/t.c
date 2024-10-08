#include <stdio.h>

int main()
{
    int n, c = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int tc, ts, tv;
        scanf("%d %d %d", &tc, &ts, &tv);
        if (tv < ts)
        {
            c++;
        }
    }
    printf("%d\n", c);

    return 0;
}