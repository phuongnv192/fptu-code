/*
	Count the number of the appearance of letters in a string 
	Source file: C.S.P0036.c
	Author: Ngo Van Phuong - HE140784
	Last modified: 04/28/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void input(char a[]);   /* Input string & check validation */
int count(char a[], int c[]);  /* Count the number of appearances of letters */
void output(int c[]);  /* Output the letter and the number are appearanced */

int main() {
	char a[100];
	int c[26], i, check;  // c[0]-c[25] count number of appearances of a-z 
	
	/* set count number = 0 */
	for (i = 0; i<26; i++) 
		c[i] = 0;

	input(a);
	check = count(a, c);
	if (check == 0)  // check = 0 means strings doesn't have any letters
		printf("String doesn't have any letters.\n");
	else output(c);
	return 0;
}

void input(char a[]) {  /* Input string & check validation */
	while (1) {
		printf("Enter a string: ");
		fflush(stdin);  // clear buffer
		strcpy(a, "");  // reset variable a
		scanf("%[^\n]", a);
		if (strlen(a) != 0)  // if
			break;
		printf("Invalid string, please re-enter!\n");
	}
}

int count(char a[], int c[]) {  /* Count the number of appearances of letters */
	int i, x, check;
	
	check = 0;  // check = 0 means strings doesn't have any letters
	for (i = 0; i < strlen(a); i++) {
		if (isalpha(a[i])) {
			check = 1;  // check = 1 means strings have letters
			if (isupper(a[i])) {
				a[i] = tolower(a[i]);
			}
			x = a[i] % 97;
			c[x]++;
		}
	}
	return(check);
}

void output(int c[]) {  /* Output the letter and the number are appearanced */
	int i;
	
	for (i = 0;i < 26; i++ ) {
		if (c[i] > 0) {
			printf("%c: %d\n", i+97, c[i]);
		}
	}
}
