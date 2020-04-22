#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
/* menu, input check and "Another run?" loop */

void menu(void);
void cointoss(void);

int main() {
	int choice;
	char ch;
	
	while (1) {
		while (1) {
			system("cls");
			menu();
			printf("                     Enter your selection (0 -> 2): ");
			fflush(stdin);
			ch = '\0';
			scanf("%d%c", &choice, &ch);
			if (choice >= 0 && choice <= 2 && ch == '\n') {
				break;
			}
			printf("                     Your selection is incorrect\n");
			printf("\n");
			printf("Press any key to continue...\n");
	      	getch();
		}
		
		if (choice == 0) {
			break;
		}
		switch (choice) {
			case 1: {
				cointoss();
				break;
			}
			case 2: {
				printf("lalala\n");
				break;
			}
		}
		printf("\n");
		printf("Press any key to continue...");
      	getch();
	}
	return(0);
}

void menu(void) {
	printf("                     +---------------------------+\n");
	printf("                     |   Financial Calculator    |\n");
	printf("                     +---------------------------+\n");
	printf("                     | 1. Coin tossing           |\n");
	printf("                     | 2. Investment calculation |\n");
	printf("                     | 0. Exit                   |\n");
	printf("                     +---------------------------+\n\n");
}

void cointoss(void) {
	int a, head, tail;
	char ch, choice;
	
	/* do-while(1) loop if choice == 'y' */
	do {
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
		printf(" Percentage of heads for all tosses: %.2f\n\n", (float) head/a*100);
		
		/* loop "Another run" until choice == 'n' or 'y' */
		do {
			fflush(stdin);
			choice = '\0';
			printf("Another run <y/n>? ");
			scanf("%c", &choice);
			if (choice != 'n' && choice != 'y') {
				printf("Your selection is incorrect!\n");
			}
		} while (choice != 'n' && choice != 'y');
	} while (choice == 'y');
}
