#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *x, int *y)
  { int t;
    t = *x; *x = *y; *y = t;
  }
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
void insertSort(int a[], int n)
  { int i, j, x;
    for(i = 1; i<n; i++)
       { x = a[i];
         j = i;
         while(x<a[j-1])
            {a[j] = a[j-1]; j--;}
         a[j] = x;
       }
  }

int main()
  { system("cls");
    int a[100], n = 10;
    createData(a,n);
    printf("\nBefore sorting:\n");
    view(a,n);
    printf("\nAfter sorting:\n");
    insertSort(a,n);
    view(a,n);
    printf("\n");
    return(0);
  }
