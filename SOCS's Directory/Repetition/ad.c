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
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int tempCount = 0;
        for (int j = 0; j < n; j++)
        {
            if (j == i)
            {
                continue;
            }
            if (arr[i] == arr[j])
            {
                tempCount++;
            }
        }
        count = count < tempCount ? tempCount : count;
    }
    count++;
    printf("%d\n", count);

    return 0;
}