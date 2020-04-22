#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void binary(int a) {
	int bi[8], i;
	
	for (i = 0; a>0; i++) {
		bi[i] = a%2;
		a /= 2;
	}
	for (int j = 7;j >= 0; j--) {
		printf("%d", bi[j]);
	}
}

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
  	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);	
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
  	binary(a);
	printf(" ");
	binary(b);

  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
