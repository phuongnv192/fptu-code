#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/* menu, input check and "Another run?" loop */

void menu(void);
void saving(void);

int main() {
	printf("                     +---------------------------+\n");
	return(0);
}

void coinToss() {
	int choice;
	char ch;
	
	while (1) {
		printf("Select option:\n");
		printf("1. Start tossing\n");
		printf("0. Exit\n");
		while (1) {
			printf("Your selection (0 -> 1): ");
			fflush(stdin); 
			ch = '\0';
			scanf("%d%c", &choice, &ch);
			if (choice >= 0 && choice <= 1 && ch == '\n') {
				break;
			}
			printf("Your selection is incorrect\n");
		}

		if (choice == 0) break;
		else {
			toss();
		}
	}
}

void toss(void) {
	int a, head, tail;
	
	while (1) {
		printf("Enter number of toss: ");
		fflush(stdin); 
		ch = '\0';
		scanf("%d%c", &a, &ch)
		if (a > 0 && ch == '\n') break;
		printf("Invalid input, please re-enter.\n");
	}
	srand(time(NULL));
	head = 0; tail = 0;
	for (int i = 1; i <= a; i++) {
		if (rand() % 2 == 1) head++;
		else tail++;
	}
}

void saving(void) {
	double pri, rate, future;
	int year;
	char ch, x1[13], x2[13], choice;
	
	/* do-while(1) loop if choice == 'y' */
	do {
		printf("\n1. Test saving account\n");
			
		/* input principal amount & check validation */
		while (1) {
			printf("   Principal amount (milion VND): ");
				fflush(stdin);
			ch = '\0';
			scanf("%lf%c", &pri, &ch);
			if (pri>0 && ch == '\n') {
				break;
			}
			else {
				printf("   Invalid intput, please re-enter\n");
			}
		}
	
		/* input & check validation */
		while (1) {
			printf("   Annual rate (percent): ");
			fflush(stdin);
			ch = '\0';
			scanf("%lf%c", &rate, &ch);
			if (rate>0 && rate<100 && ch == '\n') {
				break;
			}
			else {
				printf("   Invalid intput, please re-enter\n");
			}
		}
	
		printf("   sfsdffaf\n");
		
		
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
		
		/* get out do-while(1) if choice == 'n'  ~end part 1 */
		if (choice == 'n') {
			break; 
		}
	} while (1);
}
