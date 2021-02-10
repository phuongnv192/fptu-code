/*
	Reading a file
	Source file: C.S.P0038.c
	Author: Ngo Van Phuong - HE140784
	Last modified: 04/28/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int inputfile(FILE *fp); /* Input text file path */
void readfile(FILE *fp, char x[], int len);  /* Read text file content */
void output(char x[]); /* Print the text file content to the screen */

int main() {
	FILE *fp;
	char x[100];
	int n;
	
	n = inputfile(fp);
	readfile(fp, x, n);
	output(x);
	return 0;
}

int inputfile(FILE *fp) { /* Input text file path */
	char *a;
	
	fp = fopen("dataCS38.txt", "w");
	a = (char *) calloc(100, sizeof(char));
	printf("File name: dataCS38.txt\n");
	printf("Enter file detail:\n");
	scanf("%[^\n]", a);
	fwrite(a, sizeof(char), strlen(a), fp);
	fclose(fp);
	return (strlen(a));
}

void readfile(FILE *fp, char x[], int len) {  /* Read text file content */
	fp = fopen("dataCS38.txt", "r");
	fread(x, 1, len, fp);
	fclose(fp);
}

void output(char x[]) { /* Print the text file content to the screen */
	printf("\nFile name: dataCS38.txt\n");
	printf("File content:\n");
	printf("%s\n", x);
}

