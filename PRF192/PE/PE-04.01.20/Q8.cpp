#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	int a, i;
	int b[15];
	
	scanf("%d", &a);
	i = 0;
	while (a>0) {
		b[i++] = a%10;
		a /= 10;
	}

  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
	for (int j = i-1; j >= 0; j--) {
		if (j == i-1) printf("%d", b[j]);
		else printf(",%d", b[j]);
	}

  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
