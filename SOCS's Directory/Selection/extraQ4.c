#include <stdio.h>

int main()
{
    int sizeR = 20;
    int sizeC = 20;
    int xPos = 10;
    int yPos = 10;
    char command;

    char map[sizeR][sizeC];

    for (int i = 0; i < sizeR; i++)
    {
        for (int j = 0; j < sizeC; j++)
        {
            map[i][j] = ' ';
        }
    }

    map[yPos][xPos] = 'X';

    while (1)
    {
        for (int i = 0; i < sizeR; i++)
        {
            for (int j = 0; j < sizeC; j++)
            {
                printf("%c ", map[i][j]);
            }
            printf("\n");
        }

        printf("Input Command: [W|A|S|D] ");
        scanf(" %c", &command);

        map[yPos][xPos] = ' ';

        switch (command)
        {
        case 'w':
            if (yPos > 0)
                yPos--;
            break;
        case 'a':
            if (xPos > 0)
                xPos--;
            break;
        case 's':
            if (yPos < sizeR - 1)
                yPos++;
            break;
        case 'd':
            if (xPos < sizeC - 1)
                xPos++;
            break;
        }

        map[yPos][xPos] = 'X';
    }

    return 0;
}
