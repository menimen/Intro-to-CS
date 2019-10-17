/******************************************
*Student name: name and family name
*Student ID:XXXX
*Submit Info:XXXX
*Exercise name: exXXXX
******************************************/

#ifndef _MISSION4_H_
#define _MISSION4_H_
#include <stdio.h>
#define MAXROWSIZE 25
#define MAXCOLSIZE 25
#define MAXITERATIONNUMBER 10*10*10*10*10
typedef enum{dead, alive, willcomealivenextround, willbedeadnextround}cells;
#define DEADCELL '_'
#define LIVECELL '*'
#define LIVENEXTROUNDCELL '#'
#define DEADNEXTROUNDCELL '-'
void runGame(int n, int m, long c, char board[][MAXCOLSIZE]);
void mission4();
void loadBoard(char mat[][MAXCOLSIZE], int rows, int cols);
void TransitionTime(char mat[][MAXCOLSIZE], int rows, int cols);
int checkHowManyNeighborsAlive(char mat[][MAXCOLSIZE], int i, int j, int rows, int cols);
int FindLife(char mat[][MAXCOLSIZE], int i, int j, int rows, int cols);
int drawBoard(char mat[][MAXCOLSIZE], int rows, int cols);
void printBoard(char mat[][MAXCOLSIZE], int rows, int cols);
void remove_spaces(char* s);
#endif
