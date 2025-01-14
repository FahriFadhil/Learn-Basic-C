#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    int dupeArr[n];
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        dupeArr[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int dupe = 0;

        for (int j = 0; j < count; j++)
        {
            if (arr[i] == dupeArr[j])
            {
                dupe = 1;
                break;
            }
        }

        if (!dupe)
        {
            dupeArr[count] = arr[i];
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
