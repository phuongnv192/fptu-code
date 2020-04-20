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

int main() {
	int a;
	printf("a = ");
	scanf("%d", &a);
	if (prime(a) == true) printf("a la so nguyen to\n");
	else printf("a khong la so nguyen to\n");
	return 0;
}
