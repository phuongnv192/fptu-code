#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>

int main() {
    time_t t1, t2;
    
	t1 = time(NULL);
	printf("t1 = %d\n", t1); //t1 = t2? how to make t1 != t2?
	
	t2 = time(NULL);
	printf("t2 = %d\n", t2);
	
	return(0);
}
