#include <stdio.h>
#include <string.h>

int main()
{
    //! char a[5] = 'abcde \0'

    //? BINA NUSANTARA (ilangin huruf vokal di dalam string tsb {a, i, u, o, e})
    //? BN NSNTR

    // char s = 'a';
    // char s[10] = "abascsca";
    // fgets(s, 101, stdin);
    // scanf("%s") Bina Nusantara (Bina)

    char s[101]; // 'A','B','c' = string
    scanf("%[^\n]", s);

    // strlen("Bina Nusantara") output : 14
    for (int i = 0; i < strlen(s); i++)
    {
        // jika s[i] == A;
        // jika s[i] == I;
        // jika s[i] == U;
        // jika s[i] == E;
        // jika s[i] == O;

        if (s[i] != 'A' && s[i] != 'I' && s[i] != 'U' && s[i] != 'O' && s[i] != 'E')
        {
            printf("%c", s[i]);
        }
    }

    // int n, boolean = 1;
    // scanf("%d", &n);

    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }

    // if (arr[0] > arr[1])
    // {
    //     for (int i = 0; i < n - 1; i++)
    //     {
    //         if (arr[i] < arr[i + 1])
    //         {
    //             boolean = 0;
    //         }
    //     }
    // }

    // if (arr[0] < arr[1])
    // {
    //     for (int i = 0; i < n - 1; i++)
    //     {
    //         if (arr[i] > arr[i + 1])
    //         {
    //             boolean = 0;
    //         }
    //     }
    // }

    // printf("%s\n", boolean == 1 ? "Good Hill" : "Bad Hill");

    return 0;
}