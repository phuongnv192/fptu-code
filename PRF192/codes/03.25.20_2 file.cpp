#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
	FILE *fp;
	
	if (fopen("hello.txt", "w") == NULL) {
		printf("file not exist\n");
	}
	else {
		printf("file exist\n");
	}
	return (0);
}
