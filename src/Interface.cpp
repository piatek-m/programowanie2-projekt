#include "Interface.h"
#include "Player.h"
#include "StatusEffectManager.h"
#include "StatusEffect.h"
#include "Enemy.h"

// wersja Windowsowa z użyciem conio.h
#if defined(_WIN32) || defined(_WIN64)

int Interface::messageScrollOffset = 0;
std::vector<std::string> Interface::logMessages;

void Interface::printCentered(const std::string &text, int consoleWidth)
{
    int padding = (consoleWidth - static_cast<int>(text.length())) / 2;
    if (padding < 0)
        padding = 0;

    std::cout << std::setw(padding + text.length()) << text << std::endl;
}

void Interface::drawBorders()
{
    {
        system("cls");

        // Granice zewnętrzne
        drawHorizontalLine(0, 0, SCREEN_WIDTH, '-');                 // Górna
        drawHorizontalLine(0, SCREEN_HEIGHT - 1, SCREEN_WIDTH, '-'); // Dolna
        drawVerticalLine(0, 0, SCREEN_HEIGHT, '|');                  // Lewa
        drawVerticalLine(SCREEN_WIDTH - 1, 0, SCREEN_HEIGHT, '|');   // Prawa

        // Wewnętrzne granice pionowe
        drawVerticalLine(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH, 0, OPTIONS_BOX_HEIGHT, '|');                       // Między Enemy a Inventory
        drawVerticalLine(OPTIONS_BOX_WIDTH, OPTIONS_BOX_HEIGHT, OPTIONS_BOX_HEIGHT, '|');                       // Między Options a messageLog
        drawVerticalLine(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH + INVENTORY_BOX_WIDTH, 0, OPTIONS_BOX_HEIGHT, '|'); // Między Inventory a Controls

        // Granica pozioma po środku UI
        drawHorizontalLine(0, OPTIONS_BOX_HEIGHT, SCREEN_WIDTH, '-');

        /*
            Wypisywanie + na skrzyżowaniach
        */

        gotoxy(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH, 0); // Enemy - Inventory
        std::cout << '+';
        gotoxy(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH + INVENTORY_BOX_WIDTH, 0); // Inventory-Controls
        std::cout << '+';

        // Po środku (poziomo)
        gotoxy(0, OPTIONS_BOX_HEIGHT); // Środek-lewo
        std::cout << '+';
        gotoxy(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH, OPTIONS_BOX_HEIGHT); // Monster - Inventory
        std::cout << '+';
        gotoxy(OPTIONS_BOX_WIDTH, OPTIONS_BOX_HEIGHT); // Options - MessageLog
        std::cout << '+';
        gotoxy(PLAYER_BOX_WIDTH + ENEMY_BOX_WIDTH + INVENTORY_BOX_WIDTH, OPTIONS_BOX_HEIGHT); // Inventory-Controls
        std::cout << '+';
        gotoxy(SCREEN_WIDTH - 1, OPTIONS_BOX_HEIGHT); // Środek-prawo
        std::cout << '+';

        // Dolne
        gotoxy(0, SCREEN_HEIGHT - 1); // Dół-lewo
        std::cout << '+';
        gotoxy(OPTIONS_BOX_WIDTH, SCREEN_HEIGHT - 1); // Options - MessageLog
        std::cout << '+';
        gotoxy(SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1); // Dół-prawo
        std::cout << '+';

        gotoxy(0, 0); // Góra-lewo
        std::cout << '+';
        gotoxy(SCREEN_WIDTH - 1, 0); // Góra - prawo
        std::cout << '+';
    }
}

void Interface::updatePlayerSection(const Player &player)
{
    // Czyszczenie fragmentu okienka z wyłączeniem granic
    clearArea(1, 1, PLAYER_BOX_WIDTH - 1, OPTIONS_BOX_HEIGHT - 1);

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

void Interface::clearEnemyArea()
{
    clearArea(PLAYER_BOX_WIDTH + 1, 1, ENEMY_BOX_WIDTH - 1, OPTIONS_BOX_HEIGHT - 1);
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
        std::cout << "- " << effects[i].getStatusEffectName() << " (" << effects[i].remainingDuration << "turns)";
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
    gotoxy(ACTION_BOX_WIDTH + INVENTORY_BOX_WIDTH + 2, 1);
    std::cout << "Controls:";

    gotoxy(ACTION_BOX_WIDTH + INVENTORY_BOX_WIDTH + 2, 3);
    std::cout << "W/Arrow Up - option above";

    gotoxy(ACTION_BOX_WIDTH + INVENTORY_BOX_WIDTH + 2, 4);
    std::cout << "S/Arrow Down - option below";

    gotoxy(ACTION_BOX_WIDTH + INVENTORY_BOX_WIDTH + 2, 5);
    std::cout << "1-9 - select option";

    gotoxy(ACTION_BOX_WIDTH + INVENTORY_BOX_WIDTH + 2, 6);
    std::cout << "Enter - confirm selection";

    gotoxy(ACTION_BOX_WIDTH + INVENTORY_BOX_WIDTH + 2, 8);
    std::cout << "J - scroll message log up";

    gotoxy(ACTION_BOX_WIDTH + INVENTORY_BOX_WIDTH + 2, 9);
    std::cout << "K - scroll message log down";
}

void Interface::updateOptionsSection(const Player &player)
{
    clearArea(1, OPTIONS_BOX_HEIGHT + 1, OPTIONS_BOX_WIDTH - 2, OPTIONS_BOX_HEIGHT - 2);

    gotoxy(2, OPTIONS_BOX_HEIGHT + 2);
    std::cout << "Actions:";

    for (size_t i = 0; i <= player.getInventory().getItems().size() && i < 10; i++)
    {
        gotoxy(2, OPTIONS_BOX_HEIGHT + 3 + i + 1);

        // dla 1 wypisuje Attack dla reszty itemki
        std::cout << "[" << (i + 1) << "] " << ((i == 0) ? "Attack" : "Use " + player.getInventory().getItems()[i]->getItemName());
    }
}

void Interface::updateMessagesSection()
{
    clearArea(OPTIONS_BOX_WIDTH + 1, OPTIONS_BOX_HEIGHT + 1, MESSAGE_BOX_WIDTH - 2, MESSAGE_BOX_HEIGHT - 2);

    gotoxy(OPTIONS_BOX_WIDTH + 2, OPTIONS_BOX_HEIGHT + 2);
    std::cout << "Game Log: ";

    // Show scroll indicator if there are more messages
    if (logMessages.size() > MAX_VISIBLE_MESSAGES)
    {
        std::cout << "[" << (messageScrollOffset + 1)
                  << "-"
                  << std::min(messageScrollOffset + MAX_VISIBLE_MESSAGES, (int)logMessages.size()) /* żeby nie przeskrollować więcej niż jest wiadomości XD */
                  << "/" << logMessages.size()
                  << "]";
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
        int displayLine = MESSAGE_BOX_HEIGHT + 3 + 2 * (i - startIndex); // *2 -> co drugą linię wypisuje wiadomość
        gotoxy(OPTIONS_BOX_WIDTH + 2, displayLine);

        /* For now trunkacja za długich wiadomości, dobrze byłoby, żeby robi-
           -ło ucięcie i dokończenie w nowej linii ale narazie nie chce mi się myśleć nad tym
        */
        std::string message = logMessages[i];
        if (message.length() > MESSAGE_BOX_WIDTH - 4)
        {
            message = message.substr(0, MESSAGE_BOX_WIDTH - 7) + "...";
        }
        std::cout << "> " << message;
    }
}

void Interface::addLogMessage(std::string message)
{
    Interface::logMessages.push_back(message);
    // autoscroll
    int totalMessages = logMessages.size();
    if (totalMessages > MAX_VISIBLE_MESSAGES)
    {
        messageScrollOffset = totalMessages - MAX_VISIBLE_MESSAGES;
    }
    else
    {
        messageScrollOffset = 0;
    }

    Interface::updateMessagesSection();
}

std::vector<std::string> Interface::getLogMessages()
{
    return Interface::logMessages;
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