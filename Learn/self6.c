#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
    char temp[10];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

int partition(char str[][10], int low, int high)
{
    char pivot[10];
    strcpy(pivot, str[high]);
    int i = low - i;
    for (int j = low; j < high; j++)
    {
        if (strcmp(str[j], pivot) < 0)
        {
            i++;
            swap(str[i], str[j]);
        }
    }
    swap(str[high], str[i + 1]);
    return i + 1;
}

void quickSort(char str[][10], int low, int high)
{
    if (low < high)
    {
        int pi = partition(str, low, high);

        quickSort(str, low, pi - 1);
        quickSort(str, pi + 1, high);
    }
}

int main()
{
    char str[5][10] = {"Fahri", "Irgi", "Zira", "Yafi", "Jason"};
    quickSort(str, 0, 4);

    for (int i = 0; i < 5; i++)
    {
        printf("%s\n", str[i]);
    }

    return 0;
}
