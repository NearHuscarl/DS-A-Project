#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Birthday.h"         
#include "Student.h"

using namespace std;

int StudentList::GetLine(ifstream &ifs)
{
   int count = 0;
   string line;
   while(getline(ifs, line))
   {
      count++;
   }
   //set position to beginning of the file again
   ifs.clear();
   ifs.seekg(0, ios::beg);

   return count;
}

void StudentList::Write()
{
   int total = stdList.size();
   ofstream ofs("DSSV.dat", ios::binary);
   short day, month, year;

   ofs.write((char*)&total, sizeof(total));
   ofs << endl;

   if(ofs.is_open())
   {
      for(int i = 0; i < stdList.size(); i++)
      {

         day   = stdList[i].mBirthday.GetDay();
         month = stdList[i].mBirthday.GetMonth();
         year  = stdList[i].mBirthday.GetYear();

         ofs.write((char*)&stdList[i].mID, sizeof(int));
         ofs << endl;
         ofs.write(stdList[i].mName.c_str(), stdList[i].mName.size());
         ofs << endl;
         ofs.write((char*)&day, sizeof(day));
         ofs << endl;
         ofs.write((char*)&month, sizeof(month));
         ofs << endl;
         ofs.write((char*)&year, sizeof(year));
         ofs << endl;
         ofs.write((char*)&stdList[i].mAvgScore, sizeof(int));
         ofs << endl;
      }
      cout << "File has been written successfully";
      cin.get();
      cin.get();
   }
   ofs.close();
}

void StudentList::Read()
{
   ifstream ifs("DSSV.dat", ios::binary);
   char* name;
   string strName;
   int sizeStr, size = (GetLine(ifs) - 1) / 6;
   short day = 0, month = 0, year = 0;

   stdList.resize(size);

   //Skip first line
   int dummy;
   ifs.read((char*)&dummy, sizeof(dummy));
   ifs.ignore();

   if(ifs.is_open())
   {
      for(int i = 0; i < stdList.size(); i++)
      {
         ifs.read((char*)&stdList[i].mID, sizeof(int));
         ifs.ignore();

         getline(ifs, stdList[i].mName);

         ifs.read((char*)&day, sizeof(day));
         ifs.ignore();
         ifs.read((char*)&month, sizeof(month));
         ifs.ignore();
         ifs.read((char*)&year, sizeof(year));
         ifs.ignore();
         ifs.read((char*)&stdList[i].mAvgScore, sizeof(int));
         ifs.ignore();

         stdList[i].mBirthday.SetDay(day);
         stdList[i].mBirthday.SetMonth(month);
         stdList[i].mBirthday.SetYear(year);
      }
      cout << "File has been read successfully";
      cin.get();
      cin.get();
   }
   ifs.close();
}

void StudentList::Input(void)
{
   int total;
   char keypressed;
   Student student;
   cout << "Warning: All previous data in student list will be erased. Continue? (y/n): ";
   cin >> keypressed;
   if(keypressed == 'y')
   {
      stdList.erase(stdList.begin(), stdList.end());

      cout << "Number of students: ";
      cin >> total;

      for(int i = 0; i < total; i++)
      {
         cout << "_____________________________________________" << endl;
         cout << "ID: ";
         cin >> student.mID;
         cout << "Name: ";
         cin.ignore();
         getline(cin, student.mName);
         cout << "Birthday: ";
         student.mBirthday.Input();
         cout << "Average Score: ";
         cin >> student.mAvgScore;

         stdList.push_back(student);
      }

      cout << "Press Enter to continue";
      cin.get();
      cin.get();
   }
   else
   {
      cout << "Canceled Operation. Press Enter to continue";
      cin.get();
      cin.get();
   }

}

void StudentList::Output(void)
{
   if(stdList.size() < 1)
   {
      cout << "There is not data available" << endl;
   }
   else
   {
      for(int i = 0; i < stdList.size(); i++)
      {
         cout << "_____________________________________________" << endl;
         cout << "ID: " << stdList[i].mID << endl;
         cout << "Name: " << stdList[i].mName << endl;
         cout << "Birthday: " << stdList[i].mBirthday << endl;
         cout << "Average Score: " << stdList[i].mAvgScore << endl;
      }
   }
   cout << "Press Enter to continue";
   cin.get();
   cin.get();
}

void StudentList::Update(void)
{
   Student student;
   cout << "ID: ";
   cin >> student.mID;
   cout << "Name: ";
   getline(cin, student.mName);
   cout << "Birthday: ";
   student.mBirthday.Input();
   cout << "Average Score: ";
   cin >> student.mAvgScore;

   stdList.push_back(student);
   cout << "Updated successfully";
   cin.get();
   cin.get();
   Sort(0);
}

void StudentList::Find(bool type)
{
   switch(type)
   {
      case 0:
         FindID();
         break;
      case 1:
         FindName();
         break;
   }
   cout << "Press Enter to continue";
   cin.get();
}

void StudentList::FindID(void)
{
   int id;
   cout << "Find student with ID: ";
   cin >> id;

   for(int i = 0; i < stdList.size(); i++)
   {
      if(id == stdList[i].mID)
      {
         cout << "---Find result---" << endl;
         cout << "_____________________________________________" << endl;
         cout << "ID: " << stdList[i].mID << endl;
         cout << "Name: " << stdList[i].mName << endl;
         cout << "Birthday: " << stdList[i].mBirthday << endl;
         cout << "Average Score: " << stdList[i].mAvgScore << endl;
         return;
      }
   }
   cout << "There are no students with ID " << id << endl;
}

void StudentList::FindName(void)
{
   string name;
   bool flag = 0;
   cout << "Find student with name: ";
   cin.ignore();
   getline(cin, name);

   for(int i = 0; i < stdList.size(); i++)
   {
      if(name.compare(stdList[i].mName) == 0)
      {
         flag = 1;
         cout << "---File result---" << endl;
         cout << "_____________________________________________" << endl;
         cout << "ID: " << stdList[i].mID << endl;
         cout << "Name: " << stdList[i].mName << endl;
         cout << "Birthday: " << stdList[i].mBirthday << endl;
         cout << "Average Score: " << stdList[i].mAvgScore << endl;
      }
   }

   if(flag == 0)
   {
      cout << "There are no students with the name " << name << endl;
   }
}

void StudentList::Sort(int type)
{
   int left = 0;
   int right = stdList.size()-1;
   switch(type)
   {
      case 1:
         SortID(left, right);
         break;
      case 2:
         SortName(left, right);
         break;
      case 3:
         SortScore(left, right);
         break;
   }
   cout << "Sort done. Enter to continute";
   cin.get();
   cin.get();
}

void StudentList::SortID(int left, int right)
{
   int i, j, x;

   x = stdList[(left + right) / 2].mID;
   i = left;
   j = right;

   while(stdList[i].mID < x) 
      i++;
   while(stdList[j].mID > x)
      j--;
   if(i <= j)
   {
      swap(stdList[i].mID, stdList[j].mID);
      i++;
      j--;
   }
   if (left < j)
      SortID(left, j);
   if (right > i)
      SortID(i, right);
}

void StudentList::SortName(int left, int right)
{
   int i, j;
   string x;

   x = stdList[(left + right) / 2].mName;
   i = left;
   j = right;

   while(stdList[i].mName < x) 
      i++;
   while(stdList[j].mName > x)
      j--;
   if(i <= j)
   {
      swap(stdList[i].mName, stdList[j].mName);
      i++;
      j--;
   }
   if (left < j)
      SortName(left, j);
   if (right > i)
      SortName(i, right);
}

void StudentList::SortScore(int left, int right)
{
   int i, j, x;

   x = stdList[(left + right) / 2].mAvgScore;
   i = left;
   j = right;

   while(stdList[i].mAvgScore < x) 
      i++;
   while(stdList[j].mAvgScore > x)
      j--;
   if(i <= j)
   {
      swap(stdList[i].mAvgScore, stdList[j].mAvgScore);
      i++;
      j--;
   }
   if (left < j)
      SortScore(left, j);
   if (right > i)
      SortScore(i, right);
}
