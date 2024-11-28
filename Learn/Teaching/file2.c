#include <stdio.h>

int main()
{
    // int n;
    // scanf("%d", &n);
    // // printf("%x\n", n);
    // printf("%o\n", n);

    // 0 = false
    // 1 = true

    // Relational Operator

    // == | Equality
    // != | Not Equal
    // < | Less than
    // > | Greater than
    // <= | Less or equal than
    // >= | Greater or equal than
    // ?: | Conditional assignment

    // Conditional Operator

    // &&

    // printf("%d\n", 3 > 2 && 4 > 5);

    // ||

    // printf("%d\n", 3 > 4 || 4 > 5 || 4 == 9 || 7 > 2);

    // !

    // printf("%d\n", 3 != 4);

    // 0101 0010

    // 2 + 16 + 64  = 82

    // paling kanan klo satu brarti + 1
    // paling kanan klo satu brarti + 2
    // paling kanan klo satu brarti + 4
    // paling kanan klo satu brarti + 8
    // paling kanan klo satu brarti + 16
    // paling kanan klo satu brarti + 32
    // paling kanan klo satu brarti + 64
    // paling kanan klo satu brarti + 128

    // Bitwise Operator

    int a = 12;
    int b = 2;

    // 1100
    // 1000
    // 0100

    // printf("%d/n", a & b);

    // |

    // printf("%d\n", a | b);

    // ^

    // printf("%d\n", a ^ b);

    // ~

    // printf("%d\n", ~a);

    // >> : Shift Right

    // 1100;
    // 0110;
    // 0011;
    // 0001;

    // << : Shift Left

    // 0000 0000 0011 0000

    // int a, b;
    // scanf("%d %d", &a, &b);

    // printf("%d\n", a + b);
    // printf("%d\n", a - b);
    // printf("%d\n", a * b);
    // printf("%d\n", a / b);
    // printf("%d\n", a % b);

    // int x;
    // scanf("%d", &x);
    // printf("%d plus %d is %d\n", x, x, x + x);
    // printf("minus one is %d\n", x + x - 1);

    int nilaiTugas, nilaiUTS, nilaiUAS;
    scanf("%d %d %d", &nilaiTugas, &nilaiUTS, &nilaiUAS);

    double totalNilai = (nilaiTugas * 0.2) + (nilaiUTS * 0.3) + (nilaiUAS * 0.5);
    printf("%.2lf\n", totalNilai);

    return 0;
}