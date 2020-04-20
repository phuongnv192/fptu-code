#include <stdio.h>
#include<string.h>
#include <conio.h>

int main() { 
    char n[100], m[100];
    int k, a;
    
    printf("Nhap xau: ");
	gets(n);
	a = strlen(n);
	k = a-1;
	for (int i = 0; i < a; i++) {
      m[i] = n[k];
      k--;
	}
   m[a] = '\0';
   
   if (strcmp(n,m) == 0) {
   	printf("%s and the reverse of it are the same.\n",n);
   }
   else {
   		printf("%s and the reverse of it are not the same.\n",n);
   }
	return(0);	
}
