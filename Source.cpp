#include <iostream> 
#include <stdlib.h> 
#include <fstream>
#include "Student.h"
#include <string>
#include <windows.h>

using namespace std;

class Student;

void gotoxy(int column, int line)
{
   COORD coord;
   coord.X = column;
   coord.Y = line;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

   template <typename T>
void Validate(string redoMsg, T reassignVar)
{
   while(true)
   {
      if(cin.fail())
      {
         cin.clear();
         cin.ignore(INT_MAX, '\n');
         cout << "Wrong input. Enter again" << endl;
         cout << redoMsg;
         cin >> reassignVar;
      }
      else
      {
         break;
      }
   }
}

int main()
{
   StudentList students;
   int choice = -1, subChoice;

   while(choice != 0)
   {
      cout << " /$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
      cout << "| $$__________________________________________________ /$$" << endl;
      cout << "| $$ Press 0 to exit                                  | $$" << endl;
      cout << "| $$ Press 1 to read from DSSV.dat file               | $$" << endl;
      cout << "| $$ Press 2 to write to DSSV.dat file                | $$" << endl;
      cout << "| $$ Press 3 to add a new student to the list         | $$" << endl;
      cout << "| $$ Press 4 to update a student info                 | $$" << endl;
      cout << "| $$ Press 5 to delete a student from the list        | $$" << endl;
      cout << "| $$ Press 6 to create new student list               | $$" << endl;
      cout << "| $$ Press 7 to delete student list                   | $$" << endl;
      cout << "| $$ Press 8 to print all students data               | $$" << endl;
      cout << "| $$ Press 9 to find information about (a) student(s) | $$" << endl;
      cout << "| $$ Press 10 to sort student list                    | $$" << endl;
      cout << "| $$ Choice:                                          | $$" << endl;
      cout << "| $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
      cout << "|/_______________________________________________________/";

      gotoxy(13, 13);
      cin >> choice;
      cout << "\n\n\n";

      Validate("Choice: ", choice);
      while(choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9 
            && choice != 10 && choice != 11)
      {
         cout << "Wrong input. Enter again" << endl;
         cin >> choice;
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
            students.Add();
            break;
         case 4:
            students.Update();
            break;
         case 5:
            students.DeleteOne();
            break;
         case 6:
            students.Input();
            break;
         case 7:
            students.Delete();
            break;
         case 8:
            students.Print();
            break;
         case 9:
            students.Find();
            break;
         case 10:
            students.Sort();
            break;
         case 11:
            students.ReadTxt();
            break;
      }
      system("cls");
   }
}
