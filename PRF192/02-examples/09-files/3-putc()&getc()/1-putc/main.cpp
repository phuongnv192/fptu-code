#include <stdlib.h>
#include <stdio.h>
int main()
 {system("cls");

  FILE * f = fopen("test.txt","wt");
  putc('A',f);
  putc('B',f);
  putc('C',f);
  putc(' ',f);
  putc('D',f);
  putc('\n',f);

  fclose(f);
  //system("pause");
  return(0);
 }
          
