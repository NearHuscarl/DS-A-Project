#ifndef MENU_H
#define MENU_H

struct Coords
{
   int x;
   int y;
};

#include <string>
#include "StudentList.h"

#define on ,

class Menu 
{
   private:
      int mButton = 0;
      int mOldButton = -1;
      int mKeyPressed = 0;
      int mPageScale = 0;
      int mPageMax = 0;
      bool mInitFlag = false;
      StudentList studentList;

      void GoToXY(int, int);
      int WhereX();
      int WhereY();
      void SetColor(int on int);

      void DisplayTitle();
      void UndisplayTitle();
      void DisplayText(std::string, int, int, int);
      void UndisplayText(std::string, int, int, int);
      void DisplayBotMsg(std::string);
      void UndisplayTextBlock(int, int, int, int, int);
      void ClearText(int, int, int);
      void ClearTextBlock(int, int, int, int);
      void DisplayBorderOne(std::string, std::string, std::string, std::string,
            Coords, Coords, Coords, Coords, int, int);
      void UndisplayBorderOne(Coords, Coords, Coords, Coords, int, int);

      void DisplayMainMenu();
      void UndisplayMainMenu();
      void DisplaySubMenu();
      void UndisplaySubMenu();
      void ShowStudentList(vector<Student>&);
      void PrintStudentListPage();
      void UndisplayStudentList();
      void ClearRightPanel();
      void ClearDynamicHelp();

      void InitForm();
      void InitForm2();
      void InitStudentList();
      void PrintStudentInfo(vector<Student>&, int);
      void PrintStudentInfo(Student);
      void ClearStudentInfo();

      void PrintSubFindList();
      void ClearSubFindList();
      void PrintSubSortList();
      void ClearSubSortList();
      void PrintSubUpdateList();
      void ClearSubUpdateList();

      void HighlightButton(std::string, int, int);
      void UnhighlightButton(std::string, int, int);
      void HighlightStudent(std::string, int, int);
      void UnhighlightStudent(std::string, int, int);

      void LoadButton();
      void SaveButton();
      void HelpButton();
      void CreditButton();
      void ExitButton();

      bool IsValidName(std::string);
      void ValidateOnce(std::string, int&, int, int, int, int, bool ignoreFlag = 0);
      void ValidateID(int&, int, int, int, int);
      void ValidateName(std::string&, int, int, int, int);
      void ValidateScore(double&, int, int, int, int);

      template <typename T>
      void Input(T&, int, int, bool);
      void Input(std::string&, int, int, bool ignoreFlag = true);
      void EnterID(Student&, bool ignoreFlag = true);
      void EnterName(Student&, bool ignoreFlag = true);
      void EnterBirthday(Student&, bool ignoreFlag = true);
      void EnterScore(Student&, bool ignoreFlag = true);

      void NewStudent();
      void NewList();
      void DeleteStudent();
      void DeleteAll();
      void Update(int);
      void Sort(int);
      void Find(int);

      void EnterButton(int&);
      void LeaveButton(int);
      void ActivateButton(int);
      void PageUp(vector<Student>&);
      void PageDown(vector<Student>&);

      void NextStudent(vector<Student>&, int&);
      void LeaveStudent(vector<Student>&, int);

      void KeyRight();
      void KeyLeft();

      void MainMenu();
      void SubMenu();
      void StudentListMenu(vector<Student>&);
   public:
      void CenterWindow();
      void ShowConsoleCursor(bool);
      void Run();
};

#include "Menu.hxx"

#endif //MENU_H 
