/*
	Reverse a string; convert to upper case and vice versa
	Source file: C.S.P0034.c
	Author: Ngo Van Phuong - HE140784
	Last modified: 04/28/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void input(char a[]); /* Input string & check validation */
void uplow(char b[]); /* Convert uppercase to lowercase and vice versa */
void cnvrt(char a[]); /* Reverse the string, convert uppercase to lowercase and vice versa */
void output( char a[]); /* Output the new string to the screen */

int main() {
	char a[100];
	
	input(a);
	cnvrt(a);
	output(a);
	return 0;
}

void input(char a[]) { /* Input string & check validation */
	while (1) {
		printf("Enter a string: ");
		fflush(stdin);
		strcpy(a, "");
		scanf("%[^\n]", a);
		if (strlen(a) > 0) 
			break;
		printf("Invalid string, please re-enter!\n");
	}
}

void uplow(char b[]) { /* Convert uppercase to lowercase and vice versa */
	int i;
	
	for (i = 0; i<strlen(b); i++) {
		if (isalpha(b[i])) {
			if (isupper(b[i])) {
				b[i] = tolower(b[i]);
			}
			else {
				b[i] = toupper(b[i]);
			}
		}	
	}
}
void cnvrt(char a[]) { /* Reverse the string, convert uppercase to lowercase and vice versa */
	char *b;
	int i;
	
	b = (char *) malloc(sizeof(char) * strlen(a));
	for (i = 0; i <= strlen(a)-1; i++) {
		b[i] = a[strlen(a)-1 - i];
	}
	b[strlen(a)] = '\0';
	uplow(b);
	strcpy(a, b);
}

void output( char a[]) { /* Output the new string to the screen */
	puts(a);
}
