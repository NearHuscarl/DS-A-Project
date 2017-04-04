#ifndef STUDENT_H
#define STUDENT_H

/* class Birthday; */
#include "Birthday.h"
#include <vector>

struct Student
{
   int mID;
   string mName;
   Birthday mBirthday;
   int mAvgScore;
};

class StudentList 
{
   private:
      vector<Student> stdList;
      int GetLine(ifstream &ifs);
      void SortID(int, int);
      void SortName(int, int);
      void SortScore(int, int);
      void FindID();
      void FindName();
   public:
      void Read();
      void Write();
      void Input();
      void Output();
      void Update();
      void Find(bool);
      void Sort(int);
};

#endif //STUDENT_H 
