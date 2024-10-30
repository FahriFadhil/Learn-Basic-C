#include <stdio.h>
#include <string.h>

void removeStringDuplicates(char *str)
{
    int len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len;)
        {
            if (str[i] == str[j])
            {
                for (int k = j; k < len; k++)
                {
                    str[k] = str[k + 1];
                }
                len--;
            }
            else
            {
                j++;
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        char str[100001];
        scanf("%s", str);
        removeStringDuplicates(str);

        printf("Case #%d: %s\n", tc + 1, strlen(str) % 2 == 0 ? "Yay" : "Ewwww");
    }

    return 0;
}
