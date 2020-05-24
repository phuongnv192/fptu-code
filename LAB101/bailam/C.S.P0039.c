/* 
 * Use a simple menu to manage program functions
 * File:   C.S.P0039.c
 * Author: phuong
 *
 * Created on May 21, 2020, 11:47 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
void getch(void); /* pauses the Output console until Enter is pressed */
void buffer(void); /* temp statement to clear buffer */
int menuselect(void);  /* Display a menu and asks users to select an option */
int intcheck(int min, int max, int range, char msg[], char err[]); /* Check input int number */
void datedata(void);  /* Processing date data */
void chardata(void);  /* Processing character data */
void menurun(int choice);  /* Perform selected function */ 

int main() {
    int choice;

    while (1) {
        choice = menuselect();
        if (choice == 3)
            break;
        menurun(choice);
    }
    return 0;
}

/* Pauses the Output console until Enter is pressed */
void getch(void) {
    while (getchar() != '\n');
    //getchar();
}

/* temp statement to clear buffer */
void buffer(void) {
    char temp; 
    scanf("%c", &temp); 
}

/* Display a menu and asks users to select an option */
int menuselect(void) {
    char x[2];

    while (1) {
        system("clear");
        printf("MENU\n");
        printf("------------------------------\n\n");
        printf("1- Processing date data\n");
        printf("2- Character data\n");
        printf("3- Quit\n");
        printf("Enter Your Choice: ");
        
        scanf("%[^\n]", x); buffer(); fflush(stdin);
        if (strlen(x) == 1 && strcmp(x, "3") <= 0 && strcmp(x, "1") >= 0) {
            return(atoi(x));
        }
        printf("Invalid choice, press Enter to continue.");
        getch();
    }
}

/* Check input int number in [min, max] with max 'range' digits */
int intcheck(int min, int max, int range, char msg[], char err[]) { 
    int num, i, check, len, start;
    char *x;
    
    x = (char *) calloc(range+1, sizeof(char));
    while (1) {
    	printf("%s", msg);
	fflush(stdin);
        scanf("%[^\n]", x); buffer();
	check = 1; len = strlen(x);
	if (len > 0 && len <= range) {  // check validation string
            if (x[0] == '-') { // first character can be minus sign
                start = 1;
                if (len == 1) check = 0;
            }
            else start = 0;
            for (i = start; i < len; i++) {  // check validation int number
                if (x[i] < '0' || x[i] > '9') { // all character only from '0' - '9'
                    check = 0;
                    break;
                }
            }
            if (check == 1) {  // if it is a int number, convert string ~> int
		num = atoi(x);
		if (num >= min && num <= max) {
                    free(x);
                    return(num);
		}
            }
	}
	printf("%s", err);
    }
}

void datedata(void) { /* Processing date data */
    char msg[23], err[34];
    int year, month, date, leap, datemax;

    leap = 1;  // leap = 1 mean it's a leap year
    printf("Input data:\n");
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
    while (1) {
        printf("Input 2 characters: ");
        fflush(stdin);
        scanf("%[^\n]", a); buffer();
        if (strlen(a) == 2)
                break;
        printf("Invalid input, please re-enter.\n");
    }
    if (a[0] > a[1]) {
        for (i = a[0]; i >= a[1]; i--) {
            printf(" %c: %d\n", i, i);
        }
    }
    else {
        for (i = a[1]; i >= a[0]; i--) {
            printf(" %c: %d\n", i, i);
        }
    }
}

void menurun(int choice) {  /* Perform selected function */
    printf("\n");
    if (choice == 1) {
        datedata();
    }
    else if (choice == 2) {
        chardata();
    }
    printf("\nPress Enter to continue.");
    getch();
}

