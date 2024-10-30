#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n, l = 0, b = 0;
        char s[101];
        scanf("%d", &n) ;
        scanf("%s", s);
        for (int j = 0; j < n; j++)
        {
            if (s[j] == 'L')
            {
                l++;
            }
            else if (s[j] == 'B')
            {
                b++;
            }
        }
        if (l > b)
        {
            printf("Lili\n");
        }
        else if (b > l)
        {
            printf("Bibi\n");
        }
        else
        {
            printf("None\n");
        }
    }

    return 0;
}