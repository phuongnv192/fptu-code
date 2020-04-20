#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int iAdd2(int x1,int x2);
int main(){
	int a1 = 1, a2 = 5;
	int s = 0;
    //printf("Enter a, b = "); 
	//scanf("%d %d", &a,&b);
	s = iAdd2(a1, a2);
	printf("sum = %d\n",s); 
	return(0);
}
int iAdd2(int x1,int x2) {
	int sum = 0;
	sum = x1 + x2;
	x1 = x1 - 1;
	x2 = x2 - 1;
	printf("x1 = %d, x2 = %d\n",x1,x2);
	return sum;	
}

