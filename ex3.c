#include "stdio.h"
#define MAX_BASE 10
#define MIN_BASE 2
#define MAX_T 10*10*10*10*10*10*10
#define MIN_T 1
enum player{Louise, Richard};
int getclosestpowerof2(int i);
int checkamountofbits(int i);
int checkifkesparkynumber (int i);
int checkhowmanydigitsinnumber(int temp);
void missionthreekasperkynumber(int p, int q);
void missiontwocalculatefinalT(long int missiontwo_t, long int *finaltime);
long int mission1convertnumtobase10(long int num, int base);
long int mission1converttochosebase(long int num, int base);
int subtract(int x, int y);
int main() {
    //ex3 general variables
    int loop_trigger = 0, error_message_trigger = 1;
    //mission1 variables
    int i, mission1base;
    long int mission1num1, mission1num2, sum = 0, temp = 0, mission1num1afterconvert = 0, mission1num2afterconvert = 0;
    //missiontwo variables
    long int missiontwo_t = 0, missiontwo_finalvalue = 0;
    //missionthree variables
    int p = 0, q = 0;
    //missionfour variables
    int n = 0, closestpowerof2 = 0;
    enum player m = Louise;
    do {
        error_message_trigger = 1;
        printf("please choose what you want to do next: choose between 1-4\n");
        scanf("%d", &i);
        switch(i) {
            case 1:
                printf("please enter the wanted base:");
                scanf("%d", &mission1base);
                if(mission1base < MIN_BASE || mission1base > MAX_BASE) {
                    printf("The base %d is not between %d and %d\n", mission1base, MIN_BASE, MAX_BASE);
                    error_message_trigger = 0;
                }
                if(error_message_trigger) {
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
                break;
            case 2:
                printf("Please enter the time:\n");
                scanf("%ld", &missiontwo_t);
                if(missiontwo_t > MAX_T || missiontwo_t < MIN_T) {
                    printf("ERROR - The time %ld is invalid\n", missiontwo_t);
                    error_message_trigger = 0;
                }
                if(error_message_trigger) {
                        missiontwocalculatefinalT(missiontwo_t, &missiontwo_finalvalue);
                        printf("The time in the timer after %ld seconds is %ld \n",missiontwo_t, missiontwo_finalvalue);
                }
                break;
            case 3:
                printf("Please enter the lower limit of the range (p):\n");
                scanf("%d", &p);
                printf("Please enter the higher limit of the range (q):\n");
                scanf("%d", &q);
                if(p > q) {
                    printf("ERROR - The range %d to %d isn't valid\n", p, q);
                    error_message_trigger = 0;
                }
                if(error_message_trigger) {
                    missionthreekasperkynumber(p,q);
                }
                break;
            case 4:
                printf("Please enter the initial value for the game:\n");
                m = Louise;
                scanf("%d", &n);
                while (n >= 1) {
                    switch (m) {
                        case Richard:
                            printf("Richard : %d\n", n);
                            break;
                        case Louise:
                            printf("Louise : %d\n", n);
                            break;
                    }
                    closestpowerof2 = getclosestpowerof2(n);
                    if ( n == closestpowerof2) {
                        n = n >> 1;
                    }
                    else {
                        n = subtract(n, closestpowerof2);
                    }
                    m = m ^ 1;
                }
                switch (m) {
                    case Richard :
                        printf("The winner is: Richard\n");
                        break;
                    default :
                        printf("The winner is: Louise.\n");
                        break;
                }
                break;
            default :
                printf("you chose invalid option. program exiting\n");
                loop_trigger = 1;
        }
    }while (loop_trigger == 0);
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
void missiontwocalculatefinalT(long int missiontwo_t, long int *finalvalue) {
    int inital_value = 3, i = 1;
    *finalvalue = inital_value;
    while (i <= missiontwo_t ) {
        if((*finalvalue) == 0) {
            (*finalvalue) = inital_value * 2;
        }
        else {
            (*finalvalue)--;
        }
        i++;
    }
}
void missionthreekasperkynumber(int p, int q) {
    int i = p, k = 0, missiontrigger = 1;
    while (i <= q) {
        k = checkifkesparkynumber(i);
        if (k && missiontrigger) {
            printf("The numbers between %d and %d are:\n", p, q);
            missiontrigger = 0;
        }
        if (k) {
            printf("%d\n", i);
        }
        i++;
        }
    if (missiontrigger) {
        printf("NO NUMBERS BETWEEN %d AND %d\n", p, q);
    }
}
int checkhowmanydigitsinnumber(int temp) {
    int i = 0;
    while (temp > 0) {
        i++;
        temp = temp / 10;
    }
    return i;
}
int checkifkesparkynumber (int i) {
    int j = 0, r = 0, k = 0, z = 1;
    if ( i == 0) {
        return 0;
    }
    r = checkhowmanydigitsinnumber(i);
    k = i * i;
    while ( k > 0 && r > 0 ) {
        j = j + (k % 10) * z;
        z = z * 10;
        k = k / 10;
        r--;
    }
    if ( k + j == i ) {
        return 1;
    }
    return 0;
}
int subtract(int x, int y) {
    return x ^ y;
}
int checkamountofbits(int i) {
    int count = 0;
    while (i > 0) {
        i = i >> 1;
        count ++;
    }
    return count;
}
int getclosestpowerof2(int i) {
    int mask = 1;
    int count = checkamountofbits(i);
    while ( count > 1) {
        mask = mask << 1;
        count--;
    }
    return mask;
}
