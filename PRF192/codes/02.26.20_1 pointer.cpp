#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main() { 
    int *var2; //var2 is pointer points to another int variable
	int a = 5;
	var2 = &a; // point var2 to address of a
	printf("var2 = %d\n",var2);
	
	int b = 0;
	b = *var2; // get value of variable pointed to by var2
	printf("b = %d\n",b);
	
	return(0);	
}
