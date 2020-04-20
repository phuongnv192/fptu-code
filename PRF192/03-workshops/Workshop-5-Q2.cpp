#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>

void saving(void);
void investcal(void);

int main() {
	int choice;
	char ch;
	
	while (1) {
		while (1) {
			system("cls");
			printf("                     +---------------------------+\n");
			printf("                     |   Financial Calculator    |\n");
			printf("                     +---------------------------+\n");
			printf("                     | 1. Test saving account    |\n");
			printf("                     | 2. Investment calculation |\n");
			printf("                     | 0. Exit                   |\n");
			printf("                     +---------------------------+\n\n");
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
				saving();
				break;
			}
			case 2: {
				investcal();
				break;
			}
		}
	}
	return(0);
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
	
		/* input annual rate & check validation */
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
	
		/* input years & check validation */
		while (1) {
			printf("   Number of years: ");
			fflush(stdin);
			ch = '\0';
			scanf("%d%c", &year, &ch);
			if (year>0 && ch == '\n') {
				break;
			}
			else {
				printf("   Invalid intput, please re-enter\n");
			}
		}
		
		/* reset value of x1, x2 */
		strcpy(x1, "million VNDs");
		strcpy(x2, "million VNDs");
		
		future = pow(1 + (rate/100), year)*pri;
		if (pri>1000) {
			pri /= 1000;
			strcpy(x1, "billion VNDs");
		}
		if (future>1000) {
			future /= 1000;
			strcpy(x2, "billion VNDs");
		}
		printf("   If you have %.3lf %s with annual rate at %.2lf percent,\n", pri, x1, rate);
		printf("   after %d year you will have %.3lf %s\n\n", year, future, x2);
		
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

void investcal(void) {
	double pri, rate, future;
	int year;
	char ch, x1[13] = "million VNDs", x2[13] = "million VNDs", choice;
	
	/* do-while(1) loop if choice == 'y' */
	do {
		printf("\n2. Investment calculation\n");
		
		/* input future amount & check validation */
		while (1) {
			printf("   Future amount you want (milion VND): ");
			fflush(stdin);
			ch = '\0';
			scanf("%lf%c", &future, &ch);
			if (pri>0 && ch == '\n') {
				break;
			}
			else {
				printf("   Invalid intput, please re-enter\n");
			}
		}
		
		/* input annual rate & check validation */
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
		
		/* input years & check validation */
		while (1) {
			printf("   Number of years: ");
			fflush(stdin);
			ch = '\0';
			scanf("%d%c", &year, &ch);
			if (year>0 && ch == '\n') {
				break;
			}
			else {
				printf("   Invalid intput, please re-enter\n");
			}
		}
		
		pri = future / pow(1 + (rate/100), year);
		if (pri>1000) {
			pri /= 1000;
			strcpy(x1, "billion VNDs");
		}
		if (future>1000) {
			future /= 1000;
			strcpy(x2, "billion VNDs");
		}
		printf("   If you want to have %.3lf %s with annual rate at %.2lf percent\n", future, x2, rate);
		printf("   and after %d year. You need invest %.3lf %s\n\n", year, pri, x1);
		
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
		
		/* get out do-while(1) if choice == 'n'  ~end part 2 */
		if (choice == 'n') {
			break; 
		}
		printf("\n");
	} while (1);
}
