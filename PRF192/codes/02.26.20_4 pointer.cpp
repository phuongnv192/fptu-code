#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main() { 
    int *var2; //var2 is pointer points to another int variable
	int a = 5;
	var2 = &a; // point var2 to address of a
	printf("var2 = %d, *var2 = %d\n",var2);
	printf("",*var2);
	int *var1;
	var1 = &a;
	if (var1 == var2) {
		printf("var1, var2 point to the same location\n",var2);
	}
	else {
		printf("var1 != var2\n");
	}	
	return(0);	
}
