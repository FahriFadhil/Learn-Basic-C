#include <stdio.h>

int main()
{
    // Soal: Diberi input x & y, buat sebuah bangun segi empat dengan tanda '*' selebar x & y

    // Repetition
    // int x;
    // int y;
    // scanf("%d %d", &x, &y);

    // for (int i = 0; i < x; i++)
    // {

    //     for (int j = 0; j < y; j++)
    //     {
    //         printf("*");
    //     }

    //     printf("\n");
    // }

    // SOCS REP: G

    // int n; // 3
    // scanf("%d", &n);
    // int total = 0; // Total Semua Hewan
    // for (int i = 0; i < n; i++)
    // {
    //     int m;
    //     scanf("%d", &m);
    //     total += m;
    // }
    // printf("%d\n", total);

    // int T;
    // scanf("%d", &T);

    // for (int i = 1; i <= T; i++)
    // {
    //     int N;
    //     scanf("%d", &N);

    //     long long int total = 0;
    //     for (int j = 0; j < N; j++)
    //     {
    //         long long int ai;
    //         scanf("%lld", &ai);
    //         total += ai;
    //     }

    //     printf("Case #%d: %lld\n", i, total);
    // }

    // int t;
    // scanf("%d", &t);
    // for (int tc = 0; tc < t; tc++)
    // {
    //     int finishLine, currentPosition = 0, jumpingCount = 0;
    //     scanf("%d", &finishLine);
    //     while (currentPosition < finishLine) // 6
    //     {
    //         jumpingCount++;                  // 1, 2, 3
    //         currentPosition += jumpingCount; // 1, 3, 6
    //     }
    //     printf("Case #%d: %d\n", tc + 1, jumpingCount);
    // }

    // int n, p, totalBalonYgBisaDiPecahin = 0;
    // scanf("%d %d", &n, &p);
    // for (int i = 0; i < n; i++)
    // {
    //     int x;
    //     scanf("%d", &x);
    //     if (x < p)
    //     {
    //         totalBalonYgBisaDiPecahin++;
    //     }
    // }
    // printf("%d\n", totalBalonYgBisaDiPecahin);

    int n, banyakSoalYangDiKlarifikasiBibi = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int tc; // waktu klarifikasi dikirim
        int ts; // waktu soal ke jawab temen bibi
        int tv; // waktu bibi klarifikasi
        scanf("%d %d %d", &tc, &ts, &tv);
        if (tv < ts)
        {
            banyakSoalYangDiKlarifikasiBibi++;
        }
    }
    printf("%d\n", banyakSoalYangDiKlarifikasiBibi);

    return 0;
}
