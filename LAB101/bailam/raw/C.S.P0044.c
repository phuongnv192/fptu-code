/*
	Array Manipulations
	Source file: C.S.P0044.c
	Author: Ngo Van Phuong - HE140784
	Last modified: 05/01/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int menuselect(void);  /* Display a menu and asks users to select an option */
int intcheck(int min, int max, int range, char msg[], char err[]); /* Check input int number [min, max] */
void addx(int x[], int *n);  /* Input an integer and store in the array x[] */
void findx(int a[], int n);  /* Find index of a number in the array */
void displayarr(int x[], int n);  /* Display all the array's elements */
void outputrange(int a[], int n);  /* Print out values in a range [min, max] */
void bubblesort(int a[], int size);  /* Sort the array in ascending orders */ 
void runmenu(int choice, int x[], int *n);  /* Perform selected function */ 

int main() {
	int choice, *a, n;
	
	n = 0; // number of elements entered
	a = (int *) malloc(1 * sizeof(int)); // create array a[] with 1 element
	while (1) {
		choice = menuselect();
		if (choice == 0)
			break;
		runmenu(choice, a, &n);
		printf("\nPress any key to continue.");
		getch();
	}
	free(a);
	return 0;
}

int menuselect(void) {  /* Display a menu and asks users to select an option */
	char x[2];
	
	while (1) {
		system("cls");
		printf("\t+-------------------------------------------+\n");
		printf("\t|            Array Manipulations            |\n");
		printf("\t+-------------------------------------------+\n");
		printf("\t| 1. Add a value                            |\n");
		printf("\t| 2. Search a value                         |\n");
		printf("\t| 3. Print out the array                    |\n");
		printf("\t| 4. Print out values in a range [min, max] |\n");
		printf("\t| 5. Sort the array in ascending order      |\n");
		printf("\t| 0. Exit                                   |\n");
		printf("\t+-------------------------------------------+\n\n");
		printf("\tEnter your selection (0 -> 5): ");
		fflush(stdin);
		scanf("%[^\n]", x);
		if (strlen(x) == 1 && strcmp(x, "5") <= 0 && strcmp(x, "0") >= 0)
			return(atoi(x));
		printf("\tInvalid choice, press any key to continue.");
		getch();	
	}
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

void addx(int a[], int *n) { /* Input an integer and store in the array x[] */
	char msg[15], err[35];
	
	strcpy(msg, "Enter number: ");
	strcpy(err, "Invalid number, please re-enter.\n");
	a[*n] = intcheck(INT_MIN, INT_MAX, 12, msg, err);
	a = (int *) realloc(a, ((*n)+2) * sizeof(int)); // increase array a[] 1 element
	(*n)++;
}

void findx(int a[], int n) { /* Find index of a number in the array */
	int i, f;
	char msg[32], err[35];
	
	strcpy(msg, "Enter number you want to find: ");
	strcpy(err, "Invalid number, please re-enter.\n");
	f = intcheck(INT_MIN, INT_MAX, 12, msg, err);
	
	printf("Index of number %d: ", f);
	for (i = 0; i < n; i++) {
		if (f == a[i]) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

void displayarr(int a[], int n) { /* Display all the array's elements */
	int i;
	
	printf("Array elements:\n ");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void outputrange(int a[], int n) { /* Print out values in a range [min, max] */
	int i, min, max, none;
	char msg[12], err[35];
	
	strcpy(msg, "Enter min: ");
	strcpy(err, "Invalid number, please re-enter.\n");
	min = intcheck(INT_MIN, INT_MAX, 12, msg, err);
	strcpy(msg, "Enter max: ");
	max = intcheck(min, INT_MAX, 12, msg, err);
	
	none = 1;
	printf("Numbers of array in range [%d, %d]:\n ", min, max);

	for (i = 0; i < n; i++) {
		if (a[i] >= min && a[i] <= max) {
			none = 0;
			printf("%d ", a[i]);
		}
	}
	if (none == 1) {
		printf("There's no number in range [%d, %d]\n", min, max);
	}
	else printf("\n");
}

void bubblesort(int a[], int size) { /* Sort the array in ascending orders */ 
	int i, j, temp;
	
	for (i = size-1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

void runmenu(int choice, int a[], int *n) {  /* Perform selected function */ 
	printf("\n");
	switch (choice) {
		case 1: {
			addx(a, n);
			break;
		}
		case 2: {
			findx(a, *n);
			break;
		}
		case 3: {
			displayarr(a, *n);
			break;
		}
		case 4: {
			outputrange(a, *n);
			break;
		}
		case 5: {
			bubblesort(a, *n);
			printf("Successfull.\n");
			break;
		}
	}
}
