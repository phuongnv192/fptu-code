#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Emp {
 char name[30]; int age; double sal;	
};
void input(Emp &x) {
 printf("Enter name: ");
 fflush(stdin);
 gets(x.name);
 printf("Enter age: ");
 scanf("%d",&x.age);
 printf("Enter salary: ");
 scanf("%lf",&x.sal);
}
void display(Emp x) {
  printf("%10s %5d  %7.2f\n",x.name,x.age,x.sal);
	
}
void input(Emp a[], int &n) {
	printf("Enter n = ");scanf("%d",&n);
	int i;
	for(i=0;i<n;i++) {
		printf("Enter data for person %d:\n",i);
		input(a[i]);
		
	}
}

void inputFromFile(char fname[], Emp a[], int &n) {
  FILE * f; 
  f = fopen(fname,"rt");
  char sName[20], sAge[20], sSal[20];
  int k,i;
  Emp x; i = 0;
  while(1) {
    k = fscanf(f,"%[^|]|%[^|]|%[^\n]",sName,sAge,sSal);
    if(k<3) break;
    //printf("%s  %s  %s  \n",sName,sAge,sSal);
    strcpy(x.name,sName);
    x.age = atoi(sAge);
    x.sal = atof(sSal);
    a[i++] = x;
   }
  n = i; 
  fclose(f);
	
 }  
		

void display(Emp a[], int n) {
	printf("List of %d persons:\n",n);
	for(int i=0;i<n;i++) display(a[i]);
	printf("\n"); 
}

void sortByName(Emp a[], int n) {
	Emp x; int i,j;
	for(i=0;i<n-1;i++)
	 for(j=i+1;j<n;j++) 
	  if(strcmp(a[j].name,a[i].name)<0){
		x = a[i]; a[i]=a[j]; a[j]=x;	
	  }
	   
}

void sortByAge(Emp a[], int n) {
	Emp x; int i,j;
	for(i=0;i<n-1;i++)
	 for(j=i+1;j<n;j++) 
	  if(a[j].age <a[i].age){
		x = a[i]; a[i]=a[j]; a[j]=x;	
	  }
	   
}

int main() {
  Emp a[100]; int n;
  char fname[] = "emp.txt";  
  inputFromFile(fname,a,n);
  display(a,n); 
  
  system("pause");
  return(0);	
}
