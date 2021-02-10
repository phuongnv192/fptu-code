/*
	File reading - writing practice
	Source file: C.S.P0048.c
	Author: Ngo Van Phuong - HE140784
	Last modified: 05/03/2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void name(char n[]);  /* Input the file's name */
void content(FILE *fp, char n[]);  /* Input file content */
void output(FILE *fp, char n[]);  /* Display file content */
int main(){
	char *n;
	FILE *fp;
	
	n = (char *) calloc(31, sizeof(char));
	name(n); //  name should be dataCS48
	content(fp, n);
	output(fp, n);
	return 0;
}

void name(char n[]) { /* Input the file's name */
	printf("========== Text management ==========\n");
	while (1) {
		printf("Enter file name to save content: ");
		fflush(stdin);
		scanf("%[^\n]", n);
		if (strlen(n) > 0 && strlen(n) <= 30) {
			strcat(n, ".txt");
			break;
		}
		printf("Invalid name, please re-enter.\n");
	}
}

void content(FILE *fp, char n[]) { /* Input file content */
	char *a;
	
	a = (char *) calloc(81, sizeof(char));
	while (1) {
		printf("Enter content: ");
		fflush(stdin);
		scanf("%[^\n]", a);
		if (strlen(a) > 0 && strlen(a) <= 80) {
			break;
		}
		printf("Invalid content, please re-enter.\n");
	}
	fp = fopen(n, "a");
	fwrite(a, sizeof(char), strlen(a), fp);
	fclose(fp);
	free(a);
}

void output(FILE *fp, char n[]) { /* Display file content */
	char x[31], *a;
	int b;
	
	a = (char *) calloc(500, sizeof(char));
	fp = fopen(n, "r");
	while (!feof(fp)) {
		//strcpy(x, "");
		b = fread(x, 1, 30, fp);
		x[b] = '\0';
		strcat(a, x);
	}
	printf("\nFile content:\n");
	printf("'%s' - This is new data.\n", a);
	fclose(fp);
	free(a);
}
