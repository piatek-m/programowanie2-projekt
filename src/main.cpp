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

int main()
{
    cout << "Hey! Please first input your name: ";
    string playerName;
    cin >> playerName;
    Player player("Player", 100, 100, playerName);

    Ent firstEnemy;

    /*
        Inicjalizacja interfejsu
    */
    system("cls");

    Interface::setMessageScrollOffset(0);

    // Rysowanie granic
    Interface::drawBorders();

    // Utworzenie wszystkich fragmentów UI
    Interface::updatePlayerSection(player);
    Interface::updateEnemySection(firstEnemy);
    Interface::updateInventorySection(player);
    Interface::updateControlsSection();
    Interface::updateOptionsSection(player);
    Interface::updateMessagesSection();

    // Ukrycie kursora
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    system("pause");
    return 0;
}