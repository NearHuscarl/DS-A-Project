#include <iostream>
#include "Birthday.h"
#include <iomanip>

using namespace std;

Birthday::Birthday()
{

}

void Birthday::Input()
{
   cout << endl;
   cout << "Day: ";
   cin >> day;
   cout << "Month: ";
   cin >> month;
   cout << "Year: ";
   cin >> year;
}

short Birthday::GetDay()
{
   return day;
}

short Birthday::GetMonth()
{
   return month;
}

short Birthday::GetYear()
{
   return year;
}

void Birthday::SetDay(short x)
{
   day = x;
}

void Birthday::SetMonth(short x)
{
   month = x;
}

void Birthday::SetYear(short x)
{
   year = x;
}

ostream& operator<<(ostream& x, Birthday& b)
{
   return x << setfill('0') << setw(2) << b.day << "/" << setw(2) << b.month << "/" << setw(4) << b.year << setfill(' ');
}
