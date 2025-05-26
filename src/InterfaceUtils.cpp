#include "Interface.h"

// wersja Windowsowa z użyciem conio.h
#if defined(_WIN32) || defined(_WIN64)

void Interface::gotoxy(short int x, short int y)
{
    COORD coord; // z windows.h
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Interface::drawHorizontalLine(int x, int y, int length, char ch = '-')
{
    gotoxy(x, y); // Przesunięcie kursora
    for (int i = 0; i < length; i++)
    {
        std::cout << ch; // Wypisanie znaków poziomo
    }
}

void Interface::drawVerticalLine(int x, int y, int length, char ch = '|')
{
    for (int i = 0; i < length; i++)
    {
        gotoxy(x, y + i); // Przesunięcie kursora (trzeba w pętli oraz y+i, bo cout wypisuje poziomo by default)
        std::cout << ch;  // Wypisanie jednego znaku pionowo
    }
}

void Interface::clearArea(int x, int y, int width, int height)
{
    // Na każdej wysokości (rzędzie)
    for (int i = 0; i < height; i++)
    {
        gotoxy(x, y + i);
        // Wyczyść każdą szerokość (kolumnę)
        for (int j = 0; j < width; j++)
        {
            std::cout << " ";
        }
    }
}

#endif

// wersja Linuxowa z użyciem ncurses.h
#if defined(__linux__)

Interface::Interface()
{
    // Inicjalizacja ncurses
    initscr();            // Wejście w tryb curses
    cbreak();             // Wyłączenie buforowania linii
    noecho();             // Wyłączenie echo() podczas wychwytu przycisków getch()
    keypad(stdscr, TRUE); // Strzałki etc
}

Interface::~Interface()
{
    // Zakończenie ncurses
    endwin();
}

void Interface::gotoxy(short int x, short int y)
{
    move(y, x); // Ustawienie kursora do punktu (Y,X); UWAGA!!! KOORDYNATY ZAMIENIONE KOLEJNOŚCIĄ (tak było w docsach)
    refresh();  // Odświeżenie ekranu, dopiero po nim przesuwa się kursor
}

void Interface::drawHorizontalLine(int x, int y, int length, char ch = '-')
{
    for (int i = 0; i < length; i++)
    {
        mvaddch(y, x + i, ch); // Przesunięcie kursora do punktu (Y, X+i) i wypisanie znaku
    }
    refresh(); // Odświeżenie
};

void Interface::drawVerticalLine(int x, int y, int length, char ch = '|')
{
    for (int i = 0; i < length; i++)
    {
        mvaddch(y + i, x, ch); // Przesunięcie kursora do punktu (Y+i, X) i wypisanie znaku
    }
    refresh();
}

void Interface::clearArea(int x, int y, int width, int height)
{
    // W każdym wierszu
    for (int i = 0; i < height; i++)
    {
        // I każdej kolumnie
        for (int j = 0; j < width; j++)
        {
            mvaddch(y + i, x + j, ' '); // Wyczyść znak (czyli wszystkie)
        }
    }
    refresh();
}

#endif