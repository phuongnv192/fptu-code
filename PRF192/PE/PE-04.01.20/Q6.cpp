#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main() {
  system("cls");
  //INPUT - @STUDENT:ADD YOUR CODE FOR INPUT HERE:
	char s[51];	bool mask[50];
	char a[50]; int count[50]; int k = 0;
	
	fflush(stdin);
	gets(s);
  	
  	int x = strlen(s);
  	for (int i = 0; i < x; i++) count[i] = 0;
  	for (int i = 0; i < x; i++) {
		if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
			mask[i] = false;
		}
		else mask[i] = true;
	}
  	for (int i = 0; i < x; i++) {
  		if (mask[i] == false) {
  			a[k] = s[i];
  			count[k]++;
  			for (int j = i+1; j < x; j++) {
  				if (a[k] == s[j]) {
  					count[k]++;
  					mask[j] = true;
				}
			}
			k++;
		}
	}
	
  // Fixed Do not edit anything here.
  printf("\nOUTPUT:\n");
  //@STUDENT: WRITE YOUR OUTPUT HERE:
  	int z;
	for (int i = 0; i < k; i++) {
		printf("%c_%d", a[i], count[i]);
		z = i;
		break;
	}
	for (int i = z+1; i < k; i++) 
		printf(" %c_%d", a[i], count[i]);

  //--FIXED PART - DO NOT EDIT ANY THINGS HERE
  printf("\n");
  system ("pause");
  return(0);
}
