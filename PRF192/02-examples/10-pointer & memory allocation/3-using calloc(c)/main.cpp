#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
 system("cls");
 int * a; int n, i;
 printf("Enter the size of the array n = ");
 scanf("%d",&n);
 a = (int *)  calloc(n, sizeof(int));
 printf("Enter %d numbers: ", n);
 for(i=0;i<n;i++) scanf("%d",&a[i]);

 printf("Numbers in the array: ");
 for(i=0;i<n;i++) printf("%d ",a[i]);
 printf("\n");
 free(a);
 system("pause");
 return(0);
}
