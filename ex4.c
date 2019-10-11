#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX_N 10*10*10
#define MIN_N 1
#define MAX_NUM 10*10*10*10*10*10*10*10*10
#define MIN_NUM 1
#define MIN_MISSIONTWO_N 0
#define MAX_MISSIONTWO_N 300
#define Rock "Rock"
#define Paper "Paper"
#define Spock "Spock"
#define Scissor "Scissor"
#define Lizard "Lizard"
typedef enum{ROCK = 0,PAPER = 1,SCISSOR = 2,LIZARD = 3,SPOCK = 4}shape;
int Contains(long int num, int* b);
int DeterminePath(int number, int count);
int countSteps(int number, int step);
int FindDivider(int num, int divider);
int XORWizard(long int *num, long int i);
int RockPaperScissorSpockGame(shape Alice, shape Bob, int rounds, int* alicewin, int* tie, int* alicelost);
shape AliceMove(int current_result, shape Alice_previous_move, shape Bob_previous_move);
shape BobMove(int current_result, int* isChosenSpock);
void printMatchResults(int winner_round, shape Alice, shape Bob);
int RockPaperScissorSpockMatch(shape first_opponent, shape second_opponent);
shape choosewhatisAliceShapeAfterLossOrTie(shape previous_move);
int main() {
	//ex4 general variables
	int loop_trigger = 0, i = 0;
	//mission1
	int N = 0, a = 0, b = 0, j = 1, total_numbers = 0;
	//mission2
	int num = 0;
	//mission3
	long int missiontroundshreeNum = 0;
	int count = 0;
	//mission4
	int Alice = 0, Bob = 0, rounds = 0, alicewin = 0, tie = 0, alicelost = 0, winner = 0;

	do {
		printf("please choose what you want to do next: choose between 1-4\n");
		scanf("%d", &i);
		switch (i) {
		case 1:
			j = 1;
			total_numbers = 0;
			printf("Please enter the number of pairs:\n");
			(void)scanf("%d", &N);
			while (j <= N) {
				printf("Please enter the larger number of pair %d (a):\n", j);
				(void)scanf("%d", &a);
				printf("Please enter the smaller number of pair %d (b) :\n", j);
				(void)scanf("%d", &b);
				if (Contains(a, &b)) {
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
			int temp = DeterminePath(num, 0);
			printf("the shortest route is %d\n", temp);
			break;
		case 3:
			printf("Please enter the number:\n");
			scanf("%ld", &missiontroundshreeNum);
			printf("The numbers are :\n");
			count = XORWizard(&missiontroundshreeNum, 1);
			printf("A total of %d numbers \n", count);
			break;
		case 4:
            winner = 0;
		    alicewin = 0;
		    alicelost = 0;
		    tie = 0;
		    printf("Please enter the shape Alice chose:\n");
		    scanf("%d", &Alice);
		    printf("Please enter the shape Bob chose:\n");
		    scanf("%d", &Bob);
		    printf("Please enter the number of rounds:\n");
		    scanf("%d", &rounds);
		    winner = RockPaperScissorSpockGame(Alice, Bob, rounds, &alicewin, &tie, &alicelost);
		    switch(winner) {
                case 1 :
                    printf("Alice wins, by winning %d game(s) and tying %d game(s)\n",alicewin, tie);
                    break;
                case -1 :
                    printf("Bob wins, by winning %d game(s) and tying %d game(s)\n",alicelost, tie);
                    break;
                default :
                    printf("Alice and Bob tie, each winning %d game(s) and tying %d game(s)\n",alicewin, tie);
                    break;
		    }
			break;
		default:
			printf("you chose invalid option. program exiting\n");
			loop_trigger = 1;
		}
	} while (loop_trigger == 0);
	return 0;
}
int Contains(long int num, int* b) {
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
	while (num > exponent ) {
		if (num % exponent == *b) {
			return 1;
		}
		num /= 10;
	}
	if (num % exponent == 0) {
        return 1;
	}
	else {
        return 0;
	}
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
int XORWizard(long int* num, long int i) {
	if (i == (*num)) {
		return 0;
	}
	if ((i ^ (*num)) > (*num)) {
		printf("%ld\n", i);
		return 1 + XORWizard(num, i + 1);
	}
	return XORWizard(num, i + 1);
}
int RockPaperScissorSpockGame(shape Alice, shape Bob, int rounds, int* alicewin, int* tie, int* alicelost) {
    int isChosenSpock = 0, round_winner;
    if(Bob == SPOCK) {
        isChosenSpock = 1;
    }
    while (rounds > 0) {
        round_winner = RockPaperScissorSpockMatch(Alice, Bob);
        printMatchResults(round_winner, Alice, Bob);
        rounds--;
        Alice = AliceMove(round_winner, Alice, Bob);
        Bob = BobMove(round_winner, &isChosenSpock);
        isChosenSpock = isChosenSpock ^ 1;
        switch(round_winner) {
        case 1 :
            *alicewin = *alicewin + 1;
            break;
        case -1 :
            *alicelost = *alicelost + 1;
            break;
        default:
            *tie = *tie + 1;
            break;
        }
    }
    if ((*alicelost) > (*alicewin)) {
        return -1;
    }
    else if ((*alicelost) < (*alicewin)) {
        return 1;
    }
    else {
        return 0;
    }
}
shape AliceMove(int current_result, shape Alice_previous_move, shape Bob_previous_move) {
    if(current_result == 0) { //game tied
        return choosewhatisAliceShapeAfterLossOrTie(Alice_previous_move);
    }
    else if (current_result == -1) { //Alice lost last game
        return choosewhatisAliceShapeAfterLossOrTie(Bob_previous_move);
    }
    else {
        return Alice_previous_move;
    }
}
shape BobMove(int current_result, int* isChosenSpock) {
    if((*isChosenSpock) == 1) {
        switch(current_result) {
        case 1:
            return PAPER;
        break;
        case 0 :
            return LIZARD;
        break;
        case -1:
            return ROCK;
        break;
        default:
            return ROCK;
        break;
        }
    }
    else {
        return SPOCK;
    }
}
shape choosewhatisAliceShapeAfterLossOrTie(shape previous_move) {
    shape first_nominee = ROCK, second_nominee = ROCK;
    int result = 0;
    switch(previous_move) {
        case PAPER :
            first_nominee = LIZARD;
            second_nominee = SCISSOR;
        break;
        case ROCK :
            first_nominee = PAPER;
            second_nominee = SPOCK;
        break;
        case SCISSOR :
            first_nominee = SPOCK;
            second_nominee = ROCK;
        break;
        case LIZARD :
            first_nominee = SCISSOR;
            second_nominee = ROCK;
        break;
        case SPOCK :
            first_nominee = PAPER;
            second_nominee = LIZARD;
        break;
        default:
        break;
    }
    result = RockPaperScissorSpockMatch(first_nominee, second_nominee);
    if (result == 1) {
        return first_nominee;
    }
    else {
        return second_nominee;
    }
}

int RockPaperScissorSpockMatch(shape first_opponent, shape second_opponent) {
    switch(first_opponent) {
        case ROCK :
            switch(second_opponent) {
                case PAPER :
                    return -1;
                break;
                case SPOCK :
                    return -1;
                break;
                case ROCK :
                    return 0;
                break;
                default :
                    return 1;
                break;
            }
        case PAPER :
            switch(second_opponent) {
                case PAPER :
                    return 0;
                break;
                case SCISSOR :
                    return -1;
                break;
                case LIZARD :
                    return -1;
                break;
                default :
                    return 1;
                break;
            }
        case SCISSOR :
            switch(second_opponent) {
                case ROCK :
                    return -1;
                break;
                case SPOCK :
                    return -1;
                break;
                case SCISSOR :
                    return 0;
                break;
                default :
                    return 1;
                break;
            }
        case LIZARD :
            switch(second_opponent) {
                case ROCK :
                    return -1;
                break;
                case SCISSOR :
                    return -1;
                break;
                case LIZARD :
                    return 0;
                break;
                default :
                    return 1;
                break;
            }
        case SPOCK :
            switch(second_opponent) {
                case PAPER :
                    return -1;
                break;
                case LIZARD :
                    return -1;
                break;
                case SPOCK :
                    return 0;
                break;
                default :
                    return 1;
                break;
            }
                default :
                    printf("wrong input");
                    return -10;
        break;
    }
}
void printMatchResults(int winner_round, shape Alice, shape Bob) {
    char* Shapes[5] = {"Rock","Paper","Scissor","Lizard", "Spock"};
    printf("%s ", Shapes[Alice]);
    switch(winner_round) {
    case 1:
        printf("> ");
        break;
    case 0:
        printf("= ");
        break;
    case -1:
        printf("< ");
        break;
    default :
        break;
    }
    printf("%s \n", Shapes[Bob]);
}
