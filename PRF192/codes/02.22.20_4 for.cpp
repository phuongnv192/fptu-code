#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main(){
    int a = 1;
    printf("a = "); 
	scanf("%d", &a);
	//for (;;) ~ while (x) :vong lap vo han
	for (int i = 0; i<a; i++) {
		printf("i = %d\n", i);
	}
	return(0);
}
