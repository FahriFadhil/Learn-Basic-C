#include <stdio.h>

int main()
{
    // If Else

    // int x = 100;

    // if (x >= 90)
    // {
    //     printf("%c\n", 'A');
    // }
    // else if (x >= 70)
    // {
    //     printf("%c\n", 'C');
    // }
    // else if (x >= 80)
    // {
    //     printf("%c\n", 'B');
    // }
    // else
    // {
    //     printf("%s\n", 'Ga Lulus');
    // }

    // Switch

    // W, A, S, D
    // char key = 'q';

    // switch (key)
    // {
    // case 'w':
    //     printf("%c\n", 'w');
    //     break;
    // case 'a':
    //     printf("%c\n", 'a');
    //     break;
    // case 's':
    //     printf("%c\n", 's');
    //     break;
    // case 'd':
    //     printf("%c\n", 'd');
    //     break;
    // default:
    //     printf("%c\n", 'x');
    // }

    // Ternary --

    // int ok = 10;

    // int boolean = ok == 10 ? 1 : 0;

    // int num = 3;
    // printf("%s", num % 2 == 0 ? "Genap" : "Ganjil");

    // num % 2 == 0

    // int a, b, c, d;
    // scanf("%d %d %d %d", &a, &b, &c, &d);

    // if ((a * b) == (c - d))
    // {
    //     printf("%s\n", "True");
    // }
    // else
    // {
    //     printf("%s\n", "False");
    // }

    // return 0;

    long long int a, b, c, d;

    scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

    if ((a * b) > (c + d))
    {
        printf("%s\n", "True");
    }
    else
    {
        printf("%s\n", "False");
    }
    return 0;
}