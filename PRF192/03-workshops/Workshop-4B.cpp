#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void input(int *num, int *den); // input numerator (num) and denominator of a fraction (den) and check validation
void display(int num, int den); // display the fraction
void simplify(int *num, int *den); // simplify the fraction
int roots(double a, double b, double c, double *x1, double *x2); // calculates the roots of a quadratic equation

int main() {
	int n, d, qe;
	double a, b, c, x1, x2;
	char ch, ch1, ch2, choice, choice1;
	
	/*Q1*/
    printf("Q1:\n\n");
    
    /* do-while(1) loop if choice == 'y' */
	do {
		/* input the fraction and check validation*/
		printf("   1. Input fraction\n\n");
		input(&n, &d);
		
		// display the fraction, simplify it and return the fraction after be simplified
		printf("\n   2. Simplify fraction\n\n");
		display(n, d);
		printf("   =\n");
		simplify(&n, &d); // simplify the fraction
		display(n, d); // simplify the fraction after be simplified
		
		/* loop "Another run" until choice == 'n' or 'y' */
		do {
			fflush(stdin);
			printf("   Another run <y/n>? ");
			scanf("%c", &choice);
			if (choice != 'n' && choice != 'y') {
				printf("   Invalid!\n");
			}
		} while (choice != 'n' && choice != 'y');
		
		/* get out do-while(1) if choice == 'n'  ~end Q1 */
		if (choice == 'n') {
			break; 
		}
		printf("\n");
	} while (1);
	
	/*Q2*/
	printf("\n--------------------------------------------------------\nQ2:\n");
	
	/* do-while(1) loop if choice1 == 'y' */
	do {
		/* input a, b, c and check validation*/
		printf("\n   1. Input coefficients of quadratic equation\n");
		while (1) {
    		printf("   Enter a, b, c: ");
    		fflush(stdin);
    		a = 0; ch = '\0'; ch1 = '\0'; ch2 = '\0'; /* reset value of a, ch, ch1. ch2: prevent case invalid input 
			                                             but still use previous input to calculate quadratic equation */
			scanf("%lf%c%lf%c%lf%c", &a, &ch, &b, &ch1, &c, &ch2);
			if (a != 0 && ch == ' ' && ch1 == ' ' && ch2 == '\n') {
				break;
			}
			else {
				printf("   Invalid input, please re-enter!\n");
			}
		}
		
		/* calculates the roots of a quadratic equation and return the number of real roots to qe */
		printf("\n   2. Solve the equation\n\n");
		qe = roots(a, b, c, &x1, &x2); 
		if (qe == 0) {
			printf("   There are no real roots\n\n");
		}
		else if (qe == 1) {
			printf("   There is one real root: x0 = %lf\n\n", x1);
		}
		else {
			printf("   There are 2 real roots: x1 = %lf, x2 = %lf\n\n", x1, x2);
		}
		
		/* loop "Another run" until choice1 == 'n' or 'y' */
		do {
			fflush(stdin);
			printf("   Another run <y/n>? ");
			scanf("%c", &choice1);
			if (choice1 != 'n' && choice1 != 'y') {
				printf("   Invalid choice. Try again.\n");
			}
		} while (choice1 != 'n' && choice1 != 'y');
		
		/* get out do-while(1) if choice1 == 'n' ~end Q2*/
		if (choice1 == 'n') break;
	} while (1);

	return(0);
}

void input(int *num, int *den) { // input numerator (num) and denominator of a fraction (den) and check validation
	char ch;
	
	/* input & check validation*/
	while (1) // input numrator
	{
		printf("   Enter numerator: ");
		fflush(stdin);
		scanf("%d%c", num, &ch);
		if (ch == '\n') {
			break;
		}
		else {
			printf("   Invalid numerator, please re-enter!\n");
		}
	}
	
	ch = '\0';
	while (1) { // input denominator
	
		printf("   Enter denominator: ");
		fflush(stdin);
		scanf("%d%c", den, &ch);
		if (*den != 0 && ch == '\n') {
			break;
		}
		else {
			printf("   Invalid denominator, please re-enter!\n");
		}
	}
}

void display(int num, int den) { // display the fraction
	
	printf("   %d/%d\n", num, den);
}

int GCD(int a, int b){  /* use Euclidean algorithm find greatest common divisor */
	
	while (a!=0) {
		if (a == b) {
			break;
		}
		else {
			if (a>b) {
				a = a-b;
			}
			else {
				b = b-a;
			}
		}
	}
	return a;
}

void simplify(int *num, int *den) { // simplify the fraction by: divide numerator and denominator to GCD
	int a = GCD( abs(*num), abs(*den));
	
	*num /= a;
	*den /= a;
}

int roots(double a, double b, double c, double *x1, double *x2) { // calculates the roots of a quadratic equation
	double delta;
	
	delta = pow(b,2) - 4*a*c;
	if (delta<0) {
		return(0); //return number of real roots: 0
	}
	else if (delta == 0) {
		*x1 = -b/(2*a);
		return(1); //return number of real roots: 1
	}
	else {
		*x1 = (-b + sqrt(delta)) /(2*a);
		*x2 = (-b - sqrt(delta)) /(2*a);
		return(2); //return number of real roots: 2
	}
}

		


