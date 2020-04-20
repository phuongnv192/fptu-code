#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void square(int a) {
	
	int i;
	for (i = 1; i <=a; i++) {
		for (int j = 1; j<a; j++) {
			printf("* ");
		}
		if (i<a) {
			printf("*\n");
		}
		else printf("*");
	}
}

int main() {
	int n = 6;
	square(n);
	
	return(0);
}
