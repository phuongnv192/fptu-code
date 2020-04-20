#include <stdio.h>
#include <stdlib.h>
int main()
  { system("cls");
    float a[100]; int n, i;
    printf("Enter number of elements n = ");
    scanf("%d",&n);
    printf("Enter %d float numbers: ", n);
    for(i=0;i<n;i++)  scanf("%f",&a[i]);
    printf("\nList of numbers entered is: ");
    for(i=0;i<n;i++)  printf("%.2f   ",a[i]);
    printf("\n");
    return(0);
  }
