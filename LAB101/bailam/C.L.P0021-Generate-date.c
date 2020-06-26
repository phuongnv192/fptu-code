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
int datecheck(int d, int m, int y); /* check validation date format dd/mm/yyyy */
void dateinput(int *d, int *m, int *y); /* input date & check validation */
int zellergreg(int d, int m, int y); /* calculate weekday use Zeller's algorithm for Gregorian calendar */
int zellerjulian(int d, int m, int y); /* calculate weekday use Zeller's algorithm for Julian calendar */
void dayofweek(int d, int m, int y); /* Calculate day of week */
int dayofyear(int d, int m, int y); /* Calculate day of year */
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
    char ch;
    
    while ((ch = getchar()) != '\n' && ch != EOF && ch != 27);
    return (ch);
}

/* check validation date format dd/mm/yyyy */
int datecheck(int d, int m, int y) {
    int dmax[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap;

    if (y < 0 || y > 9999) return 0; // invalid year
    if (y % 4 != 0 || (y % 100 == 0 && y % 400 != 0)) {
        dmax[1] = 28; // normal February have 28 days
        leap = 0; // it's not a leap year
    } else {
        leap = 1; // it's a leap year
        dmax[1] = 29; // February in leap year have 29 days
    }
    if (m < 0 || m > 12) return 0; // invalid month
    if (d < 0 || d > dmax[m - 1]) return 0; // invalid date
    if (y = 1752 && m == 9 && d > 2 && d < 14) return 0; // there are no day between 2/9/1752-14/9/1752
    if (leap == 0) return 1; // valid date format & is not a leap year
    if (leap == 1) return 2; // valid date format & is a leap year
}

/* input date & check validation */
void dateinput(int *d, int *m, int *y) {
    char *a;
    int check, x;

    a = (char *) calloc(11, sizeof (char));
    while (1) {
        printf("Please enter a date (dd/mm/yyyy): ");
        fflush(stdout);
        scanf("%[^\n]", a);
        buffer();
        if (strlen(a) >= 5 && strlen(a) <= 10) {
            x = sscanf(a, "%d/%d/%d", d, m, y);
            if (x == 3) {
                check = datecheck(*d, *m, *y);
                if (check != 0) break;
            }
        }
        printf("Invalid date, please re-enter.\n");
    }
}

/* calculate weekday use Zeller's algorithm for Gregorian calendar */
int zellergreg(int d, int m, int y) {
    int weekday;
    int z[12] = {13, 14, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    if (m < 3) y--;
    weekday = (d + (z[m - 1] + 1)*13 / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    return (weekday);
}

/* calculate weekday use Zeller's algorithm for Julian calendar */
int zellerjulian(int d, int m, int y) {
    int weekday;
    int z[12] = {13, 14, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    if (m < 3) y--;
    weekday = (d + (z[m - 1] + 1)*13 / 5 + y + y / 4 + 5) % 7;
    return (weekday);
}

/* Calculate day of week */
void dayofweek(int d, int m, int y) {
    int check, weekday;

    /* 01/01/0001 ~> 2/9/1752: use Julian Calendar - check = 1
     * 14/09/1752 ~> now: use Gregorian Calendar - check = 0 */
    if (y > 1752) check = 1;
    else if (y == 1752) {
        if (m > 9) check = 1;
        else if (m == 9) {
            if (d >= 14) check = 1;
        }
    } else check = 0;

    if (check == 0) weekday = zellerjulian(d, m, y);
    else weekday = zellergreg(d, m, y);
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

/* Calculate day of year */
int dayofyear(int d, int m, int y) {
    int dmax[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, sum;

    if (datecheck(d, m, y) == 1) dmax[1] = 28;
    else dmax[1] = 29;

    sum = 0;
    for (i = 0; i < m - 1; i++) sum += dmax[i];
    sum += d;
    return sum;
}

/* Calculate date process */
void dateprocess(void) {
    int date, month, year, z, weekcounts;

    dateinput(&date, &month, &year);
    z = dayofyear(date, month, year);
    printf("Day of year: %d\n", z);
    printf("Day of week: ");
    dayofweek(date, month, year);
    if (z % 7 == 0) weekcounts = z/7;
    else weekcounts = z/7 +1;
    printf("\nWeek of year: %d\n", weekcounts);
}