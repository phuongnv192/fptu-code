#include <iostream>
#include <time.h>
using namespace std;

int main()
{  long now;
   int day, month, year;
   tm * t;
   now = time(0);
   t = localtime(&now);
   day = t->tm_mday;
   month = t->tm_mon+1;
   year = t->tm_year+1900;
   cout<<"day: "<<day<<endl;
   cout<<"month: "<<month<<endl;
   cout<<"year: "<<year<<endl;
   int hour, minute, second;
   hour = t->tm_hour;
   minute = t->tm_min;
   second = t->tm_sec;
   cout<<"Time: ";
   cout.width(2);
   cout.fill('0');
   cout<<hour<<":";
   cout.width(2);
   cout.fill('0');
   cout<<minute<<":";
   cout.width(2);
   cout.fill('0');
   cout<<second<<endl;
   return(0);
}

