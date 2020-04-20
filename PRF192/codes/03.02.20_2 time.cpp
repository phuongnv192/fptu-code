#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
//#include <windows.h> //use Sleep() - by milisecond
#include <unistd.h> // use sleep() - by second

int main() {
    time_t t1, t2, tDiff;
    
	t1 = time(NULL);
	printf("t1 = %d\n", t1); //t1 = t2? how to make t1 != t2?
	
	//Sleep(5000);
	sleep(5);
	
	t2 = time(NULL);
	printf("t2 = %d\n", t2);
	
	tDiff = difftime(t1, t2);
	printf("timeDiff = %d\n", tDiff);
	
	return(0);
}
