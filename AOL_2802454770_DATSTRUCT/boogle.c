#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu() {
    printf("Welcome to Boogle!\n");
    printf("==================\n");
    printf("1. Release a new slang word\n");
    printf("2. Search a slang word\n");
    printf("3. View all slang words starting with a certain prefix word\n");
    printf("4. View all slang words\n");
    printf("5. Exit\n");
    printf(">> ");
    int decision;
    scanf("%d", &decision);
    system("clear");
    return decision;
}

void releaseNewSlang() {
    int validSlang = 0;
    do
    {
        char slang[64];
        getchar();
        scanf("%[^\n]", slang);
        if (strlen(slang) < 1)
        {
            continue;
        }
        for (int i = 0; i < strlen(slang); i++)
        {
            /* code */
        }
        
        
    } while (validSlang == 0);
    
}

int main() {
    int APP_CACHE = 1;
    while (APP_CACHE == 1)
    {
        int decision = menu();
    
        switch (decision)
        {
        case 1:
            releaseNewSlang();
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 5:
            APP_CACHE = 0;
            break;
        
        default:
            printf("Unknown Input, Try Again!\n");
            break;
        }
    }

    return 0;
}