#include <stdio.h>
#include <string.h>

typedef struct Grade
{
    char name[11];
    int score;
} G;

void swap(G *a, G *b)
{
    G temp = *a;
    *a = *b;
    *b = temp;
}

int partition(G *gradeList, int low, int high)
{
    int pivot = gradeList[high].score;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (gradeList[j].score > pivot || (gradeList[j].score == pivot && strcmp(gradeList[j].name, gradeList[high].name) < 0))
        {
            i++;
            swap(&gradeList[j], &gradeList[i]);
        }
    }
    swap(&gradeList[high], &gradeList[i + 1]);
    return i + 1;
}

void quickSort(G *gradeList, int low, int high)
{
    if (low < high)
    {
        int pi = partition(gradeList, low, high);

        quickSort(gradeList, low, pi - 1);
        quickSort(gradeList, pi + 1, high);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        int n;
        scanf("%d", &n);

        G gradeList[n];

        for (int i = 0; i < n; i++)
        {
            scanf(" %[^#]#%d", gradeList[i].name, &gradeList[i].score);
        }
        quickSort(gradeList, 0, n - 1);

        char q[11];
        scanf(" %[^\n]", q);

        for (int i = 0; i < n; i++)
        {
            if (strcmp(q, gradeList[i].name) == 0)
            {
                printf("Case #%d: %d\n", tc + 1, i + 1);
                break;
            }
        }
    }

    return 0;
}