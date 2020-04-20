#include <stdio.h>
#include <stdlib.h>
/* so hoan chinh la so co tong cac uoc = 2 lan chinh no*/

bool perfect(int n){
	int s = 0;
	for(int i = 1; i<=n; i++){
		if(n%i == 0) s += i;
	}
	if(2*n == s) return true;
	else return false;
}

int main() {
	int a;
	printf("a = ");
	scanf("%d", &a);
	if (perfect(a) == true) printf("a la so hoan chinh\n");
	else printf("a khong la so hoan chinh\n");
	return 0;
}
