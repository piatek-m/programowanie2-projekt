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

using namespace std;
using UI = Interface;

// enum odpowiadajcy za tury
enum class TurnState
{
    PLAYER_TURN,
    ENEMY_TURN
};

struct GameOverException : std::exception
{
};

// funkcja wypisujaca gameover
void gameOver()
{
    system("cls");
    UI::gotoxy(0, (UI::getScreenHeight() / 2) - 1);
    UI::Pause("\e[31mG A M E   O V E R !\e[0m", TextAlign::Center, false);
    throw GameOverException{};
};

// funkcja implementujaca tury w walce
void Combat(Player &player, std::unique_ptr<Enemy> &enemy, mt19937 &gen);

int main()
{
    try
    {
        random_device rd;  // losowy seed
        mt19937 gen(rd()); // randomizująca zmienna do przesyłania do funkcji

        // Ukrycie kursora
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
        cursorInfo.bVisible = false;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

        // wprowadzenie
        UI::gotoxy(4, 0);
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
        Player player("Player", 95, 100, playerName);

        system("cls");

        cout << "\n\n\n";
        UI::printCentered("You suddenly wake up in a strange forest.");
        UI::printCentered("Your memory is like a fog.");
        UI::printCentered("As you try to grasp your surroundings you see a small tree walking towards you!");
        UI::printCentered("It doesn't seem very friendly... Time to fight for your life!\n\n\n");

        Interface::Pause("[ \e[33mPress Enter to continue \e[0m]", TextAlign::Center, false);

        std::unique_ptr<Enemy> enemy = std::make_unique<Ent>();

        /*
            Inicjalizacja interfejsu
        */
        system("cls");

        UI::setMessageScrollOffset(0);

        // Rysowanie granic
        UI::drawBorders();

        // Utworzenie wszystkich fragmentów UI

        UI::updatePlayerSection(player);
        UI::updateEnemySection(*enemy);
        UI::updateInventorySection(player);
        UI::updateControlsSection();
        UI::updateOptionsSection(player);
        UI::updateMessagesSection();

        UI::addLogMessage("[ Welcome to our game! ]");
        UI::addLogMessage("[ You can look up controls in the upper right section. ]");
        UI::addLogMessage("[ Now go and cut that tree down! ]");
        UI::addLogMessage("[ \e[33mPress Enter to continue\e[0m ]");

        Interface::Pause();

        Combat(player, enemy, gen);
        enemy.reset();

        // otrzymanie latarki
        UI::addLogMessage("\e[1mLet the bullets hit me! What on earth was that?!\e[0m");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("\e[1mAh, whatever. I should start looking for a way out of here.\e[0m");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("You take a quick look around your surroundings again.");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("You notice a flashlight lying nearby.");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("You pick it up. Maybe it's yours.");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        player.getInventory().addItem(std::make_shared<LightItem>());
        UI::addLogMessage("Maybe you just forgot about it when you lost concioussnes. Maybe.");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("Or maybe it's not yours? You don't really care at this moment.");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("A W-A-L-K-I-N-G-T-R-E-E tried to kill you just now, no ? ");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("\e[1mWait... No... Surely there's no way...\e[0m");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();

        // druga walka - z Eyesore
        std::unique_ptr<Enemy> boloOczy = std::make_unique<Eyesore>("Eyesore", 15);
        UI::addLogMessage("\e[31mAARGHH!! My EYESS hUrtt sO bADly...\e[0m");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("\e[31m... who... ARE YOU?!!!\e[0m");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::updateEnemySection(*boloOczy);

        Combat(player, boloOczy, gen);
        boloOczy.reset();

        // otrzymanie zapałek
        UI::addLogMessage("A pack of matchsticks falls out of the creature's...");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("...eye socket? Anyway, you pick it up.");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        player.getInventory().addItem(std::make_shared<FireItem>());
        UI::addLogMessage("Are we camping now or what?");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();

        // Icepicker wprowadzzenie
        UI::addLogMessage("Suddenly it gets really cold.");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("Like, REALLY cold.Your nose starts running.");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage(" \e[1mA-psik!\e[0m");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("\e[36mHey!\e[0m");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("\e[36mCareful with the sneezing! You're spreading germs here!\e[0m");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();

        // icepicker walka
        std::unique_ptr<Enemy> icepicker = std::make_unique<IcepickerPhase1>();
        UI::updateEnemySection(*icepicker);

        Combat(player, icepicker, gen);
        icepicker.reset();

        // potka leczenia : tu już dalem Claudowi zeby fabule uzupelnil patrzac na moje poprzednie wypociny
        UI::addLogMessage("The ice melts, revealing... a fancy red potion!");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();

        player.getInventory().addItem(std::make_shared<HealingItem>());
        UI::updateInventorySection(player);

        UI::addLogMessage("You pocket the suspicious red liquid. Bottoms up later...");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("Suddenly, a creepy voice whispers from the shadows...");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("\e[35mPsst... hey kid... wanna buy some... DEATH?\e[0m");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("A sketchy hooded figure emerges. Wait, is that...");
        UI::addLogMessage("...a vampire MLM salesman?");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("\e[35mI'm the Lifestealer! I heal myself by draining YOU!\e[0m");
        UI::addLogMessage("\e[35mA win-lose situation!\e[0m");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();

        // walka z lifestealeremm
        std::unique_ptr<Enemy> lifestealer = std::make_unique<Lifestealer>();
        UI::updateEnemySection(*lifestealer);

        Combat(player, lifestealer, gen);
        lifestealer.reset();

        // After defeating Lifestealer
        UI::addLogMessage("The Lifestealer dramatically clutches his chest...");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("\e[35m\"My business model... ruined!\"\e[0m");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("He dissolves into black goo. Ew. At least he's biodegradable?");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();

        // Victory and mysterious ending
        UI::addLogMessage("As the goo evaporates, you notice the forest is suddenly... quiet.");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("Too quiet. Like, horror-movie-before-the-jumpscare quiet.");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("But then you see it - a path leading out of the forest!");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("You sprint toward freedom, your flashlight bouncing with each step.");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("Finally! You emerge into... wait...");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("...is this the same clearing you started in?");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("Your memory is still foggy, but one thing is clear:");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("You're definitely not in Kansas anymore, " + player.getPlayerName() + ".");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();

        // Mysterious ending
        UI::addLogMessage("As you catch your breath, you hear rustling behind you...");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("You turn around slowly, and in the moonlight you see...");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("...absolutely nothing. Just trees. Normal, non-walking trees.");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("But then you notice your reflection in a nearby puddle...");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("Your eyes... they're glowing with a \e[32mfaint green light\e[0m.");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();
        UI::addLogMessage("\e[32mWelcome to the family, " + player.getPlayerName() + "...\e[0m");
        UI::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        UI::Pause();

        // Final congratulations screen
        system("cls");
        UI::gotoxy(0, 8);
        UI::printCentered("\e[33m+--------------------------+\e[0m");
        UI::gotoxy(0, 9);
        UI::printCentered("\e[33m|                          |\e[0m");
        UI::gotoxy(0, 10);
        UI::printCentered("\e[33m|    C O N G R A T S !     |\e[0m");
        UI::gotoxy(0, 11);
        UI::printCentered("\e[33m|                          |\e[0m");
        UI::gotoxy(0, 12);
        UI::printCentered("\e[33m|    You survived... or    |\e[0m");
        UI::gotoxy(0, 13);
        UI::printCentered("\e[33m|       did you?           |\e[0m");
        UI::gotoxy(0, 14);
        UI::printCentered("\e[33m|                          |\e[0m");
        UI::gotoxy(0, 15);
        UI::printCentered("\e[33m|   Thanks for playing!    |\e[0m");
        UI::gotoxy(0, 16);
        UI::printCentered("\e[33m|                          |\e[0m");
        UI::gotoxy(0, 17);
        UI::printCentered("\e[33m+--------------------------+\e[0m");

        cout << "\n\n\n";
        UI::printCentered("[ Press Enter to exit ]");
        cin.ignore();
        cin.get();
    }
    catch (const GameOverException &)
    {
        return 0;
    }
}

void Combat(Player &player, unique_ptr<Enemy> &enemy, mt19937 &gen)
{
    TurnState currentTurn = TurnState::ENEMY_TURN; // zaczynamy od tury przeciwnika
    while (player.getHealthPoints() > 0 && enemy->getHealthPoints() > 0)
    {
        if (currentTurn == TurnState::PLAYER_TURN)
        {
            if (player.getHealthPoints() <= 0)
                break;

            player.getPlayerChoice(*enemy, gen); // wybor akcji
            currentTurn = TurnState::ENEMY_TURN; // po zakonczeniu tury przeruca na ture enemy

            // przejscie icepickera na faze 2
            IcepickerPhase1 *icepicker = dynamic_cast<IcepickerPhase1 *>(enemy.get()); // dynamic cast downcastuje enemy na IcepickerPhase1 i zwraca wskaznik do niego, jak sie nie da to zwraca nullptr
            if (icepicker != nullptr)
            {
                // zwraca icepickerPhase2 jesli ma ponizej 20 hp
                if (icepicker->needsPhaseChange())
                {
                    enemy = icepicker->phaseChange();
                    UI::updateEnemySection(*enemy);
                }
            }

            currentTurn = TurnState::ENEMY_TURN;
            player.endTurnActions(); // rzeczy do wykonania na poczatku tury np. skrocenie remainingDuration efektow
        }
        else if (currentTurn == TurnState::ENEMY_TURN)
        {
            if (enemy->getHealthPoints() <= 0)
                break;

            enemy->attack(player, gen);           // enemy jedyne co robi to atakuje
            currentTurn = TurnState::PLAYER_TURN; // po zakonczeniu przerzuca na ture enemy
            enemy->endTurnActions();
        }
    }
    if (player.getHealthPoints() <= 0)
    {
        gameOver();
    }
    else if (enemy->getHealthPoints() <= 0)
    {
        UI::addLogMessage(std::format("{} has been slain!", enemy->getClassName()));
        UI::clearEnemyArea();
    }
}