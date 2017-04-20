#include <conio.h>
#include <iostream> 
#include <algorithm>  //replace
#include <string>
#include <cstdlib> //exit code
#include <windows.h>
#include "Menu.h"
#include "StudentList.h"

using namespace std;

#define KEY_HOME      71
#define KEY_END       79
#define KEY_UP        72
#define KEY_DOWN      80
#define KEY_LEFT      75
#define KEY_RIGHT     77
#define KEY_ENTER     13
#define KEY_BACKSPACE  8
#define KEY_ESC       27
#define KEY_PAGE_UP   73
#define KEY_PAGE_DOWN 81

#define RIGHT_ARROW_SYMBOL       char(16)
#define TOP_HALF_BLOCK_SYMBOL    char(223)
#define BOTTOM_HALF_BLOCK_SYMBOL char(220)
#define THIN_COL_LINE_SYMBOL     char(179)
#define COL_SYMBOL               char(186)
#define ROW_SYMBOL               char(205)
#define TOP_LEFT_SYMBOL          char(201)
#define TOP_RIGHT_SYMBOL         char(187)
#define BOT_RIGHT_SYMBOL         char(188)
#define BOT_LEFT_SYMBOL          char(200)

#define on ,

const Coords TOP_LEFT_DYNAMIC_HELP =  { 75,  4};
const Coords BOT_RIGHT_DYNAMIC_HELP = {112, 10};

const Coords TOP_LEFT_TITLE  = {  8, 1};
const Coords TOP_RIGHT_TITLE = {109, 1};

const Coords TOP_LEFT_SUB_UPDATE  = {33, 21};
const Coords TOP_RIGHT_SUB_UPDATE = {54, 21};
const Coords BOT_LEFT_SUB_UPDATE  = {33, 34};
const Coords BOT_RIGHT_SUB_UPDATE = {54, 34};

const Coords TOP_LEFT_SUB_SORT  = {33, 24};
const Coords TOP_RIGHT_SUB_SORT = {54, 24};
const Coords BOT_LEFT_SUB_SORT  = {33, 34};
const Coords BOT_RIGHT_SUB_SORT = {54, 34};

const Coords TOP_LEFT_SUB_FIND    = {33, 27};
const Coords TOP_RIGHT_SUB_FIND   = {54, 27};
const Coords BOT_LEFT_SUB_FIND    = {33, 34};
const Coords BOT_RIGHT_SUB_FIND   = {54, 34};

const Coords TOP_LEFT_STUDENT_INFO  = { 75,  4};
const Coords BOT_RIGHT_STUDENT_INFO = {111, 34};

const Coords TOP_LEFT_STUDENT_LIST  = { 9,  4};
const Coords BOT_LEFT_STUDENT_LIST  = { 9, 36};
const Coords BOT_RIGHT_STUDENT_LIST = {69, 36};

const Coords DISPLAY_POS        = { 13, 7};
const Coords NEW_STUDENT_POS    = { 13, 10};
const Coords NEW_LIST_POS       = { 13, 13};
const Coords DELETE_STUDENT_POS = { 13, 16};
const Coords DELETE_ALL_POS     = { 13, 19};
const Coords UPDATE_POS         = { 13, 22};
const Coords SORT_POS           = { 13, 25};
const Coords FIND_POS           = { 13, 28};
const Coords MAIN_MENU_POS      = { 13, 31};

const Coords TOP_LEFT_SUB_RIGHT_PANEL  = { 70,  2};
const Coords BOT_LEFT_SUB_RIGHT_PANEL  = { 70, 38};
const Coords BOT_RIGHT_SUB_RIGHT_PANEL = {114, 38};
const Coords TOP_RIGHT_SUB_RIGHT_PANEL = {114,  2};

const Coords TOP_LEFT_SUB_BUTTON_LIST  = {12, 6};
const Coords BOT_LEFT_SUB_BUTTON_LIST  = {12, 34};
const Coords TOP_RIGHT_SUB_BUTTON_LIST = {33, 6};
const Coords BOT_RIGHT_SUB_BUTTON_LIST = {33, 34};

const Coords TOP_LEFT_SUB_MENU   = {  5 ,  2};
const Coords BOT_LEFT_SUB_MENU   = {  5 , 38};
const Coords BOT_RIGHT_SUB_MENU  = {114 , 38};
const Coords TOP_RIGHT_SUB_MENU  = {114 ,  2};

const Coords TOP_LEFT_BUTTON_LIST  = {7 , 16};
const Coords BOT_LEFT_BUTTON_LIST  = {7 , 35};
const Coords TOP_RIGHT_BUTTON_LIST = {28, 16};
const Coords BOT_RIGHT_BUTTON_LIST = {28, 35};

const Coords STD_MAN_POS = {8 , 17};
const Coords LOAD_POS    = {8 , 20};
const Coords SAVE_POS    = {8 , 23};
const Coords HELP_POS    = {8 , 26};
const Coords CREDIT_POS  = {8 , 29};
const Coords EXIT_POS    = {8 , 32};

const Coords TOP_LEFT_MAIN_MENU   = {  2 , 14};
const Coords BOT_LEFT_MAIN_MENU   = {  2 , 38};
const Coords BOT_RIGHT_MAIN_MENU  = {115 , 38};
const Coords TOP_RIGHT_MAIN_MENU  = {115 , 14};

const Coords TOP_LEFT_BUTTON_WIN  = {  8, 18};
const Coords BOT_LEFT_BUTTON_WIN  = {  8, 33};
const Coords TOP_RIGHT_BUTTON_WIN = { 29, 18};
const Coords BOT_RIGHT_BUTTON_WIN = { 29, 33};

const Coords TOP_LEFT_MES_WIN     = { 35, 16};
const Coords BOT_LEFT_MES_WIN     = { 35, 35};
const Coords TOP_RIGHT_MES_WIN    = {109, 16};
const Coords BOT_RIGHT_MES_WIN    = {109, 35};

bool isMainMenuTriggered    = true;
bool isSubMenuTriggered     = false;
bool isStudentListTriggered = false;

bool isLeftBorderAvail    = true;
bool isRightBorderAvail   = false;
bool isHelpContentAvail   = false;
bool isCreditContentAvail = false;
bool isSubMenu            = false;

enum Colors {
   BLACK,          //  0 text color - multiply by 16, for background colors
   DARK_BLUE,      //  1
   DARK_GREEN,     //  2
   DARK_CYAN,      //  3
   DARK_RED,       //  4
   DARK_MAGENTA,   //  5
   DARK_YELLOW,    //  6
   LIGHT_GRAY,     //  7
   DARK_GRAY,      //  8
   LIGHT_BLUE,     //  9
   LIGHT_GREEN,    // 10
   LIGHT_CYAN,     // 11
   LIGHT_RED,      // 12
   LIGHT_MAGENTA,  // 13
   LIGHT_YELLOW,   // 14
   WHITE           // 15
};

enum MainMenuButton {
   STD_MAN = 1,
   LOAD,
   SAVE,
   HELP,
   CREDIT,
   EXIT
};

enum SubMenuButton {
   DISPLAY = 1,
   NEW_STUDENT,
   NEW_LIST,
   DELETE_STUDENT,
   DELETE_ALL,
   UPDATE,
   SORT,
   FIND,
   MAIN_MENU,
   UPDATE_ID = 60,
   UPDATE_NAME = 61,
   UPDATE_BIRTHDAY = 62,
   UPDATE_SCORE = 63,
   SORT_ID = 70,
   SORT_NAME = 71,
   SORT_SCORE = 72,
   FIND_ID = 80,
   FIND_NAME = 81,
};

void Menu::GoToXY(int column, int line)
{
   COORD coord;
   coord.X = column;
   coord.Y = line;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int Menu::WhereX()
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
      return -1;
   return csbi.dwCursorPosition.X;
}

int Menu::WhereY()
{
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
      return -1;
   return csbi.dwCursorPosition.Y;
}

void Menu::CenterWindow(void)
{
   //Finding the user's screen resolution
   int Width = GetSystemMetrics(SM_CXSCREEN);
   int Height = GetSystemMetrics(SM_CYSCREEN);

   //Assigning variables for MoveWindows parameters
   int WindowWidth = 1000; // width of the console window 
   int WindowHeight = 700; // height of the console window
   //Move window to a new position (x, y)
   int XPos = (Width - WindowWidth) / 2;
   int YPos = ((Height - WindowHeight) / 2);

   //Getting the console window handle
   HWND hWnd = GetConsoleWindow();

   //Declaring the function
   BOOL WINAPI MoveWindow(_In_ HWND hWnd, _In_ int NewWidth, _In_ int NewHeight, _In_ int WindowWidth, _In_ int WindowHeight, _In_ BOOL bRepaint);
   //Using function to center the console window
   MoveWindow(hWnd, XPos, YPos, WindowWidth, WindowHeight, TRUE);
}

void Menu::ShowConsoleCursor(bool showFlag)
{
   HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

   CONSOLE_CURSOR_INFO     cursorInfo;

   GetConsoleCursorInfo(out, &cursorInfo);
   cursorInfo.bVisible = showFlag; // set the cursor visibility
   SetConsoleCursorInfo(out, &cursorInfo);
}

//Defaults to light_gray on black
void Menu::SetColor(int fgColor = 7 on int bgColor = 0)
{
   int color = (fgColor + (bgColor * 16));
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
   //0  -> 15 (0-0 -> 0-15): corresponding text color on black foreground
   //16 -> 31 (1-1 -> 1-15): corresponding text color on black_blue foreground 
   //...
}

void Menu::DisplayBorderOne(string topRow, string rightCol, string botRow, string leftCol, 
      Coords topLeft, Coords topRight, Coords botRight, Coords botLeft, int sleepRow, int sleepCol)
{
   for(int i = 0; i < topRow.size(); i++)
   {
      Sleep(sleepRow);
      GoToXY(topLeft.x + 1 + i, topLeft.y);
      cout << topRow[i];
      GoToXY(botRight.x - 1 - i, botRight.y);
      cout << botRow[i];
   }

   for(int i = 0; i < leftCol.size(); i++)
   {
      Sleep(sleepCol);
      GoToXY(topRight.x, topRight.y + i);
      cout << rightCol[i];
      GoToXY(botLeft.x, botLeft.y - i);
      cout << leftCol[i];
   }
}

void Menu::UndisplayBorderOne(Coords topLeft, Coords topRight, Coords botRight, Coords botLeft, int sleepRow, int sleepCol)
{
   int rowSize = topRight.x - topLeft.x + 1;
   int colSize = botRight.y - topRight.y + 1;

   for(int i = 0; i < colSize; i++)
   {
      Sleep(sleepCol);
      GoToXY(topLeft.x, topRight.y + i);
      cout << " ";
      GoToXY(botRight.x, botRight.y - i);
      cout << " ";
   }

   for(int i = 0; i < rowSize; i++)
   {
      Sleep(sleepRow);
      GoToXY(topRight.x - 1 - i, topLeft.y);
      cout << " ";
      GoToXY(botLeft.x + 1 + i, botLeft.y);
      cout << " ";
   }
}

void Menu::DisplayTitle(void)
{
   //                 _____ _             _            _     __  __                                                   _         
   //                / ____| |           | |          | |   |  \/  |                                                 | |      
   //               | (___ | |_ _   _  __| | ___ _ __ | |_  | \  / | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_    
   //                \___ \| __| | | |/ _` |/ _ \ '_ \| __| | |\/| |/ _` | '_ \ / _` |/ _` |/ _ \ '_ ` _ \ / _ \ '_ \| __|
   //                ____) | |_| |_| | (_| |  __/ | | | |_  | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_       
   //               |_____/ \__|\__,_|\__,_|\___|_| |_|\__| |_|  |_|\__,_|_| |_|\__,_|\__, |\___|_| |_| |_|\___|_| |_|\__|
   //                                          _____           _                 __/ |                                    
   //                                         / ____|         | |               |___/    
   //                                        | (___  _   _ ___| |_ ___ _ __ ___  
   //                                         \___ \| | | / __| __/ _ \ '_ ` _ \ 
   //                                         ____) | |_| \__ \ ||  __/ | | | | |
   //                                        |_____/ \__, |___/\__\___|_| |_| |_|
   //                                                 __/ |                      
   //                                                |___/                       

   int size = 110;
   int height = 14;
   char title[14][111] = {
      "          _____ _             _            _     __  __                                                   _   " ,
      "         / ____| |           | |          | |   |  \\/  |                                                 | |  " ,
      "        | (___ | |_ _   _  __| | ___ _ __ | |_  | \\  / | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_ " ,
      "         \\___ \\| __| | | |/ _` |/ _ \\ '_ \\| __| | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|" ,
      "         ____) | |_| |_| | (_| |  __/ | | | |_  | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_ " ,
      "        |_____/ \\__|\\__,_|\\__,_|\\___|_| |_|\\__| |_|  |_|\\__,_|_| |_|\\__, |\\__,_|\\___|_| |_| |_|\\___|_| |_|\\__|" ,
      "                                   _____           _                       __/ |                              " ,
      "                                  / ____|         | |                     |___/                               " ,
      "                                 | (___  _   _ ___| |_ ___ _ __ ___                                           " ,
      "                                  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\                                          " ,
      "                                  ____) | |_| \\__ \\ ||  __/ | | | | |                                         " ,
      "                                 |_____/ \\__, |___/\\__\\___|_| |_| |_|                                         " ,
      "                                          __/ |                                                               " ,
      "                                         |___/                                                                " 
   };

   for(int i = 0, j = size - 1;; i++, j--)
   {
      Sleep(2);
      if(i == size / 2)
      {
         for(int k = 0; k < height; k++)
         {
            GoToXY(i, k);
            cout << title[k][i];
         }
         return;
      }
      for(int k = 0; k < height; k++)
      {
         GoToXY(i, k);
         cout << title[k][i];
         GoToXY(TOP_RIGHT_TITLE.x - i, k);
         cout << title[k][j];
      }
   }
}

void Menu::UndisplayTitle()
{
   int size = 110;
   int mid  = size / 2;
   int height = 14;
   char title[14][111] = {
      "          _____ _             _            _     __  __                                                   _   " ,
      "         / ____| |           | |          | |   |  \\/  |                                                 | |  " ,
      "        | (___ | |_ _   _  __| | ___ _ __ | |_  | \\  / | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_ " ,
      "         \\___ \\| __| | | |/ _` |/ _ \\ '_ \\| __| | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|" ,
      "         ____) | |_| |_| | (_| |  __/ | | | |_  | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_ " ,
      "        |_____/ \\__|\\__,_|\\__,_|\\___|_| |_|\\__| |_|  |_|\\__,_|_| |_|\\__, |\\__,_|\\___|_| |_| |_|\\___|_| |_|\\__|" ,
      "                                   _____           _                       __/ |                              " ,
      "                                  / ____|         | |                     |___/                               " ,
      "                                 | (___  _   _ ___| |_ ___ _ __ ___                                           " ,
      "                                  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\                                          " ,
      "                                  ____) | |_| \\__ \\ ||  __/ | | | | |                                         " ,
      "                                 |_____/ \\__, |___/\\__\\___|_| |_| |_|                                         " ,
      "                                          __/ |                                                               " ,
      "                                         |___/                                                                " 
   };

   for(int k = 0; k < height; k++)
   {
      GoToXY(mid, k);
      cout << " ";
   }

   for(int i = mid - 1, j = mid + 1; i >= 0; i--, j++)
   {
      Sleep(2);
      for(int k = 0; k < height; k++)
      {
         GoToXY(i, k);
         cout << " ";
         GoToXY(j, k);
         cout << " ";
      }
   }
}

void Menu::DisplayText(string text, int x, int y, int sleep)
{
   for(int i = 0; i < text.size(); i++)
   {
      Sleep(sleep);
      GoToXY(x++, y);
      cout << text[i];
   }
}

void Menu::UndisplayText(string text, int x, int y, int sleep)
{
   for(int i = 0; i < text.size(); i++)
   {
      Sleep(sleep);
      GoToXY(x++, y);
      cout << " ";
   }
}

void Menu::DisplayBotMsg(string msg)
{
   ClearText(0, 39, 100);
   int mainMenuWidth = BOT_RIGHT_MAIN_MENU.x - BOT_LEFT_MAIN_MENU.x;
   Coords botMsgPos;
   botMsgPos.x = BOT_LEFT_MAIN_MENU.x + (mainMenuWidth - msg.size()) / 2;
   botMsgPos.y = BOT_LEFT_MAIN_MENU.y;

   DisplayText(msg, botMsgPos.x, botMsgPos.y + 1, 4);
}

void Menu::UndisplayTextBlock(int x1, int y1, int x2, int y2, int sleep)
{
   string text(x2 - x1 - 1, ' ');
   for(int i = 0; y1 + 1 + i != y2; i++)
   {
      Sleep(sleep);
      GoToXY(x1 + 1, y1 + 1 + i);
      cout << text;
   }
}

void Menu::ClearText(int x, int y, int size)
{
   GoToXY(x, y);
   string text(size, ' ');
   cout << text;
}

void Menu::ClearTextBlock(int x1, int y1, int x2, int y2)
{
   string text(x2 - x1 - 1, ' ');
   for(int i = 0; y1 + 1 + i != y2; i++)
   {
      GoToXY(x1 + 1, y1 + 1 + i);
      cout << text;
   }
}

void Menu::DisplayMainMenu(void)
{
   SetColor(LIGHT_GREEN on BLACK);
   DisplayTitle();

   string leftCol(25, COL_SYMBOL);
   string rightCol(25, COL_SYMBOL);
   string topRow(112, ROW_SYMBOL);
   string botRow(112, ROW_SYMBOL);

   leftCol[0]   = BOT_LEFT_SYMBOL;
   leftCol[24]  = TOP_LEFT_SYMBOL;
   rightCol[0]  = TOP_RIGHT_SYMBOL;
   rightCol[24] = BOT_RIGHT_SYMBOL;

   int line = 0;
   Coords buttonListPos = {TOP_LEFT_BUTTON_LIST.x, TOP_LEFT_BUTTON_LIST.y};
   char buttonList[20][23] = {
      ".____________________.",
      "|                    |",
      "| Student Management |",
      "|                    |",
      "|                    |",
      "|        Load        |",
      "|                    |",
      "|                    |",
      "|        Save        |",
      "|                    |",
      "|                    |",
      "|        Help        |",
      "|                    |",
      "|                    |",
      "|       Credit       |",
      "|                    |",
      "|                    |",
      "|        Exit        |",
      "|                    |",
      "|____________________|", };

   fill(buttonList[0],  buttonList[0]  + 22, ROW_SYMBOL);
   fill(buttonList[19], buttonList[19] + 22, ROW_SYMBOL);

   for(int i = 0; i < 20; i++)
   {
      buttonList[i][0]  = COL_SYMBOL;
      buttonList[i][21] = COL_SYMBOL;
   }

   buttonList[0][0]   = TOP_LEFT_SYMBOL;
   buttonList[0][21]  = TOP_RIGHT_SYMBOL;
   buttonList[19][0]  = BOT_LEFT_SYMBOL;
   buttonList[19][21] = BOT_RIGHT_SYMBOL;

   for(int i = 0; i < 112; i++)
   {
      Sleep(3);
      GoToXY(TOP_LEFT_MAIN_MENU.x + 1 + i, TOP_LEFT_MAIN_MENU.y);
      cout << topRow[i];
      GoToXY(BOT_RIGHT_MAIN_MENU.x - 1 - i, BOT_RIGHT_MAIN_MENU.y);
      cout << botRow[i];
   }

   for(int i = 0; i < 25; i++)
   {
      Sleep(4);
      GoToXY(TOP_RIGHT_MAIN_MENU.x, TOP_RIGHT_MAIN_MENU.y + i);
      cout << rightCol[i];
      GoToXY(BOT_LEFT_MAIN_MENU.x, BOT_LEFT_MAIN_MENU.y - i);
      cout << leftCol[i];

      if(TOP_RIGHT_MAIN_MENU.y + i >= TOP_LEFT_BUTTON_LIST.y && TOP_RIGHT_MAIN_MENU.y + i <= BOT_LEFT_BUTTON_LIST.y)
      {
         GoToXY(buttonListPos.x, buttonListPos.y++);
         cout << buttonList[line++];
      }
   }
}

void Menu::UndisplayMainMenu(void)
{
   if(isRightBorderAvail)
   {
      UndisplayBorderOne(
            TOP_LEFT_MES_WIN,
            TOP_RIGHT_MES_WIN,
            BOT_RIGHT_MES_WIN,
            BOT_LEFT_MES_WIN, 1, 1);
   }
   UndisplayBorderOne(
         TOP_LEFT_BUTTON_LIST,
         TOP_RIGHT_BUTTON_LIST,
         BOT_RIGHT_BUTTON_LIST,
         BOT_LEFT_BUTTON_LIST, 1, 1);
   UndisplayTextBlock(
         TOP_LEFT_MAIN_MENU.x,
         TOP_LEFT_MAIN_MENU.y,
         BOT_RIGHT_MAIN_MENU.x,
         BOT_RIGHT_MAIN_MENU.y, 1);
   UndisplayBorderOne(
         TOP_LEFT_MAIN_MENU,
         TOP_RIGHT_MAIN_MENU,
         BOT_RIGHT_MAIN_MENU,
         BOT_LEFT_MAIN_MENU, 1, 1);
}

void Menu::UndisplaySubMenu(void)
{
   UndisplayBorderOne(
         TOP_LEFT_SUB_BUTTON_LIST,
         TOP_RIGHT_SUB_BUTTON_LIST,
         BOT_RIGHT_SUB_BUTTON_LIST,
         BOT_LEFT_SUB_BUTTON_LIST, 1, 1);
   UndisplayTextBlock(
         TOP_LEFT_SUB_BUTTON_LIST.x,
         TOP_LEFT_SUB_BUTTON_LIST.y,
         BOT_RIGHT_SUB_BUTTON_LIST.x,
         BOT_RIGHT_SUB_BUTTON_LIST.y, 1);
   UndisplayTextBlock(
         TOP_LEFT_STUDENT_INFO.x - 1,
         TOP_LEFT_STUDENT_INFO.y - 1,
         BOT_RIGHT_STUDENT_INFO.x + 1,
         BOT_RIGHT_STUDENT_INFO.y + 1, 1);
   UndisplayBorderOne(
         TOP_LEFT_SUB_MENU,
         TOP_RIGHT_SUB_MENU,
         BOT_RIGHT_SUB_MENU,
         BOT_LEFT_SUB_MENU, 1, 1);
   UndisplayBorderOne(
         TOP_LEFT_SUB_RIGHT_PANEL,
         TOP_RIGHT_SUB_RIGHT_PANEL,
         BOT_RIGHT_SUB_RIGHT_PANEL,
         BOT_LEFT_SUB_RIGHT_PANEL, 1, 1);
}

void Menu::DisplaySubMenu(void)
{
   string leftCol(37, COL_SYMBOL);
   string rightCol(37, COL_SYMBOL);
   string topRow(108, ROW_SYMBOL);
   string botRow(108, ROW_SYMBOL);

   leftCol[0]   = BOT_LEFT_SYMBOL;
   leftCol[36]  = TOP_LEFT_SYMBOL;
   rightCol[0]  = TOP_RIGHT_SYMBOL;
   rightCol[36] = BOT_RIGHT_SYMBOL;

   int line = 0;
   Coords buttonListPos = {
      TOP_LEFT_SUB_BUTTON_LIST.x,
      TOP_LEFT_SUB_BUTTON_LIST.y};

   char buttonList[29][23] = {
      ".____________________.",
      "|                    |",
      "|      Display       |",
      "|                    |",
      "|                    |",
      "|     New Student    |",
      "|                    |",
      "|                    |",
      "|      New List      |",
      "|                    |",
      "|                    |",
      "|   Delete Student   |",
      "|                    |",
      "|                    |",
      "|     Delete All     |",
      "|                    |",
      "|                    |",
      "|       Update     > |",
      "|                    |",
      "|                    |",
      "|        Sort      > |",
      "|                    |",
      "|                    |",
      "|        Find      > |",
      "|                    |",
      "|                    |",
      "|     Main Menu      |",
      "|                    |",
      "|____________________|", };

   fill(buttonList[0],  buttonList[0]  + 22, ROW_SYMBOL);
   fill(buttonList[28], buttonList[28] + 22, ROW_SYMBOL);

   for(int i = 0; i < 29; i++)
   {
      buttonList[i][0]  = COL_SYMBOL;
      buttonList[i][21] = COL_SYMBOL;
   }

   buttonList[0][0]   = TOP_LEFT_SYMBOL;
   buttonList[0][21]  = TOP_RIGHT_SYMBOL;
   buttonList[28][0]  = BOT_LEFT_SYMBOL;
   buttonList[28][21] = BOT_RIGHT_SYMBOL;

   for(int i = 0; i < 108; i++)
   {
      Sleep(3);
      GoToXY(TOP_LEFT_SUB_MENU.x  + 1 + i, TOP_LEFT_SUB_MENU.y);
      cout << topRow[i];
      GoToXY(BOT_RIGHT_SUB_MENU.x - 1 - i, BOT_RIGHT_SUB_MENU.y);
      cout << botRow[i];
   }

   for(int i = 0; i < 38; i++)
   {
      Sleep(4);
      GoToXY(TOP_RIGHT_SUB_MENU.x, TOP_RIGHT_SUB_MENU.y + i);
      cout << rightCol[i];
      GoToXY(BOT_LEFT_SUB_MENU.x, BOT_LEFT_SUB_MENU.y - i);
      cout << leftCol[i];

      //Right panel
      if(BOT_LEFT_SUB_MENU.y - i >= TOP_LEFT_SUB_RIGHT_PANEL.y + 1 && BOT_LEFT_SUB_MENU.y - i <= BOT_LEFT_SUB_RIGHT_PANEL.y - 1)
      {
         GoToXY(TOP_LEFT_SUB_RIGHT_PANEL.x, BOT_LEFT_SUB_MENU.y - i);
         cout << COL_SYMBOL;
      }

      //Button List
      if(TOP_RIGHT_SUB_MENU.y + i >= TOP_LEFT_SUB_BUTTON_LIST.y && TOP_RIGHT_SUB_MENU.y + i <= BOT_LEFT_SUB_BUTTON_LIST.y)
      {
         GoToXY(buttonListPos.x, buttonListPos.y++);
         cout << buttonList[line++];
      }
   }
   GoToXY(TOP_LEFT_SUB_RIGHT_PANEL.x, TOP_LEFT_SUB_RIGHT_PANEL.y);
   cout << char(203);
   GoToXY(BOT_LEFT_SUB_RIGHT_PANEL.x, BOT_LEFT_SUB_RIGHT_PANEL.y);
   cout << char(202);
}

void Menu::PrintSubFindList()
{
   string subFindButtonList[8] = {
      ".____________________.",
      "|                    |",
      "|       Find ID      |",
      "|                    |",
      "|                    |",
      "|      Find Name     |",
      "|                    |",
      "|____________________|", };

   replace(subFindButtonList[0].begin(), subFindButtonList[0].end(), '_', ROW_SYMBOL);
   replace(subFindButtonList[7].begin(), subFindButtonList[7].end(), '_', ROW_SYMBOL);

   for(int i = 1; i < 7; i++)
   {
      subFindButtonList[i][0]  = COL_SYMBOL;
      subFindButtonList[i][21] = COL_SYMBOL;
   }

   subFindButtonList[0][0]  = char(204);
   subFindButtonList[0][21] = TOP_RIGHT_SYMBOL;
   subFindButtonList[7][0]  = char(202);
   subFindButtonList[7][21] = BOT_RIGHT_SYMBOL;

   GoToXY(TOP_LEFT_SUB_FIND.x, TOP_LEFT_SUB_FIND.y);
   for(int i = 0; TOP_LEFT_SUB_FIND.y + i <= BOT_LEFT_SUB_FIND.y; i++)
   {
      GoToXY(TOP_LEFT_SUB_FIND.x, TOP_LEFT_SUB_FIND.y + i);
      cout << subFindButtonList[i];
   }
}

void Menu::ClearSubFindList()
{
   ClearTextBlock(
         TOP_LEFT_SUB_FIND.x,
         TOP_LEFT_SUB_FIND.y - 1,
         BOT_RIGHT_SUB_FIND.x + 1,
         BOT_RIGHT_SUB_FIND.y + 1);
   GoToXY(
         BOT_LEFT_SUB_FIND.x,
         BOT_LEFT_SUB_FIND.y);
   cout << BOT_RIGHT_SYMBOL;
   GoToXY(
         TOP_LEFT_SUB_FIND.x,
         TOP_LEFT_SUB_FIND.y);
   cout << COL_SYMBOL;
}

void Menu::PrintSubSortList(void)
{
   string subSortButtonList[11] = {
      ".____________________.",
      "|                    |",
      "|       Sort ID      |",
      "|                    |",
      "|                    |",
      "|      Sort Name     |",
      "|                    |",
      "|                    |",
      "|     Sort Score     |",
      "|                    |",
      "|____________________|", };

   replace(subSortButtonList[0].begin(), subSortButtonList[0].end(), '_', ROW_SYMBOL);
   replace(subSortButtonList[10].begin(), subSortButtonList[10].end(), '_', ROW_SYMBOL);

   for(int i = 1; i < 10; i++)
   {
      subSortButtonList[i][0]  = COL_SYMBOL;
      subSortButtonList[i][21] = COL_SYMBOL;
   }

   subSortButtonList[0][0]  = char(204);
   subSortButtonList[0][21] = TOP_RIGHT_SYMBOL;
   subSortButtonList[10][0]  = char(202);
   subSortButtonList[10][21] = BOT_RIGHT_SYMBOL;

   GoToXY(TOP_LEFT_SUB_SORT.x, TOP_LEFT_SUB_SORT.y);
   for(int i = 0; TOP_LEFT_SUB_SORT.y + i <= BOT_LEFT_SUB_SORT.y; i++)
   {
      GoToXY(TOP_LEFT_SUB_SORT.x, TOP_LEFT_SUB_SORT.y + i);
      cout << subSortButtonList[i];
   }
}

void Menu::ClearSubSortList()
{
   ClearTextBlock(
         TOP_LEFT_SUB_SORT.x,
         TOP_LEFT_SUB_SORT.y - 1,
         BOT_RIGHT_SUB_SORT.x + 1,
         BOT_RIGHT_SUB_SORT.y + 1);
   GoToXY(
         TOP_LEFT_SUB_SORT.x,
         TOP_LEFT_SUB_SORT.y);
   cout << COL_SYMBOL;
   GoToXY(
         BOT_LEFT_SUB_SORT.x,
         BOT_LEFT_SUB_SORT.y);
   cout << BOT_RIGHT_SYMBOL;
}

void Menu::PrintSubUpdateList(void)
{
   string subUpdateButtonList[14] = {
      ".____________________.",
      "|                    |",
      "|      Update ID     |",
      "|                    |",
      "|                    |",
      "|     Update Name    |",
      "|                    |",
      "|                    |",
      "|   Update Birthday  |",
      "|                    |",
      "|                    |",
      "|     Update Score   |",
      "|                    |",
      "|____________________|", };

   replace(subUpdateButtonList[0].begin(), subUpdateButtonList[0].end(), '_', ROW_SYMBOL);
   replace(subUpdateButtonList[13].begin(), subUpdateButtonList[13].end(), '_', ROW_SYMBOL);

   for(int i = 1; i < 13; i++)
   {
      subUpdateButtonList[i][0]  = COL_SYMBOL;
      subUpdateButtonList[i][21] = COL_SYMBOL;
   }

   subUpdateButtonList[0][0]  = char(204);
   subUpdateButtonList[0][21] = TOP_RIGHT_SYMBOL;
   subUpdateButtonList[13][0]  = char(202);
   subUpdateButtonList[13][21] = BOT_RIGHT_SYMBOL;

   GoToXY(TOP_LEFT_SUB_UPDATE.x, TOP_LEFT_SUB_UPDATE.y);
   for(int i = 0; TOP_LEFT_SUB_UPDATE.y + i <= BOT_LEFT_SUB_UPDATE.y; i++)
   {
      GoToXY(TOP_LEFT_SUB_UPDATE.x, TOP_LEFT_SUB_UPDATE.y + i);
      cout << subUpdateButtonList[i];
   }
}

void Menu::ClearSubUpdateList()
{
   ClearTextBlock(
         TOP_LEFT_SUB_UPDATE.x,
         TOP_LEFT_SUB_UPDATE.y - 1,
         BOT_RIGHT_SUB_UPDATE.x + 1,
         BOT_RIGHT_SUB_UPDATE.y + 1);
   GoToXY(
         TOP_LEFT_SUB_UPDATE.x,
         TOP_LEFT_SUB_UPDATE.y);
   cout << COL_SYMBOL;
   GoToXY(
         BOT_LEFT_SUB_UPDATE.x,
         BOT_LEFT_SUB_UPDATE.y);
   cout << BOT_RIGHT_SYMBOL;
}

void Menu::HighlightButton(string str, int x, int y)
{
   SetColor(BLACK on LIGHT_GREEN);
   GoToXY(x, y);
   cout << "                    ";
   GoToXY(x, y+1);
   cout << str;
   GoToXY(x, y+2);
   cout << "                    ";
   SetColor(LIGHT_GREEN on BLACK);
}

void Menu::UnhighlightButton(string str, int x, int y)
{
   SetColor(LIGHT_GREEN on BLACK);
   GoToXY(x, y);
   cout << "                    ";
   GoToXY(x, y+1);
   cout << str;
   GoToXY(x, y+2);
   cout << "                    ";
   SetColor(BLACK on LIGHT_GREEN);
}

void Menu::HighlightStudent(string str, int x, int y)
{
   str.resize(26, ' ');
   SetColor(BLACK on LIGHT_GREEN);
   GoToXY(x, y);
   cout << " " << str;
   SetColor(LIGHT_GREEN on BLACK);
}

void Menu::UnhighlightStudent(string str, int x, int y)
{
   str.resize(26, ' ');
   SetColor(LIGHT_GREEN on BLACK);
   GoToXY(x, y);
   cout << " " << str;
   SetColor(BLACK on LIGHT_GREEN);
}

void Menu::NextStudent(vector<Student> &students, int &index)
{
   int nameMaxLength = 27;
   int studentListHeight = BOT_LEFT_STUDENT_LIST.y - TOP_LEFT_STUDENT_LIST.y + 1;
   int complement = mPageScale * 66;
   int size = students.size();

   if(index == size || index - complement == studentListHeight*2)
   {
      HighlightStudent(
            students[complement].mName,
            TOP_LEFT_STUDENT_LIST.x,
            TOP_LEFT_STUDENT_LIST.y);
      ClearStudentInfo();
      PrintStudentInfo(students, complement);
      index = complement;
      return;
   }

   if(index == complement - 1)
   {
      if(complement + studentListHeight*2 - 1 >= size)
      {
         if(size-1 - complement < studentListHeight)
         {
            HighlightStudent(
                  students[size - 1].mName,
                  TOP_LEFT_STUDENT_LIST.x,
                  TOP_LEFT_STUDENT_LIST.y + size-1 - complement);
            ClearStudentInfo();
            PrintStudentInfo(students, size - 1);
            index = size - 1;
            return;
         }
         else if(size-1 - complement >= studentListHeight)
         {
            HighlightStudent(
                  students[size - 1].mName,
                  TOP_LEFT_STUDENT_LIST.x + nameMaxLength + 5,
                  TOP_LEFT_STUDENT_LIST.y + size-1 - complement - studentListHeight);
            ClearStudentInfo();
            PrintStudentInfo(students, size - 1);
            index = size - 1;
            return;
         }
      }
      else
      {
         HighlightStudent(
               students[complement + studentListHeight*2 - 1].mName,
               TOP_LEFT_STUDENT_LIST.x + nameMaxLength + 5,
               BOT_LEFT_STUDENT_LIST.y);
         ClearStudentInfo();
         PrintStudentInfo(students, complement + studentListHeight*2 - 1);
         index = complement + studentListHeight*2 - 1;
         return;
      }
   }

   for(int i = complement; i - complement < studentListHeight*2; i++)
   {
      if(i == index)
      {
         if(index - complement < studentListHeight)
         {
            HighlightStudent(
                  students[index].mName,
                  TOP_LEFT_STUDENT_LIST.x,
                  TOP_LEFT_STUDENT_LIST.y + index - complement);
            ClearStudentInfo();
            PrintStudentInfo(students, index);
            return;
         }
         else if(index - complement >= studentListHeight)
         {
            HighlightStudent(
                  students[index].mName,
                  TOP_LEFT_STUDENT_LIST.x + nameMaxLength + 5,
                  TOP_LEFT_STUDENT_LIST.y + index - complement - studentListHeight);
            ClearStudentInfo();
            PrintStudentInfo(students, index);
            return;
         }
      }
   }
}

void Menu::LeaveStudent(vector<Student> &students, int index)
{
   int nameMaxLength = 27;
   int studentListHeight = BOT_LEFT_STUDENT_LIST.y - TOP_LEFT_STUDENT_LIST.y + 1;
   int complement = mPageScale * 66;
   int size = students.size();

   if(index == size || index - complement == studentListHeight*2)
   {
      UnhighlightStudent(
            students[complement].mName,
            TOP_LEFT_STUDENT_LIST.x,
            TOP_LEFT_STUDENT_LIST.y);
      return;
   }
   if(index == complement - 1)
   {
      if(complement + studentListHeight*2 - 1 >= size)
      {
         if(size-1 - complement < studentListHeight)
         {
            UnhighlightStudent(
                  students[size - 1].mName,
                  TOP_LEFT_STUDENT_LIST.x,
                  TOP_LEFT_STUDENT_LIST.y + size-1 - complement);
            return;
         }
         else if(size-1 - complement >= studentListHeight)
         {
            UnhighlightStudent(
                  students[size - 1].mName,
                  TOP_LEFT_STUDENT_LIST.x + nameMaxLength + 5,
                  TOP_LEFT_STUDENT_LIST.y + size-1 - complement - studentListHeight);
            return;
         }
      }
      else
      {
         UnhighlightStudent(
               students[complement + studentListHeight*2 - 1].mName,
               TOP_LEFT_STUDENT_LIST.x + nameMaxLength + 5,
               BOT_LEFT_STUDENT_LIST.y);
         return;
      }
   }

   for(int i = complement; i - complement < studentListHeight*2; i++)
   {
      if(i == index)
      {
         if(index - complement < studentListHeight)
         {
            UnhighlightStudent(
                  students[index].mName,
                  TOP_LEFT_STUDENT_LIST.x,
                  TOP_LEFT_STUDENT_LIST.y + index - complement);
            return;
         }
         else if(index - complement >= studentListHeight)
         {
            UnhighlightStudent(
                  students[index].mName,
                  TOP_LEFT_STUDENT_LIST.x + nameMaxLength + 5,
                  TOP_LEFT_STUDENT_LIST.y + index - complement - studentListHeight);
            return;
         }
      }
   }
}

void Menu::EnterButton(int &button)
{
   if(isMainMenuTriggered)
   {
      switch(button)
      {
         case 0:
            HighlightButton("        Exit        ", EXIT_POS.x, EXIT_POS.y);
            button = EXIT;
            break;
         case STD_MAN:
            HighlightButton(" Student Management ", STD_MAN_POS.x, STD_MAN_POS.y);
            break;
         case LOAD:
            HighlightButton("        Load        ", LOAD_POS.x, LOAD_POS.y);
            break;
         case SAVE:
            HighlightButton("        Save        ", SAVE_POS.x, SAVE_POS.y);
            break;
         case HELP:
            HighlightButton("        Help        ", HELP_POS.x, HELP_POS.y);
            break;
         case CREDIT:
            HighlightButton("       Credit       ", CREDIT_POS.x, CREDIT_POS.y);
            break;
         case EXIT:
            HighlightButton("        Exit        ", EXIT_POS.x, EXIT_POS.y);
            break;
         case 7:
            HighlightButton(" Student Management ", STD_MAN_POS.x, STD_MAN_POS.y);
            button = 1;
            break;
         default:
            break;
      }
   }
   else if(isSubMenuTriggered)
   {
      switch(button)
      {
         case 0:
            HighlightButton("     Main Menu      ", MAIN_MENU_POS.x, MAIN_MENU_POS.y);
            button = MAIN_MENU;

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Go back to main menu";
            //Go back to main menu
            break;
         case DISPLAY:
            HighlightButton("      Display       ", DISPLAY_POS.x, DISPLAY_POS.y);

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Display a list of students";
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+1);
            cout << "with info about ID, name, birthday ";
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+2);
            cout << "and average score";
            //Display a list of students with info about ID, name, birthday
            //and average score
            break;
         case NEW_STUDENT:
            HighlightButton("     New Student    ", NEW_STUDENT_POS.x, NEW_STUDENT_POS.y);

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Add a new student info to the";
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+1);
            cout << "existing list";
            //Add a new student info to the existing list
            break;
         case NEW_LIST:
            HighlightButton("      New List      ", NEW_LIST_POS.x, NEW_LIST_POS.y);

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Create a new student list by";
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+1);
            cout << "specifying number of students in the";
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+2);
            cout << "list then enter each student info";
            //Create a new student list by specifying number of students
            //in the list then enter each student info
            break;
         case DELETE_STUDENT:
            HighlightButton("   Delete Student   ", DELETE_STUDENT_POS.x, DELETE_STUDENT_POS.y);

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Delete one student with the";
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+1);
            cout << "input ID";
            //Delete one student with the input ID
            break;
         case DELETE_ALL:
            HighlightButton("     Delete All     ", DELETE_ALL_POS.x, DELETE_ALL_POS.y);

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Delete all students info in the list";
            //Delete all students info in the list
            break;
         case UPDATE:
            HighlightButton("       Update     > ", UPDATE_POS.x, UPDATE_POS.y);

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Update a student info by specifying";
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+1);
            cout << "that student's ID.";
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+2);
            cout << "Info can be either ID, name, birthday";
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+3);
            cout << "or average score";
            //Update a student info by specifying that student's ID
            //Info can be either ID, name, birthday or average score
            break;
         case SORT:
            HighlightButton("        Sort      > ", SORT_POS.x, SORT_POS.y);

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Sort student list by either ID, name";
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+1);
            cout << "or average score";
            //Sort student list by either ID, name or average score
            break;
         case FIND:
            HighlightButton("        Find      > ", FIND_POS.x, FIND_POS.y);

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Find student(s) info based on their";
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+1);
            cout << "ID or name";
            //Find student(s) info based on their ID or name
            break;
         case MAIN_MENU:
            HighlightButton("     Main Menu      ", MAIN_MENU_POS.x, MAIN_MENU_POS.y);

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Go back to main menu";
            //Go back to main menu
            break;

         case 59:
            HighlightButton("     Update Score   ", TOP_LEFT_SUB_UPDATE.x + 1, TOP_LEFT_SUB_UPDATE.y + 10);
            button = 63;

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Update student's average score";
            //Update student's average score
            break;
         case UPDATE_ID:
            HighlightButton("      Update ID     ", TOP_LEFT_SUB_UPDATE.x + 1, TOP_LEFT_SUB_UPDATE.y + 1);

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Update student's ID";
            //Update student's average ID
            break;
         case UPDATE_NAME:
            HighlightButton("     Update Name    ", TOP_LEFT_SUB_UPDATE.x + 1, TOP_LEFT_SUB_UPDATE.y + 4);

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Update student's name";
            //Update student's average name
            break;
         case UPDATE_BIRTHDAY:
            HighlightButton("   Update Birthday  ", TOP_LEFT_SUB_UPDATE.x + 1, TOP_LEFT_SUB_UPDATE.y + 7);

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Update student's birthday";
            //Update student's average birthday
            break;
         case UPDATE_SCORE:
            HighlightButton("     Update Score   ", TOP_LEFT_SUB_UPDATE.x + 1, TOP_LEFT_SUB_UPDATE.y + 10);

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Update student's average score";
            //Update student's average score
            break;
         case 64:
            HighlightButton("      Update ID     ", TOP_LEFT_SUB_UPDATE.x + 1, TOP_LEFT_SUB_UPDATE.y + 1);
            button = 60;

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Update student's ID";
            //Update student's average ID
            break;

         case 69:
            HighlightButton("     Sort Score     ", TOP_LEFT_SUB_SORT.x + 1, TOP_LEFT_SUB_SORT.y + 7);
            button = 72;

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Sort student list by average score";
            //Sort student list by average score
            break;
         case SORT_ID:
            HighlightButton("      Sort ID       ", TOP_LEFT_SUB_SORT.x + 1, TOP_LEFT_SUB_SORT.y + 1);

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Sort student list by ID";
            //Sort student list by ID
            break;
         case SORT_NAME:
            HighlightButton("      Sort Name     ", TOP_LEFT_SUB_SORT.x + 1, TOP_LEFT_SUB_SORT.y + 4);

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Sort student list by name";
            //Sort student list by name
            break;
         case SORT_SCORE:
            HighlightButton("     Sort Score     ", TOP_LEFT_SUB_SORT.x + 1, TOP_LEFT_SUB_SORT.y + 7);

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Sort student list by average score";
            //Sort student list by average score
            break;
         case 73:
            HighlightButton("      Sort ID       ", TOP_LEFT_SUB_SORT.x + 1, TOP_LEFT_SUB_SORT.y + 1);
            button = 70;

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Sort student list by ID";
            //Sort student list by ID
            break;

         case 79:
            HighlightButton("      Find Name     ", TOP_LEFT_SUB_FIND.x + 1, TOP_LEFT_SUB_FIND.y + 4);
            button = 81;

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Find student(s) info by specifying";
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+1);
            cout << "a name";
            //Find student(s) info by specifying a name
            break;
         case FIND_ID:
            HighlightButton("      Find ID       ", TOP_LEFT_SUB_FIND.x + 1, TOP_LEFT_SUB_FIND.y + 1);

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Find student(s) info by specifying";
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+1);
            cout << "a ID";
            //Find student(s) info by specifying a ID
            break;
         case FIND_NAME:
            HighlightButton("      Find Name     ", TOP_LEFT_SUB_FIND.x + 1, TOP_LEFT_SUB_FIND.y + 4);

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Find student(s) info by specifying";
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+1);
            cout << "a name";
            //Find student(s) info by specifying a name
            break;
         case 82:
            HighlightButton("      Find ID       ", TOP_LEFT_SUB_FIND.x + 1, TOP_LEFT_SUB_FIND.y + 1);
            button = 80;

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Find student(s) info by specifying";
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+1);
            cout << "a ID";
            //Find student(s) info by specifying a ID
            break;

         case 10:
            HighlightButton("      Display       ", DISPLAY_POS.x, DISPLAY_POS.y);
            button = 1;

            ClearDynamicHelp();
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
            cout << "Display a list of students";
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+1);
            cout << "with info about ID, name, birthday ";
            GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+2);
            cout << "and average score";
            //Display a list of students with info about ID, name, birthday
            //and average score
            break;
         default:
            break;
      }
   }
}

void Menu::LeaveButton(int button)
{
   if(isMainMenuTriggered)
   {
      switch(button)
      {
         case 0:
            UnhighlightButton("        Exit        ", EXIT_POS.x, EXIT_POS.y);
            break;
         case STD_MAN:
            UnhighlightButton(" Student Management ", STD_MAN_POS.x, STD_MAN_POS.y);
            break;
         case LOAD:
            UnhighlightButton("        Load        ", LOAD_POS.x, LOAD_POS.y);
            break;
         case SAVE:
            UnhighlightButton("        Save        ", SAVE_POS.x, SAVE_POS.y);
            break;
         case HELP:
            UnhighlightButton("        Help        ", HELP_POS.x, HELP_POS.y);
            break;
         case CREDIT:
            UnhighlightButton("       Credit       ", CREDIT_POS.x, CREDIT_POS.y);
            break;
         case EXIT:
            UnhighlightButton("        Exit        ", EXIT_POS.x, EXIT_POS.y);
            break;
         case 7:
            UnhighlightButton(" Student Management ", STD_MAN_POS.x, STD_MAN_POS.y);
            break;
         default:
            break;
      }
   }
   else if(isSubMenuTriggered)
   {
      switch(button)
      {
         case 0:
            UnhighlightButton("     Main Menu      ", MAIN_MENU_POS.x, MAIN_MENU_POS.y);
            break;
         case DISPLAY:
            UnhighlightButton("      Display       ", DISPLAY_POS.x, DISPLAY_POS.y);
            break;
         case NEW_STUDENT:
            UnhighlightButton("     New Student    ", NEW_STUDENT_POS.x, NEW_STUDENT_POS.y);
            break;
         case NEW_LIST:
            UnhighlightButton("      New List      ", NEW_LIST_POS.x, NEW_LIST_POS.y);
            break;
         case DELETE_STUDENT:
            UnhighlightButton("   Delete Student   ", DELETE_STUDENT_POS.x, DELETE_STUDENT_POS.y);
            break;
         case DELETE_ALL:
            UnhighlightButton("     Delete All     ", DELETE_ALL_POS.x, DELETE_ALL_POS.y);
            break;
         case UPDATE:
            UnhighlightButton("       Update     > ", UPDATE_POS.x, UPDATE_POS.y);
            break;
         case SORT:
            UnhighlightButton("        Sort      > ", SORT_POS.x, SORT_POS.y);
            break;
         case FIND:
            UnhighlightButton("        Find      > ", FIND_POS.x, FIND_POS.y);
            break;
         case MAIN_MENU:
            UnhighlightButton("     Main Menu      ", MAIN_MENU_POS.x, MAIN_MENU_POS.y);
            break;
         case 79:
            UnhighlightButton("     Find Name      ", TOP_LEFT_SUB_FIND.x + 1, TOP_LEFT_SUB_FIND.y + 4);
            button = 81;
            break;

         case 59:
            UnhighlightButton("     Update Score   ", TOP_LEFT_SUB_UPDATE.x + 1, TOP_LEFT_SUB_UPDATE.y + 10);
            button = 63;
            break;
         case UPDATE_ID:
            UnhighlightButton("      Update ID     ", TOP_LEFT_SUB_UPDATE.x + 1, TOP_LEFT_SUB_UPDATE.y + 1);
            break;
         case UPDATE_NAME:
            UnhighlightButton("     Update Name    ", TOP_LEFT_SUB_UPDATE.x + 1, TOP_LEFT_SUB_UPDATE.y + 4);
            break;
         case UPDATE_BIRTHDAY:
            UnhighlightButton("   Update Birthday  ", TOP_LEFT_SUB_UPDATE.x + 1, TOP_LEFT_SUB_UPDATE.y + 7);
            break;
         case UPDATE_SCORE:
            UnhighlightButton("     Update Score   ", TOP_LEFT_SUB_UPDATE.x + 1, TOP_LEFT_SUB_UPDATE.y + 10);
            break;
         case 64:
            UnhighlightButton("      Update ID     ", TOP_LEFT_SUB_UPDATE.x + 1, TOP_LEFT_SUB_UPDATE.y + 1);
            button = 60;
            break;

         case 69:
            UnhighlightButton("     Sort Score     ", TOP_LEFT_SUB_SORT.x + 1, TOP_LEFT_SUB_SORT.y + 7);
            button = 72;
            break;
         case SORT_ID:
            UnhighlightButton("      Sort ID       ", TOP_LEFT_SUB_SORT.x + 1, TOP_LEFT_SUB_SORT.y + 1);
            break;
         case SORT_NAME:
            UnhighlightButton("      Sort Name     ", TOP_LEFT_SUB_SORT.x + 1, TOP_LEFT_SUB_SORT.y + 4);
            break;
         case SORT_SCORE:
            UnhighlightButton("     Sort Score     ", TOP_LEFT_SUB_SORT.x + 1, TOP_LEFT_SUB_SORT.y + 7);
            break;
         case 73:
            UnhighlightButton("      Sort ID       ", TOP_LEFT_SUB_SORT.x + 1, TOP_LEFT_SUB_SORT.y + 1);
            button = 70;
            break;

         case FIND_ID:
            UnhighlightButton("      Find ID       ", TOP_LEFT_SUB_FIND.x + 1, TOP_LEFT_SUB_FIND.y + 1);
            break;
         case FIND_NAME:
            UnhighlightButton("      Find Name     ", TOP_LEFT_SUB_FIND.x + 1, TOP_LEFT_SUB_FIND.y + 1 + 3);
            break;
         case 82:
            UnhighlightButton("      Find ID       ", TOP_LEFT_SUB_FIND.x + 1, TOP_LEFT_SUB_FIND.y + 1);
            button = 80;
            break;

         case 10:
            UnhighlightButton("      Display       ", DISPLAY_POS.x, DISPLAY_POS.y);
            break;
         default:
            break;
      }
   }
}

void Menu::ActivateButton(int button)
{
   if(isMainMenuTriggered)
   {
      switch(button)
      {
         case STD_MAN:
            isSubMenuTriggered = true;
            isMainMenuTriggered = false;
            break;
         case LOAD:
            LoadButton();
            break;
         case SAVE:
            SaveButton();
            break;
         case HELP:
            HelpButton();
            break;
         case CREDIT:
            CreditButton();
            break;
         case EXIT:
            ExitButton();
            break;
         default:
            break;
      }
   }
   else if(isSubMenuTriggered)
   {
      switch(button)
      {
         case DISPLAY:
            if(studentList.stdList.size() == 0)
            {
               SetColor(LIGHT_RED on BLACK);
               DisplayBotMsg("Student list is empty. Please create new data first");
               SetColor(LIGHT_GREEN on BLACK);
               break;
            }
            isSubMenuTriggered     = false;
            isStudentListTriggered = true;
            break;
         case NEW_STUDENT:
            NewStudent();
            break;
         case NEW_LIST:
            NewList();
            break;
         case DELETE_STUDENT:
            DeleteStudent();
            break;
         case DELETE_ALL:
            DeleteAll();
            break;

         case UPDATE:
            mOldButton = mButton;
            PrintSubUpdateList();
            mButton = (mButton*10);
            LeaveButton(mOldButton);
            EnterButton(mButton);
            break;
         case UPDATE_ID:
            Update(UPDATE_ID);
            break;
         case UPDATE_NAME:
            Update(UPDATE_NAME);
            break;
         case UPDATE_BIRTHDAY:
            Update(UPDATE_BIRTHDAY);
            break;
         case UPDATE_SCORE:
            Update(UPDATE_SCORE);
            break;

         case SORT:
            mOldButton = mButton;
            PrintSubSortList();
            mButton = (mButton*10);
            LeaveButton(mOldButton);
            EnterButton(mButton);
            break;
         case SORT_ID:
            Sort(0);
            break;
         case SORT_NAME:
            Sort(1);
            break;
         case SORT_SCORE:
            Sort(2);
            break;

         case FIND:
            mOldButton = mButton;
            PrintSubFindList();
            mButton = (mButton*10);
            LeaveButton(mOldButton);
            EnterButton(mButton);
            break;
         case FIND_ID:
            Find(FIND_ID);
            break;
         case FIND_NAME:
            Find(FIND_NAME);
            break;

         case MAIN_MENU:
            isSubMenuTriggered = false;
            isMainMenuTriggered = true;
            break;
         default:
            break;
      }
   }
}

void Menu::PageUp(vector<Student> &students)
{
   mPageMax = students.size() / 66;

   ClearTextBlock(
         TOP_LEFT_STUDENT_LIST.x - 1,
         TOP_LEFT_STUDENT_LIST.y - 1,
         BOT_RIGHT_STUDENT_LIST.x + 1,
         BOT_RIGHT_STUDENT_LIST.y + 1);
   InitStudentList();

   if(mPageScale > 0)
   {
      mPageScale--;
      ShowStudentList(students);
   }
   else
   {
      mPageScale = mPageMax;
      ShowStudentList(students);
   }
   mButton = 66*mPageScale - 1;
   mOldButton = -100;
}

void Menu::PageDown(vector<Student> &students)
{
   mPageMax = students.size() / 66;

   ClearTextBlock(
         TOP_LEFT_STUDENT_LIST.x - 1,
         TOP_LEFT_STUDENT_LIST.y - 1,
         BOT_RIGHT_STUDENT_LIST.x + 1,
         BOT_RIGHT_STUDENT_LIST.y + 1);
   InitStudentList();

   if(mPageScale < mPageMax)
   {
      mPageScale++;
      ShowStudentList(students);
   }
   else
   {
      mPageScale = 0;
      ShowStudentList(students);
   }
   mButton = 66*mPageScale;
   mOldButton = -100;
}

void Menu::LoadButton(void)
{
   if(studentList.Read())
   {
      DisplayBotMsg("File has been read successfully");
   }
   else
   {
      SetColor(LIGHT_RED on BLACK);
      DisplayBotMsg("Fail to load file");
      SetColor(LIGHT_GREEN on BLACK);
   }
}

void Menu::SaveButton(void)
{
   if(studentList.stdList.empty())
   {
      SetColor(LIGHT_RED on BLACK);
      DisplayBotMsg("Student list is empty. Please create new data first");
      SetColor(LIGHT_GREEN on BLACK);
      return;
   }
   if(studentList.Write())
   {
      DisplayBotMsg("File has been written successfully");
   }
   else
   {
      SetColor(LIGHT_RED on BLACK);
      DisplayBotMsg("Fail to save file");
      SetColor(LIGHT_GREEN on BLACK);
   }
}

void Menu::HelpButton(void)
{
   ClearTextBlock(TOP_LEFT_MES_WIN.x, TOP_LEFT_MES_WIN.y, BOT_RIGHT_MES_WIN.x, BOT_RIGHT_MES_WIN.y);

   if(!isRightBorderAvail)
   {
      string topRow(73, ROW_SYMBOL);
      string botRow(73, ROW_SYMBOL);
      string leftCol(20, COL_SYMBOL);
      string rightCol(20, COL_SYMBOL);

      leftCol[0]   = BOT_LEFT_SYMBOL;
      leftCol[19]  = TOP_LEFT_SYMBOL;
      rightCol[0]  = TOP_RIGHT_SYMBOL;
      rightCol[19] = BOT_RIGHT_SYMBOL;

      DisplayBorderOne(topRow, rightCol, botRow, leftCol, TOP_LEFT_MES_WIN, TOP_RIGHT_MES_WIN, BOT_RIGHT_MES_WIN, BOT_LEFT_MES_WIN, 3, 4);
   }

   DisplayText("Navigation:",                                                           TOP_LEFT_MES_WIN.x +  4, TOP_LEFT_MES_WIN.y + 2,  4);
   //"   Press up and down arrow keys to navigate in the menu"
   DisplayText("   Press",                                                              TOP_LEFT_MES_WIN.x +  4, TOP_LEFT_MES_WIN.y + 3,  4);
   SetColor(LIGHT_RED on BLACK);
   DisplayText("<Up>",                                                                  TOP_LEFT_MES_WIN.x + 13, TOP_LEFT_MES_WIN.y + 3,  4);
   SetColor(LIGHT_GREEN on BLACK);
   DisplayText("or",                                                                    TOP_LEFT_MES_WIN.x + 18, TOP_LEFT_MES_WIN.y + 3,  4);
   SetColor(LIGHT_RED on BLACK);
   DisplayText("<Down>",                                                                TOP_LEFT_MES_WIN.x + 21, TOP_LEFT_MES_WIN.y + 3,  4);
   SetColor(LIGHT_GREEN on BLACK);
   DisplayText("arrow keys to navigate in the menu",                                    TOP_LEFT_MES_WIN.x + 28, TOP_LEFT_MES_WIN.y + 3,  4);

   //Press <Enter> to select button
   DisplayText("   Press",                                                              TOP_LEFT_MES_WIN.x +  4, TOP_LEFT_MES_WIN.y + 4,  4);
   SetColor(LIGHT_RED on BLACK);
   DisplayText("<Enter>",                                                               TOP_LEFT_MES_WIN.x + 13, TOP_LEFT_MES_WIN.y + 4,  4);
   SetColor(LIGHT_GREEN on BLACK);
   DisplayText("to select button",                                                      TOP_LEFT_MES_WIN.x + 21, TOP_LEFT_MES_WIN.y + 4,  4);

   DisplayText("Button:",                                                               TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 5,  4);
   DisplayText("   Save: write changes to file DSSV.dat",                               TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 6,  4);
   DisplayText("   Load: read file DSSV.dat which store info about students",           TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 7,  4);
   DisplayText("   Student Management: Manage student list data via a set of commands", TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 8,  4);
   DisplayText("      Add new student",                                                 TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 9,  4);
   DisplayText("      Update student info",                                             TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 10, 4);
   DisplayText("      Delete a student",                                                TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 11, 4);
   DisplayText("      Create new list",                                                 TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 12, 4);
   DisplayText("      Delete student list",                                             TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 13, 4);
   DisplayText("      Sort student info by name or ID",                                 TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 14, 4);
   DisplayText("      Find student by name or ID",                                      TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 15, 4);
   DisplayText("   Credit: information about this project's group",                     TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 16, 4);
   DisplayText("   DSSV.dat: a binary file to store the data of a list of students",    TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 17, 4);

   isHelpContentAvail = true;
   isCreditContentAvail = false;
   isRightBorderAvail = true;
}

void Menu::CreditButton()
{
   ClearTextBlock(TOP_LEFT_MES_WIN.x, TOP_LEFT_MES_WIN.y, BOT_RIGHT_MES_WIN.x, BOT_RIGHT_MES_WIN.y);

   if(!isRightBorderAvail)
   {
      string topRow(73, ROW_SYMBOL);
      string botRow(73, ROW_SYMBOL);
      string leftCol(20, COL_SYMBOL);
      string rightCol(20, COL_SYMBOL);

      leftCol[0]   = BOT_LEFT_SYMBOL;
      leftCol[19]  = TOP_LEFT_SYMBOL;
      rightCol[0]  = TOP_RIGHT_SYMBOL;
      rightCol[19] = BOT_RIGHT_SYMBOL;

      DisplayBorderOne(topRow, rightCol, botRow, leftCol, TOP_LEFT_MES_WIN, TOP_RIGHT_MES_WIN, BOT_RIGHT_MES_WIN, BOT_LEFT_MES_WIN, 3, 4);
   }

   DisplayText("Data structure and algorithm Project",     TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 2,  4);
   DisplayText("Members:",                                 TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 4,  4);
   DisplayText("   Nguyen Khanh Nguyen",                   TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 5,  4);
   DisplayText("   MSSV: 16520846",                        TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 6,  4);
   DisplayText("   Vo Thi Mot",                            TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 7,  4);
   DisplayText("   MSSV: 16520756",                        TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 8,  4);
   DisplayText("Instructor: ",                             TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 10, 4);
   DisplayText("   Do Van Nhon",                           TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 11, 4);
   DisplayText("Product name: Student Management System",  TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 13, 4);
   DisplayText("Date Created: 15/04/2017",                 TOP_LEFT_MES_WIN.x + 4, TOP_LEFT_MES_WIN.y + 14, 4);

   isHelpContentAvail = false;
   isCreditContentAvail = true;
   isRightBorderAvail = true;
}

void Menu::ExitButton(void)
{
   UndisplayMainMenu();
   UndisplayTitle();
   exit(EXIT_SUCCESS);
}

void Menu::ValidateOnce(string errorMsg, int &reassignVar, int x1, int y1, int x2, int y2, bool ignoreFlag)
{
   if(cin.fail())
   {
      ClearText(x2, y2, 18);
      cin.clear();
      if(ignoreFlag)
      {
         cin.ignore(INT_MAX, '\n');
      }
      ClearText(x1, y1, 36);
      SetColor(LIGHT_RED on BLACK);
      DisplayText("Invalid input. Please type again", x1, y1, 10);
      SetColor(LIGHT_GREEN on BLACK);
      Input(reassignVar, x2, y2, false);
      return;
   }

   ClearText(x2, y2, 18);
   cin.clear();
   if(ignoreFlag)
   {
      cin.ignore(INT_MAX, '\n');
   }
   ClearText(x1, y1, 36);
   SetColor(LIGHT_RED on BLACK);
   DisplayText(errorMsg, x1, y1, 10);
   SetColor(LIGHT_GREEN on BLACK);
   Input(reassignVar, x2, y2, false);
}

void Menu::ValidateScore(double &score, int x1, int y1, int x2, int y2)
{
   while(true)
   {
      if(cin.fail())
      {
         cin.clear();
         cin.ignore(INT_MAX, '\n');
         ClearText(x1, y1, 36);
         SetColor(LIGHT_RED on BLACK);
         DisplayText("Invalid score. Please Enter again", x1, y1, 10);
         SetColor(LIGHT_GREEN on BLACK);

         ClearText(x2, y2, 22);
         Input(score, x2, y2, false);
      }
      else if(score > 10 || score < 0)
      {
         ClearText(x1, y1, 36);
         cin.ignore(INT_MAX, '\n');
         SetColor(LIGHT_RED on BLACK);
         DisplayText("Score is out of range", x1, y1, 10);
         SetColor(LIGHT_GREEN on BLACK);

         ClearText(x2, y2, 22);
         Input(score, x2, y2, false);
      }
      else
      {
         ClearText(x1, y1, 36);
         break;
      }
   }
}

bool Menu::IsValidName(string str)
{
   for(int i = 0; str[i]; i++)
   {
      if(!isalpha(str[i]) && !isspace(str[i]))
      {
         return 0;
      }
   }
   return 1;
}

void Menu::ValidateID(int &ID, int x1, int y1, int x2, int y2)
{
   bool isUniqueID = false;

   while(true)
   {
      if(cin.fail())
      {
         cin.clear();
         cin.ignore(INT_MAX, '\n');
         ClearText(x1, y1, 36);
         SetColor(LIGHT_RED on BLACK);
         DisplayText("Invalid ID. Please Enter again", x1, y1, 10);
         SetColor(LIGHT_GREEN on BLACK);

         ClearText(x2, y2, 31);
         Input(ID, x2, y2, false);
      }
      else if(ID < 0)
      {
         ClearText(x2, y2, 25);
         cin.clear();
         cin.ignore(INT_MAX, '\n');
         ClearText(x1, y1, 36);
         SetColor(LIGHT_RED on BLACK);
         DisplayText("ID number cant be negative", x1, y1, 10);
         SetColor(LIGHT_GREEN on BLACK);
         Input(ID, x2, y2, false);
      }
      else if(!isUniqueID)
      {
         int size = studentList.stdList.size();
         isUniqueID = true;

         for(int i = 0; i < size; i++)
         {
            if(studentList.stdList[i].mID == ID)
            {
               isUniqueID = false;

               ClearText(x1, y1, 36);
               cin.ignore(INT_MAX, '\n');
               SetColor(LIGHT_RED on BLACK);
               DisplayText("ID is not unique", x1, y1, 10);
               SetColor(LIGHT_GREEN on BLACK);

               ClearText(x2, y2, 31);
               Input(ID, x2, y2, false);
            }
         }
      }
      else //All good
      {
         ClearText(x1, y1, 36);
         break;
      }
   }
}

void Menu::ValidateName(string &name, int x1, int y1, int x2, int y2)
{
   while(true)
   {
      if(cin.fail())
      {
         ClearText(x2, y2, 31);
         cin.clear();
         SetColor(LIGHT_RED on BLACK);
         DisplayText("Invalid name. Please Enter again", x1, y1, 10);
         SetColor(LIGHT_GREEN on BLACK);
         Input(name, x2, y2);
      }
      else if(!IsValidName(name))
      {
         ClearText(x2, y2, 31);
         SetColor(LIGHT_RED on BLACK);
         DisplayText("Alphanumaric characters only", x1, y1, 10);
         SetColor(LIGHT_GREEN on BLACK);
         Input(name, x2, y2, false);
      }
      else if(name.empty())
      {
         ClearText(x2, y2, 31);
         SetColor(LIGHT_RED on BLACK);
         DisplayText("Input must not be empty", x1, y1, 10);
         SetColor(LIGHT_GREEN on BLACK);
         Input(name, x2, y2, false);
      }
      else
      {
         ClearText(x1, y1, 36);
         break;
      }
   }
}

void Menu::Input(std::string &input, int x, int y, bool ignoreFlag)
{
   if(ignoreFlag)
   {
      cin.ignore(INT_MAX, '\n');
   }

   GoToXY(x, y);
   ShowConsoleCursor(true);
   SetColor(LIGHT_CYAN on BLACK);
   getline(cin, input);
   SetColor(LIGHT_GREEN on BLACK);
   ShowConsoleCursor(false);
}

void Menu::EnterID(Student &student, bool ignoreFlag)
{
   if(ignoreFlag)
   {
      Input(student.mID,
            TOP_LEFT_STUDENT_INFO.x + 6,
            TOP_LEFT_STUDENT_INFO.y + 11, true);
   }
   else
   {
      Input(student.mID,
            TOP_LEFT_STUDENT_INFO.x + 6,
            TOP_LEFT_STUDENT_INFO.y + 11, false);
   }

   ValidateID(
         student.mID,
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 10,
         TOP_LEFT_STUDENT_INFO.x + 6,
         TOP_LEFT_STUDENT_INFO.y + 11);
   ClearText(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 10,
         36);
}

void Menu::EnterName(Student &student, bool ignoreFlag)
{
   if(ignoreFlag)
   {
      Input(student.mName,
            TOP_LEFT_STUDENT_INFO.x + 8,
            TOP_LEFT_STUDENT_INFO.y + 16);
   }
   else
   {
      Input(student.mName,
            TOP_LEFT_STUDENT_INFO.x + 8,
            TOP_LEFT_STUDENT_INFO.y + 16, false);
   }

   ValidateName(
         student.mName,
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 15,
         TOP_LEFT_STUDENT_INFO.x + 8,
         TOP_LEFT_STUDENT_INFO.y + 16);
   ClearText(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 15,
         36);
}

void Menu::EnterBirthday(Student &student, bool ignoreFlag)
{
   if(ignoreFlag)
   {
      Input(student.mBirthday.day,
            TOP_LEFT_STUDENT_INFO.x + 9,
            TOP_LEFT_STUDENT_INFO.y + 22, true);
   }
   else
   {
      Input(student.mBirthday.day,
            TOP_LEFT_STUDENT_INFO.x + 9,
            TOP_LEFT_STUDENT_INFO.y + 22, false);
   }

   while(!student.mBirthday.IsValidDay() || cin.fail())
   {
      ValidateOnce("Day number is out of range",
            student.mBirthday.day,
            TOP_LEFT_STUDENT_INFO.x + 2,
            TOP_LEFT_STUDENT_INFO.y + 20,
            TOP_LEFT_STUDENT_INFO.x + 9,
            TOP_LEFT_STUDENT_INFO.y + 22,
            1);
   }

   Input(student.mBirthday.month,
         TOP_LEFT_STUDENT_INFO.x + 11,
         TOP_LEFT_STUDENT_INFO.y + 23, true);

   while(!student.mBirthday.IsValidMonth() || cin.fail())
   {
      ValidateOnce("Month number is out of range",
            student.mBirthday.month,
            TOP_LEFT_STUDENT_INFO.x + 2,
            TOP_LEFT_STUDENT_INFO.y + 20,
            TOP_LEFT_STUDENT_INFO.x + 11,
            TOP_LEFT_STUDENT_INFO.y + 23,
            1);
   }
   ClearText(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 20,
         36);

   Input(student.mBirthday.year,
         TOP_LEFT_STUDENT_INFO.x + 10,
         TOP_LEFT_STUDENT_INFO.y + 24, true);

   while(!student.mBirthday.IsValidYear() || cin.fail())
   {
      ValidateOnce("Year number is out of range",
            student.mBirthday.year,
            TOP_LEFT_STUDENT_INFO.x + 2,
            TOP_LEFT_STUDENT_INFO.y + 20,
            TOP_LEFT_STUDENT_INFO.x + 10,
            TOP_LEFT_STUDENT_INFO.y + 24,
            1);
   }
   ClearText(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 20,
         36);
}

void Menu::EnterScore(Student &student, bool ignoreFlag)
{
   if(ignoreFlag)
   {
      Input(student.mAvgScore,
            TOP_LEFT_STUDENT_INFO.x + 17,
            TOP_LEFT_STUDENT_INFO.y + 29, true);
   }
   else
   {
      Input(student.mAvgScore,
            TOP_LEFT_STUDENT_INFO.x + 17,
            TOP_LEFT_STUDENT_INFO.y + 29, false);
   }

   ValidateScore(
         student.mAvgScore,
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 28,
         TOP_LEFT_STUDENT_INFO.x + 17,
         TOP_LEFT_STUDENT_INFO.y + 29);

   ClearText(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 28,
         36);
}

void Menu::NewStudent(void)
{
   Student newStudent;

   ClearRightPanel();
   InitForm2();

   //cin.ignore(); is only skipped on the first run because
   //there is no cin leaving the extra newline yet
   if(mInitFlag)
   {
      cin.ignore();
   }
   if(!mInitFlag)
   {
      mInitFlag = true;
   }

   SetColor(LIGHT_CYAN on BLACK);
   EnterID(newStudent, false);
   EnterName(newStudent, true);
   EnterBirthday(newStudent, false);
   EnterScore(newStudent, true);

   //WIP -> make a seperate func
   SetColor(LIGHT_GREEN on BLACK);
   studentList.stdList.push_back(newStudent);
   DisplayBotMsg("New student created");
   ClearRightPanel();
   InitForm();
   PrintStudentInfo(newStudent);
}

void Menu::NewList(void)
{
   int keyPressed;

   if(!studentList.stdList.empty())
   {
      SetColor(WHITE on BLACK);
      DisplayBotMsg("Warning: All info about student list will be erased. Press Enter to proceed");
      SetColor(LIGHT_GREEN on BLACK);

      keyPressed = _getch();
      if(keyPressed != KEY_ENTER)
      {
         DisplayBotMsg("Operation is cancelled");
         return;
      }
      studentList.Delete();
      //WIP
   }
   else
   {
      keyPressed = KEY_ENTER;
   }

   //cin.ignore(); is only skipped on the first run because
   //there is no cin leaving the extra newline yet
   if(mInitFlag)
   {
      cin.ignore();
   }
   if(!mInitFlag)
   {
      mInitFlag = true;
   }

   Student newStudent;
   int total;
   string block(35, BOTTOM_HALF_BLOCK_SYMBOL);

   GoToXY(
         TOP_LEFT_STUDENT_INFO.x,
         TOP_LEFT_STUDENT_INFO.y + 8);
   cout << block;
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 11);
   cout << "Number of student:";

   Input(total, 
         TOP_LEFT_STUDENT_INFO.x + 21,
         TOP_LEFT_STUDENT_INFO.y + 11, false);

   while(total < 0 || cin.fail())
   {
      ValidateOnce("Number of students cant be negative",
            total,
            TOP_LEFT_STUDENT_INFO.x + 2,
            TOP_LEFT_STUDENT_INFO.y + 10,
            TOP_LEFT_STUDENT_INFO.x + 21,
            TOP_LEFT_STUDENT_INFO.y + 11, 1);
   }

   for(int i = 0; i < total; i++)
   {
      NewStudent();
   }

   DisplayBotMsg("Student List created successfully");
}

void Menu::DeleteStudent(void)
{
   if(studentList.stdList.empty())
   {
      SetColor(WHITE on BLACK);
      DisplayBotMsg("There is no student in the list to delete");
      SetColor(LIGHT_GREEN on BLACK);
      return;
   }

   //cin.ignore(); is only skipped on the first run because
   //there is no cin leaving the extra newline yet
   if(mInitFlag)
   {
      cin.ignore();
   }
   if(!mInitFlag)
   {
      mInitFlag = true;
   }

   string block(35, BOTTOM_HALF_BLOCK_SYMBOL);
   int ID;

   GoToXY(
         TOP_LEFT_STUDENT_INFO.x,
         TOP_LEFT_STUDENT_INFO.y + 8);
   cout << block;

   GoToXY(TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 11);
   cout << "ID of student to be deleted:";

   Input(ID,
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 12, false);

   while(ID < 0 || cin.fail())
   {
      ValidateOnce("ID number cant be negative",
            ID,
            TOP_LEFT_STUDENT_INFO.x + 2,
            TOP_LEFT_STUDENT_INFO.y + 10,
            TOP_LEFT_STUDENT_INFO.x + 2,
            TOP_LEFT_STUDENT_INFO.y + 12, 1);
   }

   int size = studentList.stdList.size();
   for(int i = 0; i < size; i++)
   {
      if(ID == studentList.stdList[i].mID)
      {
         studentList.DeleteOne(i);
         string successMsg = "Student with ID " + to_string(ID) + " has been deleted successfully";
         DisplayBotMsg(successMsg);
         return;
      }
   }
   string errorMsg = "There are no students with ID " + to_string(ID);
   DisplayBotMsg(errorMsg);
}

void Menu::DeleteAll(void)
{
   if(studentList.stdList.empty())
   {
      SetColor(WHITE on BLACK);
      DisplayBotMsg("There is no student list available");
      SetColor(LIGHT_GREEN on BLACK);
      return;
   }

   SetColor(LIGHT_RED on BLACK);
   DisplayBotMsg("Warning: All info about student list will be erased. Press Enter to proceed");
   SetColor(LIGHT_GREEN on BLACK);

   int keyPressed;
   keyPressed = _getch();
   if(keyPressed == KEY_ENTER)
   {
      studentList.Delete();
      DisplayBotMsg("Student list has been deleted");
   }
   else
   {
      DisplayBotMsg("Operation is cancelled");
   }
}

void Menu::Sort(int choice)
{
   if(studentList.stdList.empty())
   {
      SetColor(WHITE on BLACK);
      DisplayBotMsg("There is no student in the list to sort");
      SetColor(LIGHT_GREEN on BLACK);
      return;
   }

   if(studentList.stdList.size() == 1)
   {
      SetColor(WHITE on BLACK);
      DisplayBotMsg("There must be more than one student to sort");
      SetColor(LIGHT_GREEN on BLACK);
      return;
   }

   studentList.Sort(choice);

   //Show student list after sort
   DisplayBotMsg("Sort done!");
   UndisplayTextBlock(
         TOP_LEFT_SUB_BUTTON_LIST.x - 1,
         TOP_LEFT_SUB_BUTTON_LIST.y - 1,
         BOT_RIGHT_SUB_SORT.x + 1,
         BOT_RIGHT_SUB_SORT.y + 1, 2);
   isStudentListTriggered = true;
   isSubMenuTriggered = false;
   StudentListMenu(studentList.stdList);

   ClearText(0, 39, 100);
   DisplaySubMenu();
   mButton = SORT;
   HighlightButton("        Sort      > ", SORT_POS.x, SORT_POS.y);
}

void Menu::Find(int choice)
{
   if(studentList.stdList.empty())
   {
      SetColor(WHITE on BLACK);
      DisplayBotMsg("There is no data to look for");
      SetColor(LIGHT_GREEN on BLACK);
      return;
   }

   //cin.ignore(); is only skipped on the first run because
   //there is no cin leaving the extra newline yet
   if(mInitFlag)
   {
      cin.ignore();
   }
   if(!mInitFlag)
   {
      mInitFlag = true;
   }

   string block(35, BOTTOM_HALF_BLOCK_SYMBOL);
   vector<Student> resultList;
   int ID;
   string name;

   GoToXY(
         TOP_LEFT_STUDENT_INFO.x,
         TOP_LEFT_STUDENT_INFO.y + 8);
   cout << block;

   switch(choice)
   {
      case FIND_ID:
         GoToXY(TOP_LEFT_STUDENT_INFO.x + 2,
               TOP_LEFT_STUDENT_INFO.y + 11);
         cout << "ID to search for:";

         Input(ID, 
               TOP_LEFT_STUDENT_INFO.x + 2,
               TOP_LEFT_STUDENT_INFO.y + 12, false);

         while(ID < 0 || cin.fail())
         {
            ValidateOnce("ID number cant be negative",
                  ID,
                  TOP_LEFT_STUDENT_INFO.x + 2,
                  TOP_LEFT_STUDENT_INFO.y + 10,
                  TOP_LEFT_STUDENT_INFO.x + 2,
                  TOP_LEFT_STUDENT_INFO.y + 12, 1);
         }
         resultList = studentList.FindID(ID);
         break;
      case FIND_NAME:
         GoToXY(TOP_LEFT_STUDENT_INFO.x + 2,
               TOP_LEFT_STUDENT_INFO.y + 11);
         cout << "Name to search for:";

         Input(name, 
               TOP_LEFT_STUDENT_INFO.x + 2,
               TOP_LEFT_STUDENT_INFO.y + 12, false);

         ValidateName(
               name,
               TOP_LEFT_STUDENT_INFO.x + 2,
               TOP_LEFT_STUDENT_INFO.y + 10,
               TOP_LEFT_STUDENT_INFO.x + 2,
               TOP_LEFT_STUDENT_INFO.y + 12);
         mInitFlag = false;
         resultList = studentList.FindName(name);
         break;
      default:
         break;
   }

   if(resultList.empty())
   {
      DisplayBotMsg("No result found");
      return;
   }

   string msg = to_string(resultList.size()) + " result(s) found";

   DisplayBotMsg(msg);
   isStudentListTriggered = true;

   //Clear (ID/Name) to search for text
   ClearText(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 11, 20);
   ClearText(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 12, 37);

   //Highlight First found result


   //Undisplay Menu and subMenu find
   UndisplayTextBlock(
         TOP_LEFT_SUB_BUTTON_LIST.x - 1,
         TOP_LEFT_SUB_BUTTON_LIST.y - 1,
         BOT_RIGHT_SUB_FIND.x + 1,
         BOT_RIGHT_SUB_FIND.y + 1, 2);
   StudentListMenu(resultList);
   DisplaySubMenu();
   mButton = FIND;
   HighlightButton("        Find      > ", FIND_POS.x, FIND_POS.y);
}

void Menu::ShowStudentList(vector<Student> &students)
{
   int complement = mPageScale * 66;
   int nameMaxLength = 27;
   int studentListHeight = BOT_LEFT_STUDENT_LIST.y - TOP_LEFT_STUDENT_LIST.y + 1;
   int size = students.size();

   UndisplayTextBlock(
         TOP_LEFT_SUB_BUTTON_LIST.x - 1,
         TOP_LEFT_SUB_BUTTON_LIST.y - 1,
         BOT_RIGHT_SUB_BUTTON_LIST.x + 1,
         BOT_RIGHT_SUB_BUTTON_LIST.y + 1, 2);

   for(int i = complement; i - complement < studentListHeight*2 && i < size; i++)
   {
      if(i - complement < studentListHeight)
      {
         GoToXY(
               TOP_LEFT_STUDENT_LIST.x,
               TOP_LEFT_STUDENT_LIST.y + i - complement);
         cout << " " << students[i].mName;
      }
      else if(i - complement >= studentListHeight)
      {
         GoToXY(
               TOP_LEFT_STUDENT_LIST.x + nameMaxLength + 5,
               TOP_LEFT_STUDENT_LIST.y + i - complement - studentListHeight);
         cout << " " << students[i].mName;
      }
   }
   PrintStudentListPage();

   //Highlight first student info
   mButton = complement;
   NextStudent(students, mButton);
}

void Menu::PrintStudentListPage()
{
   //Clear previous page display
   ClearText(30, BOT_LEFT_STUDENT_LIST.y + 1, 12);

   int studentListWidth = TOP_LEFT_SUB_RIGHT_PANEL.x - TOP_LEFT_SUB_MENU.x;
   string pageNum = to_string(mPageScale+1) + "/" + to_string(mPageMax+1);
   Coords pagePos;
   pagePos.x = BOT_LEFT_SUB_MENU.x + (studentListWidth - pageNum.size()) / 2;
   pagePos.y = BOT_LEFT_STUDENT_LIST.y + 1;

   GoToXY(pagePos.x, pagePos.y);
   cout << pageNum;
}

void Menu::UndisplayStudentList(void)
{
   UndisplayTextBlock(
         TOP_LEFT_STUDENT_LIST.x - 1,
         TOP_LEFT_STUDENT_LIST.y - 1,
         BOT_RIGHT_STUDENT_LIST.x + 1,
         BOT_RIGHT_STUDENT_LIST.y + 2, 2);
   //+ another 1 for page count info at the bottom
}

void Menu::ClearRightPanel(void)
{
   //WIP
   UndisplayTextBlock(
         TOP_LEFT_STUDENT_INFO.x - 1,
         TOP_LEFT_STUDENT_INFO.y - 1 + 8,
         BOT_RIGHT_STUDENT_INFO.x + 1,
         BOT_RIGHT_STUDENT_INFO.y + 1, 1);
}

void Menu::ClearDynamicHelp(void)
{
   ClearTextBlock(
         TOP_LEFT_DYNAMIC_HELP.x-1,
         TOP_LEFT_DYNAMIC_HELP.y-1,
         BOT_RIGHT_DYNAMIC_HELP.x+1,
         BOT_RIGHT_DYNAMIC_HELP.y+1);
}

//ID
//Name
//Birthday
//Score
void Menu::InitForm(void)
{
   string block(35, BOTTOM_HALF_BLOCK_SYMBOL);

   GoToXY(
         TOP_LEFT_STUDENT_INFO.x,
         TOP_LEFT_STUDENT_INFO.y + 8);
   cout << block;
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 11);
   cout << "ID:";


   GoToXY(
         TOP_LEFT_STUDENT_INFO.x,
         TOP_LEFT_STUDENT_INFO.y + 14);
   cout << block;
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 17);
   cout << "Name:";


   GoToXY(
         TOP_LEFT_STUDENT_INFO.x,
         TOP_LEFT_STUDENT_INFO.y + 20);
   cout << block;
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 23);
   cout << "Birthday:";


   GoToXY(
         TOP_LEFT_STUDENT_INFO.x,
         TOP_LEFT_STUDENT_INFO.y + 26);
   cout << block;
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 29);
   cout << "Average Score:";
}

//ID
//Name
//Birthday
// Day
// Month
// Year
//Score
void Menu::InitForm2(void)
{
   string block(35, BOTTOM_HALF_BLOCK_SYMBOL);

   GoToXY(
         TOP_LEFT_STUDENT_INFO.x,
         TOP_LEFT_STUDENT_INFO.y + 8);
   cout << block;
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 11);
   cout << "ID:";


   GoToXY(
         TOP_LEFT_STUDENT_INFO.x,
         TOP_LEFT_STUDENT_INFO.y + 13);
   cout << block;
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 16);
   cout << "Name:";


   GoToXY(
         TOP_LEFT_STUDENT_INFO.x,
         TOP_LEFT_STUDENT_INFO.y + 18);
   cout << block;
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 21);
   cout << "Birthday:";
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 4,
         TOP_LEFT_STUDENT_INFO.y + 22);
   cout << "Day:";
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 4,
         TOP_LEFT_STUDENT_INFO.y + 23);
   cout << "Month:";
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 4,
         TOP_LEFT_STUDENT_INFO.y + 24);
   cout << "Year:";


   GoToXY(
         TOP_LEFT_STUDENT_INFO.x,
         TOP_LEFT_STUDENT_INFO.y + 26);
   cout << block;
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 29);
   cout << "Average Score:";
}

void Menu::InitStudentList(void)
{
   //Initilize splitting line
   for(int i = 0; i < BOT_LEFT_STUDENT_LIST.y - TOP_LEFT_STUDENT_LIST.y + 1; i++)
   {
      GoToXY(
            (TOP_LEFT_SUB_RIGHT_PANEL.x + TOP_LEFT_SUB_MENU.x) / 2,
            TOP_LEFT_STUDENT_LIST.y + i);
      cout << THIN_COL_LINE_SYMBOL;
   }

   InitForm();
}

void Menu::PrintStudentInfo(vector<Student> &students, int index)
{
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 12);
   cout << students[index].mID;
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 18);
   cout << students[index].mName;
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 24);
   cout << students[index].mBirthday;
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 30);
   cout << students[index].mAvgScore;
}

void Menu::PrintStudentInfo(Student student)
{
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 12);
   cout << student.mID;
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 18);
   cout << student.mName;
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 24);
   cout << student.mBirthday;
   GoToXY(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 30);
   cout << student.mAvgScore;
}

void Menu::ClearStudentInfo()
{
   ClearText(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 12,
         37);
   ClearText(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 18,
         37);
   ClearText(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 24,
         37);
   ClearText(
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 30,
         37);
   /* ClearTextBlock( */
   /*       TOP_LEFT_STUDENT_INFO.x - 1, */
   /*       TOP_LEFT_STUDENT_INFO.y - 1, */
   /*       BOT_RIGHT_STUDENT_INFO.x + 1, */
   /* BOT_RIGHT_STUDENT_INFO.y + 1); */
}

void Menu::StudentListMenu(vector<Student> &students)
{
   int complement = mPageScale * 64 + 1;
   int size = students.size();
   mPageScale = 0;
   mPageMax = size / 66;
   ShowStudentList(students);
   InitStudentList();

   //Show dynamic help
   GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
   SetColor(LIGHT_RED on BLACK);
   cout << "<Up> <Down>";
   SetColor(LIGHT_GREEN on BLACK);
   cout << ": Up/Down navigation";

   GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+1);
   SetColor(LIGHT_RED on BLACK);
   cout << "<Left> <Right>";
   SetColor(LIGHT_GREEN on BLACK);
   cout << ": Left/Right navigation";

   GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+2);
   SetColor(LIGHT_RED on BLACK);
   cout << "<Enter> <PgDn>";
   SetColor(LIGHT_GREEN on BLACK);
   cout << ": Go to the next page";

   GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+3);
   SetColor(LIGHT_RED on BLACK);
   cout << "<BS> <PgUp>";
   SetColor(LIGHT_GREEN on BLACK);
   cout << ": Go to the previous page";

   GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+4);
   SetColor(LIGHT_RED on BLACK);
   cout << "<Home>";
   SetColor(LIGHT_GREEN on BLACK);
   cout << ": Go to the first page";

   GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+5);
   SetColor(LIGHT_RED on BLACK);
   cout << "<End>";
   SetColor(LIGHT_GREEN on BLACK);
   cout << ": Go to the last page";

   GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+6);
   SetColor(LIGHT_RED on BLACK);
   cout << "<Esc>";
   SetColor(LIGHT_GREEN on BLACK);
   cout << ": Go back to submenu";

   while(true)
   {
      if(!isStudentListTriggered)
      {
         isSubMenuTriggered = true;
         UndisplayStudentList();
         ClearRightPanel();
         return;
      }

      mKeyPressed = _getch();
      switch(mKeyPressed) 
      {
         case KEY_UP:
            mOldButton = mButton;
            mButton--;
            LeaveStudent(students, mOldButton);
            NextStudent(students, mButton);
            break;
         case KEY_DOWN:
            mOldButton = mButton;
            mButton++;
            LeaveStudent(students, mOldButton);
            NextStudent(students, mButton);
            break;
         case KEY_LEFT:
            KeyLeft();
            break;
         case KEY_RIGHT:
            KeyRight();
            break;
         case KEY_PAGE_DOWN:
            PageDown(students);
            complement = mPageScale * 66;
            break;
         case KEY_PAGE_UP:
            PageUp(students);
            complement = mPageScale * 66;
            break;
         case KEY_ENTER:
            PageDown(students);
            complement = mPageScale * 66;
            break;
         case KEY_BACKSPACE:
            PageUp(students);
            complement = mPageScale * 66;
            break;
         case KEY_HOME:
            ClearTextBlock(
                  TOP_LEFT_STUDENT_LIST.x - 1,
                  TOP_LEFT_STUDENT_LIST.y - 1,
                  BOT_RIGHT_STUDENT_LIST.x + 1,
                  BOT_RIGHT_STUDENT_LIST.y + 1);
            InitStudentList();

            mPageScale = 0;
            ShowStudentList(students);
            mButton = 66*mPageScale - 1;
            mOldButton = -100;
            break;
         case KEY_END:
            ClearTextBlock(
                  TOP_LEFT_STUDENT_LIST.x - 1,
                  TOP_LEFT_STUDENT_LIST.y - 1,
                  BOT_RIGHT_STUDENT_LIST.x + 1,
                  BOT_RIGHT_STUDENT_LIST.y + 1);
            InitStudentList();

            mPageScale = mPageMax;
            ShowStudentList(students);
            mButton = 66*mPageScale - 1;
            mOldButton = -100;
            break;
            break;
         case KEY_ESC:
            isStudentListTriggered = false;
            break;
      }
   }
}

void Menu::KeyRight(void)
{
   if(isSubMenuTriggered)
   {
      if(mButton == SORT || mButton == FIND || mButton == UPDATE)
      {
         ActivateButton(mButton);
      }
      else if(80 == mButton || mButton == 81)
      {
         mOldButton = mButton;
         mButton = (mButton/10);
         ClearSubFindList();
         EnterButton(mButton);
      }
      else if(70 == mButton || mButton == 71 || mButton == 72)
      {
         mOldButton = mButton;
         mButton = (mButton/10);
         ClearSubSortList();
         EnterButton(mButton);
      }
      else if(60 <= mButton && mButton <= 63 )
      {
         mOldButton = mButton;
         mButton = (mButton/10);
         ClearSubUpdateList();
         EnterButton(mButton);
      }
   }
   else if(isStudentListTriggered)
   {
      int size = studentList.stdList.size();
      int complement = mPageScale * 64 + 1;
      int studentListHeight = BOT_LEFT_STUDENT_LIST.y - TOP_LEFT_STUDENT_LIST.y + 1;
      if(mButton - complement < studentListHeight)
      {
         mOldButton = mButton;
         if(mButton+33 > size - 1)
         {
            mButton = size - 1;
         }
         else
         {
            mButton+= 33;
         }
      }
      else
      {
         mOldButton = mButton;
         mButton-= 33;
      }
      LeaveStudent(studentList.stdList, mOldButton);
      NextStudent(studentList.stdList, mButton);
   }
}

void Menu::KeyLeft(void)
{
   if(isSubMenuTriggered)
   {
      if(mButton == SORT || mButton == FIND || mButton == UPDATE)
      {
         ActivateButton(mButton);
      }
      else if(80 == mButton || mButton == 81)
      {
         mOldButton = mButton;
         mButton = (mButton/10);
         ClearSubFindList();
         EnterButton(mButton);
      }
      else if(70 == mButton || mButton == 71 || mButton == 72)
      {
         mOldButton = mButton;
         mButton = (mButton/10);
         ClearSubSortList();
         EnterButton(mButton);
      }
      else if(60 <= mButton && mButton <= 63 )
      {
         mOldButton = mButton;
         mButton = (mButton/10);
         ClearSubUpdateList();
         EnterButton(mButton);
      }
   }
   else if(isStudentListTriggered)
   {
      int size = studentList.stdList.size();
      int complement = mPageScale * 64 + 1;
      int studentListHeight = BOT_LEFT_STUDENT_LIST.y - TOP_LEFT_STUDENT_LIST.y + 1;
      if(mButton - complement < studentListHeight)
      {
         mOldButton = mButton;
         if(mButton+33 > size - 1)
         {
            mButton = size - 1;
         }
         else
         {
            mButton+= 33;
         }
      }
      else
      {
         mOldButton = mButton;
         mButton-= 33;
      }
      LeaveStudent(studentList.stdList, mOldButton);
      NextStudent(studentList.stdList, mButton);
   }
}

void Menu::MainMenu(void)
{
   DisplayMainMenu();

   mButton = 1;
   HighlightButton(" Student Management ", STD_MAN_POS.x, STD_MAN_POS.y);

   while(true)
   {
      if(!isMainMenuTriggered)
      {
         UndisplayMainMenu();
         UndisplayTitle();
         return;
      }

      mKeyPressed = _getch();
      switch(mKeyPressed) 
      {
         case KEY_UP:
            mOldButton = mButton--;
            LeaveButton(mOldButton);
            EnterButton(mButton);
            break;
         case KEY_DOWN:
            mOldButton = mButton++;
            LeaveButton(mOldButton);
            EnterButton(mButton);
            break;
         case KEY_ENTER:
            ClearText(0, 39, 100);
            ActivateButton(mButton);
            break;
         case KEY_ESC:
            break;
      }
   }
}

void Menu::SubMenu(void)
{
   if(isRightBorderAvail)
   {
      isRightBorderAvail = false;
   }

   DisplaySubMenu();

   //Highlight first button and dynamic help
   mButton = 1;
   HighlightButton("      Display       ", DISPLAY_POS.x, DISPLAY_POS.y);
   GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y);
   cout << "Display a list of students";
   GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+1);
   cout << "with info about ID, name, birthday ";
   GoToXY(TOP_LEFT_DYNAMIC_HELP.x, TOP_LEFT_DYNAMIC_HELP.y+2);
   cout << "and average score";

   while(true)
   {
      if(!isSubMenuTriggered)
      {
         if(isMainMenuTriggered)
         {
            UndisplaySubMenu();
            return;
         }
         return;
      }

      mKeyPressed = _getch();
      switch(mKeyPressed) 
      {
         case KEY_UP:
            mOldButton = mButton--;
            LeaveButton(mOldButton);
            EnterButton(mButton);
            break;
         case KEY_DOWN:
            mOldButton = mButton++;
            LeaveButton(mOldButton);
            EnterButton(mButton);
            break;
         case KEY_RIGHT:
            KeyRight();
            break;
         case KEY_LEFT:
            KeyLeft();
            break;
         case KEY_ENTER:
            //Clear bottom msg
            ClearText(0, 39, 100);
            ClearRightPanel();
            ActivateButton(mButton);
            break;
         case KEY_ESC:
            isSubMenuTriggered = false;
            isMainMenuTriggered = true;
            break;
      }
   }
}

void Menu::Run()
{
   CenterWindow();
   ShowConsoleCursor(false);

   while(true)
   {
      if(isMainMenuTriggered)
      {
         MainMenu();
      }
      else if(isSubMenuTriggered)
      {
         SubMenu();
      }
      else if(isStudentListTriggered)
      {
         StudentListMenu(studentList.stdList);
      }
   }
}

void Menu::Update(int choice)
{
   if(studentList.stdList.empty())
   {
      SetColor(WHITE on BLACK);
      DisplayBotMsg("There is no student in the list to update");
      SetColor(LIGHT_GREEN on BLACK);
      return;
   }

   //cin.ignore(); is only skipped on the first run because
   //there is no cin leaving the extra newline yet
   if(mInitFlag)
   {
      cin.ignore();
   }
   if(!mInitFlag)
   {
      mInitFlag = true;
   }

   string block(35, BOTTOM_HALF_BLOCK_SYMBOL);
   int ID;
   int size = studentList.stdList.size();

   GoToXY(
         TOP_LEFT_STUDENT_INFO.x,
         TOP_LEFT_STUDENT_INFO.y + 8);
   cout << block;

   GoToXY(TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 11);
   cout << "ID of student to be updated:";

   Input(ID, 
         TOP_LEFT_STUDENT_INFO.x + 2,
         TOP_LEFT_STUDENT_INFO.y + 12, false);

   while(ID < 0 || cin.fail())
   {
      ValidateOnce("ID number cant be negative",
            ID,
            TOP_LEFT_STUDENT_INFO.x + 2,
            TOP_LEFT_STUDENT_INFO.y + 10,
            TOP_LEFT_STUDENT_INFO.x + 2,
            TOP_LEFT_STUDENT_INFO.y + 12, 1);
   }
   //Binary search WIP
   for(int i = 0; i < size; i++)
   {
      if(studentList.stdList[i].mID == ID)
      {
         //cin.ignore(); is only skipped on the first run because
         //there is no cin leaving the extra newline yet
         if(mInitFlag)
         {
            cin.ignore();
         }
         if(!mInitFlag)
         {
            mInitFlag = true;
         }

         ClearRightPanel();

         SetColor(LIGHT_RED on BLACK);

         InitForm2();
         GoToXY(
               TOP_LEFT_STUDENT_INFO.x + 6,
               TOP_LEFT_STUDENT_INFO.y + 11);
         cout << studentList.stdList[i].mID;
         GoToXY(
               TOP_LEFT_STUDENT_INFO.x + 8,
               TOP_LEFT_STUDENT_INFO.y + 16);
         cout << studentList.stdList[i].mName;
         GoToXY(
               TOP_LEFT_STUDENT_INFO.x + 9,
               TOP_LEFT_STUDENT_INFO.y + 22);
         cout << studentList.stdList[i].mBirthday.day;
         GoToXY(
               TOP_LEFT_STUDENT_INFO.x + 11,
               TOP_LEFT_STUDENT_INFO.y + 23);
         cout << studentList.stdList[i].mBirthday.month;
         GoToXY(
               TOP_LEFT_STUDENT_INFO.x + 10,
               TOP_LEFT_STUDENT_INFO.y + 24);
         cout << studentList.stdList[i].mBirthday.year;
         GoToXY(
               TOP_LEFT_STUDENT_INFO.x + 17,
               TOP_LEFT_STUDENT_INFO.y + 29);
         cout << studentList.stdList[i].mAvgScore;

         SetColor(LIGHT_GREEN on BLACK);
         string block(35, BOTTOM_HALF_BLOCK_SYMBOL);

         switch(choice)
         {
            case UPDATE_ID:
               int newID;

               GoToXY(
                     TOP_LEFT_STUDENT_INFO.x,
                     TOP_LEFT_STUDENT_INFO.y + 8);
               cout << block;
               GoToXY(
                     TOP_LEFT_STUDENT_INFO.x + 2,
                     TOP_LEFT_STUDENT_INFO.y + 11);
               cout << "ID: ";

               GoToXY(
                     TOP_LEFT_STUDENT_INFO.x + 6,
                     TOP_LEFT_STUDENT_INFO.y + 11);
               SetColor(DARK_GRAY on BLACK);
               cout << studentList.stdList[i].mID;
               SetColor(LIGHT_GREEN on BLACK);

               Input(newID,
                     TOP_LEFT_STUDENT_INFO.x + 6,
                     TOP_LEFT_STUDENT_INFO.y + 11, false);

               ValidateID(newID,
                     TOP_LEFT_STUDENT_INFO.x + 2,
                     TOP_LEFT_STUDENT_INFO.y + 10,
                     TOP_LEFT_STUDENT_INFO.x + 6,
                     TOP_LEFT_STUDENT_INFO.y + 11);
               studentList.stdList[i].mID = newID;
               DisplayBotMsg("Student's ID has been updated successfully");
               break;
            case UPDATE_NAME:
               GoToXY(
                     TOP_LEFT_STUDENT_INFO.x,
                     TOP_LEFT_STUDENT_INFO.y + 13);
               cout << block;
               GoToXY(
                     TOP_LEFT_STUDENT_INFO.x + 2,
                     TOP_LEFT_STUDENT_INFO.y + 16);
               cout << "Name:";

               GoToXY(
                     TOP_LEFT_STUDENT_INFO.x + 8,
                     TOP_LEFT_STUDENT_INFO.y + 16);
               SetColor(DARK_GRAY on BLACK);
               cout << studentList.stdList[i].mName;
               SetColor(LIGHT_GREEN on BLACK);

               //Noooo!
               EnterName(studentList.stdList[i], false);
               mInitFlag = false;
               DisplayBotMsg("Student's Name has been updated successfully");
               break;
            case UPDATE_BIRTHDAY:
               GoToXY(
                     TOP_LEFT_STUDENT_INFO.x,
                     TOP_LEFT_STUDENT_INFO.y + 18);
               cout << block;
               GoToXY(
                     TOP_LEFT_STUDENT_INFO.x + 2,
                     TOP_LEFT_STUDENT_INFO.y + 21);
               cout << "Birthday:";
               GoToXY(
                     TOP_LEFT_STUDENT_INFO.x + 4,
                     TOP_LEFT_STUDENT_INFO.y + 22);
               cout << "Day:";
               GoToXY(
                     TOP_LEFT_STUDENT_INFO.x + 4,
                     TOP_LEFT_STUDENT_INFO.y + 23);
               cout << "Month:";
               GoToXY(
                     TOP_LEFT_STUDENT_INFO.x + 4,
                     TOP_LEFT_STUDENT_INFO.y + 24);
               cout << "Year:";

               SetColor(DARK_GRAY on BLACK);
               GoToXY(
                     TOP_LEFT_STUDENT_INFO.x + 9,
                     TOP_LEFT_STUDENT_INFO.y + 22);
               cout << studentList.stdList[i].mBirthday.day;
               GoToXY(
                     TOP_LEFT_STUDENT_INFO.x + 11,
                     TOP_LEFT_STUDENT_INFO.y + 23);
               cout << studentList.stdList[i].mBirthday.month;
               GoToXY(
                     TOP_LEFT_STUDENT_INFO.x + 10,
                     TOP_LEFT_STUDENT_INFO.y + 24);
               cout << studentList.stdList[i].mBirthday.year;
               SetColor(LIGHT_GREEN on BLACK);

               EnterBirthday(studentList.stdList[i], false);
               DisplayBotMsg("Student's Birthday has been updated successfully");
               break;
            case UPDATE_SCORE:
               GoToXY(
                     TOP_LEFT_STUDENT_INFO.x,
                     TOP_LEFT_STUDENT_INFO.y + 26);
               cout << block;
               GoToXY(
                     TOP_LEFT_STUDENT_INFO.x + 2,
                     TOP_LEFT_STUDENT_INFO.y + 29);
               cout << "Average Score:";

               GoToXY(
                     TOP_LEFT_STUDENT_INFO.x + 17,
                     TOP_LEFT_STUDENT_INFO.y + 29);
               SetColor(DARK_GRAY on BLACK);
               cout << studentList.stdList[i].mAvgScore;
               SetColor(LIGHT_GREEN on BLACK);

               EnterScore(studentList.stdList[i]);
               DisplayBotMsg("Student's Score has been updated successfully");
               break;
            default:
               break;  
         }
         return;
      }
   }
   string errorMsg = "There are no students with ID " + to_string(ID);
   DisplayBotMsg(errorMsg);
}

//TODO:
// undisplay
// new student is created -> display
// dynamic help -> press any other key to cancel
