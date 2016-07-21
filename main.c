// TIC TAC TOE
//
//By Ian Angillis
//
//
//If compiling in Visual Studio:
//project->Properties -> C/C++ -> Preprocessor -> Preprocessor Defintions -> edit _CRT_SECURE_NO_WARNINGS
//
//
//
#define EMPTY_VALUE '.'
#define MAX_ROWS 3
#define MAX_COLUMNS 3

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef char value;
typedef value ticTacToeGrid[MAX_COLUMNS][MAX_COLUMNS];

/*Function prototypes*/

void initField(ticTacToeGrid sample); //Initialises the field, can be seen as some sort of contructor
void printField(ticTacToeGrid sample, int player); //Prints the fiedl
bool isLegal(ticTacToeGrid sample, char cell, int player);//Checks wether a move is legal
char getCell();//Gets the cell from the player that is playing
bool isWinner(ticTacToeGrid sample);//Checks if there is a winner
void gongratulateWinner(int player);//Gongratulates the winner if there is a winner
void determineField(int *row, int *column, char cell);//Determines the specific field from the simplified input
void setField(ticTacToeGrid sample, int i, int j, int player);//Edits the board
bool isDraw(ticTacToeGrid sample);//Checks if there is a draw

int main(void)
{
	bool isDone;
	int player;
	char cell;
	int totalMoves;

	isDone = false;
	totalMoves = 0;
	player = 0;

	ticTacToeGrid sample;

	initField(sample);

	while (!isDone)//Gameloop
	{
		printField(sample, player);
		cell = getCell();

		while (!isLegal(sample, cell, player))
		{
			printf("Wrong input, plz try again\n");
			cell = getCell();
		}

		if (isWinner(sample))
		{
			printField(sample, player);
			gongratulateWinner(player);
			
			isDone = true;
		}

		if (isDraw(sample) && (isDone == false))
		{
			
			printf("It's a draw");
			printf("Program exiting");
			isDone = true;
		}

		++player;
		++totalMoves;
	}

	return 0;
}

void initField(ticTacToeGrid sample)
{
	for (int i = 0; i < MAX_ROWS; ++i)
	{
		for (int j = 0; j < MAX_COLUMNS; ++j)
		{
			sample[i][j] = EMPTY_VALUE;
		}
	}
}

/*Prints field*/
void printField(ticTacToeGrid sample, int player)
{
	/*Determine active player*/
	if ((player % 2) == 0)
		printf("Active Player: player 1\n");
	else
		printf("Active Player: player 2\n");

	printf("\nField\n");
	/*Print field*/
	for (int i = 0; i < MAX_ROWS; ++i)
	{
		printf("\n");
		for (int j = 0; j < MAX_COLUMNS; ++j)
		{
			printf("%c ", sample[i][j]);
		}
	}

	printf("\n\n");
}

char getCell()									//Field
{												// 1 2 3
	char cell;									// 4 5 6
												// 7 8 9
	printf("Enter location (1 - 9): ");
	cell = _getche();

	printf("\n");

	return cell;
}

bool isLegal(ticTacToeGrid sample, char cell, int player)
{
	int row;
	int column;

	determineField(&row, &column, cell);

	if (row == -1)
		return false;

	if (sample[row][column] != EMPTY_VALUE)
		return false;
	else
		setField(sample, row, column, player);
	return true;

}

void determineField(int *row, int *column, char cell)
{
	switch (cell)
	{
	case 49:
		*row = 0;
		*column = 0;
		break;

	case 50:
		*row = 0;
		*column = 1;
		break;

	case 51:
		*row = 0;
		*column = 2;
		break;

	case 52:
		*row = 1;
		*column = 0;
		break;

	case 53:
		*row = 1;
		*column = 1;
		break;

	case 54:
		*row = 1;
		*column = 2;
		break;

	case 55:
		*row = 2;
		*column = 0;
		break;

	case 56:
		*row = 2;
		*column = 1;
		break;

	case 57:
		*row = 2;
		*column = 2;
		break;

	default://Should never be reached
		printf("No cell found\n");
		*row = -1;
		*column = -1;
		break;
	}
}


void setField(ticTacToeGrid sample, int i, int j, int player)
{
	if ((player % 2) == 0)
		sample[i][j] = 'X';
	else
		sample[i][j] = 'O';
}

bool isWinner(ticTacToeGrid sample)//Hardcoded, needs improvement
{
	if (sample[0][0] == 'X' && sample[1][1] == 'X' && sample[2][2] == 'X')
		return true;

	else if (sample[0][0] == 'O' && sample[1][1] == 'O' && sample[2][2] == 'O')
		return true;

	else if (sample[0][2] == 'X' && sample[1][1] == 'X' && sample[2][0] == 'X')
		return true;

	else if (sample[0][2] == 'O' && sample[1][1] == 'O' && sample[2][0] == 'O')
		return true;

	else if (sample[0][0] == 'X' && sample[0][1] == 'X' && sample[0][2] == 'X')
		return true;

	else if (sample[0][0] == 'O' && sample[0][1] == 'O' && sample[0][2] == 'O')
		return true;

	else if (sample[1][0] == 'X' && sample[1][1] == 'X' && sample[1][2] == 'X')
		return true;

	else if (sample[1][0] == 'O' && sample[1][1] == 'O' && sample[1][2] == 'O')
		return true;

	else if (sample[2][0] == 'X' && sample[2][1] == 'X' && sample[2][2] == 'X')
		return true;

	else if (sample[2][0] == 'O' && sample[2][1] == 'O' && sample[2][2] == 'O')
		return true;

	else if (sample[0][0] == 'X' &&  sample[1][0] == 'X' && sample[2][0] == 'X')
		return true;

	else if (sample[0][0] == 'O' &&  sample[1][0] == 'O' && sample[2][0] == 'O')
		return true;

	else if (sample[0][1] == 'X' && sample[1][1] == 'X' && sample[2][1] == 'X')
		return true;

	else if (sample[0][1] == 'O' && sample[1][1] == 'O' && sample[2][1] == 'O')
		return true;

	else if (sample[0][2] == 'X' && sample[1][2] == 'X' && sample[2][2] == 'X')
		return true;

	else if (sample[0][2] == 'O' && sample[1][2] == 'O' && sample[2][2] == 'O')
		return true;

	else
		return false;
}

void gongratulateWinner(int player)
{
	if ((player % 2) == 0)
	{
		printf("Player 1 wins!\n");
	}

	else
	{
		printf("Player 2 wins!\n");
	}
}

bool isDraw(ticTacToeGrid sample)
{
	for (int i = 0; i < MAX_ROWS; ++i)
	{
		for (int j = 0; j < MAX_COLUMNS; ++j)
		{
			if (sample[i][j] == EMPTY_VALUE)
				return false;
		}
	}
	return true;
}