#include <stdio.h>
#include <stdlib.h>
int factorial(int n)
 { int s, i;
   s = 1;
   for(i =1;i<=n;i++)
    s *=i;
   return(s); 
 }
int main()
 { system("cls");
   int n;
   printf("Enter n = ");
   scanf("%d",&s);
   
   printf(" %d! = %d\n", n, factorial(n));
   system("pause");
   return(0);
 }
 
          
