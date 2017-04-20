#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Birthday.h"
#include "Student.h"
#include <vector>

class StudentList 
{
   private:
      vector<Student> stdList;
      int GetLine(ifstream &ifs);
      void SortID(int, int);
      void SortName(int left, int right, vector<string>& nameList);
      void SortScore();
      string GetName(string);
      void ValidateID(Student &st);
   public:
      std::string GetFullName(int);

      void ReadTxt();
      bool Read();
      bool Write();
      void Input();
      void Update();
      void DeleteOne(int);
      void Delete();
      void Print();
      void Add();
      void Sort(int);
      vector<Student> FindID(int);
      vector<Student> FindName(std::string);
      friend class Menu;
};

#endif //STUDENTLIST_H

//TODO:
