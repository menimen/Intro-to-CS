/******************************************
*Student name: name and family name
*Student ID:XXXX
*Submit Info:XXXX
*Exercise name: exXXXX
******************************************/

#ifndef _MISSION5_H_
#define _MISSION5_H_
#define MAXBOARDSIZE 25
#include <stdio.h>
void mission5();
void loadCastleBoard(char mat[][MAXBOARDSIZE], int rows, int cols);
int getMinLength(char mat[][MAXBOARDSIZE], int r, int c, int goalR, int goalC, int n);
int getMinLengthhelper(char mat[][MAXBOARDSIZE], int startX, int startY, int goalX, int goalY, int n, int count);
int Min(int up, int down, int n);
void loadCastleBoardhelper(char mat[][MAXBOARDSIZE],int i, int rows, int cols);
void printBoardM(char mat[][MAXBOARDSIZE], int n);
#endif
