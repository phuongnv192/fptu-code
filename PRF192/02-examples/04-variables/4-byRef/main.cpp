//ByRef.CPP Vi du ve truyen tham so theo tham chieu (pass by reference)
#include <stdio.h>
#include <conio.h>
//==================================================
/*Ham swap doi gia tri hai bien thuc x va y, truyen theo tham chieu
nen su thay doi ben trong ham khi ra ben ngoai van con hieu luc.
*/
void swap(float *px,float *py)
 {float t;
  t=*px;*px=*py;*py=t;
  printf("\nGia tri cua x va y         trong ham swap la: %4.0f  %4.0f",*px,*py);
 };
//==================================================
int main()
 {float x,y;
  x=1; y=5;
  printf("\nGia tri cua x va y truoc khi goi ham swap la: %4.0f  %4.0f",x,y);
  swap(&x,&y);
  printf("\nGia tri cua x va y   sau khi goi ham swap la: %4.0f  %4.0f\n",x,y);
  return(0);

  }
