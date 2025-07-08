#ifndef __CONSOLE__H__
#define __CONSOLE__H__

#include <windows.h>
#include <iostream>

class console {
private:
    CONSOLE_SCREEN_BUFFER_INFO csbi;

public:
    console() {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        this->csbi = csbi;
    }

    int getConsoleHeight(){return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;}
    int getConsoleWidth(){return csbi.srWindow.Right - csbi.srWindow.Left + 1;}
    void clearConsole() {system("cls");}

    void PrintToXY(int x, int y, char content){
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        std::cout << content;
    }
}; 

#endif 
