#include <stdio.h>
#include <string.h>

void decrypt(int shifted, char str[1001], int iteration)
{
    char decryptedCode[1001];
    strcpy(decryptedCode, str);
    int len = strlen(decryptedCode);

    for (int i = 0; i < len; i++)
    {
        switch (decryptedCode[i])
        {
        case '0':
            decryptedCode[i] = 'O';
            break;
        case '1':
            decryptedCode[i] = 'I';
            break;
        case '3':
            decryptedCode[i] = 'E';
            break;
        case '4':
            decryptedCode[i] = 'A';
            break;
        case '5':
            decryptedCode[i] = 'S';
            break;
        case '6':
            decryptedCode[i] = 'G';
            break;
        case '7':
            decryptedCode[i] = 'T';
            break;
        case '8':
            decryptedCode[i] = 'B';
            break;
        default:
            break;
        }
    }

    for (int i = 0; i < len; i++)
    {
        int ascii = decryptedCode[i];
        if (decryptedCode[i] >= 'A' && decryptedCode[i] <= 'Z')
        {
            decryptedCode[i] -= shifted;
            if (decryptedCode[i] < 'A')
            {
                decryptedCode[i] += 26;
            }
        }
    }

    printf("Case #%d: %s\n", iteration, decryptedCode);
}

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
    for (int i = 0; i < t; i++)
    {
        int shifted;
        char str[1001];
        fscanf(file, "%d", &shifted);
        fscanf(file, " %[^\n]\n", str);
        decrypt(shifted, str, i + 1);
    }
    fclose(file);

    return 0;
}