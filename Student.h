#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "Birthday.h"

class Student
{
   private:
      int mID;
      std::string mName;
      Birthday mBirthday;
      double mAvgScore;
   public:
      bool IsValidScore(double);
      void Input();
      void Output();
      friend class StudentList;
      friend class Menu;
      friend bool Compare(const Student&, const Student&);
};

#endif //STUDENT_H 
