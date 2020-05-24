/* 
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
char* mystrcat(char *a, const char *b);
int mystrcmp(const char *a, const char *b);
char* mystrcpy (char *a, const char *b);
char* mystrnset(char *str, char ch, int n);
char* mystrchr(char *str, int ch);
char* mystrstr (char *str1, const char *str2);

int main() {
    char *x, a[3] = "ab", b[4] = "def";
    /* 
    printf("a = %s\nb = %s\n", a, b);
    x = mystrcat(a, b);
    printf("a = %s\nb = %s\nx = %s", a, b, x);
    
    printf("%d\n", mystrcmp("a", "ab"));
    
    printf("a = %s\nb = %s\n", a, b);
    x = mystrcpy(a, b);
    printf("a = %s\nb = %s\nx = %s", a, b, x);
    */
    //x = mystrnset("abcd", '*', 3);
    //printf("%s\n", x);
    /*
    printf("%s\n", strchr("abcd", 'c'));
    printf("%s\n", mystrchr("abcdcxcz", 'c'));
    */
    printf("%s\n", strstr("abcdefjfghijklmno", "jkl"));
    printf("%s\n", mystrstr("abcdefjfghijklmno", "jkl"));
    return 0;
}

char* mystrcat(char *a, const char *b) {
    int i, j;
    
    i = 0; j = strlen(a);
    while (b[i] != '\0') {
        a[j] = b[i];
        i++;
        j++;
    }
    a[j] = '\0';
    return(a);
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

char* mystrcpy (char *a, const char *b) {
    int i;
    while (b[i] != '\0') {
        a[i] = b[i];
        i++;
    }
    a[i] = '\0';
    return(a);
}

char* mystrnset(char *str, char ch, int n) {
    int i, len;
    char src[n];
    
    len = strlen(str); printf("%d\n", len);
    for (i = 0; i < n; i++) {
        str[i] = ch;
    }
    if (n > len) str[i] = '\0';
    return(str);
}

char* mystrchr (char *str, int ch) {
    int i;
    
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == ch) return (&str[i]);
    }
    return (NULL);
}

char* mystrstr (char *str1, const char *str2) {
    char *p, *src;
    int check, pos, len2;
    
    src = str1;
    while (1) {
        p = mystrchr(src, str2[0]);
        //printf("%s\n", p);
        if (p == NULL) return(NULL);
        check = 1;
        //pos = p - str1;
        len2 = strlen(str2);
        char temp[len2+1];
        memcpy(temp, p, len2 * sizeof(char));
        temp[len2] = '\0';
        //printf("%s\n", temp);
        if (mystrcmp(str2, temp) == 0) {
            return (p);
        }
        else {
            p++;
            src = p;
        }
    }
}
