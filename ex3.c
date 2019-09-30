#include "stdio.h"
#define MAX_BASE 10
#define MIN_BASE 2
long int mission1convertnumtobase10(long int num, int base);
long int mission1converttochosebase(long int num, int base);
int main()
{
    int i, trigger = 1, mission1base;
    long int mission1num1, mission1num2, sum = 0, temp = 0, mission1num1afterconvert = 0, mission1num2afterconvert = 0;
    do {
            trigger = 1;
        printf("please choose what you want to do next: choose between 1-4\n");
        scanf("%d", &i);
        switch(i) {
            case 1:
                printf("please enter the wanted base:");
                scanf("%d", &mission1base);
                if(mission1base < MIN_BASE || mission1base > MAX_BASE) {
                    printf("The base %d is not between %d and %d\n", mission1base, MIN_BASE, MAX_BASE);
                }
                if(trigger) {
                    printf("Please enter the first number in base %d:", mission1base);
                    scanf("%ld", &mission1num1);
                    printf("Please enter the second number in base %d:", mission1base);
                    scanf("%ld", &mission1num2);
                    mission1num1afterconvert = mission1convertnumtobase10(mission1num1, mission1base);
                    mission1num2afterconvert = mission1convertnumtobase10(mission1num2, mission1base);
                    sum = mission1num1afterconvert + mission1num2afterconvert;
                    temp = mission1converttochosebase(sum, mission1base);
                    printf("The result of %ld + %ld in base %d is %ld \n", mission1num1, mission1num2, mission1base, temp);
                }
                trigger = 0;
                break;
            case 2:
            case 3:
            case 4:
            default :
                printf("you chose invalid option. program exiting\n");

        }
    }while (trigger == 0);
}
long int mission1convertnumtobase10(long int num, int base) {
    int numbase = base, j =0;
    long int sum = 0.0;
    while (num > 0) {
                        if( j == 0) {
                            sum = sum + ((num % 10)*1);
                        }
                        else if ( j == 1 ) {
                            sum = sum + ((num % 10)*base);
                        }
                        else {
                            numbase = numbase * base;
                            sum = sum + ((num % 10) * numbase);
                        }
                        num = num / 10;
                        j++;
                    }
    return sum;
}
long int mission1converttochosebase(long int num, int base) {
    long int sum = 0.0;
    int i = 1;
    while (num > 0) {
        sum = sum  + (num % base) * i;
        num = num / base;
        i = i * 10;
    }
    return sum;
}
