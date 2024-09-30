#include <stdio.h>

int main()
{
    int T = 3;
    long long int A, B, C, D, E, F;
    double rot1, rot2, rot3;

    scanf("%d", &T);
    scanf("%lld %lld", &A, &B);
    scanf("%lld %lld", &C, &D);
    scanf("%lld %lld", &E, &F);
    for (int i = 0; i < T; i++)
    {
        rot1 = (double)(A * B) / 360;
        rot2 = (double)(C * D) / 360;
        rot3 = (double)(E * F) / 360;
    }
    printf("%.2lf\n%.2lf\n%.2lf\n", rot1, rot2, rot3);

    return 0;
}
