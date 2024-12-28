#include <stdio.h>

void swap(char *a, char *b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char arr[], char low, char high)
{
    if (low < high)
    {
        char pivot = arr[high];
    }
}

int main()
{
    int r, c;
    scanf("%d %d", &r, &c);
    char arr[r][c];

    for (int i = 0; i < r; i++)
    {
        char str[r];
        scanf("%s", str);
        for (int j = 0; j < c; j++)
        {
            arr[i][j] = str[j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%c", arr[i][j]);
        }
    }

    return 0;
}