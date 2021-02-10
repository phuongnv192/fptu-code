/*
	Using a simple menu to manage program functions
	Source file: C.S.P0039.c
	Author: Ngo Van Phuong - HE140784
	Last modified: 04/29/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int menuselect(void);  /* Display a menu and asks users to select an option */
int intcheck(int min, int max, int range, char msg[], char err[]); /* Check input int number */
void datedata(void);  /* Processing date data */
void chardata(void);  /* Processing character data */
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
		printf("1- Processing date data\n");
		printf("2- Character data\n");
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

int intcheck(int min, int max, int range, char msg[], char err[]) { /* Check input int number */
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

void datedata(void) { /* Processing date data */
	char msg[23], err[34];
	int year, month, date, leap, datemax;
	
	leap = 1;  // leap = 1 mean it's a leap year
	printf("\nInput data:\n");
	strcpy(msg, " Enter year: ");
	strcpy(err, " Invalid year, please re-enter.\n");
	year = intcheck(1, 9999, 4, msg, err);
	if (year%4 != 0 || (year%100 == 0 && year%400 != 0))
		leap = 0;  // it's not a leap year

	strcpy(msg, " Enter month: ");
	strcpy(err, " Invalid month, please re-enter.\n");
	month = intcheck(1, 12, 2, msg, err);
	
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		datemax = 30;
	}	
	else if (month == 2) {
		if (leap == 1)
			datemax = 29;
		else datemax = 28;	
	}
	else datemax = 31;
	strcpy(msg, " Enter date: ");
	strcpy(err, " Invalid date, please re-enter.\n");
	date = intcheck(1, datemax, 2, msg, err);
	
	printf("\nThe date were entered is : %02d/%02d/%04d\n", date, month, year);
}

void chardata(void) { /* Processing character data */
	char *a;
	int i;
	
	a = (char *) malloc(3 * sizeof(char));
	printf("\n");
	while (1) {
		printf("Input 2 characters: ");
		fflush(stdin);
		scanf("%[^\n]", a);
		if (strlen(a) == 2)
			break;
		printf("Invalid input, please re-enter.\n");
	}
	if (a[0] > a[1]) {
		for (i = a[0]; i >= a[1]; i--)
			printf(" %c: %d\n", i, i);
	}
	else {
		for (i = a[1]; i >= a[0]; i--)
			printf(" %c: %d\n", i, i);
	}
}

void runmenu(int choice) {  /* Perform selected function */ 
	if (choice == 1) {
		datedata();
	}
	else if (choice == 2)
		chardata();
}
