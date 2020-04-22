#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void bubblesort (int a[], int size) {
	int i, j;
	int temp;
	
	for (i = size - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (a[j] > a[j+1]) {
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	int a[5];
	
	for (int i = 0; i<5; i++) {
		scanf("%d", &a[i]);
	}
	bubblesort (a, 5); 

  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
  	printf("%d", a[0]);
	for (int i = 1; i<5; i++) {
		printf(" %d", a[i]*a[i]);
	}

  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
