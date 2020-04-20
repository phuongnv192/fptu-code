#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>


int main() {
	int book[9] = {5, 9, 7, 10, 1, 8, 3, 5, 3};
	int sold[9] = {15, 19, 17, 110, 11, 18, 13, 15, 13};
	
	int mask[9] = {0};

	int count = 0;
	
	// create unique array
	int unique[9] = {0};
	int sum[9] = {0};
	
	for (int i = 0; i<9; i++) {
		for (int j = 0; j<i; j++) {
			if (unique[i] != book[j] && mask[j] == 0) {
				unique[i] = book[j];
				mask[j] = 1;
				sum[i] += sold[j];
				count++;
			}
		}
	}
	
	for (int i = 0; i<count; i++) {
		if unique[i] != 0
		printf("book[%d] sold[%d]\n", unique[i], sum[i]);
	}
	return(0);
}
