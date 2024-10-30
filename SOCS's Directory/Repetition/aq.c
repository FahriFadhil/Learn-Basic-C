#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isvalid(const char *s)
{
    int dots = 0;
    int nums = 0;
    int i = 0;

    while (s[i] != '\0')
    {
        if (s[i] == '.')
        {
            dots++;
            if (i == 0 || s[i - 1] == '.' || s[i + 1] == '.' || s[i + 1] == '\0')
            {
                return 0;
            }
        }
        else if (isdigit(s[i]))
        {
            if (i == 0 || s[i - 1] == '.')
            {
                nums++;
            }
        }
        else
        {
            return 0;
        }
        i++;
    }

    return (dots == 5 && nums == 6);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        char s[101];
        scanf("%s", s);

        printf("Case #%d: %s\n", tc + 1, isvalid(s) ? "YES" : "NO");
    }
    return 0;
}
