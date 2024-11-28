#include <stdio.h>

int main()
{
    char fileName[] = "testdata.in";
    int a, b;

    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 0;
    }
    fscanf(file, "%d %d", &a, &b);
    fclose(file);

    printf("%d\n", a + b);

    return 0;
}