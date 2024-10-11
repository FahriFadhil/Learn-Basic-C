#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        char str[1001], resStr[1001];
        scanf("%s", str);
        int count = strlen(str) - 1;
        for (int i = 0; i < strlen(str); i++)
        {
            resStr[i] = str[count];
            count--;
        }
        printf("Case #%d : %s\n", tc + 1, resStr);
    }

    return 0;
}