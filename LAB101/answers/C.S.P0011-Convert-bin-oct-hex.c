/* 
 * Convert binary, octal and hexadecimal to decimal
 * File:   C.S.P0011.c
 * Author: phuong
 *
 * Created on May 22, 2020, 8:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
 * 
 */
int getch(void); /* pauses the Output console until Enter is pressed & clear buffer */
void input(char num[], char mode[], int length, char bank[]); /* Input a number & check validation */
int convert(char num[], char mode[], int length, char bank[]); /* Convert a number to decimal number */
void convert2dec(char mode[], int length, char bank[]); /* Enter, convert & display a number to decimal number */
int menuselect(void); /* Display a menu and asks users to select an option */
void menurun(int choice); /* Perform selected function */

int main() {
    int choice;

    while (1) {
        choice = menuselect();
        if (choice == 4) break; // Exit
        menurun(choice);
    }
    return 0;
}

/* Pauses the Output console until Enter or Esc is pressed & clear buffer */
int getch() {
    char c;

    while (1) {
        c = getchar();
        if (c == '\n' || c == 27) return c;
    }
}

/* Input a number & check validation */
void input(char num[], char mode[], int length, char bank[]) {
    int i;
    char *temp;

    temp = (char *) calloc(length + 1, sizeof (char));
    while (1) { // input number & check validation
        printf(" Enter %s number: ", mode);
        fflush(stdout);
        scanf("%[^\n]", temp);
        getch();
        if (strlen(temp) > 0 && strlen(temp) <= length) {
            for (i = 0; i < strlen(temp); i++) {
                if (strchr(bank, temp[i]) == NULL) break; // cannot find the number in bank[]
            }
        }
        if (i == strlen(temp)) { // FINISH input
            strcpy(num, temp);
            free(temp);
            break;
        }
        printf(" Invalid %s number, please re-enter.\n", mode);
    }
}

/* Convert a number to decimal number */
int convert(char num[], char mode[], int length, char bank[]) {
    int i, dec, power, coso, chuso;

    dec = 0;
    power = 0;
    if (strcmp(mode, "binary") == 0) coso = 2; // binary co so 2
    else if (strcmp(mode, "octal") == 0) coso = 8; // octal co so 8
    else coso = 16; // hexadecimal co so 16
    for (i = strlen(num) - 1; i >= 0; i--) {
        if (num[i] >= '0' && num[i] <= '9') chuso = num[i] - 48; // '0' ~> 0
        else if (num[i] >= 'A' && num[i] <= 'F') chuso = num[i] - 55; // 'A' ~> 10
        else chuso = num[i] - 87; // 'a' ~> 10
        dec += chuso * pow(coso, power);
        power++;
    }
    return (dec);
}

/* Enter, convert & display a number to decimal number */
void convert2dec(char mode[], int length, char bank[]) {
    int dec;
    char num[32];

    do { // loop until press ESC
        printf("\n");
        input(num, mode, length, bank);
        dec = convert(num, mode, length, bank);
        printf(" Decimal number is: %d\n", dec);
        printf("\n Press Enter to continue, Esc to return the main menu.");
        if (getch() == 27) break;
    } while (1); // if press ESC ~> exit loop
    getch();
}

/* Display a menu and asks users to select an option */
int menuselect(void) {
    char *x;

    x = (char *) calloc(2, sizeof (char));
    while (1) {
        system("clear");
        printf("MENU\n");
        printf("-------------------------------------------------\n\n");
        printf("1.  Convert binary number to decimal number\n");
        printf("2.  Convert octal number to decimal number\n");
        printf("3.  Convert hexadecimal number to decimal number\n");
        printf("4.  Exit\n");
        printf(" Please choose number (1 – 4): ");
        fflush(stdout);
        scanf("%[^\n]", x);
        getch();
        if (strlen(x) == 1 && strcmp(x, "4") <= 0 && strcmp(x, "1") >= 0) {
            return (atoi(x));
        }
        printf(" Invalid choice, press Enter to continue.");
        getch();
    }
}

/* Perform selected function */
void menurun(int choice) {
    switch (choice) {
        case 1: // convert binary ~> decimal
        {
            convert2dec("binary", 31, "01"); // INT_MAX in binary have max 31 digits
            break;
        }
        case 2: // convert octal ~> decimal
        {
            convert2dec("octal", 11, "01234567"); // INT_MAX in octal have max 11 digits
            break;
        }
        case 3: // convert hexadecimal ~> decimal
        {
            convert2dec("hexadecimal", 8, "0123456789ABCDEFabcdef"); // INT_MAX in hexadecimal have max 8 digits
            break;
        }
    }
}