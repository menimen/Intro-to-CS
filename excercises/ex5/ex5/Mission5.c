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
	char board[MAXBOARDSIZE][MAXBOARDSIZE], dummy;

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
	scanf("%c", &dummy);
	loadCastleBoard(board, n, n);		// Reading the Board
	result = getMinLength(board, startX, startY, goalX, goalY, n);	// Getting the Minimum Value
	if(result >= (n*n)) {
        result = -1;
	}
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
int getMinLength(char mat[][MAXBOARDSIZE], int startX, int startY, int goalX, int goalY, int n)
{
    return getMinLengthhelper(mat, startX, startY, goalX, goalY, n, 0);
}

int getMinLengthhelper(char mat[][MAXBOARDSIZE],int startX,int startY,int goalX,int goalY,int n, int count)
{
    if (startX == goalX && startY == goalY) {
        return count ;
    }
    if(startX < 0 || startX >= n || startY < 0 || startY >= n) {
        return n*n;
    }
    if (mat[startX][startY] == 'X' || mat[startX][startY] == 'V' ) {
        return n*n;
    }
    mat[startX][startY] = 'V';
    int path1 = getMinLengthhelper(mat, startX - 1, startY, goalX, goalY, n, count + 1);
    int path2 = getMinLengthhelper(mat, startX + 1, startY, goalX, goalY, n, count + 1);
    int path3 = getMinLengthhelper(mat, startX , startY - 1, goalX, goalY, n, count + 1);
    int path4 = getMinLengthhelper(mat, startX , startY + 1, goalX, goalY, n, count + 1);
    mat[startX][startY] = '_';
    if( Min(path1, path2, n) > Min(path3, path4, n)) {
            return Min(path3, path4, n);
    }
    else {
            return Min(path1, path2, n);
    }
}
int Min(int up, int down, int n)
{
    if (up < (n*n) && down < (n*n)) {
        if(up < down) {
            return up;
        }
        else {
            return down;
        }
    }
    else if (up >= (n*n) && down < (n*n)) {
        return down;
    }
    else {
        return up;
    }

}
/************************************************************************
 Fill comment
*************************************************************************/
void loadCastleBoard(char mat[][MAXBOARDSIZE], int rows, int cols)
{
	loadCastleBoardhelper(mat, 0, rows, cols);
}
void loadCastleBoardhelper(char mat[][MAXBOARDSIZE] ,int i, int rows, int cols)
{
    if (i == rows){
        return;
    }
    gets(mat[i]);
    mat[i][rows] = '\0';
    loadCastleBoardhelper(mat,i + 1, rows, cols);
}
void printBoardM(char mat[][MAXBOARDSIZE], int n)
{
    int i = 0, j = 0;
    for(;i<n;i++) {
        for(j = 0;j<n;j++){
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
}
