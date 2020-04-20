#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

double myExp(double x, int n); // calculate exp(x) with n
double myExp(double x, double epsi); // calculate exp(x) with epsilon
double myPi(double epsi); // calculate exp(x) with epsilon
double factorial(int a); // calculate factorial of a
double mySin(double x, double epsi); // calculate sin(x) with epsilon
double myCos(double x, double epsi); // calculate cos(x) with epsilon

int main() {
	double x, epsi, x1, epsi1, epsi2;
	int n;
	char ch, ch1, ch2;
	// epsi = 0.00001; n = 1000;
	
	
	/*Q1*/
    printf("Q1:\n\n");
    
	/* input & check validation*/
	while (1)
	{
		printf("Enter x, epsi, n: ");
		fflush(stdin);
		scanf("%lf%c%lf%c%d%c", &x, &ch, &epsi, &ch1, &n, &ch2);
		if (ch == ' ' && ch1 == ' ' && ch2 == '\n') {
			break;
		}
		else {
			printf("Invalid input, please re-enter!\n");
		}
	}
	
	printf("   myExp(%.1lf, %d) = %lf\n", x, n, myExp(x,n));  
	printf("   myExp(%.1lf, %lf) = %lf\n", x, epsi, myExp(x,epsi));
	printf("   exp(%.1lf) = %lf\n", x, exp(x));
	
	/*Q2*/
	printf("\n--------------------------------------------------------\n\nQ2:\n\n");
	
	/* input & check validation*/
	while (1)
	{
		printf("Enter epsi: ");
		fflush(stdin);
		ch = '\0';
		scanf("%lf%c", &epsi1, &ch);
		if (ch == '\n') {
			break;
		}
		else {
			printf("Invalid input, please re-enter!\n");
		}
	}
	
	printf("   myPi(%lf) = %lf\n", epsi1, myPi(epsi1));
	
	/*Q3 + Q4*/	
	printf("\n--------------------------------------------------------\n\n");
	
	/* input & check validation*/
	while (1)
	{
		printf("Enter x, epsi: ");
		fflush(stdin);
		ch = '\0'; ch1 = '\0';
		scanf("%lf%c%lf%c", &x1, &ch, &epsi2, &ch1);
		if (ch == ' ' && ch1 == '\n') {
			break;
		}
		else {
			printf("Invalid input, please re-enter!\n");
		}
	}
	
	printf("\nQ3:\n\n");
	
	printf("   mySin(%.1lf, %lf) = %lf\n",x1, epsi2, mySin(x,epsi));
	printf("   sin(%.1lf) = %lf\n", x, sin(x));
	
	/*Q4*/
	printf("\nQ4:\n\n");
	printf("   myCos(%.1lf, %lf) = %lf\n",x1, epsi2, myCos(x,epsi));
	printf("   cos(%.1lf) = %lf\n", x, cos(x));
	
	return(0);
}

double myExp(double x, int n) { // calculate exp(x) with n
	double S, a;
	
	S = 1; a = 1;
	for (int i = 1; i<= n; i++) {
		a *= (x/i);
		S += a;
	}
	
	return (S);	
}

double myExp(double x, double epsi) { // calculate exp(x) with epsilon
	double S, a; int n;
	
	S = 1; a = 1; n = 1;
	while (epsi < fabs(a)) {
		a *= (x/(n));
		S += a;
		n++;
	}
	
	return (S);
}

double myPi(double epsi) { // calculate Pi with epsilon
	double S, pi, a; int n;
	
	S = 0; n = 0;
	do {
		a = pow(-1,n) / (2*n+1);
		S += a;
		n++;
	} while (epsi < fabs(a));
	S *= 4;
	
	return (S);	
}

double factorial(int a) { // calculate factorial of a
	double f = 1;
	
	if (a == 0) {
		return (1);
	}
	else {
		for (int i = 1; i<=a; i++) {
			f *= i;
		}
		return (f);
	}
}

double mySin(double x, double epsi) { // calculate sin(x) with epsilon
	double si, a; int n;
	
	si = 0; n = 0;
	do {
		a = pow(-1,n) * pow(x,2*n+1) / factorial(2*n+1);
		si += a;
		n++;
	} while (epsi < fabs(a));
	
	return (si);	
}

double myCos(double x, double epsi) { // calculate cos(x) with epsilon
	double co, a; int n;
	
	co = 0; n = 0;
	do {
		a = pow(-1,n) * pow(x,2*n) / factorial(2*n);
		co += a;
		n++;
	} while (epsi < fabs(a));
	
	return (co);	
}

