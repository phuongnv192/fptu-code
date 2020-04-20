#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void input(double a[], int &n) {
  printf("Enter n (number of elements in the array) = ");
  scanf("%d",&n);
  printf("Enter %d numbers: ",n);
  for(int i=0;i<n;i++) scanf("%lf",&a[i]);
}
void display(double a[], int n) {
	printf("Elements in the array:\n");
	for(int i=0;i<n;i++) printf("%4.1f ",a[i]);
	printf("\n");
}
// Search and return the first element a[i], for which a[i]==x
int search(double a[],int n, double x) {
  for(int i=0;i<n;i++){
	if(a[i]==x) return(i);
  }	
  return(-1);	
}
// Delete the element a[k]
void dele(double a[], int &n, int k) {
  if(k<0 || k>n-1) return;
  for(int i=k;i<n-1;i++) a[i] = a[i+1];
  n--;
}
// Delete the first a[i], for which a[i]=x
void dele(double a[], int &n, double x) {
  int k = search(a,n,x);
  dele(a,n,k);	
}
int maxPos(double a[], int n) {
	double max = a[0]; int k =0;
	int i;
	for(i=1;i<n;i++) {
	  if(a[i]>max) {
			max = a[i]; k = i;
	  }	
	}
   return(k);
}
void sort(double a[], int n) {
	double x; int i,j;
	for(i=0;i<n-1;i++) {
		for(j=i+1;j<n;j++) {
			if(a[j]<a[i]) {
				x=a[i];a[i]=a[j];a[j]=x;
			}
		}
	}
}
int main() {
 system("cls");
 double a[100]; int n, k; double x;
 int choice;
 while(1) {
		printf("\n");
		printf("1. Input data\n");
		printf("2. Display\n");
		printf("3. Search\n");
		printf("4. Delete position\n");
		printf("5. Delete value\n");
		printf("6. Sort data\n");
		printf("0. Exit\n");
        printf("Enter your selection (0 -> 6): ");
		scanf("%d",&choice);
		if(choice==0) break;
		switch(choice) {
			case 1: input(a,n);
			        break;
			case 2: display(a,n);
			        break;
			case 3: printf("Enter a value to be searched x = ");
			        scanf("%lf",&x);
			        k = search(a,n,x);
			        if(k==-1)
			         printf("Not found\n");
			         else
			          printf("Found at position %d\n",k);
				    break;
			case 4: printf("Enter a position to be deleted k = ");
			        scanf("%d",&k);
                    		        dele(a,n,k);
			        break;
			case 5: printf("Enter a value to be deleted x = ");
			        scanf("%lf",&x);
                    		        dele(a,n,x);
			        break;
			case 6: sort(a,n); break;
			default: printf("Your selection is incorrect\n"); 
				    break;
			
		}		
 }
 printf("\n");
 system("pause");
 return(0);
}
