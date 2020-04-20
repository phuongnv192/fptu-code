#include <conio.h>
#include <stdio.h>
int main ()
{
char c;
int count=0;
int x;

for (c = 'A' ; c <= 'Z' ; c++) 
	{
	putchar (c);
	}
	getch();
	printf("\b "); // Removes Z
//	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                         "); // leaves A 
//	printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b                        "); // leaves A and Z
	
return 0;
}
