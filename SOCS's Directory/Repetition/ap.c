#include <stdio.h>

// a = 97

int main()
{
    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                         'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        long long int n, k;
        scanf("%lld %lld", &n, &k);
        char s[n + 1];
        scanf("%s", s);
        printf("Case #%d: ", tc + 1);
        for (int i = 0; i < n; i++)
        {
            long long int ascii = (int)s[i] - 97;
            ascii = (ascii + k) % 26;
            printf("%c", alphabet[ascii]);
        }
        printf("\n");
    }

    return 0;
}