#include <stdio.h>
#include <stdlib.h>
// input positive integer
int inputInteger(int *n)
 { char ch;int i;
   i = 1;
   while(1)
    {fflush(stdin);
     printf("Input integer n = ");
     scanf("%d%c", n, &ch);
     if((ch == '\n' || ch == ' ') && *n>0) return(1);
     if(i==3)
      {printf("You should learn to enter data first!\n");
       break;
      }
     i++;
    }
 }
int main()
 { int n, k;
   k = inputInteger(&n);
   if(k == 1)
     printf("Valid input\n");
       else
        printf("invalid input\n");
   return(0);
 }
