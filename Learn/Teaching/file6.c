#include <stdio.h>

int main()
{
    // int array[5] = {1248, 2, 4, 6, 8};
    // double arrayKedua[3] = {2.45, 3, 7.47};
    // char arrayKetiga[5] = {'S', 'E', 'N', 'I', 'N'};

    // printf("%c\n", arrayKetiga[1]);

    // 5
    // 4 6 7 9 10

    // int n;
    // scanf("%d", &n);

    // int arr[n];

    // for (int i = 0; i < n; i++)
    // {
    //     int nilai;
    //     scanf("%d", &nilai);
    //     arr[i] = nilai;
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }

    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; tc++)
    {
        int n; // 3
        scanf("%d", &n);
        int arr[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int nilai;
                scanf("%d", &nilai);
                arr[i][j] = nilai;
            }
        }

        printf("Case #%d: ", tc);

        for (int i = 0; i < n; i++)
        {
            int jumlah = 0;
            for (int j = 0; j < n; j++)
            {
                jumlah += arr[j][i];
            }
            printf("%d", jumlah);
            if (i != n - 1) // 3 - 1 = 2
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}