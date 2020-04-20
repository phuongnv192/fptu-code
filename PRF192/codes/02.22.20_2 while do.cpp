#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main(){
    int a = 1;
    printf("a = "); 
	scanf("%d", &a);
	
	while (a) {
		printf("a = %d\n", a--); //printF dung a roi moi giam 1 don vi
		//printf("a = %d\n", --a); //printF giam 1 don vi roi moi dung a
		if (a==5) {
			break;
		}
	}
	return(0);
}
