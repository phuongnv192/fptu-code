#include <stdlib.h>
#include <stdio.h>
int main()
 {system("cls");
   FILE * f;
   f = fopen("test.txt","wt");
   int k=10; double x = 7.5;
   fprintf(f, "%d %.1f\n",k,x);
   fclose(f);
   FILE *g;
   g = fopen("test.txt","rt");
   int h; double y;
   fscanf(g,"%d%lf",&h,&y);
   printf(" h = %d, y =  %.1f\n",h,y);
 

  //system("pause");
  return(0);
 }
          
