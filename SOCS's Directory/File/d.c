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

// #include <stdio.h>
// #include <string.h>

// int main()
// {
//     FILE *file = fopen("testdata.in", "r");
//     if (!file)
//     {
//         printf("File tidak ditemukan!");
//     }

//     int t;
//     fscanf(file, "%d", &t);

//     for (int i = 0; i < t; i++)
//     {
//         char s[110];
//         fscanf(file, " %[^\n]", s);
//         int len = strlen(s);
//         int counter[26] = {0};

//         int n;
//         fscanf(file, "%d", &n);

//         int check[26] = {0};

//         for (int j = 0; j < n; j++)
//         {
//             char a;
//             char b;
//             fscanf(file, " %c %c", &a, &b);

//             if (check[a - 'A'] == 0)
//             {
//                 for (int k = 0; k < len; k++)
//                 {
//                     if (s[k] == a)
//                     {
//                         s[k] = b;
//                     }
//                 }
//                 check[a - 'A'] = 1;
//             }
//         }
//         for (int j = 0; j < len; j++)
//         {
//             if (s[j] >= 'A' && s[j] <= 'Z')
//             {
//                 counter[s[j] - 'A']++;
//             }
//         }
//         for (int j = 0; j < 26; j++)
//         {
//             if (counter[j] != 0)
//             {
//                 printf("%c %d\n", 'A' + j, counter[j]);
//             }
//         }
//     }

//     fclose(file);

//     return 0;
// }