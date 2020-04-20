#include <stdlib.h>
#include <stdio.h>

int main() {
  int n; char x;
  while(1) {
	printf("Enter n = ");
	fflush(stdin);
	scanf("%d%c",&n,&x);
	if(x=='\n') break;
	if(x==0) // a
	 printf("You must enter a number, please reenter!\n");
	  else	
	   printf("You have entered trailing character, please`reenter!\n");
  }
  printf("The number you have entered is n = %d\n",n);
  printf("\n");
  system("pause");
  return(0);
 }

