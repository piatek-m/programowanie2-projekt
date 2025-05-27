#include "Interface.h"
#include "Player.h"
#include "StatusEffectManager.h"
#include "StatusEffect.h"
#include "Enemy.h"

// wersja Windowsowa z użyciem conio.h
#if defined(_WIN32) || defined(_WIN64)

void Interface::updatePlayerSection(const Player &player)
{
    // Czyszczenie fragmentu okienka z wyłączeniem granic
    clearArea(1, 1, PLAYER_BOX_WIDTH, OPTIONS_BOX_HEIGHT);

    gotoxy(2, 1);
    std::cout << player.getClassName();

    gotoxy(2, 3);
    std::cout << player.getClassName() << " has " << player.getHealthPoints() << "/" << player.getMaxHEALTH() << " hp";

    gotoxy(2, 5);
    std::cout << "StatusEffects:";

    const auto effects = player.getActiveEffects();

    for (size_t i = 0; i < effects.size() && i < 5; i++)
    {
        gotoxy(2, 6 + i);
        std::cout << "- " << effects[i].getStatusEffectName() << " (" << effects[i].remainingDuration << "turns)";
    }
}

void Interface::drawBorders()
{
    {
        // Górna granica
        drawHorizontalLine(0, 0, SCREEN_WIDTH);

        // Dolna granica
        drawHorizontalLine(0, SCREEN_HEIGHT - 1, SCREEN_WIDTH);

        // Granice pionowe
        drawVerticalLine(PLAYER_BOX_WIDTH, 0, OPTIONS_BOX_HEIGHT + 1);
        drawVerticalLine(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH, 0, OPTIONS_BOX_HEIGHT + 1);
        drawVerticalLine(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH + INVENTORY_BOX_WIDTH, 0, SCREEN_HEIGHT);

        // Granica pozioma
        drawHorizontalLine(0, OPTIONS_BOX_HEIGHT, PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH + INVENTORY_BOX_WIDTH);
    }
}

void Interface::updateEnemySection(const Enemy &enemy)
{
    // Czyści obszar
    clearArea(PLAYER_BOX_WIDTH + 1, 1, ENEMY_BOX_WIDTH - 1, OPTIONS_BOX_HEIGHT - 1);

    // Jeśli enemy umarł
    if (enemy.getHealthPoints() < 0)
        return;

    gotoxy(PLAYER_BOX_WIDTH + 2, 1);
    std::cout << "MONSTER";

    gotoxy(PLAYER_BOX_WIDTH + 2, 3);
    std::cout << enemy.getClassName() << " has " << enemy.getHealthPoints() << "/" << enemy.getMaxHEALTH() << " hp";

    gotoxy(PLAYER_BOX_WIDTH + 2, 5);
    std::cout << "StatusEffects:";

    const auto effects = enemy.getActiveEffects();

    for (size_t i = 0; i < effects.size() && i < 5; i++)
    {
        gotoxy(2, 6 + i);
        std::cout << "- " << effects[i].m_effectName << " (" << effects[i].remainingDuration << "turns)";
    }
}

void Interface::updateInventorySection(const Player &player)
{
    clearArea(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH + 1, 1, INVENTORY_BOX_WIDTH - 1, OPTIONS_BOX_HEIGHT - 1);

    gotoxy(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH + 2, 1);
    std::cout << "Inventory:";

    for (size_t i = 0; i < player.getInventory().getItems().size() && i < 8; i++)
    {
        gotoxy(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH + 2, 2 + i);
        std::cout << (i + 1) << ". " << player.getInventory().getItems()[i]->getItemName();
    }
}

void Interface::updateControlsSection()
{
    gotoxy(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH + INVENTORY_BOX_WIDTH + 2, 1);
    std::cout << "Controls:";

    gotoxy(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH + INVENTORY_BOX_WIDTH + 2, 3);
    std::cout << "W/Arrow Up - option above";

    gotoxy(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH + INVENTORY_BOX_WIDTH + 2, 4);
    std::cout << "S/Arrow Down - option below";

    gotoxy(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH + INVENTORY_BOX_WIDTH + 2, 5);
    std::cout << "1-9 - select option";

    gotoxy(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH + INVENTORY_BOX_WIDTH + 2, 6);
    std::cout << "Enter - confirm selection";

    gotoxy(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH + INVENTORY_BOX_WIDTH + 2, 8);
    std::cout << "J - scroll message log up";

    gotoxy(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH + INVENTORY_BOX_WIDTH + 2, 9);
    std::cout << "K - scroll message log down";
}

void Interface::updateOptionsSection(const Player &player)
{
    clearArea(1, OPTIONS_BOX_HEIGHT + 1, PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH - 1, MESSAGE_BOX_HEIGHT - 1);

    gotoxy(2, OPTIONS_BOX_HEIGHT + 2);
    std::cout << "Options:";

    for (size_t i = 0; i <= player.getInventory().getItems().size() && i < 10; i++)
    {
        gotoxy(2, OPTIONS_BOX_HEIGHT + 3 + i);

        // dla 1 wypisuje Attack dla reszty itemki
        std::cout << "[" << (i + 1) << "]" << (i == 0) ? "Attack" : player.getInventory().getItems()[i]->getItemName();
    }
}

void Interface::updateMessagesSection()
{
    clearArea(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH + 1, OPTIONS_BOX_HEIGHT + 1, INVENTORY_BOX_WIDTH - 1, MESSAGE_BOX_HEIGHT - 1);

    gotoxy(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH + 2, OPTIONS_BOX_HEIGHT + 2);
    std::cout << "Game Log: ";

    // Show scroll indicator if there are more messages
    if (logMessages.size() > MAX_VISIBLE_MESSAGES)
    {
        std::cout << "[" << (messageScrollOffset + 1)
                  << "-"
                  << std::min(messageScrollOffset + MAX_VISIBLE_MESSAGES, (int)logMessages.size()) /* żeby nie przeskrollować więcej niż jest wiadomości XD */
                  << "/" << logMessages.size()
                  << "] J/K to scroll Up/Down";
    }

    // Dobór zakresu wiadomości do wyświetlenia
    int totalMessages = logMessages.size(); // wszystkie wiadomości w wektorze
    int startIndex, endIndex;

    if (totalMessages <= MAX_VISIBLE_MESSAGES)
    {
        // Pokaż wszystkie jeśli jest wystarczająco mało
        startIndex = 0;
        endIndex = totalMessages;
    }
    else
    {
        // Indeksy wiadomości do pokazania, bazują na offsecie scrollowania
        startIndex = messageScrollOffset;
        endIndex = std::min(startIndex + MAX_VISIBLE_MESSAGES, totalMessages) /* bounds check znowu */;
    }

    // Wypisz wiadomości w naszym dobranym wyżej zakresie
    for (int i = startIndex; i < endIndex; i++)
    {
        gotoxy(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH + 2, OPTIONS_BOX_HEIGHT + 3 + (i - startIndex));

        /* For now trunkacja za długich wiadomości, dobrze byłoby, żeby robi-
           -ło ucięcie i dokończenie w nowej linii ale narazie nie chce mi się myśleć nad tym
        */
        std::string message = logMessages[i];
        if (message.length() > INVENTORY_BOX_WIDTH - 4)
        {
            message = message.substr(0, INVENTORY_BOX_WIDTH - 7) + "...";
        }
        std::cout << message;
    }
}

void Interface::scrollMessagesUp()
{
    if (messageScrollOffset > 0)
    {
        messageScrollOffset--;
        updateMessagesSection();
    }
}

void Interface::scrollMessagesDown()
{
    int maxOffset = std::max(0, (int)logMessages.size() - MAX_VISIBLE_MESSAGES);
    if (messageScrollOffset < maxOffset)
    {
        messageScrollOffset++;
        updateMessagesSection();
    }
}

#endif

// wersja Linuxowa z użyciem ncurses.h
#if defined(__linux__)

#endif