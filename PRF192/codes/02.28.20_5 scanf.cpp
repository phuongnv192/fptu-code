#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void clear(void) {
	while (getchar() != '\n'); //null statement intentional
}

int main() { 
    char c = ' ';
    int d = 0, a = 0;
	printf("Input char the number: ");
	a = scanf("%c %d", &c, &d);
	printf("c = %c_END, d = %d, scanf returns a = %d\n", c, d ,a);

	return(0);	
}
