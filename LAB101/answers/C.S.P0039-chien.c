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
void buffer(void); /* pauses the Output console until Enter is pressed & clear buffer */
int intcheck(int max, char msg[], char err[]); /* Check input int number (0, max] */
void datedata(void); /* Processing date data */
void chardata(void); /* Processing character data */
int menuselect(void); /* Display a menu and asks users to select an option */
void menurun(int choice); /* Perform selected function */

int main() {
    int choice;

    while (1) {
        choice = menuselect();
        if (choice == 3) break; // Exit
        menurun(choice);
    }
    return 0;
}

/* Pauses the Output console until Enter is pressed & clear buffer */
void buffer(void) {
    while (getchar() != '\n');
}

/* Check input int number (0, max] */
int intcheck(int max, char msg[], char err[]) {
    int num, i, check, len;
    char *x;

    x = (char *) calloc(11, sizeof (char)); // INT_MAX have max 10 digits
    while (1) {
        printf("%s", msg);
        fflush(stdout);
        scanf("%[^\n]", x);
        buffer();
        check = 1;
        len = strlen(x);
        if (len > 0 && len <= 10) { // check validation string
            for (i = 0; i < len; i++) { // check validation int number
                if (x[i] < '0' || x[i] > '9') break; // all character only from '0' - '9'
            }
            if (i == len) { // nếu tất cả kí tự là số: vòng lặp for ko bị break giữa chừng
                num = atoi(x); // string to int
                if (num > 0 && num <= max) {
                    free(x);
                    return (num);
                }
            }
        }
        printf("%s", err);
    }
}

/* Processing date data */
void datedata(void) {
    int year, month, date, leap, datemax;

    printf("Input data:\n");
    year = intcheck(9999, " Enter year: ", " Invalid year, please re-enter.\n");
    if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) leap = 0; // it's not a leap year
    else leap = 1; // it's a leap year
    month = intcheck(12, " Enter month: ", " Invalid month, please re-enter.\n");
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        datemax = 30;
    } else if (month == 2) {
        if (leap == 1) datemax = 29;
        else datemax = 28;
    } else datemax = 31;
    date = intcheck(datemax, " Enter date: ", " Invalid date, please re-enter.\n");
    printf("\nThe date were entered is : %02d/%02d/%04d\n", date, month, year);
}

/* Processing character data */
void chardata(void) {
    char *a;
    int i;

    a = (char *) malloc(3 * sizeof (char));
    while (1) {
        printf("Input 2 characters: ");
        fflush(stdout);
        scanf("%[^\n]", a);
        buffer();
        if (strlen(a) == 2) break;
        printf("Invalid input, please re-enter.\n");
    }
    if (a[0] > a[1]) {
        for (i = a[0]; i >= a[1]; i--) {
            printf(" %c: %d\n", i, i);
        }
    } else {
        for (i = a[1]; i >= a[0]; i--) {
            printf(" %c: %d\n", i, i);
        }
    }
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
        fflush(stdout);
        scanf("%[^\n]", x);
        buffer();
        if (strlen(x) == 1 && strcmp(x, "3") <= 0 && strcmp(x, "1") >= 0) {
            return (atoi(x));
        }
        printf("Invalid choice, press Enter to continue.");
        buffer();
    }
}

/* Perform selected function */
void menurun(int choice) {
    printf("\n");
    if (choice == 1) datedata(); // process date data
    else chardata(); // process char data
    printf("\nPress Enter to continue.");
    buffer();
}