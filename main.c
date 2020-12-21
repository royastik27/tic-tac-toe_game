/**
* Tic-Tac-Toe Game
* Author: Astik Roy
* Date: 07-05-2020
**/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

_Bool win = 0;
int player = 0, gamecount = 0, entry[9]={0};
char ara[9] = "123456789";

void checkForWin()
{
    if( (ara[0]==ara[1] && ara[1]==ara[2]) || (ara[3]==ara[4] && ara[4]==ara[5]) || (ara[6]==ara[7] && ara[7]==ara[8]) )
        win = 1;
    else if( (ara[0]==ara[3] && ara[3]==ara[6]) || (ara[1]==ara[4] && ara[4]==ara[7]) || (ara[2]==ara[5] && ara[5]==ara[8]) )
        win = 1;
    else if( (ara[0]==ara[4] && ara[4]==ara[8]) || (ara[2]==ara[4] && ara[4]==ara[6]) )
        win = 1;
}

void effectChoice(int n)
{
    if(player == 1)
        ara[n-1] = 'O';
    else
        ara[n-1] = 'X';
}

int checkEntry(int n)
{
    if(entry[n-1] || n<1 || n>9)
        return 1;
    else
    {
        entry[n-1]=1;
        return 0;
    }
}

void playerChoice()
{
    if(player == 1)
        player = 2;
    else
        player = 1;
}

void displayBoard()
{
    int i;

    printf("\n\t%c%c%c ROYASTIK TIC-TAC-TOE GAME %c%c%c\n", 219, 219, 219, 219, 219, 219);
    printf("\t__________________________________\n");

    printf("\tPlayer 1 = O\t      Player 2 = X\n\n");

    for(i = 0; i<=3; i+=3)
    {
        printf("\t\t%c | %c | %c\n", ara[i], ara[i+1], ara[i+2]);
        printf("\t     _____|___|_____\n");
    }
    printf("\t\t%c | %c | %c\n", ara[i], ara[i+1], ara[i+2]);
    printf("\t          |   |     \n");
}

int main()
{
    int number;

    system("title ROYASTIK TIC-TAC-TOE GAME");
    system("cls");

    displayBoard();

    level:

    playerChoice();

    again:
    printf("\nPlayer %d %c Enter Number: ", player, 175);
    scanf("%d", &number);

    if(checkEntry(number))
    {
        printf("Invalid Entry!");
        goto again;
    }

    effectChoice(number);

    system("cls");
    displayBoard();

    checkForWin();

    gamecount++;

    if(win == 1)
    {
        printf("\n\aCongrats!! Player %d wins !!!\n\n", player);
        //return 0;
    }
    else
    {
        if(gamecount == 9)
        {
            printf("\n\aDraw!! Nobody wins!\n\n");
        }
        else
            goto level;
    }

    printf("Press any key to exit...");
    getch();

    return 0;
}
