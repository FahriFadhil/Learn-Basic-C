#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        char s[1000];
        char S[1000];
        scanf("%[^\n]", s);
        int n = strlen(s);
        int N = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            S[N] = s[i];
            N++;
        }
        S[N] = '\0';

        printf("Case #%d: %s\n", tc + 1, S);
    }

    return 0;
}
