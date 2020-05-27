/*
	String Array Manipulations
	Source file: C.S.P0045.c
	Author: Ngo Van Phuong - HE140784
	Last modified: 05/02/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int intcheck(int min, int max, int range, char msg[], char err[]); /* Check input int number in [min, max] */
void inputa(char **a, int n); /* Input a number of string corresponding to the inputted size */
void bubblesort(char **a, int size); /* Sort the string array in ascending orders alphabetically */
void output(char **a, int n);  /* Output the array elements */

int main() {
	char msg[23], err[35], **a;
	int n, i;
	
	strcpy(msg, "Enter the value of n: ");
	strcpy(err, "Invalid number, please re-enter.\n");
	n = intcheck(1, INT_MAX, 11, msg, err);
	
	a = (char **) calloc(n, sizeof(char *));
	for (i = 0; i<n; i++) {
		a[i] = (char *) calloc(51, sizeof(char));
	}
	inputa(a, n);
	printf("List input name:\n");
	output(a, n);
	printf("List sort name:\n");
	bubblesort(a, n);
	output(a, n);
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

void inputa(char **a, int n) { /* Input a number of string corresponding to the inputted size */
	int i;
	
	printf("Enter %d names:\n", n);
	for (i = 0; i < n; i++) {
		while (1) {
			printf("%d. ", i+1);
			fflush(stdin);
			scanf("%[^\n]", a[i]);
			if (strlen(a[i]) > 0 && strlen(a[i]) <= 50) {
				break;
			}
			printf("Invalid name, please re-enter.\n");
		}
	}
}

void bubblesort(char **a, int size) { /* Sort the string array in ascending orders alphabetically */
	int i, j;
	char temp[51];
	
	for (i = size - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (strcmp(a[j], a[j+1]) > 0) {
				strcpy(temp, a[j]);
				strcpy(a[j], a[j+1]);
				strcpy(a[j+1], temp);
			}
		}
	}
}

void output(char **a, int n) { /* Output the array elements */
	int i;
	
	for (i = 0; i < n; i++) {
		printf("%d. %s\n", i+1, a[i]);
	}
}
