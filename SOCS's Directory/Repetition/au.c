#include <stdio.h>

int main()
{
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int n;
        scanf("%d", &n);
        printf("Case #%d: ", tc + 1);
        for (int i = 0; i < n; i++)
        {
            printf("%c", alphabet[i]);
        }
        printf("\n");
    }

    return 0;
}