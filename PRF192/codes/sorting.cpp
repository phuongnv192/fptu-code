#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void selectsort (int a[], int size) {
	int i, j, jmax;
	int max;
	
	for (i = 0; i < size - 1; i++) {
		max = a[0];
		jmax = 0;

		for (j = 1; j< size - i; j++) {
			if (a[j] > max) {
				max = a[j];
				jmax = j;
			}
		}
		if (jmax != size - i - 1) {
			max = a[size - i - 1];
			a[size -i -1] = a[jmax];
			a[jmax] = max;
		}
	}
}

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
	int x[10] = {45, 12, 3, 6, 98, 1, 56, 11, 87, 0};
	int size = 10;
	
	printf("Before:\n");
	for (int i = 0; i<size; i++) {
		printf("a[%d] ", i);
	}
	printf("\n");
	for (int i = 0; i<size; i++) {
		printf("%-4d ", x[i]);
	}
	printf("\n");
	
	/* bo comment 1 trong 2 phuong phap de tinh */
	selectsort (x, size);
	//bubblesort (x, size);
	
	printf("\n\nAfter:\n");
	for (int i = 0; i<size; i++) {
		printf("a[%d] ", i);
	}
	printf("\n");
	for (int i = 0; i<size; i++) {
		printf("%-4d ", x[i]);
	}

	return (0);
}
