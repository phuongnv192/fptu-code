#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* doi gia tri t va z ~ 5 va 2
	pointer: con tro
			* va &
	*  : gia tri
	&  : dia chi
*/

//lay qua chuoi trong tu lanh

void swap(int *a, int *b) { // lay qua chuoi (co tem)
	int x;
	
	printf("ban dau: %d %d\n", *a, *b);
	x = *b;
	*b = *a;
	*a = x;
	
	printf("luc sau: %d %d\n", *a, *b);
}

int main() {
	int t, z;
	
	t = 5; z = 2;
	swap(&t, &z); // trong tu lanh.
	printf("tai main(): %d %d\n", t, z);
	return 0;
}

//lay qua chuoi trong tu lanh
void swap(int &a, int &b) { // bao Ha Hai den tu lanh giup Phuong lay cai gi do 
                            // trong tu lanh chi co 1 qua chuoi.
	int x;
	
	printf("ban dau: %d %d\n", a, b);
	x = b;
	b = a;
	a = x;
	
	printf("luc sau: %d %d\n", a, b);
}

int main() {
	int t, z;
	
	t = 5; z = 2;
	swap(t, z); //t ~ &a cai tu lanh
	printf("tai main(): %d %d\n", t, z);
	return 0;
}
