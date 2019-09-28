#include <stdio.h>

typedef enum {not_in_range, hot,normal,cold} Weather;
#define HOT "the weather was hot\n"
#define COLD "the weather was cold\n"
#define NORMAL "the weather was normal\n"
#define NUMBER_OF_SEASONS 4.0



int main(int argc, char* argv[]){
	int choose_mission='\n';
	char c1='0',c2='0',c3='0',c4='0';
	float temperature=0.0,temp1=0.0,temp2=0.0,temp3 = 0.0,temp4 = 0.0;
	int open_curly=0;
	int open_square=0;
	int var1,var2;
	char op='\n';
	float result=0;
	Weather rank= cold;
	printf("welcome to my program!\n please choose which mission you want to be done\n");
	scanf("%d", &choose_mission);
	switch(choose_mission){
		case 1:
			printf("please enter 4 characters:\n");
			getchar();
			c1=getchar();
			getchar();
			c2=getchar();
			getchar();
			c3=getchar();
			getchar();
			c4=getchar();
            if(c1 != 'a' && c1 != '(' && c1 != '[' && c1 != ')' && c1 != ']'){
				printf("Invalid Input");
				
			}
			if(c2 != 'a' && c2 != '(' && c2 != '[' && c2 != ')' && c2 != ']'){
				printf("Invalid Input");
				
			}
			if(c3 != 'a' && c3 != '(' && c3 != '[' && c3 != ')' && c3 != ']'){
				printf("Invalid Input");
				
			}
			if(c4 != 'a' && c4 != '(' && c4 != '[' && c4 != ')' && c4 != ']'){
				printf("Invalid Input");
				
			}
			if(c1 == ')' || c1 == ']' ){
				printf("Bad Structure");
				
			}
			if(c1 == '['){
					open_square++;
			}
			if(c1 == '('){
                open_curly++;
            }
			if(c2 == '['){
				if(open_square>0 || open_curly>0){
					printf("Bad Structure");
					
				}
				else{
					open_square++;
				}
			}
			if(c2 == ']'){
				if(open_square<1){
					printf("Bad Structure");
					
				}
				else{
					open_square--;
				}
			}
			if(c2 == ')'){
				if(open_curly<1){
					printf("Bad Structure");
					
				}
				else{
					open_curly--;
				}
			}
			if(c2 == '('){
				if(open_curly > 0){
					printf("Bad Structure");
					
				}
				else{
					open_curly++;
				}
			}
			if(c3 == '['){
				if(open_square>0){
					printf("Bad Structure");
				
				}
				else{
					open_square++;
				}
			}
			if(c3 == ']'){
				if(open_square<1){
					printf("Bad Structure");
					
				}
				else{
					open_square--;
				}
			}
			if(c3 == ')'){
				if(open_curly < 1){
					printf("Bad Structure");
					
				}
				else{
					open_curly--;
				}
			}
			if(c3 == '('){
				if(open_curly > 0){
					printf("Bad Structure");
					
				}
				else{
					open_curly++;
				}
			}
			if(c4 == '[' || c4 == '(' ){
				printf("Bad Structure");
				

			}
			if(c4 == ']'){
                    if(open_square<1){
                        printf("Bad Structure");
                        
                    }
				open_square--;
			}
			if(c4 == ')'){
                    if(open_curly<1){
                        printf("Bad Structure");
                       
                    }
				open_curly--;
			}
			if(open_curly!=0 || open_square!=0){
				printf("Bad Structure\n");
				
			}
			else{
                printf("OK\n");
            }

			break;
		case 2:
            printf("please enter number-operator-number\n");
            scanf("%d %c %d",&var1,&op,&var2);
            switch(op){
                    case '+':
                        result = var1 + var2;
                        printf("the result is: %7.2lf", result);
                        break;
                    case '-':
                        result = var1 - var2;
                        printf("the result is: %7.2lf", result);
                        break;
                    case '*':
                        result = var1 * var2;
                        printf("the result is: %7.2lf", result);
                        break;
                    case '/':
                        if(var2==0){
                            printf("Invalid Input\n");
                            return 0;
                        }
                        result = var1 / var2;
                        printf("the result is: %7.2lf", result);
                        break;
                    case '%':
                        if(var2==0){
                            printf("Invalid Input\n");
                            return 0;
                        }
                        result = var1 % var2;
                        printf("the result is: %7.2lf", result);
                        break;
                    default:
                        printf("invalid input\n");
                        break;
                }
			break;
		case 3:
			printf("please enter 4 numbers\n");
			scanf("%f %f %f %f", &temp1, &temp2, &temp3, &temp4);
			temperature=(temp1+temp2+temp3+temp4)/NUMBER_OF_SEASONS;
			if(temperature <= 37 && temperature >= 30){
				rank = hot;
			}
			else if(temperature < 30 && temperature >= 20){
				rank = normal;
			}
			else if(temperature >= 20 && temperature < 30){
				rank = cold;
			}
			else{
				rank = not_in_range;
			}
			switch(rank){
				case hot:
					printf(HOT);
					printf("estimated average: %7.2lf\n", temperature);
					break;
				case cold:
					printf(COLD);
					printf("estimated average: %7.2lf\n", temperature);
					break;
				case normal:
					printf(NORMAL);
					printf("estimated average: %7.2lf\n", temperature);
					break;
				default:
					printf("invalid input\n");
					break;
            }
            break;
		default:
            printf("you chose different option from the list. program ending...\n");
            break;
	}
	return 0;


}

