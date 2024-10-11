#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        char s[1001];
        scanf("%s", s);

        printf("Case %d: ", tc + 1);
        for (int i = 0; i < strlen(s); i++)
        {
            printf("%d", (int)s[i]);
            if (strlen(s) != (i + 1))
            {
                printf("-");
            }
        }
        printf("\n");
    }

    return 0;
}