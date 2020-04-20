#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

void shuffle(int card[]) {
	int i, cardleft, j, temp;
	
	cardleft = cards;
	for (i = 0; i < cards; i++) {
		j = i + rand() % cardsleft;
		temp = card[i];
		card[i] = card [j];
		card[j] = temp;
		cardsleft--;
	}
}

int main() {
	int a[5] = {1,2,3,4,5};
	
	
	printf("Before: ")
	for (int i = 0; i<5; i++) {
		printf("%d, ", a[i])
	}
	shuffle(a);
	printf("After: ")
	for (int i = 0; i<5; i++) {
		printf("%d, ", a[i])
	}
	return(0);
}
