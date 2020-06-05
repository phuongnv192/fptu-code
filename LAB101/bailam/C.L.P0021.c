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
int getch(void); /* pauses the Output console until Enter is pressed */
void buffer(void); /* temp statement to clear buffer */
int menuselect(void); /* Display a menu and asks users to select an option */
int intcheck(int min, int max, int range, char msg[], char err[]); /* Check input int number */
int datecheck(int d, int m, int y);
void dateinput(int *d, int *m, int *y);
int zellergreg(int d, int m, int y);
int zellerjulian(int d, int m, int y);
void dayofweek(int d, int m, int y);
int dayofyear(int d, int m, int y);
void dateprocess(void);

int main() {
    int choice;

    while (1) {
        dateprocess();
        if (getch() == 27) break;
    }

    return 0;
}

/* Pauses the Output console until Enter is pressed */
int getch(void) {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF && ch != 27);
    return (ch);
}

/* temp statement to clear buffer */
void buffer(void) {
    char temp;
    scanf("%c", &temp);
}

int datecheck(int d, int m, int y) {
    int dmax[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int leap;

    if (y < 0 || y > 9999) return 0;
    if (y % 4 != 0 || (y % 100 == 0 && y % 400 != 0)) {
        dmax[1] = 28; // normal February have 28 days
        leap = 0; // it's not a leap year
    } else {
        leap = 1; // it's a leap year
        dmax[1] = 29; // February in leap year have 29 days
    }
    if (m < 0 || m > 12) return 0;
    if (d < 0 || d > dmax[m - 1]) return 0;
    if (y = 1752 && m == 9 && d > 2 && d < 14) return 0;
    if (leap == 0) return 1;
    if (leap == 1) return 2;
}

void dateinput(int *d, int *m, int *y) {
    char *dchar, *mchar, *ychar, *a;
    int leap, check, x;
    int datemax[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    dchar = (char *) calloc(3, sizeof (char));
    mchar = (char *) calloc(3, sizeof (char));
    ychar = (char *) calloc(5, sizeof (char));
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

int zellergreg(int d, int m, int y) {
    int weekday;
    int z[12] = {13, 14, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    if (m < 3) y--;
    weekday = (d + (z[m - 1] + 1)*13 / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    return (weekday);
}

int zellerjulian(int d, int m, int y) {
    int weekday;
    int z[12] = {13, 14, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    if (m < 3) y--;
    weekday = (d + (z[m - 1] + 1)*13 / 5 + y + y / 4 + 5) % 7;
    return (weekday);
}

void dayofweek(int d, int m, int y) {
    int check, weekday;

    // 2/9/1752 ~> 14/9/1752
    // check = 0 ~> use Julian, check = 1 ~> use Gregorian
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

void dateprocess(void) {
    int date, month, year, z;

    dateinput(&date, &month, &year);
    z = dayofyear(date, month, year);
    printf("Day of year: %d\n", z);
    printf("Day of week: ");
    dayofweek(date, month, year);
    printf("\nWeek of year: %d\n", z / 7);
}
