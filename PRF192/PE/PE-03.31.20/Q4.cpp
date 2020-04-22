#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void bubblesort (int a[], int size) {
	int i, j;
	int temp;
	
	for (i = size - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (a[j] < a[j+1]) {
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
  	int a[5], b[5];
  	
	for (int i = 0; i<5; i++) {
		scanf("%d", &a[i]);
	}
	int j = 0;
	for (int i = 0; i<5; i++) {
		if (a[i] %2 == 1) {
			b[j] = a[i];
			j++;
		}
	}
	bubblesort (b,j);
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
  	if (j>0) {
  		printf("%d", b[0]);
  		if (j>1) {
  			for (int i = 1; i<j; i++) {
				printf(" %d", b[i]);
		  	}
		}
  	}
  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
