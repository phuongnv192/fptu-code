/*
	Convert decimal to binary numbers
	Source file: C.S.P0026.c
	Author: Ngo Van Phuong - HE140784
	Last modified: 05/02/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int intcheck(int min, int max, int range, char msg[], char err[]); /* Check input int number in [min, max] */
void dectobin(int a, int b[]);  /* Convert decimal to binary and display to the screen */

int main() {
	char msg[34], err[43];
	int a, *b;
	
	strcpy(msg, "\tEnter a positive number: ");
	strcpy(err, "\tInvalid number, please re-enter.\n");
	while (1) {
		printf("Convert Decimal to Binary program\n");
		a = intcheck(1, INT_MAX, 12, msg, err);
		b = (int *) malloc(1 * sizeof(int)); // create array b[] with 1 element
		dectobin(a, b);
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

void dectobin(int a, int b[]) { /* Convert decimal to binary and display to the screen */
	int j, i;
	
	j = 0;
	do {
		b[j] = a%2;
		a /= 2;
		b = (int *) realloc(b, (j + 2) * sizeof(int)); // increase array b[] 1 element
		j++;
	} while (a != 0);
	
	printf("\tBinary number: ");
	for (i  = j-1; i >= 0; i--) {
		printf("%d", b[i]);
	}
	printf("\n");
}
