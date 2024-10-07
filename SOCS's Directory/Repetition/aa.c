#include <stdio.h>

int main()
{
    int n, p = 0;
    int sIn[] = {9, 33, 76, 53, 80, 97};
    int sOut[] = {21, 42, 92, 37, 59, 88};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int s;
        scanf("%d", &s);
        p += s;
        for (int j = 0; j < (sizeof(sIn) / sizeof(sIn[0])); j++)
        {
            // printf("%d %d", sIn[j], sOut[j]);
            if (p == sIn[j])
            {
                p = sOut[j];
            }
        }
    }
    printf("%d\n", p);

    return 0;
}