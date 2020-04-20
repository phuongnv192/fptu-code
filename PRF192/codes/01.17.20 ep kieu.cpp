#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
	int a,b;
	scanf("%d %d", &a,&b);
	if ((a==b) && (a>1)){
		printf("a<b\n");
	}
	else{ printf("a>=b\n");
	}
	if (a) {
		printf("%d\n", a++);
		printf("%d\n", ++a);
	}
	printf("%f\n", a); //0
	printf("%f\n", (float)a); //x.xxxxxxx
	return 0;
}
