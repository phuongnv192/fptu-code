#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	int a[7]; bool mask[7];
	int b[7], count[7] = {0}, x = 0;  
	
	for (int i = 0; i < 7; i++) {
		scanf("%d", &a[i]);
	}
	
	for (int i = 0; i < 7; i++) {
		if (a[i] >= 100 && a[i] <= 999) mask[i] = false;
		else mask[i] = true;
	}
	for (int i = 0; i < 7; i++) {
		if (mask[i] == false) {
			b[x] = a[i];
			count[x] = 1;
			for (int j = i+1; j < 7; j++) {
				if (a[j] == b[x]) {
					count[x]++;
					mask[j] = true;
				}
			}
			x++;
		}
	}
  	
  	int maxcount = count[0];
  	for (int i = 0; i < x; i++) {
  		if (maxcount < count[i]) maxcount = count[i];
	}
  
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
	int z;
	if (x == 0) printf("No three-digit number");
	else {
		for (int i = 0; i<x; i++) {
			if (count[i] == maxcount) {
				printf("%d", b[i]);
				z = i;
				break;
			}
		}
		for (int i = z+1; i<x; i++)
			if (count[i] == maxcount) printf(" %d", b[i]);
	}

  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
