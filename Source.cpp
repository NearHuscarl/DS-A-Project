#include <iostream> 
#include <stdlib.h> 
#include <fstream>
#include "Student.h"
#include <string>

using namespace std;

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
      cout << "Choice: ";
      cin >> choice;
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
         default:
            cout << "Invalid Input";
            cin.get();
            cin.get();
            break;
      }
      system("cls");
   }
}

/* int main() */
/* { */
/*    ofstream os; */
/*    string a, b, c, d; */
/*    int e, f, g, h; */
/*    char* buf; */
/*    cin >> e >> f; */
/*    cin.ignore(); */
/*    getline(cin, a); */
/*    getline(cin, b); */

/*    os.open("input.txt", ios::binary); */
/*    os.write((char*)&e, sizeof(e)); */
/*    os << endl; */
/*    os.write((char*)&f, sizeof(f)); */
/*    os << endl; */
/*    os.write(a.c_str(), a.size()); */
/*    os << endl; */
/*    os.write(b.c_str(), b.size()); */
/*    os << endl; */

/*    os.close(); */

/*    ifstream is("input.txt", ios::binary); */

/*    is.read((char*)&g, sizeof(g)); */
/*    is.ignore(); */
/*    is.read((char*)&h, sizeof(h)); */
/*    is.ignore(); */

/*    buf = new char[a.size()]; */
/*    is.read(buf, a.size()); */
/*    c = ""; */
/*    c.append(buf, a.size()); */
/*    is.ignore(); */

/*    buf = new char[d.size()]; */
/*    is.read(buf, b.size()); */
/*    d = ""; */
/*    d.append(buf, b.size()); */
/*    is.ignore(); */


/*    is.close(); */

/*    cout << g << endl; */
/*    cout << h << endl; */
/*    cout << c << endl; */
/*    cout << d << endl; */
/*    system("pause"); */
/*    return 0; */
/* } */
