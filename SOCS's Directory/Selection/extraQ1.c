#include <stdio.h>
#include <string.h>

int main()
{
    char n[100];
    scanf("%s", n);

    int al = strlen(n);
    int sum = 0;
    for (int i = 0; i < al; i++)
    {
        printf("Nomor %c adalah %s\n", n[i], (n[i] - '0') % 2 == 0 ? "Genap" : "Ganjil");
        sum += n[i] - '0';
    }
    printf("Jumlah: %d\n%d adalah %s", sum, sum, sum % 2 == 0 ? "Genap" : "Ganjil");
    return 0;
}
