//ByVal.CPP Vi du ve truyen tham so theo tham tri (pass by value)
#include <stdio.h>
#include <conio.h>
//==================================================
/*Ham swap doi gia tri hai bien thuc x va y, nhung vi truyen theo tham tri
nen su doi gia tri chi co hieu luc ben trong ham ma thoi
*/
void swap(float x,float y)
 {float t;
  t=x;x=y;y=t;
  printf("\nGia tri cua x va y         trong ham swap la: %4.0f  %4.0f",x,y);
 };
//==================================================
int main()
  { float x,y;
  
    x=1; y=5;
    printf("\nGia tri cua x va y truoc khi goi ham swap la: %4.0f  %4.0f",x,y);
    swap(x,y);
    printf("\nGia tri cua x va y   sau khi goi ham swap la: %4.0f  %4.0f\n",x,y);
    return(0);
  }
