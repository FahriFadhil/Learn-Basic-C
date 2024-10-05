#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int anim[n];
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &anim[i]);
        sum += anim[i];
    }

    printf("%d\n", sum);

    return 0;
}
