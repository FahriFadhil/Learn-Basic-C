#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (i != 0 && arr[i] == 1)
        {
            printf("%d ", count - 1);
            count = 1;
        }
        count++;
    }
    printf("%d\n", count - 1);

    return 0;
}