#include <stdio.h>
#include <string.h>

int main()
{
    // ASCII

    // angka yg jadi character

    // for (int i = 0; i < 128; i++)
    // {
    //     printf("%d %c\n", i, i);
    // }

    char sentence[] = "Binus University";
    int n = strlen(sentence);

    char revSentence[n];

    int j = n - 1; // 4
    for (int i = 0; i < n; i++)
    {
        revSentence[i] = sentence[j]; // i = 1, j = 3
        j--;
    }

    printf("%s\n", revSentence);

    for (int i = 0; i < n; i++)
    {
        if (sentence[i] >= 65 && sentence[i] <= 90)
        {
            sentence[i] += 32;
        }
        else if (sentence[i] >= 97 && sentence[i] <= 122)
        {
            sentence[i] -= 32;
        }
    }

    printf("%s\n", sentence);

    return 0;
}