/******************************************
*Student name: name and family name
*Student ID:XXXX
*Submit Info:XXXX
*Exercise name: exXXXX
******************************************/

#ifndef _MISSION2_H_
#define _MISSION2_H_
#include <stdio.h>
void swap(int* a, int* b);
void quickSort(int arr[], int low, int high);
int findTheLimit(int arr[], int n, int K);
int SpecialCombineCookie(int num1, int num2);
int partition (int arr[], int low, int high);
void mission2();
int sweetCookies(int cookies[], int n, int K);
#define NUMOFCOOKIES 1000
#define BIGGESTSWEETNESSALLOWED 10*10*10*10
#define BIGGESTSWEETNESSOFCOOKIE 10*10*10*10*10
#endif
