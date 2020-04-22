#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	int a, b;
  	scanf("%d",&a);
  	scanf("%d",&b);
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
	int prod = 0;
	for(int i=a; i<=b; i++)	//@STUDENT: EDIT THIS LINE TO HAVE DESIRED OUTPUT
	{
		if (i%2 != 0)	
		{
			prod = prod+i;
		}
	}
	printf("%d",prod);
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
