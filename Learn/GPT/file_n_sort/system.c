#include <stdio.h>

typedef struct score
{
    char name[64];
    int value;
} S;

void swap(S *a, S *b)
{
    S temp = *a;
    *a = *b;
    *b = temp;
}

int partition(S *scoreList, int low, int high)
{
    int pivot = scoreList[high].value;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (scoreList[j].value > pivot)
        {
            i++;
            swap(&scoreList[i], &scoreList[j]);
        }
    }
    swap(&scoreList[i + 1], &scoreList[high]);
    return i + 1;
}

void quickSort(S *scoreList, int low, int high)
{
    if (low < high)
    {
        int pi = partition(scoreList, low, high);

        quickSort(scoreList, low, pi - 1);
        quickSort(scoreList, pi + 1, high);
    }
}

int main()
{
    FILE *fp = fopen("scores.txt", "r");
    if (fp == NULL)
    {
        perror("No File Found");
        return 1;
    }

    int n;
    fscanf(fp, "%d", &n);

    S scoreList[n];

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%s %d", scoreList[i].name, &scoreList[i].value);
    }

    quickSort(scoreList, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%s, %d\n", scoreList[i].name, scoreList[i].value);
    }

    fclose(fp);
    return 0;

    char cha;
    int count = 0;

    while (fscanf(fp, "%c", &cha) == 1)
    {
        if (cha == '\n')
        {
            count++;
        }
    }
}