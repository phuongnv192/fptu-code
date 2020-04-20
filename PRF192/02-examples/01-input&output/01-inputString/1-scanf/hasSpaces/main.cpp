#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//===================================
int main()
  { char str[200]; 
    system("CLS");

    fflush(stdin);
    printf("Enter the string (only the characters A, B, and C): ");
    scanf("%[ABC]",str);//read only the characters A, B, and C
    printf("The string entered is:  %s\n", str);

    fflush(stdin);
    printf("Enter the string (accept the letters 'A' through 'F'): ");
    scanf("%[A-F]",str);//read only the characters A, B, C, E, E, F
    printf("The string entered is:  %s\n", str);

    fflush(stdin);
    printf("Enter the string until encountering the '\\n' character: ");
    scanf("%[^\n]",str);//read until encountering the '\n' character
    printf("The string entered is:  %s\n", str);
    return(0);
  }
