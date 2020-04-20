#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int a, b, n;
		
	a = 6; // start
	b = 100; // end
	srand(time(NULL)); // lay seed random = thoi giam tai thoi diem hien tai
	for (int i = 0; i < 10; i++) {
		n = a + rand() % (b+1-a); // (b+1-a) = 95 ~> rand() % (b+1-a) duoc ket qua tu 0-94
		printf("Random number %d is %d\n", i, n);
	}		
	return 0;
}
