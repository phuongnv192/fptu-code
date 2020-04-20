#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct transcript {
	char filename[101];
	char detail[201];
	char time[30];
};

bool readdata(transcript demo[], bool mask[], int &n);

int main() {
	transcript demo[100];
	bool mask[100]; 
	int n, k;
	FILE  *fdemo, *fresult;

	readdata(demo, mask, n);
	
	/* result */
	fresult = fopen("result.txt", "w");
	for (int i = 0; i<n; i++) {
		if (mask[i] == true) {
			printf("Found '%s' with %s\n", demo[i].filename, demo[i].time);
			fprintf(fresult, "%s|%s\n", demo[i].filename, demo[i].time);
		}
	}
	fclose(fresult);
	
	return (0);
}

bool readdata(transcript demo[], bool mask[], int &n) {
	int k, x;
	FILE *fdemo;
	
	fdemo = fopen("transcriptDemo.txt", "r");
	if (fdemo == NULL) return false;
	n = 0;
	do {
		fflush(stdin);
		k = fscanf(fdemo,"%[^|]|%[^|]|%[^\n]\n", demo[n].filename, demo[n].detail, demo[n].time);
		n++;
		
		if (k == EOF) n--;
	} while (k != EOF);
	
	/* test fscanf */ /*
	for (int i = 0; i<n; i++) {
		puts(demo[i].filename);
		puts(demo[i].detail);
		puts(demo[i].time);
	} */
	
	for (int i = 0; i<n; i++) {
		//x = memcmp(demo[i].time,"0.00000", 7);
		x = strncmp(demo[i].time,"0.00000", 7);
		if ( x == 0) {
			mask[i] = false;
		}
		else mask[i] = true;
	}
	fclose(fdemo);
	return true;
}

