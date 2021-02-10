/*
	Addition of odd/even numbers
	Source file: C.S.P0030.c
	Author: Ngo Van Phuong - HE140784
	Last modified: 05/02/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int intcheck(int min, int max, int range, char msg[], char err[]); /* Check input int number in [min, max] */
int inputn(void);  /* Enter the number of natural numbers */
void inputa(int a[], int n); /* Input element numbers */
int sumeven (int a[], int n);  /* Calculate sum of even numbers */
int sumodd (int a[], int n);  /* Calculate sum of odd numbers */
void output(int sume, int sumo);  /* Output sum of odd and even numbers to the screen */

int main() {
	char msg, err;
	int n, *a, sume, sumo;
	
	n = inputn();
	a = (int *) malloc(n * sizeof(int));
	inputa(a, n);
	sume = sumeven(a, n);
	sumo = sumodd(a, n);
	output(sume, sumo);
	free(a);
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

int inputn(void) { /* Enter the number of natural numbers */
	int n;
	char msg[31], err[35];
	
	printf("Sum Even Odd Program\n");
	strcpy(msg, "Enter a nubmer of element n = ");
	strcpy(err, "Invalid number, please re-enter.\n");
	n = intcheck(1, INT_MAX, 11, msg, err);
	return(n);
}

void inputa(int a[], int n) { /* Input element numbers */
	int i, j, check, len;
	char *x;
	
	printf("Input elements:\n");
	
	x = (char *) malloc(12 * sizeof(char));
	for (i = 0; i < n; i++) {
	    while (1) {
	    	printf("\tElement %d = ", i+1);
			fflush(stdin);
			scanf("%[^\n]", x);
			check = 1; len = strlen(x);
			if (len > 0 && len <= 12) {  // check validation string
				for (j = 0; j < len; j++) {  // check validation int number
					if (x[0] == '-') continue;
					if (x[j] < '0' || x[j] > '9') {
						check = 0;
						break;
					}
				}
				if (check == 1) {  // if it is a int number, convert string ~> int
					a[i] = atoi(x);
					break;  // break while (1)
				}
			}
			printf("\tInvalid number, please re-enter.\n");
		}
		strcpy(x, "");	
	}
	free(x);
}

int sumeven (int a[], int n) {  /* Calculate sum of even numbers */
	int i, sum;
	
	sum = 0;
	for (i = 0; i < n; i++) {
		if (a[i]%2 == 0) {
			sum += a[i];
		}
	}
	return(sum);
}

int sumodd (int a[], int n) {  /* Calculate sum of odd numbers */
	int i, sum;
	
	sum = 0;
	for (i = 0; i < n; i++) {
		if (a[i]%2 == 1) {
			sum += a[i];
		}
	}
	return(sum);
}

void output(int sume, int sumo) { /* Output sum of odd and even numbers to the screen */
	printf("Sum of Even = %d\n", sume);
	printf("Sum of Odd = %d\n", sumo);
}

