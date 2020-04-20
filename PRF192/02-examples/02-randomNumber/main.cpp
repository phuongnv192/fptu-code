#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

// Create n random number from  a  to  b
void randNumbers(int a, int b, int n)
   { printf("\n%d  random numbers between  %d   and   %d:\n\n",n,a, b );
     int k;
     for (int i = 0; i < n ; i++)
        { k = a + rand() % (b + 1 - a);
          printf("%d  ",  k); 
        }
     printf("\n\n");
   }
// Create n float random number from  a  to  b
void randNumbers(float a, float b, int n)
   { printf("\n%d  random numbers between  %5.0f   and   %5.0f:\n\n",n,a, b );
     float x;
     for (int i = 0; i < n ; i++)
        { x = a + ((float) rand()) / RAND_MAX*(b - a);
          printf("%5.2f  ",  x); 
        }
     printf("\n\n");
   }
int main ( )
  {
     int  n =10, a = 6, b = 100;

     printf("RAND_MAX = %d\n", RAND_MAX);
     srand(time(NULL));
     printf("This is a pseudo random number between 0 and RAND_MAX: %d\n", rand());
     randNumbers(a,b,n);     
     getch();
     randNumbers(a,b,n);     
     randNumbers((float) a,(float) b,n);     
     return(0);
  }

/*
 The prototype for rand( ) is in <stdlib.h>.
 The rand( ) function generates a sequence of pseudorandom numbers. Each time it
 is called it returns an integer between 0 and RAND_MAX.
 The srand() function creates the seed value for the random number generator.
 This function should be called before calling the rand() function. 
 srand(time(NULL)) create the seed value based on current time.
*/
