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
      void SortScore();
      void FindID();
      void FindName();
      string GetName(string);
      void ValidateStr(string, string);
      void ValidateID(Student &st);
   public:
      void ReadTxt();
      void Read();
      void Write();
      void Input();
      void Update();
      void DeleteOne();
      void Delete();
      void Print();
      void Add();
      void Find();
      void Sort();
};

#endif //STUDENT_H 
