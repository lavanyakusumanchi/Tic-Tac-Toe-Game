#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 50

int grid[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
int moveHistory[MAX_STACK_SIZE];
int moveCount = 0;

int findWinner();
void squareBoard();
void pushMove(int move);
int popMove();
void printMoveHistory();

int main()
{
    int player = 1, check, wish;

    char spot;
    do
    {
        squareBoard();
        player = (player % 2) ? 1 : 2;

        printf("\033[1;34m");
        printf("Player %d, enter a digit:  ", player);
        scanf("%d", &wish);

        spot = (player == 1) ? 'X' : '0';

        if (wish >= 1 && wish <= 9 && grid[wish] == '0' + wish)
        {
            grid[wish] = spot;
            pushMove(wish);
        }
        else
        {
            printf("\033[1;32m");
            printf("Invalid move by the player");
            player--;
            getch();
        }

        check = findWinner();
        player++;

    } while (check == -1 && moveCount < MAX_STACK_SIZE);

    squareBoard();

    if (check == 1)
        printf("==>\aPlayer %d win. Congratulations!\n", --player);
    else if (check == 0)
        printf("==>\aGame draw! Better luck next time!\n");
    else
        printf("==>\aGame over! Maximum move limit reached.\n");

    printf("\nMove History:\n");
    printMoveHistory();

    getch();
    return 0;
}

int findWinner()
{
    if (grid[1] == grid[2] && grid[2] == grid[3])
        return 1;
    else if (grid[4] == grid[5] && grid[5] == grid[6])
        return 1;
    else if (grid[7] == grid[8] && grid[8] == grid[9])
        return 1;
    else if (grid[1] == grid[4] && grid[4] == grid[7])
        return 1;
    else if (grid[2] == grid[5] && grid[5] == grid[8])
        return 1;
    else if (grid[3] == grid[6] && grid[6] == grid[9])
        return 1;
    else if (grid[1] == grid[5] && grid[5] == grid[9])
        return 1;
    else if (grid[3] == grid[5] && grid[5] == grid[7])
        return 1;
    else if (grid[1] != '1' && grid[2] != '2' && grid[3] != '3' &&
             grid[4] != '4' && grid[5] != '5' && grid[6] != '6' && grid[7] != '7' &&
             grid[8] != '8' && grid[9] != '9')
        return 0;
    else
        return -1;
}

void squareBoard()
{
    printf("\033[1;31m");
    printf("\n\t\tTIC TAC TOE GAME \n\n\n");

    printf("\033[1;36m");
    printf("\tPlayer1 (X)  -  Player2 (0)\n\n");
    printf("\033[1;35m");

    printf("  ____________________\n");
    printf(" |      |       |     |\n");
    printf(" |  %c   |  %c    |  %c  |\n", grid[1], grid[2], grid[3]);

    printf(" |______|_______|_____|\n");
    printf(" |      |       |     |\n");

    printf(" |  %c   |  %c    |  %c  |\n", grid[4], grid[5], grid[6]);

    printf(" |______|_______|_____|\n");
    printf(" |      |       |     |\n");

    printf(" |  %c   |  %c    |  %c  |\n", grid[7], grid[8], grid[9]);
    printf(" |______|_______|_____|\n");
}
 
void pushMove(int move)
{
    if (moveCount < MAX_STACK_SIZE)
        moveHistory[moveCount++] = move;
}

int popMove()
{
    if (moveCount > 0)
        return moveHistory[--moveCount];
    else
        return -1; // Stack underflow
}

void printMoveHistory()

{
	int i;
    for (i = 0; i < moveCount; i++)
    {
        printf("%d ", moveHistory[i]);
    }
    printf("\n");
}
