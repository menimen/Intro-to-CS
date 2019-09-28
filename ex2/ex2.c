#include<stdio.h>
#include <ctype.h>
#include <string.h>
#include "ex2utils.h"
void mission1();
void mission2();
void mission3();
void main() {
    int choose = 4;
    char buf[Max];
    printf("welcome to my program\n");
    printf("please type down your option to what to do next: 1-perform mission 1, 2-perform mission 2, 3-perform mission 3\n");
    fgets(buf, Max, stdin);
    if(isdigit(buf[0])) {
        choose = buf[0] - '0';
    }
    switch(choose) {
        case 1:
            mission1();
            break;
        case 2:
            mission2();
            break;
        case 3:
            mission3();
            break;
        default:
            break;

    }

}
void mission1() {
    char str[Max];
    int i = 0,count = 0,trigger = 0, squaretrigger = 0, brackettrigger = 0;
    printf("Please enter four chars:\n");
    fgets(str, Max, stdin);
    for (i = 0; str[i]!='\n'; i++)  {//trim string from spaces
        if (str[i] != ' '){
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
    count = 0;
    if(strlen(str)!= 4) {//check that only 4 characters entered
        printf("Bad structure\n");
        printf("%d", strlen(str));
        trigger++;
    }
    for (i = 0; str[i] && trigger == 0; i++)  {
        if (str[i] == 'a' || str[i] == '[' || str[i] == ']' || str[i] == '(' || str[i] == ')'){
            count++;
        }
    }
    if(count != (strlen(str)) && trigger == 0) {
        printf("bad input\n");
        trigger = 1;
    }
    if(trigger == 0) {
            for(i = 0; str[i]!='\0' && trigger == 0; i++) {
                if(str[i] == '[') {
                    if (squaretrigger > 0 || brackettrigger > 0) {
                        printf("bad structure\n");
                        trigger++;
                    }
                    else {
                        squaretrigger++;
                    }
                }
                if(str[i] == '(') {
                    if(brackettrigger > 0) {
                        printf("bad structure\n");
                        trigger++;
                    }
                    brackettrigger++;
                }
                if(str[i] == ')') {
                    if(brackettrigger > 0) {
                        brackettrigger--;
                    }
                    else {
                        printf("bad structure\n");
                        trigger++;
                    }
                }
                if(str[i] == ']') {
                    if(squaretrigger > 0) {
                        squaretrigger--;
                    }
                    else {
                        printf("bad structure\n");
                        trigger++;
                    }
                }
        }
        if((brackettrigger > 0 || squaretrigger > 0) && trigger == 0) {
            printf("bad structure\n");
            trigger++;
        }
        if(trigger == 0){
            printf("OK");
        }
    }
}
void mission2() {

return;
}
void mission3() {
return;

}
