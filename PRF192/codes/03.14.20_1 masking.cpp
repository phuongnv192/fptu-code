#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>


int main() {
	int a[5] = {1, 2, 5, 7};
	int mask[] = {0}; //1 = set - uneditable; 0 = unset
	
	mask[2] = 1;
	
	for (int i = 0; i<4; i++) {
		if (mask[i] == 0) {
			a[i]++;
		}
	}
	
	for (int i = 0; i<4; i++) {
		printf("a[%d] = %d\n", i, a[i]);
	}
	return(0);
}
