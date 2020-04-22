#include <stdio.h>
#include <stdlib.h>


int main() {
	int book[9] = {5, 9, 7, 10, 1, 8, 3, 5, 3}; // result: 5-30, 9-19, 7-17, 10-110, 1-11, 8-18, 3-26 
	int sold[9] = {15, 19, 17, 110, 11, 18, 13, 15, 13};
	bool mask[9];

	// create unique array
	int unique[9] = {0};
	int sum[9] = {0};
	int count = 0;
	
	for (int i = 0; i < 9; i++) mask[i] = false; // set mask = true mean hide.
	for (int i = 0; i < 9; i++) {
		if (mask[i] == false) {
			unique[count] = book[i];
			sum[count] = sold[i];
			for (int j = i+1; j < 9; j++) {
				if (unique[count] == book[j]) {
					sum[count] += sold[j];
					mask[j] = true; // hide j
				}
			}
			count++;
		}
	}
	
	for (int i = 0; i<count; i++) {
		printf("book %-2d sold %-3d\n", unique[i], sum[i]);
	}
	return(0);
}
