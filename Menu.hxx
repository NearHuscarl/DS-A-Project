#ifndef MENU_HXX
#define MENU_HXX

#include "Menu.h"

template <typename T>
void Menu::Input(T &input, int x, int y, bool ignoreFlag)
{
   GoToXY(x, y);
   
   if(ignoreFlag)
   {
      cin.ignore();
   }

   ShowConsoleCursor(true);
   SetColor(LIGHT_CYAN on BLACK);
   cin >> noskipws >> input;
   SetColor(LIGHT_GREEN on BLACK);
   ShowConsoleCursor(false);
}

#endif //MENU_HXX 
