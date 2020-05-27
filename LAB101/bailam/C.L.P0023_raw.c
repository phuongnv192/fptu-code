/* Rewrite some basic functions in C: strcat, strcmp, strcpy, strncpy, strnset, strstr, strchr 
 * File:   phuong_C.L.P0023.c
 * Author: ADMIN
 *
 * Created on May 24, 2020, 10:13 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
void getch(void); /* pauses the Output console until Enter is pressed */
void buffer(void); /* temp statement to clear buffer */
int menuselect(void); /* Display a menu and asks users to select an option */
char* mystrcat(char *a, const char *b);
int mystrcmp(const char *a, const char *b);
char* mystrcpy(char *a, const char *b);
char* mystrnset(char *str, int ch, int n);
char* mystrchr(char *str, int ch);
char* mystrstr(char *str1, const char *str2);
void runstrcat(void);
void menurun(int choice); /* Perform selected function */

int main() {
    int choice;

    while (1) {
        choice = menuselect();
        if (choice == 0) break;
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
    char x[2];

    while (1) {
        system("clear");
        printf("MENU\n");
        printf("------------------------------\n\n");
        printf("1- mystrcat\n");
        printf("2- mystrcmp\n");
        printf("3- mystrcpy\n");
        printf("4- mystrnset\n");
        printf("5- mystrchr\n");
        printf("6- mystrstr\n");
        printf("0- Quit\n");
        printf("Enter your choice: ");

        scanf("%[^\n]", x);
        buffer();
        fflush(stdin);
        if (strlen(x) == 1 && strcmp(x, "6") <= 0 && strcmp(x, "0") >= 0) {
            return (atoi(x));
        }
        printf("Invalid choice, press Enter to continue.");
        getch();
    }
}

char* mystrcat(char *a, const char *b) {
    int i, j;

    i = 0;
    j = strlen(a);
    while (b[i] != '\0') {
        a[j] = b[i];
        i++;
        j++;
    }
    a[j] = '\0';
    return (a);
}

int mystrcmp(const char *a, const char *b) {
    int i;

    i = 0;
    while (a[i] != '\0') {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
        i++;
    }
    if (b[i] == '\0') return 0;
    else return -1;
}

char* mystrcpy(char *a, const char *b) {
    int i;

    i = 0;
    while (b[i] != '\0') {
        a[i] = b[i];
        i++;
    }
    a[i] = 0;
    return (a);
}

char* mystrnset(char *str, int ch, int n) {
    int i, len;

    len = strlen(str);
    printf("%d\n", len);
    for (i = 0; i < n; i++) {
        str[i] = 42;
    }
    if (n > len) str[i] = '\0';
    return (str);
}

char* mystrchr(char *str, int ch) {
    int i;

    for (i = 0; i < strlen(str); i++) {
        if (str[i] == ch) return (&str[i]);
    }
    return (NULL);
}

char* mystrstr(char *str1, const char *str2) {
    char *p, *src;
    int len2;

    src = str1;
    while (1) {
        p = mystrchr(src, str2[0]);
        if (p == NULL) return (NULL);
        len2 = strlen(str2);
        if (memcmp(str2, p, len2 * sizeof (char)) == 0) {
            return (p);
        } else {
            p++;
            src = p;
        }
    }
}

/* Scan a string until get bfr or \n */
int scanline(char a[], char bfr) {
    int check, i;

    i = 0;
    while (1) {
        fflush(stdin);
        a[i] = getchar();
        if (a[i] == '\n') {
            check = 0;
            break;
        }
        if (a[i] == bfr) {
            a[i] = '\0';
            check = 1;
            break;
        }
        i++;
    }
    return (check);
}

void runstrcat(void) {
    char a[51], b[51], mid[4], end[4], *x;
    int s, cond, i;

    printf("mystrcat(\"str1\", \"str2\");\n");

    do {
        printf(" x = mystrcat(\"");
        fflush(stdin);
        cond = scanline(a, '\"');
        if (cond == 0) {
            printf("Invalid input1, please re-enter.\n");
            continue;
        } else {
            cond = scanline(mid, '\"');
            if (cond == 0 || (mystrcmp(mid, ", ") != 0)) {
                //buffer();
                printf("Invalid input2, please re-enter.\n");
                continue;
            } else {
                cond = scanline(b, '\"');
                if (cond == 0) {
                    printf("Invalid input3, please re-enter.\n");
                    continue;
                } else {
                    s = scanf("%[^\n]", end);
                    buffer();
                    if (s != 1 || (mystrcmp(end, ");") != 0)) {
                        cond = 0;
                        printf("Invalid input4, please re-enter.\n");
                    }
                }
            }
        }
    } while (cond == 0);
    printf("\n Before:\n a = \"%s\"\n", a);
    printf(" b = \"%s\"\n", b);
    x = mystrcat(a, b);
    printf("\n After:\n a = \"%s\"\n", a);
    printf(" b = \"%s\"\n", b);
    printf(" x = \"%s\"\n", x);
}

void runstrcmp(void) {
    char a[51], b[51], mid[4], end[4];
    int s, cond, i, x;

    printf("mystrcmp(\"str1\", \"str2\");\n");

    do {
        printf(" x = mystrcmp(\"");
        fflush(stdin);
        i = 0;
        cond = 69;
        while (1) {
            fflush(stdin);
            a[i] = getchar();
            //printf("a = '%s'\n", a);
            if (a[i] == '\n') {
                cond = 0;
                break;
            }
            if (a[i] == '\"') {
                a[i] = '\0';
                break;
            }
            i++;
        }
        if (cond == 0) {
            printf("Invalid input, please re-enter.\n");
            continue;
        } else {
            i = 0; // mid = , "
            while (1) {
                fflush(stdin);
                mid[i] = getchar();
                //printf("mid = '%s'\n", mid);
                if (mid[i] == '\n') {
                    cond = 0;
                    break;
                }
                if (mid[i] == '\"') break;
                i++;
            }
            if (cond == 0 || (mystrcmp(mid, ", \"") != 0)) {
                printf("Invalid input, please re-enter.\n");
                continue;
            } else { // end = ");
                s = scanf("%[^\"]%[^\n]", b, end);
                buffer();
                if (s == 2 && (mystrcmp(end, "\");") == 0)) {
                    cond = 1;
                } else {
                    cond = 0;
                    printf("Invalid input, please re-enter.\n");
                }
            }
        }

    } while (cond == 0);
    x = mystrcmp(a, b);
    printf("\n a = \"%s\"\n", a);
    printf(" b = \"%s\"\n", b);
    printf(" x = \"%s\"\n", x);
}

void menurun(int choice) { /* Perform selected function */
    printf("\n");
    switch (choice) {
        case 1:
        {
            runstrcat();
            break;
        }
        case 2:
        {
            runstrcmp();
            break;
        }
        case 3:
        {
            runstrcat();
            break;
        }
        case 4:
        {
            runstrcat();
            break;
        }
        case 5:
        {
            runstrcat();
            break;
        }
        case 6:
        {
            runstrcat();
            break;
        }
    }
    printf("\nPress Enter to continue.");
    getch();
}