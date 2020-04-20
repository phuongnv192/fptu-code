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
void bubbleSort(int a[], int n)
  { int i, t, k, doicho;
    k = 1;
    while(1)
       { doicho=0;
          for(i=0; i<n-k; i++)
              if(a[i+1]<a[i]) 
                { swap(&a[i], &a[i+1]);
                  doicho = 1;
                }
          if(!doicho) break;
          k++;  
       }
  }

int main()
  { system("cls");
    int a[100], n = 10;
    createData(a,n);
    printf("\nBefore sorting:\n");
    view(a,n);
    printf("\nAfter sorting:\n");
    bubbleSort(a,n);
    view(a,n);
    printf("\n");
    return(0);
  }
