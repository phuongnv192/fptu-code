#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool prime(int x){
	for (int i = 2; i <= sqrt(x); i++) { 
		if ((x%i) == 0){
			return(false);
		}
	}
	return(true);
}

int main() {
	int lower, upper, col, start, k;
	char ch;
	
	printf("Table of Primes\n");
	printf("===============\n");
	
	/* input lower & check validation */
	while (1) {
		printf("Lower limit: ");
		fflush(stdin);
		ch = '\0';
		scanf("%d%c", &lower, &ch);
		if (ch == '\n') {
			break;
		}
		else {
			printf("Invalid intput, please re-enter\n");
		}
	}
	
	/* input upper & check validation */
	while (1) {
		printf("Upper limit: ");
		fflush(stdin);
		ch = '\0';
		scanf("%d%c", &upper, &ch);
		if (upper>=lower && upper>=2 && ch == '\n') {
			break;
		}
		else {
			printf("Invalid intput, please re-enter\n");
		}
	}
	
	/* input col & check validation */
	while (1) {
		printf("# of columns: ");
		fflush(stdin);
		ch = '\0';
		scanf("%d%c", &col, &ch);
		if (ch == '\n') {
			break;
		}
		else {
			printf("Invalid intput, please re-enter\n");
		}
	}
	
	printf("\n");
	if (lower < 2) {
		start  = 2;
	}
	else {
		start = lower;
	}
	k = 0;
	for (int i = start; i <= upper; i++) {
		if (prime(i) == true) {
			printf("%8d", i);
			k++;
			if (k%col == 0) {
				printf("\n");
			}
		}
	}
	if (k == 0) {
		printf("There is no prime number between %d and %d!\n", lower, upper);
	}
	return(0);
}

