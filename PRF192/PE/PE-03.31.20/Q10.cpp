#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	int a, i, sum;
	int b[15], count;
	
	scanf("%d", &a);
	count = 0;
	while (a>0) {
		b[count++] = a%10;
		a /= 10;
	}

	sum = 0;
	for (int i = count-1; i >= 0; i -= 2) {
		sum += b[i];
	}

  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
	printf("%d",sum);

  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
