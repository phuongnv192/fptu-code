#include <stdio.h>
#include <stdlib.h>
void swap(int x, int y)
 { int t;
   t = x;
   x = y;
   y = t;
 }
int main()
 { system("cls");
   int x, y;
   x = 5; y = 10; 
   printf(" x = %d, y = %d \n ", x, y);
   swap(x,y);
   printf(" x = %d, y = %d \n ", x, y);
   system("pause");
   return(0);
 }
 
          
