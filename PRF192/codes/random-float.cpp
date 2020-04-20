#include <stdio.h>
#include <stdlib.h>

int main() {
	double n, a, b;
	
	a = 3; // start
	b = 100; // end
	
	for (int i = 0; i < 10; i++) {
		n = a + ( (double) rand() / RAND_MAX * (b-a)); // 0<= (double)rand()/RAND_MAX <= 1 ~> a <= n <= a + (b-a) = b
		printf("Random number %d is %.2lf\n", i, n);
	}
		
	return 0;
}
