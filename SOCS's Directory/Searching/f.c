#include <stdio.h>

int main()
{
    int n, hard = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x == 1)
        {
            hard = 1;
        }
    }
    printf("%s\n", hard == 1 ? "not easy" : "easy");

    return 0;
}