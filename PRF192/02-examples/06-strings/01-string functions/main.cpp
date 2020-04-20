#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//=====================
int main()
  {system("cls");
   char a[] ="HOA";
   char b[10];
   strcpy(b,a);
   printf("\nb = %s\n",b);
   strcat(a," LA");
   printf("\na = %s\n",a);

   printf("\nstrcmp(HOA,LA) = %d\n",strcmp("HOA","LA"));
   printf("\nstrcmp(LA,HOA) = %d\n",strcmp("LA","HOA"));
   printf("\nstrcmp(HOA,HOA) = %d\n",strcmp("HOA","HOA"));
   printf("\n");
   return(0);
  }
