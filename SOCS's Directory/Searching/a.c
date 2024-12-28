#include <stdio.h>
#include <string.h>

typedef struct Dictionary
{
    char key[51];
    char word[51];
} D;

void translator(char *sentence, D *dictionary, int nDictionary)
{
    int n = strlen(sentence);
    int pivot = 0;

    for (int i = 0; i <= n; i++)
    {
        if (sentence[i] == ' ' || sentence[i] == '\0')
        {
            char m[51] = {0};
            int k = 0;
            for (int j = pivot; j < i; j++)
            {
                m[k++] = sentence[j];
            }
            m[k] = '\0';

            int found = 0;
            for (int j = 0; j < nDictionary; j++)
            {
                if (strcmp(dictionary[j].key, m) == 0)
                {
                    printf("%s", dictionary[j].word);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("%s", m);
            }

            if (sentence[i] == ' ')
            {
                printf(" ");
            }

            pivot = i + 1;
        }
    }
}

int main()
{
    FILE *fp = fopen("testdata.in", "r");
    if (fp == NULL)
    {
        perror("No File Found");
        return 1;
    }

    int n;
    fscanf(fp, "%d", &n);
    D dictionary[n];

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, " %[^#]#%[^\n]\n", dictionary[i].key, dictionary[i].word);
    }

    int t;
    fscanf(fp, "%d", &t);
    for (int tc = 1; tc <= t; tc++)
    {
        char sentence[101];
        fscanf(fp, " %[^\n]", sentence);

        printf("Case #%d:\n", tc);
        translator(sentence, dictionary, n);
        printf("\n");
    }

    fclose(fp);
    return 0;
}