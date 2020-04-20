/*
Su dung bien duoc khai bao la static
Cu phap
static <kieu du lieu> <ten bien>;
Co hai kieu bien: automatic la ngam dinh va static. Bien kieu static
duoc khai bao ben trong ham va no khong bi mat di khi mot loi goi ham
ket thuc ma van giu nguyen gia tri cuoi cung.
Vi du sau cho thay gia tri x trong ham thu duoc khoi tao lan dau va
duoc cap nhat cho cac lan goi sau.
*/
#include <stdio.h>
#include <conio.h>
void thu()
 {static int n=1;
  printf("\n    Ham thu() duoc goi lan thu %d",n);
  n++;
 }
int main()
 { int i;
   for(i=1;i<=10;i++) thu();

   printf("\n\n");
   return(0);
 }
