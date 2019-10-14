/******************************************
*Student name: name and family name
*Student ID:XXXX
*Submit Info:XXXX
*Exercise name: exXXXX
******************************************/

#include "Mission1.h"

void mission1()
{
	int n, i, count = 0;
	char source[STRINGMAXLENGTH], target[STRINGMAXLENGTH];

	printf("Please enter the amount of pairs:\n");
	// Input the n
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("Please enter the first string of pair %d:\n", i + 1);
		scanf("%s", target);
		printf("Please enter the second string pair %d:\n", i + 1);
		scanf("%s", source);
		count += isSemiSimilar(target, source);
	}
	printf("The amount of Semi-Similar strings is %d\n", count);
}

/************************************************************************
* function name: isSemiSimilar 											*
* The Input: target - The target string containing a-z letters 			*
* 			 source - The source string containing a-z letters			*
* The output: The function returns 1 or 0								*
* The Function operation: The function checks if target is 				*
*						   semi-similar to source 						*
*************************************************************************/
int isSemiSimilar(char target[], char source[])
{
	int arr[26] = { 0 };
	int i, strLength = 0;
	for (i = 0; source[i] != '\0'; i++)
	{
		arr[(int)source[i] - (int)'a']++;
		strLength++;
	}
	for (i = 0; target[i] != '\0'; i++)
	{
		arr[(int)target[i] - (int)'a']--;
		strLength--;
	}
	//If target and source aren't of same length, return 0.
	if (strLength != 0)
		return 0;
	for (i = 0; i < 26; i++)
	{
		if (arr[i] != 0)
			return 0;
	}
	return 1;
}
