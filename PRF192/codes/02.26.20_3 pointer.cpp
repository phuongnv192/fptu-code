#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main() { 
    int *var2; //var2 is pointer points to another int variable
	int a = 5;
	var2 = &a; // point var2 to address of a
	printf("var2 = %d\n",var2);
	*var2 = 10;
	printf("a = %d\n",a);
	printf("a = %d\n",&var2);
	printf("a = %d\n",&a);
	return(0);	
}
