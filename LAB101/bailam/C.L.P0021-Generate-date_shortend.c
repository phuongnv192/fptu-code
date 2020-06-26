/* Generate day of year, day of week and week of year from a string in date format. 
 * File:   C.L.P0021.c
 * Author: phuong
 *
 * Created on June 1, 2020, 12:48 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int buffer(void); /* pauses the Output console until Enter is pressed & clear buffer */
int dateinput(int *d, int *m, int *y); /* input date & check validation */
void dayofweek(int d, int m, int y); /* Calculate day of week */
void dateprocess(void); /* Calculate date process */

int main() {

    while (1) {
        dateprocess();
        printf("\nPress Enter to continue, press Esc to exit");
        if (buffer() == 27) break;
        printf("\n");
    }
    return 0;
}

/* Pauses the Output console until Enter is pressed & clear buffer */
int buffer(void) {
    char c;

    while ((c = getchar()) != '\n' && c != EOF && c != 27);
    return c;
}

/* input date & check validation */
int dateinput(int *d, int *m, int *y) {
    char *a;
    int check, leap;
    int dmax[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    a = (char *) calloc(11, sizeof (char));
    while (1) {
        printf("Please enter a date (dd/mm/yyyy): ");
        fflush(stdout);
        scanf("%[^\n]", a);
        buffer();
        if (strlen(a) >= 5 && strlen(a) <= 10) {
            check = sscanf(a, "%d/%d/%d", d, m, y);
            if (check == 3) {
                if (*y >= 1920 && *y <= 9999) { // year from 1920 ~> now use Gregorian Calendar
                    if (*m >= 1 && *m <= 12) {
                        if (*y % 4 != 0 || (*y % 100 == 0 && *y % 400 != 0)) {
                            dmax[1] = 28; // normal February have 28 days
                            leap = 0; // it's not a leap year
                        } else {
                            leap = 1; // it's a leap year
                            dmax[1] = 29; // February in leap year have 29 days
                        }
                        if (*d > 0 && *d <= dmax[*m - 1]) break; // valid date format: break while (1)
                    }
                }
            }
        }
        printf("Invalid date, please re-enter.\n");
    }
    return leap;
}

/* Calculate day of week */
void dayofweek(int d, int m, int y) {
    int check, weekday;
    
    /* Zeller's algorithm for Gregorian calendar */
    int z[12] = {13, 14, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    if (m < 3) y--;
    weekday = (d + (z[m - 1] + 1)*13 / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    switch (weekday) {
        case 0:
        {
            printf("Saturday");
            break;
        }
        case 1:
        {
            printf("Sunday");
            break;
        }
        case 2:
        {
            printf("Monday");
            break;
        }
        case 3:
        {
            printf("Tuesday");
            break;
        }
        case 4:
        {
            printf("Wednesday");
            break;
        }
        case 5:
        {
            printf("Thursday");
            break;
        }
        case 6:
        {
            printf("Friday");
            break;
        }
    }
}

/* Calculate date process */
void dateprocess(void) {
    int leap, date, month, year, daycounts, weekcounts, i;
    int dmax[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    leap = dateinput(&date, &month, &year);
    if (leap == 1) dmax[1] = 29;
    else dmax[1] = 28;
    daycounts = 0;
    for (i = 0; i < month - 1; i++) daycounts += dmax[i];
    daycounts += date; // daycounts = sum of maxday from 1 ~> month-1 + current date
    printf("Day of year: %d\n", daycounts);
    printf("Day of week: ");
    dayofweek(date, month, year);
    if (daycounts % 7 == 0) weekcounts = daycounts / 7;
    else weekcounts = daycounts / 7 + 1;
    printf("\nWeek of year: %d\n", weekcounts);
}