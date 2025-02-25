#include <stdio.h>

int main()
{
    int arr[1000];
    for (int i = 0; i < 1000; i++)
    {
        arr[i] = 0;
    }

    int num, i = 0;

    FILE *fp1 = fopen("file1.txt", "r");
    if (fp1 == NULL)
    {
        perror("No File Found");
        return 1;
    }

    while (fscanf(fp1, "%d", &num) == 1)
    {
        arr[i] = num;
        i++;
    }

    fclose(fp1);

    FILE *fp2 = fopen("file2.txt", "r");
    if (fp2 == NULL)
    {
        perror("No File Found");
        return 1;
    }

    while (fscanf(fp2, "%d", &num) == 1)
    {
        arr[i] = num;
        i++;
    }

    fclose(fp2);

    int n, found = 0;

    printf("Enter Number: ");
    scanf("%d", &n);
    for (int i = 0; i < 1000; i++)
    {
        if (n == arr[i])
        {
            printf("Found");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Not Found");
    }

    return 0;
}