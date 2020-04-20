//EXTERN.CPP Vi du ve su dung bien extern
#include <stdio.h>
#include <conio.h>
//==================================================
/*Gia su ta dung lenh #include de chen mot tep nao do vao chuong trinh
 hien tai. Khi do neu ta khai bao lai mot bien da khai bao trong tep include
 thi chuong trinh se bao loi. Luc nay hoac ta khong khai bao lai, hoac
 khai bao voi tu khoa extern de bao cho C biet la bien nay da khai bao.
 ta Vi du trong tep EX.H ta da khai bao bien toan cuc x co kieu float
 (float x;), khi do neu khai bao lai x thi phai viet la extern float x;
*/
#include "ex.h"
extern float x;
int main()
 {// clrscr();
  printf("\nHay nhap gia tri x = ");
  scanf("%f",&x);
  printf("\n\nGia tri x da nhap la: %4.1f\n",x);
  return(0);
  }
