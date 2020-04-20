#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int find (int search, int key[], int size) {
	int i = 0, rc = -1; // rc = -1 mean not found, if found rc record position of key[i]
	
	for (i = 0; i < size && rc == -1; i++) {
		if (search == key[i]) {
			rc = i;
		}
	}
	return rc;
}

int main() {
	int a[7] = {1, 2, 3, 4, 5, 76, 413}, x;
	
	x = find(76, a, 7);
	if (x != -1) {
		printf("Found 76 in position number %d.", x+1);
	}
	else printf("76 is not found.");
	
	return (0);
}
