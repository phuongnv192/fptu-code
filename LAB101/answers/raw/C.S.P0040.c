/*
	Use simple menu to manage program functions
	Source file: C.S.P0040.c
	Author: Ngo Van Phuong - HE140784
	Last modified: 04/30/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <float.h>

int menuselect(void);  /* Display a menu and asks users to select an option */
void quadequal(void);  /* Calculate quadratic equation */
int intcheck(int min, int max, int range, char msg[], char err[]); /* Check input int number [min, max] with maximum range-digit */
double floatcheck(double min, double max, char msg[], char err[]); /* Check input float number in range (min, max] */
void bankinvst(void);  /* Bank deposit calculation */
void runmenu(int choice);  /* Perform selected function */ 

int main() {
	int choice;
	
	while (1) {
		choice = menuselect();
		runmenu(choice);
		if (choice == 3)
			break;
		printf("\nPress any key to continue.");
		getch();
	}
	return 0;
}

int menuselect(void) {  /* Display a menu and asks users to select an option */
	char x[2];
	
	while (1) {
		system("cls");
		printf("MENU\n");
		printf("------------------------------\n\n");
		printf("1- Quadratic equation\n");
		printf("2- Bank deposit problem\n");
		printf("3- Quit\n");
		printf("Enter Your Choice: ");
		fflush(stdin);
		scanf("%[^\n]", x);
		if (strlen(x) == 1 && strcmp(x, "3") <= 0 && strcmp(x, "1") >= 0)
			return(atoi(x));
		printf("Invalid choice, press any key to continue.\n");
		getch();	
	}
}

void quadequal(void) { /* Calculate quadratic equation */
	double a, b, c, delta;
	char *str;
	int check;
	
	printf("\n");
	str = (char *) malloc(50 * sizeof(char));
	while (1) {
		printf("Enter a, b, c: ");
		fflush(stdin);
		scanf("%[^\n]", str);
		check = sscanf(str, "%lf %lf %lf", &a, &b, &c);
		if (check == 3) {
			if (a != 0) {
				break;
			}	
		}
		printf("Invalid input, please re-enter.\n");
	}
	
	delta = pow(b, 2) - 4*a*c;
	if (delta < 0) {
		printf("\nThe quadratic equation have no real root.\n");
	}
	else if (delta == 0) {
		printf("\nThe quadratic equation have 1 real root:\n");
		printf(" x = %.2lf\n", -b/(2*a));
	}
	else {
		printf("\nThe quadratic equation have 2 real root:\n");
		printf(" x1 = %.2lf\n", (-b + sqrt(delta)) / (2*a));
		printf(" x2 = %.2lf\n", (-b - sqrt(delta)) / (2*a));
	}
	free(str);
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

/* Check input float number in range (min, max] */
double floatcheck(double min, double max, char msg[], char err[]) {
    double num;
    char *x;
    int i, check;
    
	x = (char *) malloc(20 * sizeof(char));
    while (1) {
    	printf("%s", msg);
		fflush(stdin);
		scanf("%[^\n]", x);
		check = 1;
		if (strlen(x) > 0 && strlen(x) < 20) {  // check validation string
			for (i = 0; i < strlen(x); i++) {  // check validation double number
				if (x[0] == '-') continue;
				if (x[i] < '0' || x[i] > '9') {
					if (x[i] != '.') {
						check = 0;
						break;
					}
				}
			}
			if (check == 1) {  // if it is a float number, convert string ~> double
				num = atof(x);
				if (num > min && num <= max)
					return(num);
			}	
		}
		printf("%s", err);
	}
	free(x);
}

void bankinvst(void) { /* Bank deposit calculation */
	char *msg, *err;
	double amount, rate, total;
	int month;
	
	printf("\n");
	msg = "Enter amount: ";
	err = "Invalid amount, please re-enter.\n";
	amount = floatcheck(0, DBL_MAX, msg, err);
	msg = "Enter interest rates: ";
	err = "Invalid rates, please re-enter.\n";
	rate = floatcheck(0, 0.1, msg, err);
	msg = "Enter number of deposit months: ";
	err = "Invalid number, please re-enter.\n";
	month = intcheck(1, 12, 2, msg, err);
	
	total = amount * (1 + rate*month);
	printf("Total amount received: %.3lf\n", total);
}

void runmenu(int choice) {  /* Perform selected function */ 
	if (choice == 1) {
		quadequal();
	}
	else if (choice == 2)
		bankinvst();
}
