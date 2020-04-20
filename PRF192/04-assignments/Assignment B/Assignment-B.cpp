#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX_book 100    // max numbers of book
#define SPACE_menu 30   // adjust space of menu Book in stock

struct bookstore {
	char code[11]; 
	char title[31];
	int quantity;
	double price;
	double value;
} bkinstck[MAX_book];

void print_space(int x); /* print x times ' ' */
bool dupcheck_code(char a[11], int k); /* check duplicate a in array bkinstck[].code which have k elements */
bool dupcheck_title(char a[31], int k); /* check duplicate a in array bkinstck[].title which have k elements */
void input_code(int i); /* input bkinstck[i].code */
void input_title(int i); /* input bkinstck[i].title */
void input_quantity(int i); /* input bkinstck[i].quantity */
void input_price(int i); /* input bkinstck[i].price */
void value(int i); /* calculate bkinstck[i].value */
double value_total(int k); /* calculate total value */
void enterlist(double &total, int &k); /* enter books in array bkinstck[] which have k elements */
void display_header(void); /* display the header of table */
void display_1row(int i); /* display row bkinstck[i] */
void display_full(double total, int k); /* display full table of books */
void swap(int a, int b); /* swap book at position bkinstck[a] and bkinstck[b] */
void sortASC(int k); /* sort book in bkinstck[] in ascending order */
int loadf(int &line, int &k); /* return error code at line number *line when load data from file */
void loadfile(double &total, int &k); /* load data from file bookstore.txt */
void fexport(double total, int &k); /* Export data to file */
void fstmax(int k); /* find first max in bkinstck[].price which have k elements and display it */
void display_fheader(void); /* display the header of find table */
bool find(int k, int pos[], int &j); /* find and display the list which are matched with code */
void edit_code(int i); /* edit bkinstck[i].code */
void edit_title(int i); /* edit bkinstck[i].title */
void edit_quantity(int i); /* edit bkinstck[i].quantity */
void edit_price(int i); /* edit bkinstck[i].price */
void findnedit(double &total, int k, int pos[], int j); /* find and edit book */
void delele_book(int i, int &k); /* delete book bkinstck[i] in array bkinstck[] which have k elements */
void findndelete(double &total, int &k, int pos[], int j); /* find and delete book */
void info(void); /* display infomation of group */
void menu(void); /* display menu Books in stock */

int main() {
	/* we use an array to store information of the list which are founed by code
		pos[i]
		i: number from 0 to the max of choice
		value of pos[i] = k mean: bkinstck[k].xxx                  */
	int pos[MAX_book];
	int choice;
	char ch; 
	int k = 0; // number of books in bkinstck[MAX_book]
	int j = 0; // number of books were found in number[MAX_book] = j+1
	double total; // total value of books	
	
	while (1) {
		while (1) {
			system("cls");
			menu();
			printf("\n");
			print_space(SPACE_menu);
		    printf("Enter your selection (0 -> 9): ");
			fflush(stdin); 
			ch = '\0';
			scanf("%d%c", &choice, &ch);
			if (choice >= 0 && choice <= 9 && ch == '\n') {
				break;
			}
			print_space(SPACE_menu);
			printf("Your selection is incorrect\n");
			printf("\n\n");
			printf("Press any key to continue...");
	      	getch();
		}
		printf("\n");
		
		if (choice == 0) {
			break;
		}

		switch (choice) {
			case 1: {
				enterlist(total, k);
				break;
			}
			case 2: {
				if (k == 0) {
					print_space(SPACE_menu);
					printf("Please input data first.\n");
				}
				else display_full(total, k);
				break;
			}
			case 3: {
				if (k == 0) {
					print_space(SPACE_menu);
					printf("Please input data first.\n");
				}
				else sortASC(k);
				break;
			}
			case 4: {
				loadfile(total, k);
				break;
			}
			case 5: {
				if (k == 0) {
					print_space(SPACE_menu);
					printf("Please input data first.\n");
				}
				else fexport(total, k);
				break;
			}
			case 6: {
				if (k == 0) {
					print_space(SPACE_menu);
					printf("Please input data first.\n");
				}
				else fstmax(k);
				break;
			}
			case 7: {
				if (k == 0) {
					print_space(SPACE_menu);
					printf("Please input data first.\n");
				}
				else findnedit(total, k, pos, j);
				break;
			}
			case 8: {
				if (k == 0) {
					print_space(SPACE_menu);
					printf("Please input data first.\n");
				}
				else findndelete(total, k, pos, j);
				break;
			}
			case 9: {
				info();
				break;
			}
			default: {
				printf("Your selection is incorrect\n"); 
				break;
			}
		}
		printf("\n");
		printf("Press any key to continue...");
      	getch();
	}

	return (0);
}

void print_space(int x) { /* print x times ' ' */
	for (int i = 1; i <= x; i++) {
		printf(" ");
	}
}

bool dupcheck_code(char a[11], int k) { /* check duplicate a in array bkinstck[].code which have k elements */
	for (int i = 0; i<k; i++) {
		if (strcmp(bkinstck[i].code, a) == 0) {
			return(true);
		}
	}
	return(false);
}

bool dupcheck_title(char a[31], int k) { /* check duplicate a in array bkinstck[].title which have k elements */
	for (int i = 0; i<k; i++) { 
		if (strcmp(bkinstck[i].title, a) == 0) {
			return(true);
		}
	}
	return(false);
}

void input_code(int i) { /* input bkinstck[i].code */
	char a[11];
	
	while (1) {
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf(" Enter code (enter STOP to stop): "); 
		fflush(stdin);
		gets(a);
		if ((strlen(a) > 0) && (strlen(a) <= 10)) {
			if (dupcheck_code(a, i) == true) {
				print_space(SPACE_menu/2); // adjust space on the screen.
				printf(" The code %s already exists, please re-enter!\n", a);
			}
			else {
				strcpy(bkinstck[i].code, a);
				break;
			}
		}
		else {
			print_space(SPACE_menu/2); // adjust space on the screen.
			printf(" Invalid code, please re-enter!\n");
		}
	}
}

void input_title(int i) { /* input bkinstck[i].title */
	char a[31];
	
	while (1) {
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf(" Enter title: "); 
		fflush(stdin);
		gets(a);
		if ((strlen(a) > 0) && (strlen(a) <= 31)) {
			if (dupcheck_title(a, i) == true) {
				print_space(SPACE_menu/2); // adjust space on the screen.
				printf(" The title %s already exists, please re-enter!\n", a);
			}
			else {
				strcpy(bkinstck[i].title, a);
				break;
			}
		}
		else {
			print_space(SPACE_menu/2); // adjust space on the screen.
			printf(" Invalid title, please re-enter!\n");
		}
	}
}

void input_quantity(int i) { /* input bkinstck[i].quantity */
	char ch;
	
	while (1) {
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf(" Enter quantity: "); 
		fflush(stdin);
		ch = '\0';
		scanf("%d%c", &bkinstck[i].quantity, &ch);
		if ((bkinstck[i].quantity > 0) && (ch == '\n')) {
			break;
		}
		else {
			print_space(SPACE_menu/2); // adjust space on the screen.
			printf(" Invalid quantity, please re-enter!\n");
		}
	}
}

void input_price(int i) { /* input bkinstck[i].price */
	char ch;
	
	while (1) {
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf(" Enter price: "); 
		fflush(stdin);
		ch = '\0';
		scanf("%lf%c", &bkinstck[i].price, &ch);
		if ((bkinstck[i].price > 0) && (ch == '\n')) {
			break;
		}
		else {
			print_space(SPACE_menu/2); // adjust space on the screen.
			printf(" Invalid price, please re-enter!\n");
		}
	}
}

void value(int i) { /* calculate bkinstck[i].value */
	bkinstck[i].value = bkinstck[i].quantity*bkinstck[i].price;
}

double value_total(int k) { /* calculate total value */
	double total = 0;
	
	for (int i = 0; i<k; i++) {
		total += bkinstck[i].value;
	}
	return(total);
}

void enterlist(double &total, int &k) { /* enter books in array bkinstck[] which have k elements */
	int i = 1;
	char stop[5] = "STOP";
	
	while (1) {
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf("Book %d:\n", i);
		input_code(k);
		if 	(strcmp(bkinstck[k].code, stop) == 0) {
			break;
		}
		input_title(k);
		input_quantity(k);
		input_price (k);
		value(k);
		i++;
		k++;
	}
	total = value_total(k);
}

void display_header(void) { /* display the header of table */
	print_space(SPACE_menu/2); // adjust space on the screen.
	printf("+------------+--------------------------------+----------+------------+------------+\n");
	print_space(SPACE_menu/2); // adjust space on the screen.
	printf("| %-10s | %-30s | %8s | %10s | %10s |\n", "Code", "Title", "Quantity", "Price", "Value");
	print_space(SPACE_menu/2); // adjust space on the screen.
	printf("+------------+--------------------------------+----------+------------+------------+\n");
}

void display_1row(int i) { /* display row bkinstck[i] */
	printf("| %-10s | %-30s | %8d | %10.1lf | %10.1lf |\n", bkinstck[i].code, bkinstck[i].title, bkinstck[i].quantity, bkinstck[i].price, bkinstck[i].value);
}

void display_full(double total, int k) { /* display full table of books */

	display_header();
	for (int i = 0; i<k; i++) {
		print_space(SPACE_menu/2); // adjust space on the screen.
		display_1row(i);
	}
	print_space(SPACE_menu/2); // adjust space on the screen.
	printf("+------------+--------------------------------+----------+------------+------------+\n");
	
	print_space(SPACE_menu/2); // adjust space on the screen.
	printf("|                                                          Total value: %-10.1lf |\n", total);
	print_space(SPACE_menu/2); // adjust space on the screen.
	printf("+----------------------------------------------------------------------------------+\n");
}

void swap(int a, int b) { /* swap book at position bkinstck[a] and bkinstck[b] */
	char temp_code[11]; 
	char temp_title[31];
	int temp_quantity;
	double temp_price;
	double temp_value;
	
	/* swap code */
	strcpy(temp_code, bkinstck[a].code);
	strcpy(bkinstck[a].code, bkinstck[b].code);
	strcpy(bkinstck[b].code, temp_code);
	
	/* swap title */
	strcpy(temp_title, bkinstck[a].title);
	strcpy(bkinstck[a].title, bkinstck[b].title);
	strcpy(bkinstck[b].title, temp_title);
	
	/* swap quantity */
	temp_quantity = bkinstck[a].quantity;
	bkinstck[a].quantity = bkinstck[b].quantity;
	bkinstck[b].quantity = temp_quantity;
	
	/* swap price */
	temp_price = bkinstck[a].price;
	bkinstck[a].price = bkinstck[b].price;
	bkinstck[b].price = temp_price;
	
	/* swap value */
	temp_value = bkinstck[a].value;
	bkinstck[a].value = bkinstck[b].value;
	bkinstck[b].value = temp_value;	
}

void sortASC(int k) { /* sort book in bkinstck[] in ascending order */
	for (int i = 1; i < k-1; i++) {
		for (int j = 0; j < k-i; j++) {
			if (strcmp(bkinstck[j].code, bkinstck[j+1].code) > 0) {
				swap(j, j+1);
			}
		}
	}
	print_space(SPACE_menu/2); // adjust space on the screen.
	printf("Successfull.\n");
}

int loadf(int &line, int &k) { /* return error code at line number *line when load data from file */
	FILE *fp;
	char header[3][72], last[72], tcode[11], ttitle[31], temp[100];
	int val, tquantity;
	double tprice;
	/* 
		funtion return as a Error code:
		1 [Error] file does not exists!
		2 [Error] file empty!
		3 [Error] Invalid format (line %d).
		4 [Error] Code duplicated (line %d).
		5 [Error] Title duplicated (line %d).
		6 [Error] Invalid quantity (line %d).
		7 [Error] Invalid price (line %d).
	*/
	
	line = 1; val = 0; // val store return value of fscanf
	fp = fopen("bookstore.txt", "r");
	if (fp == NULL) {
		fclose(fp);
		return 1;
	}
	else {
		if (fscanf(fp, "%s", temp) == EOF) {
			fclose(fp);
			return 2;
		}
		else rewind(fp); //turn back to begining of file
		while (!feof(fp)) {
			val = 0;
			val = fscanf(fp, "%71[^\n]\n", header[0]); // line 1
			if (val == EOF || (strcmp(header[0], "+------------+--------------------------------+----------+------------+") != 0)) {
				fclose(fp);
				return 3;
			}
			else {
				line++; val = 0;
				val = fscanf(fp, "%71[^\n]\n", header[1]); // line 2
				if (val == EOF || strcmp(header[1], "| Code       | Title                          | Quantity |      Price |") != 0) {
					fclose(fp);
					return 3;
				}
				else {
					line++; val = 0;
					val = fscanf(fp, "%71[^\n]\n", header[2]); // line 3
					if (val == EOF || strcmp(header[2], "+------------+--------------------------------+----------+------------+") != 0) {
						fclose(fp);
						return 3;
					}
					else {
						line++;
						while (1) {
							val = 0;
							val = fscanf(fp, "| %10[^ |] | %30[^ |] | %8d | %10lf |\n", tcode, ttitle, &tquantity, &tprice);

							if (val == 4) {
								if (strlen(tcode) > 0 && strlen(tcode) <= 10 && dupcheck_code(tcode, k) == true) {
									fclose(fp);
									return 4;
								}
								else if (strlen(ttitle) > 0 && strlen(ttitle) <= 30 && dupcheck_title(ttitle, k) == true) {
									fclose(fp);
									return 5;	
								}
								else if (tquantity < 0) {
									fclose(fp);
									return 6;
								}
								else if (tprice < 0) {
									fclose(fp);
									return 7;
								}
								else {
									strcpy(bkinstck[k].code, tcode);
									strcpy(bkinstck[k].title, ttitle);
									bkinstck[k].quantity = tquantity;
									bkinstck[k].price = tprice;				
									k++;
								}
							}
							else {
								val = 0;
								val = fscanf(fp, "%s", last);
								if (val == EOF || strcmp(last, "+------------+--------------------------------+----------+------------+") != 0) {
									fclose(fp);
									return 3;
								}
								else {
									fclose(fp);
									return 0;
								}
							}
							line++;
						}
					}
				}
			}
		}
	}
}

void loadfile(double &total, int &k) { /* load data from file bookstore.txt */
	int f, line = 0; // error code at [line] when load file. if f = 0 means no error

	print_space(SPACE_menu/2); // adjust space on the screen.
	printf("Load data from file bookstore.txt:\n");
	f = loadf(line, k);
	for (int i = 0; i<k; i++) {
		value(i);
	}
	total = value_total(k);
	
	if (f == 0) {
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf("Load successfully %d books from file bookstore.txt!\n", k);
	}

	switch (f) {
		case 1: {
			print_space(SPACE_menu/2); // adjust space on the screen.
			printf("[Error] file does not exists!\n");
			break;
		}
		case 2: {
			print_space(SPACE_menu/2); // adjust space on the screen.
			printf("[Error] file empty!\n");
			break;
		}
		case 3: {
			if (line > 3) {
				print_space(SPACE_menu/2); // adjust space on the screen.
				printf("Load successfully %d books with: ", k);
			}
			printf("[Error] Invalid format (line %d).\n", line);
			break;
		}
		case 4: {
			if (line > 3) {
				print_space(SPACE_menu/2); // adjust space on the screen.
				printf("Load successfully %d books with: ", k);
			}
			printf("[Error] Code duplicated (line %d).\n", line);
			break;
		}
		case 5: {
			if (line > 3) {
				print_space(SPACE_menu/2); // adjust space on the screen.
				printf("Load successfully %d books with: ", k);
			}
			printf("[Error] Title duplicated (line %d).\n", line);
			break;
		}
		case 6: {
			if (line > 3) {
				print_space(SPACE_menu/2); // adjust space on the screen.
				printf("Load successfully %d books with: ", k);
			}
			printf("[Error] Invalid quantity  (line %d).\n", line);
			break;
		}
		case 7: {
			if (line > 3) {
				print_space(SPACE_menu/2); // adjust space on the screen.
				printf("Load successfully %d books with: ", k);
			}
			printf("[Error] Invalid price  (line %d).\n", line);
			break;
		}
	}
}

void fexport(double total, int &k) { /* Export data to file */
	int choice;
	char ch;
	FILE *fp, *fp1;
	
	print_space(SPACE_menu/2); // adjust space on the screen.
	printf("1. Save file to load next time - bookstore.txt\n");
	print_space(SPACE_menu/2); // adjust space on the screen.
	printf("2. Export full information - bookstore_full.txt\n\n");
	
	while (1) {
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf("Enter number (1-2): ");
		fflush(stdin); ch = '\0';
		scanf("%d%c", &choice, &ch);
		if (choice >=1 && choice <= 2 && ch == '\n') break;
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf("Invalid code, please re-enter!\n");
	}
	
	if (choice == 1) {
		fp = fopen("bookstore.txt", "w");
		fprintf(fp, "+------------+--------------------------------+----------+------------+\n");
		fprintf(fp, "| %-10s | %-30s | %8s | %10s |\n", "Code", "Title", "Quantity", "Price");
		fprintf(fp, "+------------+--------------------------------+----------+------------+\n");
		for (int i = 0; i<k; i++) {
			fprintf(fp, "| %-10s | %-30s | %8d | %10.1lf |\n", bkinstck[i].code, bkinstck[i].title, bkinstck[i].quantity, bkinstck[i].price);
		}
		fprintf(fp, "+------------+--------------------------------+----------+------------+\n");
		fclose(fp);
	}
	else { // choice == 2
		fp1 = fopen("bookstore_full.txt", "w");
		fprintf(fp1, "+------------+--------------------------------+----------+------------+------------+\n");
		fprintf(fp1, "| %-10s | %-30s | %8s | %10s | %10s |\n", "Code", "Title", "Quantity", "Price", "Value");
		fprintf(fp1, "+------------+--------------------------------+----------+------------+------------+\n");
		for (int i = 0; i<k; i++) {
			fprintf(fp1, "| %-10s | %-30s | %8d | %10.1lf | %10.1lf |\n", bkinstck[i].code, bkinstck[i].title, bkinstck[i].quantity, bkinstck[i].price, bkinstck[i].value);
		}
		fprintf(fp1, "+------------+--------------------------------+----------+------------+------------+\n");
		fprintf(fp1, "|                                                          Total value: %-10.1lf |\n", total);
		fprintf(fp1, "+----------------------------------------------------------------------------------+\n");
		fclose(fp1);
	}
	printf("\n");
	print_space(SPACE_menu/2); // adjust space on the screen.
	printf("File exported successfully.\n");
}

void fstmax(int k) { /* find first max in bkinstck[].price which have k elements and display it */
	double max;
	int a;
	
	max = bkinstck[0].price; a = 0;
	for (int i = 1; i<k; i++) {
		if (max < bkinstck[i].price) {
			max = bkinstck[i].price;
			a = i;
		}	
	}
	print_space(SPACE_menu/2); // adjust space on the screen.
	printf("Here is the (first) max price:\n");
	display_header();
	print_space(SPACE_menu/2); // adjust space on the screen.
	display_1row(a);
	print_space(SPACE_menu/2); // adjust space on the screen.
	printf("+------------+--------------------------------+----------+------------+------------+\n");
}

void display_fheader(void) { /* display the header of find table */
	print_space(SPACE_menu/2); // adjust space on the screen.
	printf("+--------+------------+--------------------------------+----------+------------+------------+\n");
	print_space(SPACE_menu/2); // adjust space on the screen.
	printf("| %-6s | %-10s | %-30s | %8s | %10s | %10s |\n", "Number", "Code", "Title", "Quantity", "Price", "Value");
	print_space(SPACE_menu/2); // adjust space on the screen.
	printf("+--------+------------+--------------------------------+----------+------------+------------+\n");
}

bool find(int k,  int pos[], int &j) { /* find and display the list which are matched with code */
	char a[11], *b, temp[11];
	bool check;
	
	/* input code & check validation */
	while (1) {
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf("Enter code you want to find: ");
		fflush(stdin);
		gets(a);
		if ((strlen(a) > 0) && (strlen(a) <= 10)) {
			break;
		}
		else {
			print_space(SPACE_menu/2); // adjust space on the screen.
			printf("Invalid code, please re-enter!\n");
		}
	}
	
	j = 0;
	for (int i = 0; i<k; i++) {
		strcpy(temp, bkinstck[i].code); // stored value of bkinstck[i].code to temp, 
		                                // because if we use direct bkinstck[i].code, after reset b = *strstr()
		                                // we have also reset the small-string in bkinstck[i].code ~> lost information
		b = strstr(temp, a);
		if (b != NULL) { 
			pos[j] = i;
			j++;
			strcpy(b, "\0"); // reset the value of b. It's also reset the small-string INSIDE temp
			                // but if not, b will be a string which store all the pointers of small-string.
		}
	}
	
	/* print list matched with code want to find */
	if (j > 0) {
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf("Here is the list which matched with '%s':\n", a);
		display_fheader();
		for (int i = 0; i<j; i++) {
			print_space(SPACE_menu/2); // adjust space on the screen.
			printf("| %-6d ", i);
			display_1row(pos[i]);
		}
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf("+--------+------------+--------------------------------+----------+------------+------------+\n");
		printf("\n");
		check = true;		
	}
	else {
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf("None of these book are match with code '%s'.\n", a);
		check = false;		
	}
	
	return(check);
}

void edit_code(int i) { /* edit bkinstck[i].code */
	char code[11];
	
	while (1) {
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf(" Enter code: "); 
		fflush(stdin);
		gets(code);
		if ((strlen(code) > 0) && (strlen(code) <= 10)) {
			if (strcmp(code, "-1") == 0) {
				break;
			}		
			else if (dupcheck_code(code, i) == true) {
				print_space(SPACE_menu/2); // adjust space on the screen.
				printf(" The code %s already exists, please re-enter!\n", code);
			}
			else {
				strcpy(bkinstck[i].code, code);
				break;
			}
		}
		else {
			print_space(SPACE_menu/2); // adjust space on the screen.
			printf(" Invalid code, please re-enter!\n");
		}
	}
}

void edit_title(int i) { /* edit bkinstck[i].title */
	char title[31];
	
	while (1) {
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf(" Enter title: "); 
		fflush(stdin);
		gets(title);
		if ((strlen(title) > 0) && (strlen(title) <= 30)) {
			if (strcmp(title, "-1") == 0) {
				break;
			}		
			else if (dupcheck_title(title, i) == true) {
				print_space(SPACE_menu/2); // adjust space on the screen.
				printf(" The title %s already exists, please re-enter!\n", title);
			}
			else {
				strcpy(bkinstck[i].title, title);
				break;
			}
		}
		else {
			print_space(SPACE_menu/2); // adjust space on the screen.
			printf(" Invalid title, please re-enter!\n");
		}
	}
}

void edit_quantity(int i) { /* edit bkinstck[i].quantity */
	char ch;
	int quantity;
	
	while (1) {
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf(" Enter quantity: "); 
		fflush(stdin);
		ch = '\0'; // reset value ~> make sure program uses the value from last run & BREAK
		scanf("%d%c", &quantity, &ch);
		if ((quantity == -1) && (ch == '\n')) {
			break;
		}
		else if ((quantity > 0) && (ch == '\n')) {
			bkinstck[i].quantity = quantity;
			break;
		}
		else {
			print_space(SPACE_menu/2); // adjust space on the screen.
			printf(" Invalid quantity, please re-enter!\n");
		}
	}
}

void edit_price(int i) { /* edit bkinstck[i].price */
	char ch;
	double price;
	
	while (1) {
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf(" Enter price: "); 
		fflush(stdin);
		ch = '\0'; // reset value ~> make sure program uses the value from last run & BREAK
		scanf("%lf%c", &price, &ch);
		if ((price == -1) && (ch == '\n')) {
			break;
		}
		else if ((price > 0) && (ch == '\n')) {
			bkinstck[i].price = price;
			break;
		}
		else {
			print_space(SPACE_menu/2); // adjust space on the screen.
			printf(" Invalid price, please re-enter!\n");
		}
	}
}

void findnedit(double &total, int k, int pos[], int j) { /* find and edit book */
	int choice;
	char ch, confirm;
	bool check;
	
	check = find(k, pos, j);
	if (check == true) {
		/* loop if choice == 'n' */
		do {
			/* input selection & check validation */
			while (1) {
				print_space(SPACE_menu/2); // adjust space on the screen.
				printf("Enter number (0-%d): ", j-1);
				fflush(stdin); ch = '\0';
				scanf("%d%c", &choice, &ch);
				if ((choice >= 0) && (choice < j) && (ch == '\n')) {
					break;
				}
				else {
					print_space(SPACE_menu/2); // adjust space on the screen.
					printf("Your selection is incorrect!\n"); 
				}
			}
			
			/* loop confirm until confirm == 'n' or 'y' */
			do {
				print_space(SPACE_menu/2); // adjust space on the screen.
				printf("Do you want to edit line number %d <y/n>? ", choice);
				fflush(stdin);
				scanf("%c", &confirm);
				if ((confirm != 'n') && (confirm != 'y')) {
					print_space(SPACE_menu/2); // adjust space on the screen.
					printf("Your selection is incorrect!\n"); 
				}
			} while ((confirm != 'n') && (confirm != 'y'));
			
			/* get out do-while(confirm == 'n') if choice == 'n'  ~> go to edit */
			if (confirm == 'y') {
				break; 
			}
			printf("\n");
		} while(confirm == 'n');
		
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf("Enter your new information, if you want to keep it, enter -1 \n");
			
		edit_code(pos[choice]);
		edit_title(pos[choice]);
		edit_quantity(pos[choice]);
		edit_price(pos[choice]);
		value(pos[choice]);
		total = value_total(pos[choice]);
		
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf("Your book after edit:\n");
		display_header();
		print_space(SPACE_menu/2); // adjust space on the screen.
		display_1row(pos[choice]);
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf("+------------+--------------------------------+----------+------------+------------+\n");
		printf("\n");
	}	
}

void delele_book(int i, int &k) { /* delete book bkinstck[i] in array bkinstck[] which have k elements */
	for (int j = i; j <= k-2; j++) {
		strcpy(bkinstck[j].code, bkinstck[j+1].code);
		strcpy(bkinstck[j].title, bkinstck[j+1].title);
		bkinstck[j].quantity = bkinstck[j+1].quantity;
		bkinstck[j].price = bkinstck[j+1].price;
		bkinstck[j].value = bkinstck[j+1].value;
	}
	k--;
}

void findndelete(double &total, int &k, int pos[], int j) { /* find and delete book */
	int choice;
	char ch, confirm;
	bool check;
	
	check = find(k, pos, j);
	if (check == true) {
		/* loop if choice == 'n' */
		do {
			/* input selection & check validation */
			while (1) {
				print_space(SPACE_menu/2); // adjust space on the screen.
				printf("Enter number (0-%d): ", j-1);
				fflush(stdin); ch = '\0';
				scanf("%d%c", &choice, &ch);
				if ((choice >= 0) && (choice < j) && (ch == '\n')) {
					break;
				}
				else {
					print_space(SPACE_menu/2); // adjust space on the screen.
					printf("Your selection is incorrect!\n"); 
				}
			}
			
			/* loop confirm until confirm == 'n' or 'y' */
			do {
				print_space(SPACE_menu/2); // adjust space on the screen.
				printf("Do you want to delete line number %d <y/n>? ", choice);
				fflush(stdin);
				scanf("%c", &confirm);
				if ((confirm != 'n') && (confirm != 'y')) {
					print_space(SPACE_menu/2); // adjust space on the screen.
					printf("Your selection is incorrect!\n"); 
				}
			} while ((confirm != 'n') && (confirm != 'y'));
			
			/* get out do-while(confirm == 'n') if choice == 'n'  ~> go to edit */
			if (confirm == 'y') {
				break; 
			}
			printf("\n");
		} while(confirm == 'n');
		
		delele_book(pos[choice], k);
		total = value_total(k);
		print_space(SPACE_menu/2); // adjust space on the screen.
		printf("Successfull.\n");
	}	
}

void info(void) { /* display infomation of group */

	print_space(SPACE_menu);		                     
	printf(" ______________________________ \n");
	print_space(SPACE_menu);
	printf("|Class: SE1440                 |\n");
	print_space(SPACE_menu);
	printf("|Group: 1                      |\n");
	print_space(SPACE_menu);
	printf("|-----------------+------------|\n");
	print_space(SPACE_menu);
	printf("|      Name       | Student ID |\n");
	print_space(SPACE_menu);
	printf("|-----------------+------------|\n");
	print_space(SPACE_menu);
	printf("| Dao Hoai Nam    | HE130139   |\n");
	print_space(SPACE_menu);
	printf("| Nguyen Mau Vinh | HE140137   |\n");
	print_space(SPACE_menu);
	printf("| Le Thanh Vuong  | HE140580   |\n");
	print_space(SPACE_menu);
	printf("| Ngo Van Phuong  | HE140784   |\n");
	print_space(SPACE_menu);
	printf("+------------------------------+\n");
}

void menu(void) { /* display menu Books in stock */
	print_space(SPACE_menu);
	printf(".---------------------------------------.\n");
	print_space(SPACE_menu);
	printf("|             BOOK IN STOCK             |\n");
	print_space(SPACE_menu);
	printf(":---------------------------------------:\n");
	print_space(SPACE_menu);
	printf("|  1. Enter the list of books           |\n");
	print_space(SPACE_menu);
	printf("|  2. Display the list of books         |\n");
	print_space(SPACE_menu);
	printf("|  3. Sort the list of books by code    |\n");
	print_space(SPACE_menu);
	printf("|  4. Load data from file               |\n");
	print_space(SPACE_menu);
	printf("|  5. Export data to file               |\n");
	print_space(SPACE_menu);
	printf("|  6. Find the (first) max price        |\n");
	print_space(SPACE_menu);
	printf("|  7. Find by code and edit the book    |\n");
	print_space(SPACE_menu);
	printf("|  8. Find by code and delete the book  |\n");
	print_space(SPACE_menu);
	printf("|  9. About us                          |\n");	
	print_space(SPACE_menu);
	printf("|  0. Exit                              |\n");
	print_space(SPACE_menu);
	printf(":_______________________________________:\n");
}
