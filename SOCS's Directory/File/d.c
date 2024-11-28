#include <stdio.h>
#include <string.h>

typedef struct Instruction
{
    char initialChar;
    char changedToChar;
    int changedCount;
} I;

int main()
{
    char fileName[] = "testdata.in";
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 0;
    }

    int t;
    fscanf(file, "%d", &t);
    for (int tc = 0; tc < t; tc++)
    {
        char str[255];
        fscanf(file, " %[^\n]\n", str);

        int n;
        fscanf(file, "%d", &n);
        I instruction[n];
        for (int i = 0; i < n; i++)
        {
            instruction[i].changedCount = 0;
            fscanf(file, " %c %c\n", &instruction[i].initialChar, &instruction[i].changedToChar);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (instruction[j].changedToChar > instruction[j + 1].changedToChar)
                {
                    I temp = instruction[j];
                    instruction[j] = instruction[j + 1];
                    instruction[j + 1] = temp;
                }
            }
        }

        for (int i = 0; i < strlen(str); i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (str[i] == instruction[j].initialChar)
                {
                    str[i] = instruction[j].changedToChar;
                    break;
                }
            }
        }

        for (int i = 0; i < strlen(str); i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (str[i] == instruction[j].changedToChar)
                {
                    instruction[j].changedCount++;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            printf("%c %d\n", instruction[i].changedToChar, instruction[i].changedCount);
        }
    }

    fclose(file);
    return 0;
}