/*
	Sum of decimal numbers
	Source file: C.S.P0033.c
	Author: Ngo Van Phuong - HE140784
	Last modified: 04/30/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int intcheck(int min, int max, int range, char msg[], char err[]); /* Check input int number [min, max] */
int inputn(void);  /* Input the number of decimals  - n */
void inputs(int n, int s[]);  /* Input a number decimals - s[i] */ 
long int sums(int n, int s[]);  /* Calculate sum of all inputted decimals */
void output(long int sum);  /* Output sum of inputted decimals */

int main() {
	int n, *s;
	long int sum;
	
	while (1) {
		system("cls");
		n = inputn();
		s = (int *) malloc(n * sizeof(int));
		inputs(n, s);
		sum = sums(n, s);
		output(sum);
		free(s);
		printf("\nPress any key to continue.");
		getch();
	}
	return 0;
}

/* Check input int number [min, max] with maximum range-digit */
int intcheck(int min, int max, int range, char msg[], char err[]) {
    int num, i, check;
    char *x;
    
	x = (char *) malloc(range * sizeof(char));
    while (1) {
    	printf("%s", msg);
		fflush(stdin);
		scanf("%[^\n]", x);
		check = 1;
		if (strlen(x) > 0 && strlen(x) <= range) {  // check validation string
			for (i = 0; i < strlen(x); i++) {  // check validation int number
				if (x[i] < '0' || x[i] > '9') {
					check = 0;
					break;
				}
			}
			if (check == 1) {  // if it is a int number, convert string ~> int
			num = atoi(x);
			if (num >= min && num <= max)
				return(num);
			}
		}
		printf("%s", err);
	}
	free(x);
}

int inputn(void) { /* Input the number of decimals  - n */
	char msg[] = "\tNumber of element s = ";
	char err[] = "\tInvalid number, please re-enter.\n";
	int n;
	
	printf("Dynamic memory allocation\n");
	//strcpy(msg, "\tNumber of element s = ");
	//strcpy(err, "\tInvalid number, please re-enter.\n");
	n = intcheck(1, INT_MAX, 10, msg, err);
	return n;
}

void inputs(int n, int s[]) { /* Input a number decimals - s[i] */ 
	char msg[] = "\tEnter an integer: ";
	char err[] = "\tInvalid number, please re-enter.\n";
	int i;	
	
	for (i = 0; i < n; i++) {
		s[i] = intcheck(INT_MIN, INT_MAX, 10, msg, err);
	}
}

long int sums(int n, int s[]) { /* Calculate sum of all inputted decimals */
	long int sum = 0;
	int i;
	
	for (i = 0; i < n; i++) {
		sum += s[i];
	}
	return(sum);
}

void output(long int sum) { /* Output sum of inputted decimals */
	printf("\tSum = %ld\n", sum);
}
