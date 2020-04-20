#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main() { 
    char c = ' ';
	printf("Input text: ");
	c = getchar();
	printf("c = %c_END\n", c); //how about EOF?	
	return(0);	
}
