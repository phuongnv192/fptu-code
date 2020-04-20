#include <stdio.h>
#include <stdlib.h>
void input(float a[], int *n)
  { printf("Enter number of elements n = ");
    scanf("%d",n);
    printf("Enter %d float numbers: ", *n);
    for(int i=0;i<*n;i++)  scanf("%f",&a[i]);
  }
void display(float a[], int n)
  { printf("\nList of numbers: ");
    for(int i=0;i<n;i++)  printf("%.2f   ",a[i]);
    printf("\n");
  }
int main()
  { system("cls");
    float a[100]; int n;
    input(a,&n);
    display(a,n);
    printf("\n");
    return(0);
  }
