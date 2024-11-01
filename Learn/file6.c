#include <stdio.h>

int main()
{
    int x = 9;
    for (int i = 0; i < x; i++)
    {
        for (int i = 0; i < x; i++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (i == 0 || j == 0 || i == x - 1 || j == x - 1 || i == j || i + j == x - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");
    for (int i = x; i > 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 0; i < x; i++)
    {
        for (int j = 1; j < x - i; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < i; k++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 0; i < x; i++)
    {
        for (int k = 0; k < i; k++)
        {
            printf(" ");
        }
        for (int j = 1; j < x - i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 0; i < x; i++)
    {
        for (int k = 0; k < i; k++)
        {
            printf(" ");
        }
        for (int j = 0; j < x; j++)
        {
            if (j == 0 || i == 0 || j == x - 1 || i == x - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");
    for (int i = 0; i < x; i++)
    {
        for (int k = x; k > i + 1; k--)
        {
            printf(" ");
        }
        for (int j = 0; j < x; j++)
        {
            if (j == 0 || i == 0 || j == x - 1 || i == x - 1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    printf("\n");
    for (int i = x; i > 0; i--)
    {
        for (int j = 0; j < x; j++)
        {
            if (j > i / 2 && j < x - (i / 2))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}