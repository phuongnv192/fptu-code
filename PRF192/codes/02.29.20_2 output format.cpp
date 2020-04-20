#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>


int main() { 
    float x = 1234.72533232;
    
	printf("x = %f\n", x);
	printf("x = %.2f\n", x);
	printf("x = %03.2f\n", x);
	printf("x = %010.2f\n", x);
	printf("x = %-10.2f\n", x);

	return(0);	
}
