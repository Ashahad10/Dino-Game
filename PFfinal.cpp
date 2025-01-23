#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(unsigned int mseconds) {
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void getup() {
    system("cls");
    gotoxy(10, 2);
    std::cout << "Press X to Exit, Press Space to Jump";
    gotoxy(62, 2);
    std::cout << "SCORE : ";
    gotoxy(1, 25);
    for (int x = 0; x < 79; x++)
        std::cout << "ß";
}

int t, speed = 40;

void ds(int jump = 0) {
    static int a = 1;

    if (jump == 0)
        t = 0;
    else if (jump == 2)
        t--;
    else
        t++;

    gotoxy(2, 15 - t);
    std::cout << "                 ";
    gotoxy(2, 16 - t);
    std::cout << "         ÜÛßÛÛÛÛÜ";
    gotoxy(2, 17 - t);
    std::cout << "         ÛÛÛÛÛÛÛÛ";
    gotoxy(2, 18 - t);
    std::cout << "         ÛÛÛÛÛßßß";
    gotoxy(2, 19 - t);
    std::cout << " Û      ÜÛÛÛÛßßß ";
    gotoxy(2, 20 - t);
    std::cout << " ÛÛÜ  ÜÛÛÛÛÛÛÜÜÜ ";
    gotoxy(2, 21 - t);
    std::cout << " ßÛÛÛÛÛÛÛÛÛÛÛ  ß ";
    gotoxy(2, 22 - t);
    std::cout << "   ßÛÛÛÛÛÛÛß     ";
    gotoxy(2, 23 - t);
    if (jump == 1 || jump == 2) {
        std::cout << "    ÛÛß ßÛ       ";
        gotoxy(2, 24 - t);
        std::cout << "    ÛÜ   ÛÜ      ";
    } else if (a == 1) {
        std::cout << "    ßÛÛß  ßßß    ";
        gotoxy(2, 24 - t);
        std::cout << "      ÛÜ         ";
        a = 2;
    } else if (a == 2) {
        std::cout << "     ßÛÜ ßÛ      ";
        gotoxy(2, 24 - t);
        std::cout << "          ÛÜ     ";
        a = 1;
    }
    gotoxy(2, 25 - t);
    if (jump != 0) {
        std::cout << "                ";
    } else {
        std::cout << "ßßßßßßßßßßßßßßßßß";
    } 
    delay(speed);
}

void obj() {
    static int x = 0, scr = 0; 
    if (x == 56 && t < 4) {
        scr = 0;
        speed = 40;
        gotoxy(36, 8);
        std::cout << "Game Over";
        _getch();
        gotoxy(36, 8);
        std::cout << "         ";
    }
    
    gotoxy(74 - x, 20);
    std::cout << "Û    Û ";
    gotoxy(74 - x, 21);
    std::cout << "Û    Û ";
    gotoxy(74 - x, 22);
    std::cout << "ÛÜÜÜÜÛ ";
    gotoxy(74 - x, 23);
    std::cout << "  Û    ";
    gotoxy(74 - x, 24);
    std::cout << "  Û  ";
    x++;
    
    if (x == 73) {
        x = 0;
        scr++;
        gotoxy(70, 2);
        std::cout << "     ";
        gotoxy(70, 2);
        std::cout << scr;
        if (speed > 20)
            speed--;
    }
}

int main() {
    system("mode con: lines=29 cols=82");
    char ch;
    int i;
    getup();
    while (true) {
        while (!_kbhit()) {
            ds();
            obj();
        }
        ch = _getch();
        if (ch == ' ') {
            for (i = 0; i < 10; i++) {
                ds(1);
                obj();
            }
            for (i = 0; i < 10; i++) {
                ds(2);
                obj();
            }
        } else if (ch == 'x') {
            return 0;
        }
    }
}

