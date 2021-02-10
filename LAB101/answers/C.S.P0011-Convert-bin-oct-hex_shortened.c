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
int getch(); /* pauses the Output console until Enter is pressed & clear buffer */
int menuselect(); /* Display a menu and asks users to select an option */
void convert(char mode[], int length, char bank[]); /* Enter, convert & display a number to decimal number */

int main() {
    int choice;

    while (1) {
        choice = menuselect();
        if (choice == 4) break; // Exit
        switch (choice) {
            case 1: // convert binary ~> decimal
            {
                convert("binary", 31, "01"); // INT_MAX in binary have max 31 digits
                break;
            }
            case 2: // convert octal ~> decimal
            {
                convert("octal", 11, "01234567"); // INT_MAX in octal have max 11 digits
                break;
            }
            case 3: // convert hexadecimal ~> decimal
            {
                convert("hexadecimal", 8, "0123456789ABCDEFabcdef"); // INT_MAX in hexadecimal have max 8 digits
                break;
            }
        }
    }
    return 0;
}

/* Pauses the Output console until Enter or Esc is pressed & clear buffer */
int getch() {
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != 27);
    return c;
}

/* Display a menu and asks users to select an option */
int menuselect() {
    int a;

    while (1) {
        system("clear");
        printf("MENU\n");
        printf("-------------------------------------------------\n\n");
        printf("1.  Convert binary number to decimal number\n");
        printf("2.  Convert octal number to decimal number\n");
        printf("3.  Convert hexadecimal number to decimal number\n");
        printf("4.  Exit\n");
        printf(" Please choose number (1 - 4): ");
        fflush(stdout);
        a = -1;
        scanf("%d", &a);
        getch();
        if (a >= 1 && a <= 4) return a;
        printf(" Invalid choice, press Enter to continue.");
        getch();
    }
}

/* Enter, convert & display a number to decimal number */
void convert(char mode[], int length, char bank[]) {
    int i, power, dec, chuso, coso;
    char num[32];
    
    do { // loop until press ESC
        printf("\n");
        while (1) { // input number & check validation
            printf(" Enter %s number: ", mode);
            fflush(stdout);
            scanf("%s", num);
            getch();
            if (strlen(num) > 0 && strlen(num) <= length) {
                for (i = 0; i < strlen(num); i++) {
                    if (strchr(bank, num[i]) == NULL) break; // cannot find the number in bank[]
                }
            }
            if (i == strlen(num)) break; // FINISH input ~> break while (1)
            printf(" Invalid %s number, please re-enter.\n", mode);
        }

        /* convert process */
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
        printf(" Decimal number is: %d\n", dec);
        printf("\n Press Enter to continue, Esc to return the main menu.");
        if (getch() == 27) break;
    } while (1); // if press ESC ~> exit loop
}