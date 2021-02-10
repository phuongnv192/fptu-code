/*
	Addition of digits in a natural number
	Source file: C.S.P0032.c
	Author: Ngo Van Phuong - HE140784
	Last modified: 05/02/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int intcheck(int min, int max, int range, char msg[], char err[]); /* Check input int number in [min, max] */
int sumdigit(int a);  /* Calculate sum of digits in the decimal number */
void output(int sum);  /* Output sum of digits in the inputted decimal number */


int main() {
	char msg[27], err[35];
	int a, sum;
	
	printf("Sum Digit program\n");
	strcpy(msg, "Enter an integer number = ");
	strcpy(err, "Invalid number, please re-enter.\n");
	while (1) {
		a = intcheck(INT_MIN, INT_MAX, 12, msg, err);
		sum = sumdigit(a);
		output(sum);
		printf("Press any key to do another conversion.");
		getch();
		printf("\n\n");
	}
	return 0;
}

/* Check input int number [min, max] with maximum range-digit */
int intcheck(int min, int max, int range, char msg[], char err[]) {
    int num, i, check, len;
    char *x;
    
	x = (char *) malloc(range * sizeof(char));
    while (1) {
    	printf("%s", msg);
		fflush(stdin);
		scanf("%[^\n]", x);
		check = 1; len = strlen(x);
		if (len > 0 && len <= range) {  // check validation string
			for (i = 0; i < len; i++) {  // check validation int number
				if (x[0] == '-') continue;
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

int sumdigit(int a) { /* Calculate sum of digits in the decimal number */
	int sum;
	
	sum = 0;
	if (a < 0) {
		a *= -1;
	}
	while (a != 0) {
		sum += (a%10);
		a /= 10;
	}
	return sum;
}

void output(int sum) { /* Output sum of digits in the inputted decimal number */
	printf("Sum digit = %d\n", sum);
}
