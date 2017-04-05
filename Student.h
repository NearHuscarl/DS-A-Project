#ifndef STUDENT_H
#define STUDENT_H

#include "Birthday.h"
#include <vector>

struct Student
{
   int mID;
   string mName;
   Birthday mBirthday;
   double mAvgScore;
};

class StudentList 
{
   private:
      vector<Student> stdList;
      int GetLine(ifstream &ifs);
      void SortID(int, int);
      void SortName(int left, int right, vector<string>& nameList);
      void SortScore(int, int);
      void FindID();
      void FindName();
      string GetName(string);

      /* template <typename T> */
      /* friend void Validate(string, T); */
      void ValidateStr(string, string);
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
