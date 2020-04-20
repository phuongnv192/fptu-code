#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int swap(float &a, float &b){
	float t;
	t= a;
	a= b;
	b= t;
	return 0;
}

int main(){
	float a, b, c, x;
	double S1, S2, p, Peri, Area;
	
	printf("Q1:\n");
	printf(" Enter a = "); scanf("%f", &a);
	printf(" Enter b = "); scanf("%f", &b);
	printf(" Enter c = "); scanf("%f", &c);
	printf(" Enter x = "); scanf("%f", &x);
	
	S1 = a * pow(x, 2) + b*x +c;
	S2 =  pow(b, 2) - 4*a*c;
	if (S2 > 0) {
		S2 = sqrt(S2);
	}
	else S2 = 0;
	printf("\n S1 = %.3lf, S2 = %.3lf\n\n", S1, S2);
	
	printf(" Enter a, b, c = ");
	scanf("%f %f %f", &a, &b, &c);
	if (((a+b) > c) && ((b+c) > a) && ((c+a) > b)) {
		p = (a+b+c) / 2;
		Peri = (a+b+c);
		Area = sqrt(p * (p - a) * (p - b) * (p - c));
		printf(" Perimeter = %.4lf\n", Peri);
		printf(" Area = %.4lf\n\n", Area);	
	}
	else printf(" a, b, c are not side of a triangle.\n\n");
	
	printf("Q2:\n");
	printf(" Enter a, b, c = ");
	scanf("%f %f %f", &a, &b, &c);
	if (a>b && a>c) { // Max = a
		if (b<c) { // Min = b
			printf(" Max = %.2f, Min = %.2f\n", a, b);
			printf(" %.2f <= %.2f <= %.2f\n", b, c, a);
		}
		else { // Min = c
			printf(" Max = %.2f, Min = %.2f\n", a, c);
			printf(" %.2f <= %.2f <= %.2f\n", c, b, a);
		}
	}
	else if (b>c) { // Max = b
		if (a<c) { // Min = a
			printf(" Max = %.2f, Min = %.2f\n", b, a);
			printf(" %.2f <= %.2f <= %.2f\n", a, c, b);
		}
		else { // Min = c
			printf(" Max = %.2f, Min = %.2f\n", b, c);
			printf(" %.2f <= %.2f <= %.2f\n", c, a, b);
		}
	}
	else if (b<a) { // Max = c, Min = b
			printf(" Max = %.2f, Min = %.2f\n", c, b);
			printf(" %.2f <= %.2f <= %.2f\n", b, a, c);
		}
	else { // Min = a
		printf(" Max = %.2f, Min = %.2f\n", c, a);
		printf(" %.2f <= %.2f <= %.2f\n", a, b, c);
	} 
	return 0;
}
