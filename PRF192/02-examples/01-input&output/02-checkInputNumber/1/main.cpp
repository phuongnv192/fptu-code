#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
   int n; char ch; 
   fflush(stdin);
   printf("Input integer n = ");
   scanf("%d%c",&n,&ch);
   fflush(stdin);
   if(ch==0) // Enter a
     printf("InCorrect input!\n");
   if(isalpha(ch)) // Enter 12a
     printf("Trailing character\n");

   printf("n = %d\n",n);	
   printf("ch = %d\n",ch);	
   //system ("pause");
 return(0);
}
