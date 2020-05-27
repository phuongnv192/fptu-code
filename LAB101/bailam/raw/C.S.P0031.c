/*
	Convert decimal to binary
	Source file: C.S.P0031.c
	Author: Ngo Van Phuong - HE140784
	Last modified: 05/02/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int intcheck(int min, int max, int range, char msg[], char err[]); /* Check input int number in [min, max] */
int dectobin(int a, int b[]);  /* Convert decimal to binary and display to the screen */
void output(int b[], int n);  /* Display to the screen binary number */

int main() {
	char msg[34], err[43];
	int a, *b, n;
	
	strcpy(msg, "\tEnter a positive number: ");
	strcpy(err, "\tInvalid number, please re-enter.\n");
	while (1) {
		printf("Convert Decimal to Binary program\n");

		a = intcheck(1, INT_MAX, 12, msg, err);
		b = (int *) malloc(1 * sizeof(int)); // create array b[] with 1 element
		n = dectobin(a, b);
		output(b, n);
		printf("Press any key to do another conversion.");
		getch();
		printf("\n\n");
		free(b);
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

int dectobin(int a, int b[]) { /* Convert decimal to binary and display to the screen */
	int n;
	
	n = 0;
	do {
		b[n] = a%2;
		a /= 2;
		b = (int *) realloc(b, (n + 2) * sizeof(int)); // increase array b[] 1 element
		n++;
	} while (a != 0);
	return (n);
}

void output(int b[], int n) {  /* Display to the screen binary number */
	int i;
	
	printf("\tBinary number: ");
	for (i  = n-1; i >= 0; i--) {
		printf("%d", b[i]);
	}
	printf("\n");
}
