#include <iostream> 
#include <stdlib.h> 
#include <fstream>
#include "Student.h"
#include <string>

using namespace std;

class Student;

int main()
{
   StudentList students;
   int choice = -1, subChoice;

   while(choice != 0)
   {
      cout << "Press 0 to exit" << endl;
      cout << "Press 1 to read from DSSV.dat file" << endl;
      cout << "Press 2 to write to DSSV.dat file" << endl;
      cout << "Press 3 to add new data" << endl;
      cout << "Press 4 to print all students data" << endl;
      cout << "Press 5 to add a new student to the list" << endl;
      cout << "Press 6 to find information about (a) student(s)" << endl;
      cout << "Press 7 to sort student list" << endl;
      cout << "Press 8 to read from input.txt" << endl;
      cout << "Choice: ";
      cin >> choice;
      while(true)
      {
         if(cin.fail() || choice < 0 || choice > 8)
         {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Wrong input. Enter again" << endl;
            cout << "Choice: ";
            cin >> choice;
         }
         else
         {
            break;
         }
      }
      switch(choice)
      {
         case 0:
            return 0;
         case 1:
            students.Read();
            break;
         case 2:
            students.Write();
            break;
         case 3:
            students.Input();
            break;
         case 4:
            students.Output();
            break;
         case 5:
            students.Update();
            break;
         case 6:
            cout << "Press 0 to find student by ID" << endl;
            cout << "Press 1 to find student by name" << endl;
            cout << "Choice: ";
            cin >> subChoice;
            students.Find(subChoice);
            break;
         case 7:
            cout << "Press 1 to sort student list by ID" << endl;
            cout << "Press 2 to sort student list by name" << endl;
            cout << "Press 3 to sort student list by average score" << endl;
            cout << "Choice: ";
            cin >> subChoice;
            students.Sort(subChoice);
            break;
         case 8:
            int size;
            cout << "Size: ";
            cin >> size;
            students.ReadTxt(size);
            break;
      }
      system("cls");
   }
}
