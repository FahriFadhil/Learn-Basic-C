#include <stdio.h>

int main()
{
    int n, p = 0;
    int sIn[] = {30, 12, 35};
    int sOut[] = {10, 28, 7};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int s;
        scanf("%d", &s);
        p += s;
        while (p >= 39)
        {
            p -= 40;
        }
        for (int j = 0; j < (sizeof(sIn) / sizeof(sIn[0])); j++)
        {
            if (p == sIn[j])
            {
                p = sOut[j];
            }
        }
    }
    printf("%d\n", p);

    return 0;
}