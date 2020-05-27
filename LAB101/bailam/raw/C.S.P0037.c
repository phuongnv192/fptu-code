/*
	Identify Square Numbers
	Source file: C.S.P0037.c
	Author: Ngo Van Phuong - HE140784
	Last modified: 04/28/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int input(int *n); /* Input a positive natural number n */
int square(int n); /* Check square number */
void output(int n, int x); /* Print result square check to the screen */

int main() {
	int n, check;
	
	while (1) {
		check = input(&n);
		if (check == 0)
			printf("Please enter a positive integer!\n");
		else {
			check = square(n);
			output(n, check);
		}
		printf("Press any key to continue.\n");
		getch();
		printf("\n");
	}
	return 0;
}

int input(int *n) { /* Input a positive natural number n */
	char ch;
	
	printf("Check Square Number Program\n");
	printf("Enter a positive integer n = ");
	ch = '\0';
	scanf("%d%c", n, &ch);
	fflush(stdin);
	if (*n>0 && ch == '\n')
		return 1;
	else return 0;	
}

int square(int n) { /* Check square number */
	int x;
	
	x = (int) sqrt(n);
	if (x*x == n)
		return x;
	else return (-1);
}

void output(int n, int x) { /* Print result square check to the screen */
	if (x == -1)
		printf("%d is not a square number\n", n);
	else printf("%d is a square number %d = %d x %d\n", n, n, x, x);
}
