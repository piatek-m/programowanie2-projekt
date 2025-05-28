#ifndef INTERFACE_H
#define INTERFACE_H

// #include "Entity.h"
// #include "Player.h" -> przeniesione do Interface.cpp
class Player;
// #include "Enemy.h" -> przeniesione do Interface.cpp
class Enemy;

#include <format> // wypisywanie
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <memory>

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
    static const int ACTION_BOX_WIDTH = SCREEN_WIDTH / 2;                                        // Szerokość okna walki
    static const int PLAYER_BOX_WIDTH = ACTION_BOX_WIDTH / 2;                                    // Szerokość fragmentu gracza wewnątrz okna walki (bez printowanej granicy)
    static const int ENEMY_BOX_WIDTH = ACTION_BOX_WIDTH / 2;                                     // Szerokość fragmentu potworka wewnątrz okna walki (bez printowanej granicy)
    static const int INVENTORY_BOX_WIDTH = ((SCREEN_WIDTH - ACTION_BOX_WIDTH) / 5) * 2;          // Szerokość okna ekwipunku
    static const int CONTROLS_BOX_WIDTH = SCREEN_WIDTH - ACTION_BOX_WIDTH - INVENTORY_BOX_WIDTH; // Szerokość okna z cheatsheetem sterowania
    static const int OPTIONS_BOX_WIDTH = (SCREEN_WIDTH / 5) * 2;                                 // Szerokość okna dialogowego
    static const int OPTIONS_BOX_HEIGHT = SCREEN_HEIGHT / 2;                                     // Wysokość okna opcji dialogowych (i nie tylko dialogowych XD)
    static const int MESSAGE_BOX_WIDTH = SCREEN_WIDTH - OPTIONS_BOX_WIDTH;                       // Szerokość okna dzienniczka
    static const int MESSAGE_BOX_HEIGHT = SCREEN_HEIGHT / 2;                                     // Wysokość okna dzienniczka wiadomości (message log)

    // Scrollowanie dzienniczka
    static int messageScrollOffset;                                       // Offset do scrollowania dzienniczka wiadomości
    static const int MAX_VISIBLE_MESSAGES = (MESSAGE_BOX_HEIGHT - 3) / 2; // Ile wiadomości widać na raz w dzienniczku
    static std::vector<std::string> logMessages;                          // Wiadomości w dzienniczku

    /*
        Funkcje pomocnicze zdefiniowane w
            InterfaceUtils.cpp
    */

    // Funkcja pomocnicza ustawiająca kursor w punkcie (X,Y)
    static void gotoxy(short int x, short int y);

    // Funkcja pomocnicza rysująca granicę poziomą
    static void drawHorizontalLine(int x, int y, int length, char ch = '-');

    // Funkcja pomocnicza rysująca granicę pionową
    static void drawVerticalLine(int x, int y, int length, char ch = '|');

    // Funkcja pomocnicza czyszcząca obszar (do czyszczenia okienek)
    static void clearArea(int x, int y, int width, int height);

public:
    /*
        Funkcje zdefiniowane
            w Interface.cpp
    */

    static void printCentered(const std::string &text, int consoleWidth = SCREEN_WIDTH);

    // Funkcja updateująca fragment UI Gracza
    static void updatePlayerSection(const Player &player);

    // Updateuje fragment UI Enemy
    static void updateEnemySection(const Enemy &enemy);

    static void clearEnemyArea();

    // Update fragmentu UI Inventory
    static void updateInventorySection(const Player &player);

    // Update boxa sterowania
    static void updateControlsSection();

    // Update boxa opcji dialogowych
    static void updateOptionsSection(const Player &player);

    // Update okienka dzienniczka
    static void updateMessagesSection();

    // Dodaje wiadomość do wektora dzienniczka
    static void addLogMessage(std::string message);

    // Getter wektora dzienniczka
    static std::vector<std::string> getLogMessages();

    // Tworzy granice UI
    static void drawBorders();

    /*
        Funkcje scrollujące wiadomości w dzienniczku
    */
    static void scrollMessagesUp();

    static void scrollMessagesDown();

    // ustawienie messageScrollOffset, zmienna jest static i prywatna wiec nie da sie w klasie zdefiniować wartości, ani zmienić ręcznie poza nią
    static void setMessageScrollOffset(int messScrlOffset)
    {
        messageScrollOffset = messScrlOffset;
    }
};

#endif