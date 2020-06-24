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
void getch(); /* pauses the Output console until Enter is pressed */
int menuselect(); /* Display a menu and asks users to select an option */
int intcheck(int min, int max, char msg[], char err[]); /* Check input int number */
void datedata(); /* Processing date data */
void chardata(); /* Processing character data */

int main() {
    int choice;

    while (1) {
        printf("\n");
        choice = menuselect();
        if (choice == 3) break; // Quit
        else if (choice == 1) datedata(); // process date data
        else chardata(); // process char data
        printf("\nPress Enter to continue.");
        getch();
    }
    return 0;
}

/* Pauses the Output console until Enter is pressed */
void getch() {
    while (getchar() != '\n');
}

/* Check input int number in [min, max] */
int intcheck(int min, int max, char msg[], char err[]) {
    int num;

    while (1) {
        printf("%s", msg);
        fflush(stdout);
        num = -1;
        scanf("%d", &num);
        getch();
        if (num >= min && num <= max) return num;
        printf("%s", err);
    }
}

/* Display a menu and asks users to select an option */
int menuselect() {
    int a;

    while (1) {
        system("clear");
        printf("MENU\n");
        printf("------------------------------\n\n");
        printf("1- Processing date data\n");
        printf("2- Character data\n");
        printf("3- Quit\n");
        printf("Enter Your Choice: ");
        fflush(stdout);
        a = -1;
        scanf("%d", &a);
        getch();
        if (a >= 1 && a <= 3) return a;
        printf("Invalid choice, press Enter to continue.");
        getch();
    }
}

/* Processing date data */
void datedata() {
    int year, month, date, leap, datemax;

    printf("Input data:\n");
    year = intcheck(1, 9999, " Enter year: ", " Invalid year, please re-enter.\n");
    if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) leap = 0; // it's not a leap yea
    else leap = 1; // leap = 1 mean it's a leap year
    month = intcheck(1, 12, " Enter month: ", " Invalid month, please re-enter.\n");
    if (month == 4 || month == 6 || month == 9 || month == 11) datemax = 30;
    else if (month == 2) {
        if (leap == 1) datemax = 29;
        else datemax = 28;
    } else datemax = 31;
    date = intcheck(1, datemax, " Enter date: ", " Invalid date, please re-enter.\n");
    printf("\nThe date were entered is : %02d/%02d/%04d\n", date, month, year);
}

/* Processing character data */
void chardata() {
    char ch1, ch2;
    int i;

    printf("Input 2 characters: ");
    fflush(stdout);
    scanf("%c%c", &ch1, &ch2);
    getch();
    if (ch1 > ch2) for (i = ch1; i >= ch2; i--) printf(" %c: %d\n", i, i);
    else for (i = ch2; i >= ch1; i--) printf(" %c: %d\n", i, i);
}