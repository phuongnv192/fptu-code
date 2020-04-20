#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
 {system("cls");

  int a[5], b[5];
  int i,n; n = 3;
  for(i=0;i<n;i++) a[i] = 10 +i;


  for(i=0;i<n;i++) printf("%d ",a[i]);
  printf("\n");
  memcpy(b,a,n*sizeof(int));  

  for(i=0;i<n;i++) printf("%d ",b[i]);
  printf("\n");

  //system("pause");
  return(0);
 }
          
