/******************************************
*Student name: name and family name
*Student ID:XXXX
*Submit Info:XXXX
*Exercise name: exXXXX
******************************************/ 

#include "Mission4.h"

/************************************************************************
 Fill comment
*************************************************************************/
void mission4()
{
	int n, m;
	long c;
	char board[/*Complete..*/][/*Complete..*/];

	printf("Please enter the number of rows (n):\n");
	scanf("%d", &n);
	printf("Please enter the number of columns (m):\n");
	scanf("%d", &m);
	printf("Please enter the number of iterations (c):\n");
	scanf("%ld", &c);
	printf("Please enter the board:\n");
    loadBoard(board, n, m);		// Reading the Board
	RunGame(n, m, c, board);
}

/************************************************************************
 Fill comment
*************************************************************************/
void runGame(int n, int m, long c, char board[][/*Complete..*/])
{
	/*Complete..*/
}

/************************************************************************
 Fill comment
*************************************************************************/
void loadBoard(char mat[][/*Complete..*/], int rows, int cols)
{
	// The Function reads from the IO and loads to the array
}