#include "Interface.h"
#include "IncludeAggregator.h"

// wersja Windowsowa z użyciem conio.h
#if defined(_WIN32) || defined(_WIN64)

void Interface::updateEntitySection(std::shared_ptr<Entity> &Entity)
{
    // Czyszczenie fragmentu okienka z wyłączeniem granic
    clearArea(1, 1, ENTITY_BOX_WIDTH, OPTIONS_BOX_HEIGHT);

    gotoxy(2, 1);
    std::cout << Entity->getClassName();

    gotoxy(2, 3);
    std::cout << Entity->getClassName() << " has " << Entity->getHealthPoints() << "/" << Entity->getMaxHEALTH() << " hp";

    gotoxy(2, 5);
    std::cout << "StatusEffects:";

    const auto effects = Entity->getActiveEffects();

    for (size_t i = 0; i < effects.size() && i < 5; i++)
    {
        gotoxy(2, 6 + i);
        std::cout << "- " << effects[i].m_effectName << " (" << effects[i].remainingDuration << "turns)";
    }
}

#endif

// wersja Linuxowa z użyciem ncurses.h
#if defined(__linux__)

#endif