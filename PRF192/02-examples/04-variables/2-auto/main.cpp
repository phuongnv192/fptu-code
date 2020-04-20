#include <stdio.h>
#include <conio.h>
// auto int y; /* ERROR */
int main()
 {auto float x;
  printf("\nHay nhap gia tri x = ");
  scanf("%f",&x);
  printf("\n\nGia tri x da nhap la: %4.1f\n",x);
  return(0);
  }

/*
The C language contains the keyword auto, which can be used to declare local variables.
 However, since all nonglobal variables are assumed to be auto by default, it is virtually never used.
*/