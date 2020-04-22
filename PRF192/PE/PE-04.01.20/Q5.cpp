#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

bool symmetric(int a[], int size) {
	int mid;
	
	if (size%2 == 1) mid = size/2;
	else mid = size/2 - 1;
	for (int i = 0; i <= mid; i++) {
		if (a[i] != a[size-1 - i]) {
			return false;
		}
	}
	return true;
}

int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	int a[10], n;
	bool check = false;
	
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i<n; i++) {
		if (a[i]%2 == 1) {
			check = true;
			break;
		}
	}
	if (symmetric(a, n) == true) check = false;
	int sum = 0;
	if (check == true) {
		for (int i = 0; i < n; i++) {
			if (a[i]%2 == 0) sum += a[i];
		}
	}
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
	printf("%d", sum);

  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
