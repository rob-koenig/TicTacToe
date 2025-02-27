#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
//Uncomment the next line for raspberry pi
//#include "framebuffer.h"

//showBoard:	Prints the entire tic-tac-toe-board
//Parameters:	board: A pointer to an array of 9 characters representing the tic-tac-toe board.
//					Legal values for each entry are ' ','X','O'
//Returns:		None				
void showBoard(char *board)
{	
	printf("   |   |   \n %c | %c | %c \n   |   |   \n-----------\n   |   |   \n %c | %c | %c \n   |   |   \n-----------\n   |   |   \n %c | %c | %c \n   |   |   \n", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);
}

//getMove:		Processes a player move
//Paramters:	board: A pointer to an array of 9 characters representing the tic-tac-toe board.
//					Legal values for each entry are ' ','X','O'
//				player: The symbol for the current player (X for 1,O for 2)
//Returns:		None
//Note:			Only accepts input between 1 and 9 for the move.  Only allows input if current space in board is empty (' ')
void getMove(char *board, char playerSymbol)
{
	char buffer[255];
	int input;
	printf("Enter a position from 1-9 player %d: ", playerSymbol); 
	scanf("%s",buffer);
	sscanf(buffer,"%d",&input);
	//while (isdigit(input) == false){
	//	printf("\nEnter numbers only: ");
        //        scanf("%s",buffer);
        //        sscanf(buffer,"%d",&input);
	//}
	while ((input) < 1 || (input) > 9){
		printf("\nEnter a valid position: ");
                scanf("%s",buffer);
                sscanf(buffer,"%d",&input);
	}
	while (board[input-1] != ' '){
		printf("\nPosition already taken, try again: ");
                scanf("%s",buffer);
                sscanf(buffer,"%d",&input);
	}
	board[input-1] = playerSymbol;
			
}

//checkWin: checks the board to see if there is a win for the given player
//Parameters:	board: A pointer to an array of 9 characters representing the tic-tac-toe board.
//					Legal values for each entry are ' ','X','O'
//				playerSymbol: The symbol for the player being checked for a win ('X','O')
//Returns: 		non-zero if a win occurs for playerSymbol, zero otherise
int checkWin(char *board, char playerSymbol)
{
	if (board[0] == playerSymbol && board[1] == playerSymbol && board[2] == playerSymbol){
		return 1;
	} else if (board[3] == playerSymbol && board[4] == playerSymbol && board[5] == playerSymbol){
		return 1;
	} else if (board[6] == playerSymbol && board[7] == playerSymbol && board[8] == playerSymbol){
                return 1;
        } else if (board[0] == playerSymbol && board[3] == playerSymbol && board[6] == playerSymbol){
                return 1;
        } else if (board[1] == playerSymbol && board[4] == playerSymbol && board[7] == playerSymbol){
                return 1;
        } else if (board[2] == playerSymbol && board[5] == playerSymbol && board[8] == playerSymbol){
                return 1;
        } else if (board[0] == playerSymbol && board[4] == playerSymbol && board[8] == playerSymbol){
                return 1;
        } else if (board[2] == playerSymbol && board[4] == playerSymbol && board[6] == playerSymbol){
                return 1;
        } else {
		return 0;
	}
}

//checkBoard: checks the board to see if the game is over
//Parameters:	board: A pointer to an array of 9 characters representing the tic-tac-toe board.
//					Legal values for each entry are ' ','X','O'
//				winner: A pointer to an integer to accept the current winner.  0 indicates no winner, otherwise it is the player number
//Returns:		0 if the game is over, non-zero if the game should continue.  Game is over if a player wins, or there are no more valid moves.
int checkBoard(char *board, int *winner)
{
	if (checkWin(board, 'X'))
	{
		*winner = 1;
		return 0;
	}
	if (checkWin(board, 'O'))
	{
		*winner = 2;
		return 0;
	}
	int spaceCount = 0;
	for (int i = 0; i < 9; i++)
	{
		if (board[i] == ' ')
		{
			spaceCount++;
		}
	}
	return spaceCount;
}

int main(int argc, char **argv)
{
	//char board[10] = {' ', ' ', ' ', ' ', ' ', ' ',  ' ', ' ', ' ', ' '};
    	//char symbols[3] = {' ','X','O'};
    	//int player=2;
    	//showBoard(board); 
    	//for (int i=0;i<9;i++){
        //	player = (player++) % 2 + 1;
        //	getMove(board, symbols[player]);
        //	showBoard(board);
    	//}
    	//return 0;
	char board[9] = {' ', ' ', ' ', ' ', ' ', ' ',  ' ', ' ', ' '};
	char symbols[3]={' ','X','O'};
	int player = 2;
	int winner = 0;
	int running = 1;
	while (running)
	{
		player = (player++) % 2 + 1;
		showBoard(board);
		getMove(board, symbols[player]);
		running = checkBoard(board, &winner);
	}
	showBoard(board);
	if (winner!=0){
		printf("Congratulations player %d!!! You win.\n",player);
	}else{
		printf("It's a tie!!!\n");
	}
	return 0;
}
