#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void menu(void);
bool input(char a[]);
int countword(char a[]);
void splitword(char a[]);
void rmv_space(char a[]);
void properform (char a[]);
bool checkname(char a[]);

int main() {
	int choice;
	char a[91], b[91], ch;
	bool inputcheck = false;
	
	while (1) {
		while (1) {
			system("cls");
			menu();
			printf("                     Enter your selection (0 -> 5): ");
			fflush(stdin); 
			ch = '\0';
			scanf("%d%c", &choice, &ch);
			printf("\n");
			if (choice >= 0 && choice <= 5 && ch == '\n') {
				break;
			}
			printf("                     Your selection is incorrect\n");
			printf("\n");
			printf("           Press any key to continue...");
	      	getch();
		}
		
		
		if (choice == 0) { // get out while(1) if choice == '0' 
			break;
		}
		switch (choice) {
			case 1: {
				inputcheck = input(a);
				break;
			}
			case 2: {
				if (inputcheck == false) {
					printf("           Please input first!\n");
				}
				else {
					printf("           The original string: ");
					puts(a);
					printf("           It has %d words, there are:\n", countword(a));
					splitword(a);
				}
				
				break;
			}
			case 3: {
				if (inputcheck == false) {
					printf("           Please input first!\n");
				}
				else properform(a);
				break;
			}
			case 4: {
				if (inputcheck == false) {
					printf("           Please input first!\n");
				}
				else {
					printf("           The original string: ");
					puts(a);
					strcpy(b, a);
					rmv_space(b);
					printf("           The cleaned form: ");	
					puts(b);
				}
				break;
			}
			case 5: {
				if (inputcheck == false) {
					printf("           Please input first!\n");
				}
				else {
					bool x = checkname(a);
					if ( x == true) {
						printf("           The string '%s' is a valid name\n", a);
					}
					else {
						printf("           The string '%s' is not a valid name\n", a);
					}
				}
				break;
			}
		}
		printf("\n");
		printf("           Press any key to continue...");
      	getch();
	}
	return (0);
}

void menu(void) {
	printf("                     +-----------------------------------------+\n");
	printf("                     |             Words Processing            |\n");
	printf("                     +-----------------------------------------+\n");
	printf("                     | 1. Input a string                       |\n");
	printf("                     | 2. Split string into words              |\n");
	printf("                     | 3. Convert a string into proper form    |\n");
	printf("                     | 4. Remove redundant spaces              |\n");
	printf("                     | 5. Check valid name                     |\n");
	printf("                     | 0. Exit                                 |\n");
	printf("                     +-----------------------------------------+\n\n");
}

bool input(char a[]) {
	bool check = false;
	
	while (1) {
		printf("           Input a string: ");
		fflush(stdin); strcpy(a, "\0");
		scanf("%[^\n]", a);
		if (strlen(a)>0 && strlen(a)<=90) {
			check = true;
			break;
		}
		else if (strlen(a) == 0) {
			printf("           Invalid string, please re-enter.\n");
		}
		else {
			printf("           String too long, please re-enter (Max = 90).\n");
		}
	}
	return (check);
}

int countword(char a[]) {
	int count = 0;
	
	if (a[0] != ' ') {
		count++;
	}
	for (int i = 0; i <= (strlen(a)-2); i++) {
 		if (a[i] == ' ' && a[i+1] != ' ') {
 			count++;
 		}
	}
	return (count);
}

void splitword(char a[]) {
	char b[91], *token;
	
	strcpy(b, a);
	token = strtok(b, " ,.?\t");
	while (token != '\0') {
		printf("           \t");
		puts(token);
		token = strtok(NULL," ,.?\t");
	}
}

void rmv_space(char b[]) {
	int x;
	
	/* Remove redundant spaces */
	x = strlen(b);
	for (int i = 0; i <= (x-2); i++) {	/* Replace \t by space */
		if (b[i] == '\t') {
			b[i] = ' ';
		}
	}
	for (int i = 0; i <= (x-2); i++) {
		if (b[0] == ' ') { /* Clear first space in b[0] */
			for (int j = 0; j <= (x-2); j++) {
				b[j] = b[j+1];
			}
			b[x-1] = '\0';
			x--;
			i--;
		}
		if (b[i] == ' ' && b[i+1] == ' ') { /* Clear double space */
			for (int j = i+1; j <= (x-2); j++) {
				b[j] = b[j+1];
			}
			b[x-1] = '\0';
			x--;
			i--;
		}
		if (b[x-1] == ' ') { /* Clear last space in b[0] */
			b[x-1] = '\0';
			x--;
		}
	}
}

void properform(char a[]) {
	char b[91];
	
	strcpy(b, a);
	rmv_space(b);
	if (islower(b[0])) {
		b[0] = toupper(b[0]);
	}
	for (int i = 0; i <= strlen(b)-2; i++) {
		if (b[i] == ' ' && islower(b[i+1])) {
			b[i+1] = toupper(b[i+1]);
			i++;
		}
	}
	
	printf("           The original string: ");
	puts(a);
	printf("           The proper form: ");	
	puts(b);
}

bool checkname(char a[]) {
	for (int i = 0; i < strlen(a); i++) {
		if (isalpha(a[i]) == false && a[i] != ' ') {
			return (false);
		}
	}
	return (true);
}

