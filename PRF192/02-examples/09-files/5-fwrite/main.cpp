#include <stdlib.h>
#include <stdio.h>
int main()
 {system("cls");

  FILE * f = fopen("test.dat","wb");
  int a[5];
  int i,n; n = 3;
  for(i=0;i<n;i++) a[i] = i + 10;
  for(i=0;i<n;i++) printf("%d ",a[i]);
  printf("\n");
  fwrite(a,n,sizeof(int),f);
  fclose(f);
  

  //system("pause");
  return(0);
 }
          
