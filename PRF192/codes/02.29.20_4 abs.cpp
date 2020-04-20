#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>


int main() { 
    int a1 = -7;
    long a2 = -12;
    
	printf("abs a1 = %d\n", abs(a1));
	printf("long abs a2 = %l\n", labs(a2));
	printf("float abs -123.45 = %f\n", fabs(-123.45));

	return(0);	
}
