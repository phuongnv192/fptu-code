/*
	Array Manipulations
	Source file: C.S.P0041.c
	Author: Ngo Van Phuong - HE140784
	Last modified: 05/01/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *msg, *err;
	int i, n, *s, max;
	
	msg = "Enter the size of an array\n";
	err = "Invalid number, please re-enter.\n";
	n = intcheck(1, INT_MAX, 11, msg, err);
	s = (int *) malloc(n * sizeof(int));
	
	printf("Enter the elements of the array\n");
	msg = "";
	for (i = 0; i < n; i++) {
		s[i] = intcheck(INT_MIN, INT_MAX, 11, msg, err);
	}
	
	printf("\nArray elements:\n");
	for (i = 0; i < n; i++) {
		printf("%d ", s[i]);
	}
	
	max = s[0];
	for (i = 0; i < n; i++) {
		if (s[i] > max) {
			max = s[i];
		}
	}
	printf("\n\nArray maximum value:\n");
	printf("The max is %d\n", max);
	
	printf("\nArray even values:\n");
	for (i = 0; i < n; i++) {
		if (s[i]%2 == 0) {
			printf("%d ", s[i]);
		}
	}
	free(s);
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
