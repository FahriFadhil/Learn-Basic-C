#include <stdio.h>

int main()
{
    // int n;
    // scanf("%d", &n);

    // int arr[n]; // 5
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }

    // int total = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] % 2 == 0)
    //     {
    //         total = total + arr[i];
    //     }
    // }

    // printf("%d\n", total);

    // int n;
    // printf("Enter the number of elements: ");
    // scanf("%d", &n);
    // printf("Enter %d integers: ", n);
    // int arr[n];

    // int count = 0;
    // double sum = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr[i]);
    //     sum += arr[i];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] > (sum / n))
    //     {
    //         count++;
    //     }
    // }
    // printf("Average: %.2lf\nCount of numbers above average: %d\n", (sum / n), count);

    // int n;
    // printf("Enter the number of elements: ");
    // scanf("%d", &n); // 6

    // printf("Enter %d integers: ", n);
    // int arr[n]; // 0, 1, 2, 3, 4, 5
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &arr[i]);
    // }

    // int reversedArray[n];
    // int j = n - 1;              // 5, 4
    // for (int i = 0; i < n; i++) // 1
    // {
    //     reversedArray[j] = arr[i];
    //     j--;
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", reversedArray[i]);
    // }

    // n = 6
    // arr[n] = 1, 2, 3, 4, 5, 6
    // revArr[n] = #, #, #, , 2, 1

    int N, M;

    scanf("%d", &N);

    int nonton[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &nonton[i]);
    }

    scanf("%d", &M);

    int A, B;

    for (int i = 1; i <= M; i++)
    {
        scanf("%d %d", &A, &B);
        int jumlah_tayangan = 0;
        for (int j = A - 1; j < B; j++)
        {
            jumlah_tayangan += nonton[j];
        }

        printf("Case #%d: %d\n", i, jumlah_tayangan);
    }

    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
    }

    return 0;
}