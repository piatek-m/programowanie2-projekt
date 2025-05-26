#ifndef INTERFACE_H
#define INTERFACE_H

#include "IncludeAggregator.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

// Windows
#if defined(_WIN32) || defined(_WIN64)

#include <conio.h>
#include <windows.h>

#endif

// System Unixowy
#if defined(__linux__)

#include <ncurses.h>

#endif

class Interface
{
private:
    // Wymiary konsoli
    static const int SCREEN_WIDTH = 120; // Szerokość konsoli
    static const int SCREEN_HEIGHT = 30; // Wysokość konsoli

    // Granice poszczególnych fragmentów UI
    static const int ACTION_BOX_WIDTH = SCREEN_WIDTH / 2;                         // Szerokość okna walki
    static const int ENTITY_BOX_WIDTH = ACTION_BOX_WIDTH / 2;                     // Szerokość fragmentu pojedynczego Entity (gracza lub potworka) wewnątrz okna walki (bez printowanej granicy)
    static const int INVENTORY_BOX_WIDTH = (SCREEN_WIDTH - ACTION_BOX_WIDTH) / 3; // Szerokość okna ekwipunku
    static const int CONTROLS_BOX_WIDTH = INVENTORY_BOX_WIDTH * 2;                // Szerokość okna z cheatsheetem sterowania
    static const int OPTIONS_BOX_HEIGHT = SCREEN_HEIGHT / 2;                      // Wysokość okna opcji dialogowych (i nie tylko dialogowych XD)
    static const int MESSAGE_BOX_HEIGHT = SCREEN_HEIGHT / 2;                      // Wysokość okna dzienniczka wiadomości (message log)

    // Scrollowanie dzienniczka
    int messageScrollOffset = 0;                // Do scrollowania dzienniczka wiadomości
    static const int MAX_VISIBLE_MESSAGES = 10; // Ile wiadomości widać na raz w dzienniczku

    /*
        Funkcje pomocnicze zdefiniowane w
            InterfaceUtils.cpp
    */

    // Funkcja pomocnicza ustawiająca kursor w punkcie (X,Y)
    void gotoxy(short int x, short int y);

    // Funkcja pomocnicza rysująca granicę poziomą
    void drawHorizontalLine(int x, int y, int length, char ch = '-');

    // Funkcja pomocnicza rysująca granicę pionową
    void drawVerticalLine(int x, int y, int length, char ch = '|');

    // Funkcja pomocnicza czyszcząca obszar (do czyszczenia okienek)
    void clearArea(int x, int y, int width, int height);

    // Funkcja updateująca fragment UI danego Entity (połowa ACTION_BOXa), gracza i potworków
    void updateEntitySection(std::shared_ptr<Entity> &Entity);
};

#endif