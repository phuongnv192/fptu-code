 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

 int main ( ) {
   long t = time(NULL);
   long yearFrom1970 = t/(3600*24*365);
   printf(" Years last from 1970 until now: %d\n", yearFrom1970);
   tm *h;
   h = localtime(&t);
   printf(" Year: %d\n", 1900+h->tm_year);
   printf(" Month: %d\n", h->tm_mon);
   printf(" Month day: %d\n", h->tm_mday);
   printf(" Week day: %d\n", h->tm_wday);
   printf(" Hour: %d\n", h->tm_hour);
   printf(" Minute: %d\n", h->tm_min);
   printf(" Second: %d\n", h->tm_sec);

  return 0;
 }

/*
time_t time(time_t* tp);
    Returns number of seconds from 1970 until now or -1 if not available. If tp is non-NULL, return value is also assigned to *tp.
time_t is of long type
*/