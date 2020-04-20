#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
//#include <windows.h> //use Sleep() - by milisecond
//#include <unistd.h> // use sleep() - by second

int main() {
    clock_t t1, t2;
    
	t1 = clock();
	printf("t1 = %.10lf\n", (double) t1); //t1 = t2? how to make t1 != t2?
	
	for (int i = 0; i<1000000000; i++) { //tao su delay cho hien tai
		int a = a + 1;
	}
	
	t2 = clock();
	printf("t2 = %.10lf\n", (double)t2);
	
	return(0);
}
