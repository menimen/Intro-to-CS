/******************************************
*Student name: name and family name
*Student ID:XXXX
*Submit Info:XXXX
*Exercise name: exXXXX
******************************************/

#include "Mission3.h"

/************************************************************************
* function name: CanAnagram 											*
* The Input: str - string containing a-z letters 						*
* The output: None														*
* The Function operation: check if the given string can be used as  	*
                          a palindrome                                  *
*************************************************************************/
void CanAnagram(char str[])
{
    int ABC[26] = {0};
	int stringLength = countStringLength(str);
	fillABCArray(ABC, str, stringLength);
	if(!checkIfPalindromeIsPossible(ABC, 26, (stringLength % 2))) {
        printf("the string ");
        printString(str);
        printf(" does not have a palindrome\n");
        return;
	}
    if (stringLength % 2 == 0) {
        dealWithEvenLengthString(ABC, str,  stringLength);
    }
    else {
        dealWithOddLengthString(ABC, str,  stringLength);
    }
}
void printString(char* ptr)
{
    while (*ptr != '\0') {
        printf("%c", (*ptr));
        ptr++;
    }
}
void dealWithEvenLengthString(int ABC[],char *str, int stringLength)
{
    char arr[MAXLENGTHOFSTRING] = {'\0'};
    printf("The string ");
    printString(str);
    printf(" has the palindrome ");
    int *ptr = ABC;
    int i = 0, j = stringLength -1, k = 0;
    while((i < j)) {
        if(*ptr > 0) {
            arr[i] = ((char) k + 'a');
            arr[j] = ((char) k + 'a');
            i++;
            j--;
            *ptr = (*ptr) - 2;
        }
        else {
            k++;
            ptr++;
        }
    }
    printString(arr);
    printf("\n");
}
void dealWithOddLengthString(int ABC[],char str[], int stringLength)
{
    int *ptr = ABC, trigger = 0, i = 0, j = stringLength - 1, k = 0;
    int oddLetter = findTheOddNumberOfOccurs(ABC, 26);
    char limit = oddLetter + 'a';
    ABC[oddLetter]--;
    char arr[MAXLENGTHOFSTRING] = {'\0'};
    printf("The string ");
    printString(str);
    printf(" has the palindrome ");
    while((i < j-1)) {
        if(((*ptr) % 2 != 0) && !trigger) {
            limit = ((char) k + 'a');
            trigger++;
            (*ptr)--;
        }
        if((*ptr) > 0) {
            arr[i] = ((char) k + 'a');
            arr[j] = ((char) k + 'a');
            i++;
            j--;
            *ptr = (*ptr) - 2;
        }
        else {
            k++;
            ptr++;
        }
    }
    arr[i] = limit;
    printString(arr);
    printf("\n");
}
int findTheOddNumberOfOccurs(int ABC[], int size)
{
    int i = 0;
    while(i < size) {
        if(ABC[i] % 2 != 0) {
            return i;
        }
        i++;
    }
    return 0;
}
void fillABCArray(int ABC[], char str[], int stringLength)
{
    int i = 0;
    char *ptr = str;
    while (i < stringLength) {
        ABC[((int)*ptr) - ((int)'a')]++;
        ptr++;
        i++;
    }
}
int checkIfPalindromeIsPossible(int ABC[], int size, int isnotEven)
{
    int *ptr = ABC;
    int i = 0, odd = 0;
    while (i < size) {
        if ((*ptr) % 2 !=0) {
            odd++;
        }
        ptr++;
        i++;
    }
    if(odd > 1) {
        return 0;
    }
    else if(odd < 1 && isnotEven == 1) {
        return 0;
    }
    else if((odd < 1 && isnotEven == 0) || (odd == 1 && isnotEven == 1) ) {
        return 1;
    }
    else {
        return 0;
    }
}

/************************************************************************
 Fill comment
*************************************************************************/
void mission3()
{
	char str[MAXLENGTHOFSTRING];
	printf("Please enter the string:\n");
	scanf("%s", str); // input the str
	CanAnagram(str);
}
int countStringLength(char str[])
{
    char *i = str;
    int size = 0;
    while (*i != '\0') {
        i++;
        size++;
    }
    return size;
}
