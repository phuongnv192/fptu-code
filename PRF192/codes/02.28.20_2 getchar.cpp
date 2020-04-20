#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main() { 
    char c = ' ';
	printf("Input text: ");
	c = getchar();
	if (c == EOF) {
		printf("c = EOF",c); //doesn't show EOF
	}
	else {
		printf("c = %c_END\n", c);
	}
	
	return(0);	
}
