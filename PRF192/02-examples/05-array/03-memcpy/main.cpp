#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
//===================================
int main()
  { system("CLS");
    int a[10], b[10], i;
    for(i=0; i<10; i++) {a[i] = 0; b[i] = i;}
    memcpy(a, b, 10*sizeof(int));
    for(i=0; i<10; i++) printf("%d  ", a[i]);
    printf("\n");
    return 0;
  }
