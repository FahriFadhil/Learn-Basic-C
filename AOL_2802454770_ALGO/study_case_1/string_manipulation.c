#include <stdio.h>
#include <string.h>

/*
    # PSEUDO_CODE
    This is for the First Study Case, String Reversal and Inverse Capitalize

    - Reversal use reverseString() func to run;
    Simple str duplication with manipulation on assign;

    - Inverse Capitalize use formatCase() func to run;
    Make use of the ascii value to modify lower and upper case;
 */

void reverseString(char *str, char *revStr, int n)
{
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        revStr[i] = str[j];
        j--;
    }
    revStr[n] = '\0';
}

void formatCase(char *str, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            str[i] += 32;
        }
        else if (str[i] >= 97 && str[i] <= 122)
        {
            str[i] -= 32;
        }
    }
}

int main()
{
    char str[101];
    scanf("%[^\n]", str);
    int n = strlen(str);

    char revStr[101];
    reverseString(str, revStr, n);
    formatCase(revStr, n);

    printf("%s\n", revStr);
    return 0;
}