/******************************************
*Student name: name and family name
*Student ID:XXXX
*Submit Info:XXXX
*Exercise name: exXXXX
******************************************/ 

#include "Mission2.h"

/************************************************************************
 Fill comment
*************************************************************************/
int sweetCookies(int cookies[], int n, int K)
{
	// Complete..
}

/************************************************************************
 Fill comment
*************************************************************************/
void mission2()
{
	int n, sweet;
	int cookies[/*Complete..*/];
	int i;
	int result;

	printf("Please enter the amount of cookies:\n");
	scanf("%d", &n);
	printf("Please enter the minimum required sweetness:\n");
	scanf("%d", &sweet);

	for (i = 0; i < n; i++)
	{
		printf("Please enter cookie number %d:\n", i + 1);
		scanf("%d", &cookies[i]);
	}

	result = SweetCookies(cookies, n, sweet);
	printf("The number of operations that are needed is %d\n", result);
}