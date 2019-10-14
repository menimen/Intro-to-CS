/******************************************
*Student name: name and family name
*Student ID:XXXX
*Submit Info:XXXX
*Exercise name: exXXXX
******************************************/ 

#include "Mission5.h"

/************************************************************************
 Fill comment
*************************************************************************/
void mission5()
{
	int n;
	char board[/*Complete..*/][/*Complete..*/];

	int startX, startY, goalX, goalY, result;

	printf("Please enter the number of rows and columns (n):\n");
	scanf("%d", &n);
	printf("Please enter the X of the starting position:\n");
	scanf("%d", &startX);
	printf("Please enter the Y of the starting position:\n");
	scanf("%d", &startY);
	printf("Please enter the X of the goal position:\n");
	scanf("%d", &goalX);
	printf("Please enter the Y of the goal position:\n");
	scanf("%d", &goalY);
	printf("Please enter the grid:\n");
	loadCastleBoard(board, n, n);		// Reading the Board

	result = getMinLength(board, startX, startY, goalX, goalY, n);	// Getting the Minimum Value
	if (result != -1)
	{
		printf("The maximum number of steps is %d\n", result);
	}
	else
	{
		printf("No path was found from (%d,%d) to (%d,%d)\n", startX, startY, goalX, goalY);
	}
}

/************************************************************************
 Fill comment
*************************************************************************/
int getMinLength(char mat[][/*Complete..*/], int startX, int startY, int goalX, int goalY, int n)
{
	
}


/************************************************************************
 Fill comment
*************************************************************************/
void loadCastleBoard(char mat[][/*Complete..*/], int rows, int cols)
{
	// The Function reads from the IO and loads to the array
}
