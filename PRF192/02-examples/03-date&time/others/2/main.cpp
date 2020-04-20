//This program displays the local time defined by the system:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
  { system("cls");
    tm *local, *gm;
    time_t lt; // lt is a variable of long type
    lt = clock(); // calculate number of miliseconds until current time 
    local = localtime(&lt); // convert to tm format using local time
    printf("\n");
    char * str = asctime(local);
    printf(str); // (*) 
    printf("\n");
    printf("\n");
    printf(ctime(&lt)); // The same as (*) 
    printf("\n");
    gm = gmtime(&lt);
    printf("Greenwich mean time and date: %s", asctime(gm));
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

 time_t  time(time_t  *time);
 Description
 The prototype for time( ) is in <time.h>.
 The time( ) function returns the current calendar time of the system.
*/