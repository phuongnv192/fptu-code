#include <stdio.h>
#include <stdlib.h>
#include <math.h>

bool square(int n){
	if(n<2) return false;
	if(sqrt(n) == (int) sqrt(n)) return true; // can bac 2 cua n (float) = phan nguyen cua sqrt(n)
	else return false;
}

int main() {
	int a;
	printf("a = ");
	scanf("%d", &a);
	if (square(a) == true) printf("a la so chinh phuong\n");
	else printf("a khong la so chinh phuong\n");
	return 0;
}
