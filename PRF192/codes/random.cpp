#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	
	for (i = 0; i < 10; i++)
		printf("Random number %d is %d\n", i, rand());
	// same every runs
	// random in range [0-32767]
	return 0;
}
