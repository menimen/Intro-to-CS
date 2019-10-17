/******************************************
*Student name: name and family name
*Student ID:XXXX
*Submit Info:XXXX
*Exercise name: exXXXX
******************************************/

#ifndef _MISSION3_H_
#define _MISSION3_H_
#include <stdio.h>
void CanAnagram(char str[]);
int countStringLength(char str[]);
void dealWithEvenLengthString(int ABC[], char str[], int stringLength);
void dealWithOddLengthString(int ABC[], char str[], int stringLength);
int checkIfPalindromeIsPossible(int ABC[], int size, int isnotEven);
void fillABCArray(int ABC[], char str[], int stringLength);
int findTheOddNumberOfOccurs(int ABC[], int size);
void printString(char* ptr);
void mission3();
#define MAXLENGTHOFSTRING 100
#endif
