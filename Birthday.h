#ifndef BIRTHDAY_H
#define BIRTHDAY_H

#include <iostream>

using namespace std;

class Birthday 
{
   private:
      int day;
      int month;
      int year;
      bool IsLeapYear();
      int MaxDayInMonth(int);

      bool IsValidDay();
      bool IsValidMonth();
      bool IsValidYear();
      bool IsValidDate();
   public:
      Birthday();
      void Input();
      int GetDay();
      int GetMonth();
      int GetYear();
      void SetDay(int);
      void SetMonth(int);
      void SetYear(int);
      friend ostream& operator<<(ostream& x, Birthday& b);
      friend class Menu;
};

#endif //BIRTHDAY_H 
