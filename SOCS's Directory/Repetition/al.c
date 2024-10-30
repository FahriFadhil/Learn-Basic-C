#include <stdio.h>

int main()
{
    int n, m, sword = 0, dragon = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (sword < temp)
            sword = temp;
    }
    for (int i = 0; i < m; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (dragon < temp)
            dragon = temp;
    }
    printf("%s\n", sword > dragon ? "The dark secret was true" : "Secret debunked");

    return 0;
}