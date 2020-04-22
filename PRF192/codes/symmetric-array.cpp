#include <stdio.h>
#include <stdlib.h>

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
	int a[9] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
	int n = 9;
	
	if (symmetric(a, n) == true)  printf("a[] is a symmetric array.\n");
	else printf("a[] is not a symmetric array.\n");
	return 0;
}
