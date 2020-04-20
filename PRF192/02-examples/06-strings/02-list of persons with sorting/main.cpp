#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//=====================
struct PType
 {char name[31]; int age;
 };
void input(PType &t)
 {printf("\nEnter name: "); fflush(stdin);gets(t.name);
  printf("Enter age: "); scanf("%d",&(t.age));
 }
void display(PType t)
 {printf("%20s %5d\n",t.name,t.age);
 }
void input(PType a[],int &n)
 {printf("\nEnter n = ");
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++)
   {printf("\nEnter data for person %d:",i+1);
    input(a[i]);  
   }
 }
void display(PType a[],int n)
 {int i;
  printf("\nList of persons:\n");
  for(i=0;i<n;i++) display(a[i]);
 }
void sort(PType a[],int n)
 {int i,j; PType t;
  for(i=0;i<n-1;i++)
   for(j=i+1;j<n;j++)
    if(strcmpi(a[j].name,a[i].name)<0) {t=a[i];a[i]=a[j];a[j]=t;}
 }

int main()
  {system("cls");
   int n;
   PType a[100];
   input(a,n);
   display(a,n);
   printf("\nAfter sorting by name:");
   sort(a,n);
   display(a,n);
   printf("\n");
   return(0);
  }
