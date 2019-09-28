#include<stdio.h>
#include <ctype.h>
#include "ex2utils.h"
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
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;

    }

}
