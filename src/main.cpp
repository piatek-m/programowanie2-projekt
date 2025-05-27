#include "Interface.h"
#include "Entity.h"
#include "Player.h"

#include "StatusEffect.h"
#include "StatusEffectManager.h"

#include "Enemy.h"
#include "Ent.h"
#include "Eyesore.h"
#include "Icepicker.h"
#include "IcepickerPhase1.h"
#include "IcepickerPhase2.h"
#include "Lifestealer.h"

#include "Item.h"
#include "HealingItem.h"
#include "StatusEffectItem.h"
#include "LightItem.h"
#include "FireItem.h"

// no chyba iostream jest już included XD

using namespace std;
using UI = Interface;

void gameOver()
{
    Sleep(2000);
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n"
         << right << setw(60) << "GAME OVER!";
    Sleep(2000);
};

int main()
{
    random_device rd;  // losowy seed
    mt19937 gen(rd()); // randomizująca zmienna do przesyłania do funkcji

    cout << "\n\n\n";
    UI::printCentered("Hey!\n\n");
    UI::printCentered("The recommended Command Prompt size for this \"game\" is 120x30.");
    UI::printCentered("On Windows 10 you can change the window size by:");
    UI::printCentered("- right clicking on the window bar -");
    UI::printCentered("- then clicking the \"Layout\" tab -");
    UI::printCentered("- in the middle you should be seeing the \"Window Size\" section -");
    cout << "\n\n\n";
    UI::printCentered("Now, please input your character's name: ");

    string playerName;
    cin >> playerName;
    Player player("Player", 100, 100, playerName);

    system("cls");

    cout << "\n\n\n";
    UI::printCentered("You suddenly wake up in a strange forest.");
    UI::printCentered("Your memory is like a fog.");
    UI::printCentered("As you try to grasp your surroundings you see a small tree walking towards you!");
    UI::printCentered("It doesn't seem very friendly... Time to fight for your life!\n\n\n");

    system("pause");

    Ent firstEnemy;

    /*
    Inicjalizacja interfejsu
*/
    system("cls");

    UI::setMessageScrollOffset(0);

    // Rysowanie granic
    UI::drawBorders();

    // Utworzenie wszystkich fragmentów UI

    UI::updatePlayerSection(player);
    UI::updateEnemySection(firstEnemy);
    UI::updateInventorySection(player);
    UI::updateControlsSection();
    UI::updateOptionsSection(player);
    UI::updateMessagesSection();

    // Ukrycie kursora
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    UI::addLogMessage("Welcome to our game!");
    UI::addLogMessage("You can look up controls in the upper right section.");
    UI::addLogMessage("Now go and cut that tree down!     ");

    system("pause");

    // pierwsza walka z przeciwnikiem - Entem
    while (firstEnemy.getHealthPoints() > 0)
    {
        firstEnemy.attack(player, gen);
        if (player.getHealthPoints() <= 0)
        {
            gameOver();
            return 0;
        }
        player.getPlayerChoice(firstEnemy, gen);
    }
    UI::addLogMessage("Ent pokonany!");
    UI::clearEnemyArea();

    system("pause");
    return 0;
}