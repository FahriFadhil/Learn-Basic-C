#include <stdio.h>
#include <string.h>

typedef struct Profile
{
    char id[11];
    char name[255];
} P;

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

    P profileList[n];

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%s %[^\n]\n", profileList[i].id, profileList[i].name);
    }

    int m;
    fscanf(fp, "%d", &m);
    for (int i = 0; i < m; i++)
    {
        char q[11];
        fscanf(fp, "%s", q);

        int found = 0;

        printf("Case #%d: ", i + 1);

        for (int j = 0; j < n; j++)
        {
            if (strcmp(profileList[j].id, q) == 0)
            {
                printf("%s\n", profileList[j].name);
                found = 1;
            }
        }

        if (!found)
        {
            printf("N/A\n");
        }
    }

    fclose(fp);
    return 0;
}