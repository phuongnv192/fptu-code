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
char* mystrncpy(char *des, const char *src, int n);
char* mystrnset(char *str, int ch, int n);
char* mystrchr(char *str, int ch);
char* mystrstr(char *str1, const char *str2);
int scanline(char a[], char bfr); /* Scan a string until get bfr or \n */
void runstrcat(void);
void runstrcmp(void);
void runstrcpy(void);
void runstrncpy(void);
void runstrnset(void);
void runstrchr(void);
void runstrstr(void);
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
        printf("4- mystrncpy\n");
        printf("5- mystrnset\n");
        printf("6- mystrchr\n");
        printf("7- mystrstr\n");
        printf("0- Quit\n");
        printf("Enter your choice: ");

        scanf("%[^\n]", x);
        buffer();
        fflush(stdin);
        if (strlen(x) == 1 && strcmp(x, "7") <= 0 && strcmp(x, "0") >= 0) {
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

char* mystrncpy(char *des, const char *src, int n) {
    int i, len;

    len = strlen(des);
    if (n > len) {
        des = (char *) realloc(des, n + 1);
    }
    for (i = 0; i < n && src[i] != '\0'; i++) {
        des[i] = src[i];
    }
    des[i] = '\0';
    return (des);
}

char* mystrnset(char *str, int ch, int n) {
    int i, len, check;

    len = strlen(str);
    check = 0;
    if (n > len) {
        str = (char *) realloc(str, n + 1);
        check = 1;
    }
    for (i = 0; i < n; i++) {
        str[i] = ch;
    }
    if (check == 1) str[i] = '\0';
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
        if (p > src + len2 - 1) return (NULL);
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
    char *a, *b, mid[4], end[4], *x;
    int s, cond, i;

    a = (char *) calloc(51, sizeof (char));
    b = (char *) calloc(51, sizeof (char));
    printf(" mystrcat(\"str1\", \"str2\");\n\n");
    do { // x = mystrcat("str1", "str2");
        printf(" x = mystrcat(\"");
        fflush(stdin);
        cond = scanline(a, '\"');
        if (cond == 0) {
            printf("Invalid input, please re-enter.\n");
            continue;
        } else {
            cond = scanline(mid, '\"');
            if (cond == 0 || (mystrcmp(mid, ", ") != 0)) {
                //buffer();
                printf("Invalid input, please re-enter.\n");
                continue;
            } else {
                cond = scanline(b, '\"');
                if (cond == 0) {
                    printf("Invalid input, please re-enter.\n");
                    continue;
                } else {
                    s = scanf("%[^\n]", end);
                    buffer();
                    if (s != 1 || (mystrcmp(end, ");") != 0)) {
                        cond = 0;
                        printf("Invalid input, please re-enter.\n");
                    }
                }
            }
        }
    } while (cond == 0);
    printf("\n Before:\n str1 = \"%s\"\n", a);
    printf(" str2 = \"%s\"\n", b);
    x = mystrcat(a, b);
    printf("\n After:\n str1 = \"%s\"\n", a);
    printf(" str2 = \"%s\"\n", b);
    printf(" x = \"%s\"\n", x);
}

void runstrcmp(void) {
    char *a, *b, mid[4], end[4];
    int s, cond, i, x;

    a = (char *) calloc(51, sizeof (char));
    b = (char *) calloc(51, sizeof (char));
    printf(" mystrcmp(\"str1\", \"str2\");\n\n");
    do { // x = mystrcmp("str1", "str2"); 
        printf(" x = mystrcmp(\"");
        fflush(stdin);
        cond = scanline(a, '\"');
        if (cond == 0) {
            printf("Invalid input, please re-enter.\n");
            continue;
        } else {
            cond = scanline(mid, '\"');
            if (cond == 0 || (mystrcmp(mid, ", ") != 0)) {
                printf("Invalid input, please re-enter.\n");
                continue;
            } else {
                cond = scanline(b, '\"');
                if (cond == 0) {
                    printf("Invalid input, please re-enter.\n");
                    continue;
                } else {
                    s = scanf("%[^\n]", end);
                    buffer();
                    if (s != 1 || (mystrcmp(end, ");") != 0)) {
                        cond = 0;
                        printf("Invalid input, please re-enter.\n");
                    }
                }
            }
        }
    } while (cond == 0);

    x = mystrcmp(a, b);
    printf("\n str1 = \"%s\"\n", a);
    printf(" str2 = \"%s\"\n", b);
    printf(" x = %d", x);
    if (x > 0) printf(" (str1 > str2)\n");
    else if (x < 0) printf(" (str1 < str2)\n");
    else printf(" (str1 = str2)\n");
}

void runstrcpy(void) {
    char *a, *b, mid[4], end[4], *x;
    int s, cond, i;

    a = (char *) calloc(51, sizeof (char));
    b = (char *) calloc(51, sizeof (char));
    printf(" mystrcpy(\"str1\", \"str2\");\n\n");
    do { // x = mystrcpy("str1", "str2");
        printf(" x = mystrcpy(\"");
        fflush(stdin);
        cond = scanline(a, '\"');
        if (cond == 0) {
            printf("Invalid input, please re-enter.\n");
            continue;
        } else {
            cond = scanline(mid, '\"');
            if (cond == 0 || (mystrcmp(mid, ", ") != 0)) {
                printf("Invalid input, please re-enter.\n");
                continue;
            } else {
                cond = scanline(b, '\"');
                if (cond == 0) {
                    printf("Invalid input, please re-enter.\n");
                    continue;
                } else {
                    s = scanf("%[^\n]", end);
                    buffer();
                    if (s != 1 || (mystrcmp(end, ");") != 0)) {
                        cond = 0;
                        printf("Invalid input, please re-enter.\n");
                    }
                }
            }
        }
    } while (cond == 0);
    printf("\n Before:\n str1 = \"%s\"\n", a);
    printf(" str2 = \"%s\"\n", b);
    x = mystrcpy(a, b);
    printf("\n After:\n str1 = \"%s\"\n", a);
    printf(" str2 = \"%s\"\n", b);
    printf(" x = \"%s\"\n", x);
}

void runstrncpy(void) {
    char *a, *b, mid[4], mid2[2], end[4], *x, nchar[12];
    int s, cond, i, n;

    a = (char *) calloc(51, sizeof (char));
    b = (char *) calloc(51, sizeof (char));
    printf(" mystrncpy(\"str1\", \"str2\", n);\n\n");
    do { // x = mystrncpy("str1", "str2", n);
        printf(" x = mystrncpy(\"");
        fflush(stdin);
        cond = scanline(a, '\"'); // str1"
        if (cond == 0) {
            printf("Invalid input1, please re-enter.\n");
            continue;
        } else {
            cond = scanline(mid, '\"'); // , "
            if (cond == 0 || (mystrcmp(mid, ", ") != 0)) {
                printf("Invalid input2, please re-enter.\n");
                continue;
            } else {
                cond = scanline(b, '\"'); // str2"
                if (cond == 0) {
                    printf("Invalid input3, please re-enter.\n");
                    continue;
                } else {
                    cond = scanline(mid2, ' '); // , 
                    if (cond == 0 || (mystrcmp(mid2, ",") != 0)) {
                        printf("Invalid input4, please re-enter.\n");
                        continue;
                    } else {
                        cond = scanline(nchar, ')'); // n)
                        n = atoi(nchar);
                        if (cond == 0 || !(n > 0)) {
                            printf("Invalid input5, please re-enter.\n");
                            continue;
                        } else {
                            s = scanf("%[^\n]", end);
                            buffer();
                            if (s != 1 || (mystrcmp(end, ";") != 0)) {
                                cond = 0;
                                printf("Invalid input6, please re-enter.\n");
                            }
                        }
                    }
                }
            }
        }
    } while (cond == 0);
    printf("\n Before:\n str1 = \"%s\"\n", a);
    printf(" str2 = \"%s\"\n", b);
    printf(" n = %d\n", n);
    x = mystrncpy(a, b, n);
    printf("\n After:\n str1 = \"%s\"\n", a);
    printf(" str2 = \"%s\"\n", b);
    printf(" x = \"%s\"\n", x);
}

void runstrnset(void) {
    char *a, ch[2], c, mid[4], mid2[2], end[4], *x, nchar[12];
    int s, cond, i, n;

    a = (char *) calloc(51, sizeof (char));
    printf(" mystrnset(\"str\", 'ch', n);\n\n");
    do { // x = mystrnset("str", 'ch', n);
        printf(" x = mystrnset(\"");
        fflush(stdin);
        cond = scanline(a, '\"'); // str"
        if (cond == 0) {
            printf("Invalid input1, please re-enter.\n");
            continue;
        } else {
            cond = scanline(mid, '\''); // , '
            if (cond == 0 || (mystrcmp(mid, ", ") != 0)) {
                printf("Invalid input2, please re-enter.\n");
                continue;
            } else {
                cond = scanline(ch, '\''); // ch'
                if (cond == 0 || strlen(ch) > 1) {
                    printf("Invalid input3, please re-enter.\n");
                    continue;
                } else {
                    cond = scanline(mid2, ' '); // , 
                    if (cond == 0 || (mystrcmp(mid2, ",") != 0)) {
                        printf("Invalid input4, please re-enter.\n");
                        continue;
                    } else {
                        cond = scanline(nchar, ')'); // n)
                        n = atoi(nchar);
                        if (cond == 0 || !(n > 0)) {
                            printf("Invalid input5, please re-enter.\n");
                            continue;
                        } else {
                            s = scanf("%[^\n]", end);
                            buffer();
                            if (s != 1 || (mystrcmp(end, ";") != 0)) {
                                cond = 0;
                                printf("Invalid input6, please re-enter.\n");
                            }
                        }
                    }
                }
            }
        }
    } while (cond == 0);
    c = ch[0];
    printf("\n Before:\n str = \"%s\"\n", a);
    printf(" ch = \'%c\'\n", c);
    printf(" n = %d\n", n);
    x = mystrnset(a, c, n);
    printf("\n After:\n str = \"%s\"\n", a);
    printf(" x = \"%s\"\n", x);
}

void runstrchr(void) {
    char *a, mid[4], end[4], *x, ch[2], c;
    int s, cond, i;

    a = (char *) calloc(51, sizeof (char));
    printf(" mystrchr(\"str\", 'ch', n);\n\n");
    do { // x = mystrnchr("str", 'ch');
        printf(" x = mystrchr(\"");
        fflush(stdin);
        cond = scanline(a, '\"'); // str"
        if (cond == 0) {
            printf("Invalid input1, please re-enter.\n");
            continue;
        } else {
            cond = scanline(mid, '\''); // , '
            if (cond == 0 || (mystrcmp(mid, ", ") != 0)) {
                printf("Invalid input2, please re-enter.\n");
                continue;
            } else {
                cond = scanline(ch, '\''); // ch'
                if (cond == 0 || strlen(ch) > 1) {
                    printf("Invalid input3, please re-enter.\n");
                    continue;
                } else {
                    s = scanf("%[^\n]", end); // );
                    buffer();
                    if (s != 1 || (mystrcmp(end, ");") != 0)) {
                        cond = 0;
                        printf("Invalid input4, please re-enter.\n");
                    }
                }
            }
        }
    } while (cond == 0);
    c = ch[0];
    printf("\n str = \"%s\"\n", a);
    printf(" ch = \'%c\'\n", c);
    x = mystrchr(a, c);
    printf(" x = \"%s\"\n", x);
}

void runstrstr(void) {
    char *a, *b, mid[4], end[4], *x;
    int s, cond, i;

    a = (char *) calloc(51, sizeof (char));
    b = (char *) calloc(51, sizeof (char));
    printf(" mystrstr(\"str1\", \"str2\");\n\n");
    do { // x = mystrstr("str1", "str2");
        printf(" x = mystrstr(\"");
        fflush(stdin);
        cond = scanline(a, '\"');
        if (cond == 0) {
            printf("Invalid input, please re-enter.\n");
            continue;
        } else {
            cond = scanline(mid, '\"');
            if (cond == 0 || (mystrcmp(mid, ", ") != 0)) {
                printf("Invalid input, please re-enter.\n");
                continue;
            } else {
                cond = scanline(b, '\"');
                if (cond == 0) {
                    printf("Invalid input, please re-enter.\n");
                    continue;
                } else {
                    s = scanf("%[^\n]", end);
                    buffer();
                    if (s != 1 || (mystrcmp(end, ");") != 0)) {
                        cond = 0;
                        printf("Invalid input, please re-enter.\n");
                    }
                }
            }
        }
    } while (cond == 0);
    printf("\n str1 = \"%s\"\n", a);
    printf(" str2 = \"%s\"\n", b);
    x = mystrstr(a, b);
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
            runstrcpy();
            break;
        }
        case 4:
        {
            runstrncpy();
            break;
        }
        case 5:
        {
            runstrnset();
            break;
        }
        case 6:
        {
            runstrchr();
            break;
        }
        case 7:
        {
            runstrstr();
            break;
        }
    }
    printf("\nPress Enter to continue.");
    getch();
}
