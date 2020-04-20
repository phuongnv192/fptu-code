#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main(){
    int a = 1;
    printf("a = "); 
	scanf("%d", &a);
	
	switch (a){
		case 0:
			printf("a = 0\n");
			break;   /*neu khong co break, xay ra fall through: 
			           chay den khi nao co break moi dung lai */
		case 1:
			printf("a = 1\n");
			break;
		default:
			printf("a != 0, 1\n");
	}
	return(0);
}
