#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Emp
 {char name[21]; int age; float sal;
 };

void loadData(char *fname, Emp a[], int &n)
 {FILE * f = fopen(fname,"rt");
  char s1[21], s2[21], s3[21];
  int xAge; float xSal; int k;
  while(true)
   {k = fscanf(f,"%[^|]|%[^|]|%[^\n]",s1,s2,s3);
    if(k<3) break;
    printf("%s  %s  %s  \n",s1,s2,s3);
   }
  fclose(f);
 }
int main()
 {system("cls");
   Emp a[100]; int n;
   char fname[20]; strcpy(fname,"emp.txt");
   loadData(fname,a,n);
  system("pause");
  return(0);
 }
 