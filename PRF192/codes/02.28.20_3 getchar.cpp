#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main() { 
    char c = ' ';
	printf("Input text: ");
	while ((c = getchar()) != EOF) { //end of input = \n
		printf("c = %c_END\n", c); //try out with string
	}

	return(0);	
}
