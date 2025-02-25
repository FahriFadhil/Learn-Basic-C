#include <stdio.h>

/*
Write a program that reads a file named data.txt.
The file contains an unknown number of integers, each separated by a space.
The program should calculate the sum of all the integers in the file and write the result to a new file called result.txt.
*/

int main()
{
    FILE *fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        perror("No File Found");
        return 1;
    }

    int sum = 0, num;

    while (fscanf(fp, "%d", &num) == 1)
    {
        sum += num;
    }
    fclose(fp);

    FILE *fpe = fopen("result.txt", "w");
    if (fpe == NULL)
    {
        perror("No File Found");
        return 1;
    }
    fprintf(fpe, "%d", sum);
    fclose(fpe);

    printf("%d\n", sum);
    return 0;
}