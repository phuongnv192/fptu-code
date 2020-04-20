#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main() {
	int n, danhdau;
	printf("Enter n = "); scanf("%d",&n); 
	printf("Day so 1 den %d chia het cho 2 la:",n);
	for (int i = 1; i<= n; i++) {
		if ((i%2)==0) {
			danhdau = i; //danh dau do dau tien thoa man dieu kien
			printf(" %d",i); //in ra so dau tien khong co dau phay
			break;
		}
	}
	
	for (int i = danhdau +1; i<= n; i++) {
		if ((i%2)==0) {
			printf(", %d",i); // in ra day so con lai co dau phay
		}
	}
	printf("END");
	
	
	/*
	// in day so cat duoi
	for (int i = 1; i<= n; i++) {
		if ((i%2)==0) {
			danhdau = i;
		}
	}
	
	for (int i = 1; i<= n; i++) {
		if ((i%2)==0) {
			printf(" %d",i); //in ra day so co dau phay
			//kiem tra, neu la so cuoi cung thi ko in dau phay
			if ( i != danhdau) {
				printf(",");
			}
		}
	}
	printf("END");
	*/
	return(0);	
}
