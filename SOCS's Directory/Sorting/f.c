#include <stdio.h>
#include <string.h>

typedef struct imGonnaNameThisVariableTheWeirdestWayPossibleJustCauseICanAndImInTheMoodRightNowAnywaySoILetMyFreeWillConquerThisVarNameOhPoorBoy
{
    char name[11];
    long long int deadlineTime;
} S;

void swap(S *a, S *b)
{
    S temp = *a;
    *a = *b;
    *b = temp;
}

int partition(S arr[], int low, int high)
{
    int pivot = arr[high].deadlineTime;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j].deadlineTime < pivot || (arr[j].deadlineTime == pivot && strcmp(arr[j].name, arr[high].name) < 0))
        {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(S arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    S deadlines[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %lld", deadlines[i].name, &deadlines[i].deadlineTime);
    }

    quickSort(deadlines, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%s\n", deadlines[i].name);
    }

    return 0;
}