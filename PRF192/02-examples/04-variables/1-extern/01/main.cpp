//EXTERN.CPP Vi du ve su dung bien extern
#include <stdio.h>
int main(void)
  { extern int first, last; /* use global vars */
    printf("%d %d\n", first, last);
    return 0;
  }
/* global definition of first and last */
int first = 10, last = 20;

/*
This program outputs 10 20 because the global variables first and last used by the printf( ) statement are initialized to these values. Because the extern declaration tells the compiler that first and last are declared elsewhere (in this case, later in the same file), the program can be compiled without error even though first and last are used prior to their definition.
It is important to understand that the extern variable declarations as shown in the preceding program are necessary only because first and last had not yet been declared prior to their use in main( ). Had their declarations occurred prior to main( ), then there would have been no need for the extern statement. Remember, if the compiler finds a variable that has not been declared within the current block, the compiler checks if it matches any of the variables declared within enclosing blocks. If it does not, the compiler then checks the global variables. If a match is found, the compiler assumes that that is the variable being referenced. The extern specifier is needed when you want to use a variable that is declared later in the file.
*/