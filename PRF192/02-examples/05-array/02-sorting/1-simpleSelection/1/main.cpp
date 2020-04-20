#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Create n numbers in the interval [10,100] randomly
void createData(int a[], int n)
  { srand(time(NULL));
    for(int i = 0; i<n; i++)
          a[i] = 10 + rand()%91; 
  }
void view(int a[], int n)
  { for(int i=0;i<n;i++)  printf("%d   ",a[i]);
    printf("\n");
  }
void sort(int a[], int n)
  { int i, j, t;
    for(i=0; i<n-1; i++)
      for(j = i+1; j<n; j++)
         if(a[j]<a[i])  {t = a[i]; a[i] = a[j]; a[j] = t;}
  }

int main()
  { system("cls");
    int a[100], n = 10;
    createData(a,n);
    printf("\nBefore sorting:\n");
    view(a,n);
    printf("\nAfter sorting:\n");
    sort(a,n);
    view(a,n);
    printf("\n");
    return(0);
  }
