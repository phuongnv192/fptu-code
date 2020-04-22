#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

bool prime(int x){
	int i;
	for (i = 2; i<=sqrt(x); i++) { 
		if ((x%i) == 0){
			return(false);
		}
	}
	return(true);
}

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
  	int a, b, x;
	scanf("%d", &a);
	scanf("%d", &b);
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
	if (b>=2 && a>=2) {
		int i;
		for (i = a; i<=b; i++) {
			if (prime(i) == true) {
				printf("%d", i);
				x = i;
				break;	
			}
		}
		for (i = x+1; i<=b; i++) {
			if (prime(i) == true) {
				printf(" %d", i);
			}
		}	
	}
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
