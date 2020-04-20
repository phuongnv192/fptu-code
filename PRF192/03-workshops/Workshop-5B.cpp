#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

void menu(void);
void coinToss(void);
void toss(void);
void stringrv(void);

int main() {
	printf("+----------------------------------------------+\nQ1:\n");
	coinToss();
	printf("\n+----------------------------------------------+\nQ2:\n");
	stringrv();
	return(0);
}

void menu(void) {
	printf("\n   +------------------+\n");
	printf("   |  Select option:  |\n");
	printf("   | 1. Start tossing |\n");
	printf("   | 0. Exit          |\n");
	printf("   +------------------+\n");
}

void coinToss(void) {
	int choice;
	char ch;
	
	while (1) {
		menu();
		while (1) {
			printf(" Your selection (0 -> 1): ");
			fflush(stdin); 
			ch = '\0';
			scanf("%d%c", &choice, &ch);
			if (choice >= 0 && choice <= 1 && ch == '\n') {
				break;
			}
			printf(" Your selection is incorrect\n");
		}

		if (choice == 0) break;
		else {
			toss();
		}
	}
}

void toss(void) {
	int a, head, tail;
	char ch;
	
	printf("\n");
	while (1) {
		printf(" Enter number of tosses: ");
		fflush(stdin); 
		ch = '\0';
		scanf("%d%c", &a, &ch);
		if (a > 0 && ch == '\n') break;
		printf(" Invalid input, please re-enter.\n");
	}
	
	srand(time(NULL));
	head = 0; tail = 0;
	for (int i = 1; i <= a; i++) {
		if (rand() % 2 == 1) head++;
		else tail++;
	}
	printf("\n Number of tosses: %d\n", a);
	printf(" Number of head: %d\n", head);
	printf(" Number of tails: %d\n", tail);
	printf(" Percentage of heads for all tosses: %.2f\n", (float) head/a*100);
}

void stringrv(void) {
	int x;
	char n[100], choice;
	
	/* do-while(1) loop if choice == 'y' */
	do {
		printf("\n Enter string end by . : ");
		x = 0;
		fflush(stdin);
		while ((n[x++] = getchar()) != '.' ); x--;
		/*
		while (1) {
			n[x] = getchar();
			if (n[x] == '.') break;
			x++;
		}*/
		n[x] = '\0';
		printf("\n The original string: ");
		puts(n);
		printf(" The reverse string: ");
		for (int i = x-1; i >= 0; i--) putchar(n[i]);
		printf("\n\n");
		
		/* loop "Another run" until choice == 'n' or 'y' */
		do {
			fflush(stdin);
			choice = '\0';
			printf(" Another run <y/n>? ");
			scanf("%c", &choice);
			if (choice != 'n' && choice != 'y') {
				printf(" Your selection is incorrect!\n");
			}
		} while (choice != 'n' && choice != 'y');
		
	} while (choice != 'n');
}
