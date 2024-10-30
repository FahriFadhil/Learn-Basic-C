#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    for (int tc = 0; tc < t; tc++)
    {
        int n;
        scanf("%d", &n);
        getchar();
        char s[n + 1];
        fgets(s, n + 1, stdin);
        printf("Case #%d: ", tc + 1);
        for (int i = 0; i < n; i++)
        {
            if ((int)s[i] >= 97 && (int)s[i] <= 122)
            {
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }

    return 0;
}