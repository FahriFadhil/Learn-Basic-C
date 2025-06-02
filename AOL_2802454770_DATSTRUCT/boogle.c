#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ASCII_SIZE 128

typedef struct TrieNode {
    struct TrieNode* children[ASCII_SIZE];
    char* description;
    bool isCompletedWord;
} TN;


int menu() {
    printf("\nWelcome to Boogle!\n");
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

/* 
o Ask the user to input the new slang word. Validate that the slang word must be more than 1 character and contains no space.
o Ask the user to input the description (meaning) of the new word. Validate that the description must be more than 1 word.
o Store the new released slang word to a Trie data structure along with its description. 
*/

void insertTrie() {

}

void releaseNewSlang() {
    int validSlang = 0;
    char slang[64];
    printf("Input a new slang word [Must be more than 1 characters and contains no space] \n");
    do {
        printf(">> ");
        scanf(" %[^\n]", slang);

        if (strlen(slang) <= 1) {
            printf("Slang must be more than 1 character!\n");
            continue;
        }

        int hasSpace = 0;
        for (int i = 0; i < strlen(slang); i++) {
            if (slang[i] == ' ') {
                hasSpace = 1;
                break;
            }
        }

        if (hasSpace) {
            printf("Slang must not contain spaces!\n");
        } else {
            validSlang = 1;
        }

    } while (!validSlang);
    
    int validDesc = 0;
    char desc[256];
    printf("Input a new slang word description [Must be more than 2 words] \n");
    do
    {
        printf(">> ");
        scanf(" %[^\n]", desc);

        int validSpaces = 0;
        for (int i = 0; i < strlen(desc); i++)
        {
            if (desc[i] == ' ')
            {
                if (desc[i-1] && desc[i+1] && desc[i-1] != ' ' && desc[i+1] != ' ')
                {
                    validSpaces++;
                }
            }
        }
        
        if (validSpaces >= 2)
        {
            validDesc = 1;
        } else {
            printf("Description must be more than 2 words!\n");
        }
    
    } while (validDesc == 0);

    insertTrie(slang, desc);
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