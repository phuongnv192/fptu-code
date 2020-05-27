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
void getch(void); /* pauses the Output console until Enter is pressed */
void buffer(void); /* temp statement to clear buffer */
int menuselect(void);  /* Display a menu and asks users to select an option */
void inputbin(char bi[]); /* Input binary number & check validation */
int convertbin(char bi[]); /* Convert binary number to decimal number */
void output(int dec); /* Display a decimal number to the screen */
void bin2dec(void); /* Enter, convert & display binary number to decimal number */
void inputoct(char oc[]); /* Input octal number & check validation */
int convertoct(char oc[]); /* Convert octal number to decimal number */
void oct2dec(void); /* Enter, convert & display octal number to decimal number */
void inputhex(char he[]); /* Input hexadecimal number & check validation */
int converthex(char he[]); /* Convert hexadecimal number to decimal number */
void hex2dec(void); /* Enter, convert & display hexadecimal number to decimal number */
void menurun(int choice);  /* Perform selected function */ 

int main() {
    int choice;
    
    while (1) {
        choice = menuselect();
        if (choice == 4) {
            break;
        }
        menurun(choice);
    }
    return 0;
}

/* Pauses the Output console until Enter is pressed */
void getch(void) {
    while (getchar() != '\n');
}

/* temp statement to clear buffer */
void buffer(void) {
    char temp; 
    scanf("%c", &temp); 
}

/* Display a menu and asks users to select an option */
int menuselect(void) {
    char *x;
    
    x = (char *) calloc(2, sizeof(char));
    while (1) {
        system("clear");
        printf("MENU\n");
        printf("-------------------------------------------------\n\n");
        printf("1.  Convert binary number to decimal number\n");
        printf("2.  Convert octal number to decimal number\n");
        printf("3.  Convert hexadecimal number to decimal number\n");
        printf("4.  Exit\n");
        printf(" Please choose number (1 - 4): ");
        fflush(stdin);
        scanf("%[^\n]", x); buffer();
        if (strlen(x) == 1 && strcmp(x, "4") <= 0 && strcmp(x, "1") >= 0) {
            return(atoi(x));
        }
        printf(" Invalid choice, press Enter to continue.");
        getch();
        
    }
}

/* Input binary number & check validation */
void inputbin(char bi[]) {
    int len, i, check;
    
    while (1) {
        printf("    Enter binary number: ");
        fflush(stdin);
        scanf("%[^\n]", bi); buffer();
        len = strlen(bi);
        check = 1; // it's a binary number
        if (len > 0 && len <= 31) {
            for (i = 0; i <= len-1; i++) {
                if (bi[i] != '0' && bi[i] != '1') { // only 0-1
                    check = 0; // it's not binary number
                    break;
                }
            }
            if (check == 1) { // break while (1)
                break;
            }
        }
        printf("    Invalid binary number, please re-enter.\n");
    }
}

/* Convert binary number to decimal number */
int convertbin(char bi[]) {
    int i, power, dec, len, chuso;
    
    len = strlen(bi);
    dec = 0; power = 0;
    for (i = len-1; i >= 0; i--) {
        chuso = bi[i] - 48; // chuyen ki tu ve chu so: '0' ~> 0
        dec += chuso * pow(2, power);
        power++;
    }
    return (dec);
}

/* Display a decimal number to the screen */
void output(int dec) {
    printf("    Decimal number is: %d\n", dec);
}

/* Enter, convert & display binary number to decimal number */
void bin2dec(void) {
    int result;
    char *bin; 
    
    bin = (char *) calloc(32, sizeof(char)); // int_MAX in binary have max 31 digits
    inputbin(bin);
    result = convertbin(bin);
    output(result);
}

/* Input octal number & check validation */
void inputoct(char oc[]) {
    int len, i, check;
    
    while (1) {
        printf("    Enter octal number: ");
        fflush(stdin);
        scanf("%[^\n]", oc); buffer();
        len = strlen(oc);
        check = 1; // it's a octal number
        if (len > 0 && len <= 11) {
            for (i = 0; i <= len-1; i++) {
                if (oc[i] < '0' || oc[i] > '7') { // only 0-7
                    check = 0; // it's not octal number
                    break;
                }
            }
            if (check == 1) { // break while (1)
                break;
            }
        }
        printf("    Invalid octal number, please re-enter.\n");
    }
}

/* Convert octal number to decimal number */
int convertoct(char oc[]) {
    int i, power, dec, len, chuso;
    
    len = strlen(oc);
    dec = 0; power = 0;
    for (i = len-1; i >= 0; i--) {
        chuso = oc[i] - 48; // chuyen ki tu ve chu so: '0' ~> 0
        dec += chuso * pow(8, power);
        power++;
    }
    return (dec);
}

/* Enter, convert & display octal number to decimal number */
void oct2dec(void) {
    int result;
    char *oct; 
    
    oct = (char *) calloc(12, sizeof(char)); // int_MAX in octal have max 11 digits
    inputoct(oct);
    result = convertoct(oct);
    output(result);
}

/* Input hexadecimal number & check validation */
void inputhex(char he[]) {
    int len, i, check;
    
    while (1) {
        printf("    Enter hexadecimal number: ");
        fflush(stdin);
        scanf("%[^\n]", he); buffer();
        len = strlen(he);
        check = 1; // it's a hexadecimal number
        if (len > 0 && len <= 8) {
            for (i = 0; i <= len-1; i++) {
                if ((he[i] < '0' || he[i] > '9') && (he[i] < 'A' || he[i] > 'F') && (he[i] < 'a' || he[i] > 'f')) { // only 0-7
                    check = 0; // it's not hexadecimal number
                    break;
                }
            }
            if (check == 1) { // break while (1)
                break;
            }
        }
        printf("    Invalid hexadecimal number, please re-enter.\n");
    }
}

/* Convert hexadecimal number to decimal number */
int converthex(char he[]) {
    int i, power, dec, len, chuso;
    char cs[23] = "0123456789ABCDEFabcdef"; int csval[22], pos;
    char *p;
    
    for (i = 0; i < 22; i++) {
        if (i <= 15) {
            csval[i] = i; // 0-F = 0-15
        }
        else csval[i] = i-6; // a-f = 10-15
    }
    len = strlen(he);
    dec = 0; power = 0;
    for (i = len-1; i >= 0; i--) {
        p = strchr(cs, he[i]);
        pos = p - cs; // dia chi cua he[i]- dia chi cs[] ~ cs[0]
        chuso = csval[pos]; // chuyen ki tu ve chu so: '0' ~> 0
        dec += chuso * pow(16, power);
        power++;
    }
    return (dec);
}

/* Enter, convert & display hexadecimal number to decimal number */
void hex2dec(void) {
    int result;
    char *hex; 
    
    hex = (char *) calloc(9, sizeof(char)); // int_MAX in octal have max 11 digits
    inputhex(hex);
    result = converthex(hex);
    output(result);
}

/* Perform selected function */
void menurun(int choice) {  
    printf("\n");
    
    switch (choice) {
        case 1: {
            bin2dec();
            break;
        }
        case 2: {
            oct2dec();
            break;
        }
        case 3: {
            hex2dec();
            break;
        }
    }
    printf("\n Press Enter to continue.");
    getch();
}
