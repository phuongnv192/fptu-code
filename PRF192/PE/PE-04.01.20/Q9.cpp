#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	float a, c;
	int x, y, b;
	
	scanf("%f", &a);
	b = (int) a; // lay phan nguyen cua a
	x = b % 10; // lay chu cai hang don vi cua a
  	c = (a - b) * 10; // nhan phan thap phan cua a voi 10
  	y = (int) c; // lay phan nguyen cua c ~ chu cai dau tien sau dau phay cua a
  	
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
	printf("%d", x*y);

  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
