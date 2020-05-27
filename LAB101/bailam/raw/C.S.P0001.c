/*
	Reverse a string
	Source file: C.S.P0001.c
	Author: Ngo Van Phuong - HE140784
	Last modified: 05/11/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input(char *a); /* Input string & check validation */
void reverse(char *a); /* Reverse the string, keep status of all characters */
void display(void); /* Display to the screen the original string and the reversed string */

int main() {
	display();
	return 0;	
}

void input(char *a) { /* Input string & check validation */
    while (1) {
    	printf("Please enter string: ");
		fflush(stdin);
		scanf("%[^\n]", a);
		if (strlen(a) > 0 && strlen(a) <= 80) {  // check validation string
			break;	
		}
		printf("Invalid string, please re-enter.\n");
	}
}

void reverse(char *a) { /* Reverse the string, keep status of all characters */
	char *b, *a_temp, *rev, temp[strlen(a)], *x, delim[8];
	int i, len_b;
	
	b = (char *) calloc(strlen(a), sizeof(char));
	a_temp = (char *) calloc(strlen(a), sizeof(char));
	rev = (char *) calloc(strlen(a), sizeof(char));
	strcpy(temp, "");
	strcpy(a_temp, a);
	strcpy(delim, "_- \t.,");
	x = strtok(a_temp, delim);
	i = strlen(x) + strlen(rev);
	len_b = 0;
	while (strchr(delim, a[i]) != NULL) {
		b[len_b] = a[i];
		len_b++;
		i++;
	}
	strcat(b, x);
	strcat(b, temp);
	strcpy(rev, b);
	free(b);
	
	do {
		x = strtok(NULL, delim);
		if (x != NULL) {
			b = (char *) calloc(strlen(a), sizeof(char));
			strcpy(temp, rev);
			i = strlen(x) + strlen(rev);
			if (i < strlen(a)) {
				len_b = 0;
				while (strchr(delim, a[i]) != NULL) {
					b[len_b] = a[i];
					len_b++;
					i++;
				}
			}
			strcat(b, x);
			strcat(b, temp);
			strcpy(rev, b);
			free(b);
		}
	} while (x != NULL);
	strcpy(a, rev);
	free(a_temp);
	free(rev);
}

void display(void)  { /* Display to the screen the original string and the reversed string */
	char *a, choice;

	do {
		choice = '\0';
		a = (char *) calloc(81, sizeof(char));
		input(a);
		printf("The old string: %s\n", a);
		reverse(a);
		printf("The reversed string: %s\n", a);
		free(a);
		printf("Press enter to continue another reverse, ESC to exit.\n");
		choice = getch();
		printf("\n");
	} while (choice != 27);	
}
