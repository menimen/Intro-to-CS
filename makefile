output: ex4.o
	gcc ex4.o -Wall -g -ansi -o output
	
ex4.o: ex4.c
	gcc -c ex4.c