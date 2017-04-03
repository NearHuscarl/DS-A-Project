#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <vector>
class Student;

using namespace std;

class StudentList: public Student 
{
   private:
      int mLength;
      vector<Student> mpStudent;
      void Swap(Student x, Student y);
   public:
      StudentList();
      ~StudentList();

      void ReadFile();
      void Insert();
      void Update();
      void Print();
      void Find(int type);
      void Sort(int type);
      void Remove();
};

#endif //STUDENTLIST_H 
