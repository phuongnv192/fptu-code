#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void clear(void) {
	while (getchar() != '\n'); //null statement intentional
}

int main() { 
    char c = ' ';
	printf("Input text: ");
	clear();
	c = getchar();
	printf("c = %c_END\n", c);

	return(0);	
}
