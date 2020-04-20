 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

 int main ( ) {
   long t = time(NULL);
   printf(" the number of seconds since midnight Jan 1, 1970: %ld\n", t);

  return 0;
 }

/*
A type for storing the current time and date. This is the number of seconds since midnight Jan 1, 1970.
typedef	long	time_t;

time_t time(time_t* tp);
    Returns number of seconds from 1970 until now or -1 if not available. If tp is non-NULL, return value is also assigned to *tp.
time_t is of long type
*/
