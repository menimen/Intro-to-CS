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
	char board[MAXROWSIZE][MAXCOLSIZE];

	printf("Please enter the number of rows (n):\n");
	scanf("%d", &n);
	printf("Please enter the number of columns (m):\n");
	scanf("%d", &m);
	printf("Please enter the number of iterations (c):\n");
	scanf("%ld", &c);
	printf("Please enter the board:\n");
    loadBoard(board, n, m);		// Reading the Board
	runGame(n, m, c, board);
}

/************************************************************************
 Fill comment
*************************************************************************/
void runGame(int n, int m, long c, char board[][MAXCOLSIZE])
{
	int i = 0, boardEmpty = 0;
	while (c > 0 && !boardEmpty) {
        TransitionTime(board, n, m);
        if(!drawBoard(board, n, m)) {
            boardEmpty++;
        }
        i++;
        c--;
	}
	printf("The board after %d iterations is:\n", i);
	printBoard(board, n, m);
}
void TransitionTime(char mat[][MAXCOLSIZE], int rows, int cols)
{
    int aliveNeighbors = 0;
    int i = 0, j = 0;
    for(i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            aliveNeighbors = checkHowManyNeighborsAlive(mat, i, j, rows, cols);
            if ((mat[i][j] == LIVECELL) ) {
                if(aliveNeighbors < 2) {
                    mat[i][j] = DEADNEXTROUNDCELL;
                }
                else if (aliveNeighbors > 3) {
                    mat[i][j] = DEADNEXTROUNDCELL;
                }
            }
            else {
                if (aliveNeighbors == 3) {
                    mat[i][j] = LIVENEXTROUNDCELL;
                }
            }
        }
	}
}
int checkHowManyNeighborsAlive(char mat[][MAXCOLSIZE], int i, int j, int rows, int cols)
{
    int count = 0;
    if (FindLife(mat, i - 1, j, rows, cols)) {
        count++;
    }
    if (FindLife(mat, i + 1, j, rows, cols)) {
        count++;
    }
    if (FindLife(mat, i, j - 1, rows, cols)) {
        count++;
    }
    if (FindLife(mat, i, j + 1, rows, cols)) {
        count++;
    }
    if (FindLife(mat, i + 1, j + 1, rows, cols)) {
        count++;
    }
    if (FindLife(mat, i - 1, j + 1, rows, cols)) {
        count++;
    }
    if (FindLife(mat, i - 1, j - 1, rows, cols)) {
        count++;
    }
    if (FindLife(mat, i + 1, j - 1, rows, cols)) {
        count++;
    }
    return count;
}
int FindLife(char mat[][MAXCOLSIZE], int i, int j, int rows, int cols)
{
    if(i < 0 ) {
        i = rows - 1;
    }
    if(i == rows ) {
        i = 0;
    }
    if(j < 0 ) {
        j = cols - 1;
    }
    if(j == cols ) {
        j = 0;
    }
    if(mat[i][j] == '*' || (mat[i][j] == DEADNEXTROUNDCELL)) {
        return 1;
    }
    return 0;
}
int drawBoard(char mat[][MAXCOLSIZE], int rows, int cols)
{
    int i,j, alivecells = 0;
    char c;
    for(i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            c = mat[i][j];
            switch (c) {
                case '_' :
                    break;
                case '*' :
                    alivecells++;
                    break;
                case '#' :
                    mat[i][j] = '*';
                    alivecells++;
                    break;
                case '-' :
                    mat[i][j] = '_';
                    break;
            }
        }
	}
	return alivecells;
}
/************************************************************************
 Fill comment
*************************************************************************/
void loadBoard(char mat[][MAXCOLSIZE], int rows, int cols)
{
    char dummy = '0';
    char buf[MAXROWSIZE] = {'\0'};
    scanf("%c", &dummy);
	int i,j;
	for(i = 0; i < rows; i++) {
        char *ptr = buf;
        gets(buf);
        remove_spaces(buf);
        for (j = 0; j < cols; j++) {
            mat[i][j] = (*ptr);
            ptr++;
        }
        printf("\n");
	}
}
void remove_spaces(char* input)
{
    int c=0,j=0;
    while(input[c]!='\0'){
        if(input[c]!=' '){
            input[j++]=input[c];
        }
        c++;
    }
    input[j]='\0';
}
void printBoard(char mat[][MAXCOLSIZE], int rows, int cols)
{
	int i,j;
	char c;
	for(i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            c = mat[i][j];
            switch (c) {
                case '_' :
                    printf("%c", '_');
                    printf(" ");
                    break;
                case '*' :
                    printf("%c", '*');
                    printf(" ");
                    break;
            }
        }
        printf("\n");
	}
}
