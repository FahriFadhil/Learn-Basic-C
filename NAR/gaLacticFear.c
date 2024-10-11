#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3];

void create_board()
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void display_board()
{
    printf("  a   b   c\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", i + 1);
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", board[i][j]);
            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf(" ---+---+---\n");
    }
}

void input_to_index(char move[], int *row, int *col)
{
    *row = move[1] - '1';
    *col = move[0] - 'a';
}

int is_valid_move(char move[])
{
    if (move[0] < 'a' || move[0] > 'c' || move[1] < '1' || move[1] > '3')
        return 0;
    int row, col;
    input_to_index(move, &row, &col);
    return board[row][col] == ' ';
}

void player_move()
{
    char move[3];
    printf("Enter your move (e.g., a1, b2, c3): ");
    scanf("%s", move);
    while (!is_valid_move(move))
    {
        printf("Invalid move. Please try again.\n");
        printf("Enter your move (e.g., a1, b2, c3): ");
        scanf("%s", move);
    }
    int row, col;
    input_to_index(move, &row, &col);
    board[row][col] = 'X';
}

void bot_move_easy()
{
    int row, col;
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');
    board[row][col] = 'O';
}

int check_win(char player)
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return 1;
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return 1;
    return 0;
}

void play_game(int difficulty)
{
    create_board();
    while (1)
    {
        display_board();
        player_move();
        if (check_win('X'))
        {
            display_board();
            printf("You win!\n");
            return;
        }
        if (difficulty == 1)
            bot_move_easy();
        if (check_win('O'))
        {
            display_board();
            printf("You lose!\n");
            return;
        }
        int draw = 1;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (board[i][j] == ' ')
                    draw = 0;
        if (draw)
        {
            display_board();
            printf("It's a draw!\n");
            return;
        }
    }
}

int main()
{
    srand(time(NULL));
    int choice, difficulty;
    printf("Welcome to Galactic Conquest - Training Module\n");
    printf("1. Play\n2. Exit\nChoose an option (1 or 2): ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Choose Difficulty Level\n1. Easy\n2. Hard\nChoose an option (1 or 2): ");
        scanf("%d", &difficulty);
        play_game(difficulty);
    }
    else
    {
        printf("Exiting the game.\n");
    }
    return 0;
}
