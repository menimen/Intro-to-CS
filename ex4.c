#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX_N 10*10*10
#define MIN_N 1
#define MAX_NUM 10*10*10*10*10*10*10*10*10
#define MIN_NUM 1
#define MIN_MISSIONTWO_N 0
#define MAX_MISSIONTWO_N 300
int Contains(int* a, int* b);
int DeterminePath(int number, int count);
int countSteps(int number, int step);
int FindDivider(int num, int divider);
int main() {
	//ex4 general variables
	int loop_trigger = 0, error_message_trigger = 1, i = 0;
	//mission1
	int N = 0, a = 0, b = 0, j = 1, total_numbers = 0;
	//mission2
	int num = 0;
	do {
		error_message_trigger = 1;
		printf("please choose what you want to do next: choose between 1-4\n");
		scanf_s("%d", &i);
		switch (i) {
		case 1:
			total_numbers = 0;
			printf("Please enter the number of pairs:\n");
			(void)scanf("%d", &N);
			while (j <= N) {
				printf("Please enter the larger number of pair %d (a):\n", j);
				(void)scanf("%d", &a);
				printf("Please enter the smaller number of pair %d (b) :\n", j);
				(void)scanf("%d", &b);
				if (Contains(&a, &b)) {
					total_numbers++;
				}
				j++;
			}
			printf("The number of pairs satisfying the condition is: %d\n", total_numbers);
			break;
		case 2:
			printf("enter number\n");
			(void)scanf("%d", &num);
			printf("The sequence of numbers produced by the actions is:\n");
			num = DeterminePath(num, 0);
			printf("the shortest route is %d\n", num);
			break;
		case 3:
			
			break;
		case 4:
			
			break;
		default:
			printf("you chose invalid option. program exiting\n");
			loop_trigger = 1;
		}
	} while (loop_trigger == 0);
	return 0;
}
int Contains(int* a, int* b) {
	int j = 0, temp = 0, exponent = 1;
	temp = *b;
	while (temp > 0) {
		j++;
		temp = temp / 10;
	}
	while (j > 0) {
		exponent *= 10;
		j--;
	}
	while ((*a) > 0 ) {
		if ((*a) % exponent == *b) {
			return 1;
		}
		(*a) /= exponent;
	}
	return 0;
}
int DeterminePath(int number, int count) {
	if (number == 0) {
		return count;
	}
	if (FindDivider(number, 2) == -1) {
		printf("%d\n", number - 1);
		return DeterminePath(number - 1, ++count);
	}
	if (countSteps(number-1, 0) >= countSteps(FindDivider(number, 2), 0)) {
		printf("%d\n", FindDivider(number, 2));
		return DeterminePath(FindDivider(number, 2), ++count);
	}
	else {
		printf("%d\n", number - 1);
		return DeterminePath(number-1, ++count);
	}
}
int countSteps(int number, int step) {
	if (number == 0) {
		return step;
	}
	if (FindDivider(number, 2) == -1) {
		return countSteps(number - 1, step+1);
	}
	if (countSteps(number - 1, 0) >= countSteps(FindDivider(number, 2), 0)) {
		return countSteps(FindDivider(number, 2), step+1);
	}
	else {
		return countSteps(number - 1, step+1);
	}
}
int FindDivider(int num, int divider) {
	if (divider >= num) {
		return -1;
	}
	if (num % divider == 0) {
		return num / divider;
	}
	else {
		return FindDivider(num, divider + 1);
	}
}
