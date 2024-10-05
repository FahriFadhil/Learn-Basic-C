#include <stdio.h>

int main()
{
    int n, j, l, b, sum;
    scanf("%d\n%d %d %d", &n, &j, &l, &b);

    int nSum[n];
    sum += j + l + b;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nSum[i]);
        sum += nSum[i];
    }

    double av = (double)sum / (3 + n);
    printf("%s\n", j >= av ? "Jojo lolos" : "Jojo tidak lolos");
    printf("%s\n", l >= av ? "Lili lolos" : "Lili tidak lolos");
    printf("%s\n", b >= av ? "Bibi lolos" : "Bibi tidak lolos");
    return 0;
}