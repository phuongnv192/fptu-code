#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main() { 
    int *var2; //var2 is pointer points to another int variable
	int a = 5;
	var2 = &a; // point var2 to address of a
	printf("var2 = %d\n",var2);
	
	int *var1;
	var1 = var2; // var 1 point to address of a
	printf("var1 = %d\n",var1);
	printf("var1 = %d\n",*var1);
	return(0);	
}
