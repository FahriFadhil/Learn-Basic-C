#include <stdio.h>

int main()
{
    char x, y, z;
    int a, b, c;
    scanf("%c %c %c", &x, &y, &z);

    if ((int)x < (int)y && (int)x < (int)z)
    {
        a = 1;
        if ((int)y < (int)z)
        {
            b = 2;
            c = 3;
        }
        else
        {
            c = 2;
            b = 3;
        }
    }
    if ((int)y < (int)x && (int)y < (int)z)
    {
        a = 2;
        if ((int)x < (int)z)
        {
            b = 1;
            c = 3;
        }
        else
        {
            c = 1;
            b = 3;
        }
    }
    if ((int)z < (int)x && (int)z < (int)y)
    {
        a = 3;
        if ((int)x < (int)y)
        {
            b = 1;
            c = 2;
        }
        else
        {
            b = 2;
            c = 1;
        }
    }
    printf("%d %d %d\n", a, b, c);
    return 0;
}