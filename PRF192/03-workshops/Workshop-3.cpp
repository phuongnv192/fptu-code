#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void binary(int a); // convert decimal to binary ~> print
int summary(int a); // calculate summary of all digits of a
int reverse(int a); // find the reverse of a
int main() {
    int n, n1, sum, rev, m, n2, z;
	char ch, ch1, ch2; // char variables for inputcheck, can be reused
    float a, b, c, delta, x1, x2;
    
    /*Q1*/
    printf("Q1:\n\n");
    
    /* input & check validation*/
	while (1)
	{
		printf(" Enter  n = ");
		fflush(stdin);
		scanf("%d%c", &n, &ch);
		if ((ch == '\n') || (ch == ' ')) {
			break;
		}
		else {
			printf(" n must be a number, please re-enter!\n");
		}
	}
	
	/* convert to binary */
	printf(" %d in binary number format is: ", n);
	binary(n);
	
	/* input again & summary, reverse digits */
	printf("\n\n Enter  n = ");
	scanf("%d", &n1);
	sum = summary(n1);
	printf(" The sum of all digits in %d is %d\n", n1, sum);
	rev = reverse(n1);
	printf(" The reverse number of %d is %d\n", n1, rev);
		
	/*Q2*/
	printf("\n--------------------------------------------------------\nQ2:\n\n");
	
	/* input & check validation*/
	ch = '\0'; ch1 = '\0'; ch2 = '\0';
    while (1) {
    	printf(" Enter a, b, c = ");
    	fflush(stdin);
		scanf("%f%c%f%c%f%c", &a, &ch, &b, &ch1, &c, &ch2);
		if (a != 0 && ch == ' ' && ch1 == ' ' && ch2 == '\n') {
			break;
		}
		else {
			printf(" Invalid input!\n");
		}
	}
	
	/* solve the quadratic equation */	
	delta = pow(b, 2) - 4*a*c;
	if (delta < 0) {
		printf(" No real root\n");
	}
	else if (delta == 0) {
		x1 = -b / (2*a);
		printf(" Root 1 = Root 2 = %.4f\n", x1);
	}
	else {
		x1 = (-b + sqrt(delta)) /(2*a);
		x2 = (-b - sqrt(delta)) /(2*a);
		printf(" Root 1 = %.4f\n", x1);
		printf(" Root 2 = %.4f\n", x2);
	}
	
	/*Q3*/
	printf("\n--------------------------------------------------------\nQ3:\n\n");
	
	/* input & check validation*/
	ch = '\0'; ch1 = '\0';
	while (1) {
    	printf(" Enter m, n: ");
    	fflush(stdin);
		scanf("%d%c%d%c", &m, &ch, &n2, &ch1);
		if (ch == ' ' && ch1 == '\n' && m<n2) {
			break;
		}
		else {
			printf(" Invalid input!\n");
		}
	}
	
	/* find palindrome numbers */
	printf(" Palindrome numbers from %d to %d are:",m ,n2);
    for (int i = m; i <= n2; i++) { // find first number and print " %d"
       if(i == reverse(i)) {
       	printf(" %d", i);
        z = i;
       	break;
       }
    }
    for (int i = z+1; i <= n2; i++) { // find the other numbers and print ", %d"
    	if (i == reverse(i)) {
    		printf(", %d", i);
		} 
 	}
	printf("\n");
	
	return(0);	
}

/* function convert decimal to binary ~> print */
void binary(int a) {
	int bi[40], i;
	for (i = 0; a>0; i++) {
		bi[i] = a%2;
		a /= 2;
	}
	for (int j = i-1;j >= 0; j--) {
		printf("%d", bi[j]);
	}
}

/* function calculate summary of all digits of a */
int summary(int a) {
	int sum = 0;
	while (a>0) {
		sum += a%10;
		a /= 10;
	}
	return(sum);
}

/* function find the reverse of a */
int reverse(int a) {
	int rv = 0;
	while (a>0) {
		rv = rv*10 + a%10;
		a /= 10;
	}
	return (rv);
}
