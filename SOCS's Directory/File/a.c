#include <stdio.h>
#include <string.h>

// void write(char fileName[255], char friendName[255], char treeName[255])
// {
//     FILE *file = fopen(fileName, "a");
//     if (file == NULL)
//     {
//         perror("Error opening file");
//         return;
//     }
//     fprintf(file, "%s#%s\n", friendName, treeName);
//     fclose(file);
// }

// void select(char fileName[255], char friendName[255], int caseNum)
// {
//     FILE *file = fopen(fileName, "r");
//     if (file == NULL)
//     {
//         perror("Error opening file");
//         return;
//     }

//     char fileFriendName[255], fileTreeName[255];
//     int found = 0;

//     while (fscanf(file, "%[^#]#%[^\n]\n", fileFriendName, fileTreeName) == 2)
//     {
//         if (strcmp(friendName, fileFriendName) == 0)
//         {
//             printf("Case #%d: %s\n", caseNum, fileTreeName);
//             found = 1;
//             break;
//         }
//     }

//     if (!found)
//     {
//         printf("Case #%d: N/A\n", caseNum);
//     }

//     fclose(file);
// }

typedef struct List
{
    char friendName[255];
    char treeName[255];
} L;

L data[255];
int recordLength = 0;

void readAllData(FILE *file, int length)
{
    for (int i = 0; i < length; i++)
    {
        fscanf(file, " %[^#]#%[^\n]\n", data[i].friendName, data[i].treeName);
    }
    recordLength = length;
}

void selectQuery(char queryName[255], int iteration)
{
    int found = 0;
    for (int i = 0; i < recordLength; i++)
    {
        if (strcmp(data[i].friendName, queryName) == 0)
        {
            printf("Case #%d: %s\n", iteration, data[i].treeName);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("Case #%d: N/A\n", iteration);
    }
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
    readAllData(file, t);

    int n;
    fscanf(file, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        char queryName[255];
        fscanf(file, " %[^\n]\n", queryName);
        selectQuery(queryName, i + 1);
    }

    fclose(file);
    return 0;
}
