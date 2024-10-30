#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int abcdef[6];
        scanf("%d %d %d %d %d %d", &abcdef[0], &abcdef[1], &abcdef[2], &abcdef[3], &abcdef[4], &abcdef[5]);
        printf("Case #%d: ", tc + 1);
        for (int i = 0; i < 6; i++)
        {
            char c;
            switch (i)
            {
            case 0:
                c = 'a';
                break;
            case 1:
                c = 's';
                break;
            case 2:
                c = 'h';
                break;
            case 3:
                c = 'i';
                break;
            case 4:
                c = 'a';
                break;
            case 5:
                c = 'p';
                break;

            default:
                c = 'a';
                break;
            }
            for (int j = 0; j < abcdef[i]; j++)
            {
                printf("%c", c);
            }
        }
        printf("\n");
    }

    return 0;
}