#include <stdlib.h>
#include <stdio.h>
int main()
 {system("cls");

  FILE * f = fopen("test.dat","rb");
  int a[5];
  int i,n; n = 3;
  for(i=0;i<n;i++) a[i] = 0;

  fread(a,n,sizeof(int),f);

  for(i=0;i<n;i++) printf("%d ",a[i]);
  printf("\n");
  fclose(f);
  

  //system("pause");
  return(0);
 }
          
