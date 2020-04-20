#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int iAddab(int x1,int x2) {
	int sum = 0;
	for (int i=x1;i<=x2; i++)
	sum += i;
	return sum;	
}

int main(){
	int a,b,s;
    printf("Enter a, b = "); 
	scanf("%d %d", &a,&b);
	s = iAddab(a, b);
	printf("summary from %d to %d = %d\n",a,b,s); 
	return(0);
}
