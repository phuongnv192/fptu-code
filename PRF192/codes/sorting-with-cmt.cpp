#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void selectsort (int a[], int size) {
	int i, j, jmax;
	int max;
	
	printf("\ni: 0 ~> %d\n", size-1-1);
	for (i = 0; i < size - 1; i++) {
		printf("\ni = %d\n", i);
		max = a[0];
		jmax = 0;
		printf("max = %d, jmax = %d\n", max, jmax);
		printf("j: 1 ~> size-i-1 (%d)\n", size-i-1);
		for (j = 1; j< size - i; j++) {
			printf("j = %d\n", j);
			if (a[j] > max) {
				printf("a[%d] > max\n", j);
				max = a[j];
				jmax = j;
				printf("max = %d, jmax = %d\n", max, j);
			}
		}
		if (jmax != size - i - 1) {
			printf("jmax (%d) != size-i-1 (%d)\n", jmax, size-i-1);
			max = a[size - i - 1];
			a[size -i -1] = a[jmax];
			a[jmax] = max;
			printf("max = %d, a[%d] = %d, a[%d] = %d\n", max, size-i-1, a[size -i -1], jmax, a[jmax]);
		}
	}
}

void bubblesort (int a[], int size) {
	int i, j;
	int temp;
	
	printf("\ni: size-1 (%d) ~> 1\n", size-1);
	for (i = size - 1; i > 0; i--) {
		printf("i = %d\n", i);
		printf("\nj: 0 ~> i-1 (%d)\n", i-1);
		for (j = 0; j < i; j++) {
			if (a[j] > a[j+1]) {
				printf("a[%d]=%d > a[%d]=%d\n", j, a[j], j+1, a[j+1]);
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				printf("a[%d] = %d, a[%d] = %d\n", j, a[j], j+1, a[j+1]);
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
	//selectsort (x, size);
	bubblesort (x, size);
	
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
