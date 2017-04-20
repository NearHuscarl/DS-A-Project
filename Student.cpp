#include <iostream>
#include <string>
#include "Student.h"
#include "Validation.h"

using namespace std;

bool Student::IsValidScore(double score)
{
   if(score < 0 || score > 10)
   {
      return false;
   }
   return true;
}

void Student::Input(void)
{
   cout << "_____________________________________________" << endl;

   cout << "ID: ";
   cin  >> mID;
   Validate("ID: ", mID);

   cout << "Name: ";
   cin.ignore();
   getline(cin, mName);
   Validate("Name: ", mName);

   cout << "Birthday: " << endl;
   mBirthday.Input();

   cout << "Average Score: ";
   cin  >> mAvgScore;
   Validate("Average Score: ", mAvgScore);
}

void Student::Output(void)
{
   cout << "_____________________________________________" << endl;
   cout << "ID: "            << mID                        << endl;
   cout << "Name: "          << mName                      << endl;
   cout << "Birthday: "      << mBirthday                  << endl;
   cout << "Average Score: " << mAvgScore                  << endl;
}
