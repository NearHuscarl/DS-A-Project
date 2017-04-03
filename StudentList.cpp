#include <iostream>
#include <vector>
#include "Student.h"
#include "StudentList.h"

using namespace std;

StudentList::StudentList()
{
}

StudentList::~StudentList()
{
}

void Swap(Student x, Student y)
{
   Student temp;

   temp = x;
   x = y;
   y = temp;
}
/* void StudentList::Insert(void) */
/* { */
/*    Student x; */

/*    x.Input(); */
/*    mpStudent.push_back(x); */
/*    Sort(1); */
/* } */

//1: ID
//2: nam
//3: avgScore
/* void StudentList::Sort(int type) */
/* { */
/*    if(type == 1) */
/*    { */
/*       for(int i = 0; i < mpStudent.size(); i++) */
/*       { */
/*          for(int j = 0; j < mpStudent.size(); j++) */
/*          { */
/*             if(mpStudent[i].GetID() > mpStudent[j].GetID()) */
/*             { */

/*             } */
/*          } */
/*       } */
/*    } */
/* } */
