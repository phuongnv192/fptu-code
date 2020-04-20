#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//fclose, fprintf, fputc, fputs 
int main () { 
	FILE *fp;
	
	fp = fopen("hello.txt", "W");
	if ( fp == NULL) { 
		printf("file not exist\n");
	}
	else {
		printf("file exists\n"); 
		fprintf(fp, "hello world %d\n", 123);
		fputs ("hello puts", fp);
 		fputc ('A', fp);
 		fclose (fp);
	}
return 0;
}
