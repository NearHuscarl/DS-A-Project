#include <iostream> 
#include <stdlib.h> 
#include <fstream>
#include "Student.h"
#include <string>

using namespace std;

int main()
{
   StudentList x, y; 
   x.Write();

   y.Read();
   y.Find(0);
   y.Find(1);
   y.Print();

   system("pause");
   return 0;
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
