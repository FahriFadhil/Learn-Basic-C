#include <stdio.h>

int main()
{
    int m = 10;
    int p;
    while (m != 0)
    {
        printf("Jumlah meja tersedia: %d\n", m);
        printf("Pilih berapa pelanggan: ");
        scanf("%d", &p);
        if (p > m * 4 || p == 0)
        {
            printf("Reservasi gagal, kekurangan meja\n");
            continue;
        }
        printf("Reservasi berhasil! anda membutuhkan %d meja\n", m - ((m * 4) - p) / 4);
        m = ((m * 4) - p) / 4;
        printf("Jumlah orang yang akan datang: %d\n", p);
        if (m == 0)
        {
            printf("Pesanan selesai, tidak ada meja tersedia");
            return 0;
        }
    }
    return 0;
}