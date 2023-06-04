#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

char board[10]={'o','1','2','3','4','5','6','7','8','9'};
int win();
void makeBoard();

int main()
{
    int player=1, i;
    int opt;
    char marker;
    printf("\n\n\t Tic Tac Toe \n\n");
    do
    {
        makeBoard(); //drawing the board first
        player = (player % 2) ? 1: 2;
        printf("Player %d enter the choice: ", player);
        scanf("%d", &opt);
        marker = (player == 1) ? 'X': 'O';
        if(opt == 1 && board[1] == '1')
        {
            board[1] = marker;
        }
        else if(opt == 2 && board[2] == '2')
        {
            board[2] = marker;
        }
        else if(opt == 3 && board[3] == '3')
        {
            board[3] = marker;
        }
        else if(opt == 4 && board[4] == '4')
        {
            board[4] = marker;
        }
        else if(opt == 5 && board[5] == '5')
        {
            board[5] = marker;
        }
        else if(opt == 6 && board[6] == '6')
        {
            board[6] = marker;
        }
        else if(opt == 7 && board[7] == '7')
        {
            board[7] = marker;
        }
        else if(opt == 8 && board[8] == '8')
        {
            board[8] = marker;
        }
        else if(opt == 9 && board[9] == '9')
        {
            board[9] = marker;
        }
        else
        {
            printf("That option is not valid!");
            player--;
        }
        i = win();
        player++;
    } while (i == -1);
    makeBoard();
	if(i==1)
	{
		printf("==>Player %d wins!",--player);
	}
	else 
	{
		printf("==>Game drawn");
	}
		return 0;
}
int win()
{
	if(board[1] == board[2] && board[2] == board[3])
		{
            return 1;
        }
	else if (board[4] == board[5] && board[5] == board[6])
		{
            return 1;
        }
	else if(board[7] == board[8] && board[8] == board[9])
		{
            return 1;
        }
	else if(board[1] == board[4] && board[4] == board[7])
		{
            return 1;
        }
	else if(board[2] == board[5] && board[5] == board[8])
		{
            return 1;
        }
	else if(board[3] == board[6] && board[6] == board[9])
		{
            return 1;
        }
	else if(board[1] == board[5] && board[5] == board[9])
		{
            return 1;
        }
	else if(board[3] == board[5] && board[5] == board[7])
		{
            return 1;
        }
	else if(board[1] != '1' && board[2] != '2' && board[3] != '3' && board[4] !='4' && board[5] != '5' && board[6] != '6' && board[7] != '7' && board[8] != '8' && board[9] != '9')
		{
            return 0; //to check if game has been drawn
        }
	else 
		{
            return -1;
        }	
}
void makeBoard()
{
	printf("Player1 (X) - Player2 (O) \n\n\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",board[1],board[2],board[3]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",board[4],board[5],board[6]);
	printf("_____|_____|_____\n");
	printf("     |     |     \n");
	printf("  %c  |  %c  |  %c  \n",board[7],board[8],board[9]);
	printf("     |     |     \n");	
}