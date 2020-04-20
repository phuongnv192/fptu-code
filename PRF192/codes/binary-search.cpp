#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*  binary Find returns the first index where search == key[index] for key[size] where key is sorted in
	ASCENDING ORDER
	or -1 if match not found
*/

int binaryFind (int search, int key[], int size) {
 	int rc = -1, i, low = 0, high = size-1;
 
	do {
		/* calculate mid-element */
		i = (low + high + 1) / 2;
		if (search < key[i]) {
			/* reset high element */
			high = i - 1;
		}		 
		else if (search > key[i]) {
			/* reset low element */
			low = i + 1;
		}
		else {
			/* found it */
			rc = i;
		}
	} while (rc == -1 && low <= high);
	 
	return rc;
}

int main() {
	int a[7] = {1, 2, 3, 4, 5, 76, 413}, x;
	
	x = binaryFind(76, a, 7);
	if (x != -1) {
		printf("Found 76 in position number %d.", x+1);
	}
	else printf("76 is not found.");
	
	return (0);
}
