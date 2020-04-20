#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, n, a, b;
	
	a = 6; // start
	b = 100; // end
	
	for (i = 0; i < 10; i++) {
		n = a + rand() % (b+1-a); // (b+1-a) = 95 ~> rand() % (b+1-a) duoc ket qua tu 0-94
		printf("Random number %d is %d\n", i, n);
	}
		
	return 0;
}
