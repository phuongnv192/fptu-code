//This program displays the local time defined by the system:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
  { system("cls");
    tm *loc;
    long t; 
     // calculate number of seconds from 1970 until current time, 
    t = time(NULL); 
    loc = localtime(&t); // convert to tm format using local time
    printf("\n");
    printf("Year: %d\n", loc->tm_year+1900);
    printf("Month: %d\n", loc->tm_mon+1);
    printf("Day: %d\n", loc->tm_mday);
    printf("Week Day: %d\n", loc->tm_wday);
    printf("Hour: %d\n", loc->tm_hour);
    printf("Minute: %d\n", loc->tm_min);
    printf("Second: %d\n", loc->tm_sec);
    printf("\n");
    return 0;
  }

/*
struct tm
  { int tm_sec; // seconds, 0-59 
    int tm_min; // minutes, 0-59 
    int tm_hour; // hours, 0-23 
    int tm_mday; // day of the month, 1-31 
    int tm_mon; // months since Jan, 0-11 
    int tm_year; // years from 1900 
    int tm_wday; // days since Sunday, 0-6 
    int tm_yday; // days since Jan 1, 0-365 
    int tm_isdst; // daylight saving time indicator 
  };

time_t time(time_t* tp);
    Returns number of seconds from 1970 until now or -1 if not available. If tp is non-NULL, return value is also assigned to *tp.
*/