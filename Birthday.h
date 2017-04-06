#ifndef BIRTHDAY_H
#define BIRTHDAY_H

#include <iostream>

using namespace std;

class Birthday 
{
   private:
      short day;
      short month;
      short year;
      bool IsLeapYear();
      int MaxDayInMonth(int);

      bool IsValidDay();
      bool IsValidMonth();
      bool IsValidYear();
      bool IsValidDate();
   public:
      Birthday();
      void Input();
      short GetDay();
      short GetMonth();
      short GetYear();
      void SetDay(short);
      void SetMonth(short);
      void SetYear(short);
      friend ostream& operator<<(ostream& x, Birthday& b);
};

#endif //BIRTHDAY_H 
