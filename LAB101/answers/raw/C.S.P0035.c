/*
	Sum of 2 matrices
	Source file: C.S.P0035.c
	Author: Ngo Van Phuong - HE140784
	Last modified: 04/28/2020
*/

#include <stdio.h>
#include <stdlib.h>

void msize(int *a, int *b); /* Input the sizes for the 2 matrices & check validation */
void inptmt(int** m1, int** m2, int a, int b); /* Input the sizes for the 2 matrices & check validation */
void summt(int** m1, int** m2, int a, int b, int** m); /* Calculate sum of the 2 matrices */
void output(int** m, int a, int b); /* Output the new matrix to the screen */
main() {
	int a, b;
	int i;
	int **m1, **m2, **m;
	
	msize(&a, &b);

	/* create 2-D array to store matrix */
	m1 = (int **) malloc(a * sizeof(int *));
	for (i = 0; i < a; i++)
		m1[i] = (int *) malloc(b * sizeof(int));
	m2 = (int **) malloc(a * sizeof(int *));
	for (i = 0; i < a; i++)
		m2[i] = (int *) malloc(b * sizeof(int));
	m = (int **) malloc(a * sizeof(int *));
	for (i = 0; i < a; i++)
		m[i] = (int *) malloc(b * sizeof(int));
	
	inptmt(m1, m2, a, b);
	summt(m1, m2, a, b, m);
	output(m, a, b);
	return 0;
}

void msize(int *a, int *b) { /* Input the sizes for the 2 matrices & check validation */
	char ch1, ch2;
	
	printf("Matrix Add\n");
	while (1) {
		printf("Accept size: ");
		fflush(stdin);
		ch2 = '\0';
		scanf("%d%c%d%c", a, &ch1, b, &ch2);
		if (*a>0 && *b>0 && ch1 == ' ' && ch2 == '\n') 
			break;
		printf("Invalid input, please re-enter.\n");
	}
}

void inptmt(int** m1, int** m2, int a, int b) { /* input the 2 matrices' elements & check validation */
	int i, j;
	char ch;
	
	/* Input & check validation matrix m1 */
	do {
		printf("Accept matrix m1:\n");
		for (i = 0; i < a; i++) {
			ch = '\0';
			fflush(stdin);
			for (j = 0; j <= b-1; j++) {
				scanf("%d", &m1[i][j]);
				if (j == (b-1))  // after last number of row must be '\n'
					ch = getchar();
			}
			if (ch != '\n')
				break; //
			fflush(stdin);		
		}
		if (ch != '\n')
			printf("Invalid input, please re-enter.\n");
		else break;
	} while (ch != '\n');
	
	/* Input & check validation matrix m1 */
	do {
		printf("Accept matricx m2:\n");
		for (i = 0; i < a; i++) {
			ch = '\0';
			for (j = 0; j <= b-1; j++) {
				scanf("%d", &m2[i][j]);
				if (j == (b-1))  // after last number of row must be '\n'
					ch = getchar();
			}
			if (ch != '\n')
				break; //
			fflush(stdin);		
		}
		if (ch != '\n')
			printf("Invalid input, please re-enter.\n");
		else break;
	} while (ch != '\n');
}

void summt(int** m1, int** m2, int a, int b, int** m) { /* Calculate sum of the 2 matrices */
	int i, j;
	
	for (i = 0; i < a; i++) {
		for (j = 0; j < b; j++) {
			m[i][j] = m1[i][j] + m2[i][j];
		}
	}	
}

void output(int** m, int a, int b) { /* Output the new matrix to the screen */
	int i, j;
	
	printf("\nm = m1 + m2:\n");
	for (i = 0; i < a; i++) {
		for (j = 0; j < b; j++) {
			printf("%d\t", m[i][j]);
		}
		printf("\n");
	}
}



