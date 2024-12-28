#include <stdio.h>

// void removeElement(int *arr, int index, int n)
// {
//     for (int i = index; i < n - 1; i++)
//         arr[i] = arr[i + 1];
// }

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int arrN[n];
    int arrM[m];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arrN[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &arrM[i]);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arrN[j] == arrM[i])
            {
                arrN[j] = -1;
            }
        }
    }

    int highest = -1;
    for (int i = 0; i < n; i++)
    {
        if (arrN[i] > highest)
        {
            highest = arrN[i];
        }
    }

    printf("Maximum number is %d\n", highest);

    return 0;
}