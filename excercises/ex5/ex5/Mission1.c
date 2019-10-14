/******************************************
*Student name: name and family name
*Student ID:XXXX
*Submit Info:XXXX
*Exercise name: exXXXX
******************************************/

#include "Mission1.h"

void Mission1()
{
	int n, i=0, count = 0,toggle=0;
	char source[STRING_MAX_LENGTH], target[STRING_MAX_LENGTH];

	printf("Please enter the amount of pairs:\n");
	// Input the n
	scanf("%d", &n);
    if(n>=1 && n<=NUMBER_OF_PAIR_LIMIT){
            for (; i < n; i++){
                printf("Please enter the first string of pair %d:\n", i + 1);
                scanf("%s", target);
                if(!isValidString(target)){
                    toggle=1;
                    break;
                }
                printf("Please enter the second string pair %d:\n", i + 1);
                scanf("%s", source);
                if(!isValidString(source)){
                    toggle=1;
                    break;
                }
                count += isSemiSimilar(target, source);
            }
            if(toggle==0){
                printf("The amount of Semi-Similar strings is %d\n", count);
            }
    }

    else{
        return ;
    }
}

/************************************************************************
* function name: isSemiSimilar 											*
* The Input: target - The target string containing a-z letters 			*
* 			 source - The source string containing a-z letters			*
* The output: The function returns 1 or 0								*
* The Function operation: The function checks CharExistinSource(source, target[i])if target is 				*
*						   semi-similar to source 						*
*************************************************************************/
int isSemiSimilar(char target[], char source[])
{
    int i=0;
	if(strlen(target)!=strlen(source)){
        return 0;
	}
	else{
        while(i<strlen(target)){
            if(!CharExistinSource(target,source[i])){
                return 0;
            }
            i++;
        }
	}
	return 1;
}
int isValidString(char *str){
    int i=0;
    while(i<strlen(str)){
        if(str[i]<'a' || str[i]>'z'){
            return 0;
        }
        i++;
    }
    return 1;


}
int CharExistinSource(const char *target, char c){
    char *ptr=NULL;
    ptr=strchr(target,c);
    if(ptr==NULL){
        return 0;
    }
    ptr[0]='.';
    return 1;
}
