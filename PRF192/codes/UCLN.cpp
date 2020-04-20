#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

int main() {
	int a, b;
	printf("a, b = ");
	scanf("%d %d", &a, &b);
	printf("UCLN(%d, %d) = %d\n", a, b, GCD(a, b));
	return 0;
}
