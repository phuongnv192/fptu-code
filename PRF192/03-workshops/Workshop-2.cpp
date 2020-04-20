#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool prime(int x) {
	for (int i = 2; i <= sqrt(x); i++) { 
		if (x%i == 0){
			return(false);
		}
	}
	return(true);
}

int GCD(int a, int b) {  /* giai thuat Euclid */
	while (a != 0){
		if (a == b) break;
		else {
			if (a>b) a -= b;
			else b-=a;
		}
	}
	return a;
}

int main (){
	int n, i, m, gcd;
	long int s1, s2, lcm;
	double s3;
	
	printf("Q1:\n");
	n = 0;
	while (n<=5) {
		printf(" Enter  n = ");
		scanf("%d", &n);
		if (n<=5) printf(" n must be > 5, please reenter!\n");
	}
	
	s1 = 0; s2 = 1; s3 = 0;
	for (i=1; i < n+1; i++){
		s1+=i;
		s2*=i;
		s3+=1.0/i;
	}
	printf(" s1 = %ld\n", s1);
	printf(" s2 = %ld\n", s2);
	printf(" s3 = %.4lf\n", s3);
	
	printf("\n Enter  n = ");
	scanf("%d", &n);
	if (prime(n) == true) printf(" %d is a prime number\n",n);
	else printf(" %d is not a prime number\n",n);
	
	
	printf("Q2:\n");
	printf("\n Enter  m, n: ");
	scanf("%d %d", &m, &n);
	gcd = GCD(m, n);
	printf(" Common prime dividers: ");
	for (i=1; i <= gcd; i++) {
		if ((m%i == 0) && (n%i == 0) && (prime(i) == true)) {
			printf("%d ", i);
		}
	}
	lcm = m*n / gcd;
	printf("\n GCD = %d\n", gcd);
	printf(" LCM = %ld", lcm);
	return 0;
}
