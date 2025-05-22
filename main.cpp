// #include "Entity.h"
// #include "Player.h"
// #include "EnemyAggregator.h"
#include <iostream>

// include Windowsowy
#if defined(_WIN32) || defined(_WIN64)
#include <conio.h>
#endif

// include Linuxowy
#if defined(__linux__) || defined(__APPLE__)
#include <ncurses.h>
#endif

using namespace std;

int main()
{
    // wersja linuxowa
    initscr();            // Start curses mode
    keypad(stdscr, TRUE); // Enable arrow keys and function keys
    noecho();             // Do not print input chars
    cbreak();             // Disable line buffering

    int c;

    while (1)
    {
        c = getch();

        switch (c)
        {
        case KEY_UP:
            printw("Up\n");
            break;
        case KEY_DOWN:
            printw("Down\n");
            break;
        case KEY_LEFT:
            printw("Left\n");
            break;
        case KEY_RIGHT:
            printw("Right\n");
            break;
        case 'q':     // Exit on 'q' key
            endwin(); // Restore terminal settings
            return 0;
        default:
            printw("Not arrow: %c\n", c);
            break;
        }

        refresh(); // Print to screen
    }

    endwin(); // Should not be reached, but good practice
    return 0;
}