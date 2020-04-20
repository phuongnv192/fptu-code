#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int a = 0,b;
	while (a<5) {
		printf("Enter a>=5: "); 
		scanf("%d", &a);
		if (a<5) {
			printf("a in not >= 5, please re-enter!\n"); 
		}
		else {
			b = a + 6;
			printf("a + 6 = %d",b); 
		}
	}
	return(0);
}

