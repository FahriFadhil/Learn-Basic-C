#include <stdio.h>

int main()
{
    int n, s = 0;
    scanf("%d", &n);
    int arrN[n], used[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arrN[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arrN[i] == arrN[j])
            {
                s++;
            }
        }
    }
    printf("%d\n", n - s);

    return 0;
}