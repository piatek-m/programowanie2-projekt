#include "Player.h"
#include "Entity.h"
#include "Interface.h"
#include "Enemy.h"

#include <algorithm>
#include <random> // std::mt19937

// getter imienia
const std::string &Player::getPlayerName() const
{
    return m_playerName;
}
// getter klasy
const std::string &Player::getClassName() const
{
    return Player::getPlayerName();
}

// atak symulujacy podwojny rzut kostka 1d6
int Player::attack(Enemy &target, std::mt19937 &gen)
{
    std::uniform_int_distribution<> dice(1, 6);
    int firstRoll = dice(gen);

    Interface::addLogMessage("To hit the enemy you must roll at least 3.");
    Interface::updateMessagesSection();
    std::string message = std::format("You rolled: {}.", firstRoll);
    Interface::addLogMessage(message);

    if (firstRoll >= 3)
    {
        Interface::addLogMessage("Rolling damage dice...     ");
        system("pause");

        int secondRoll = dice(gen);

        target.takeDamage(secondRoll);

        message = std::format("You hit the enemy for {} damage!", secondRoll);
        Interface::addLogMessage(message);
        Interface::updateEnemySection(target);
        return secondRoll;
    }
    else
    {
        Interface::addLogMessage("You missed the enemy :c");
        return 0;
    }
}

void Player::takeDamage(int damage)
{
    Entity::takeDamage(damage);
    Interface::updatePlayerSection(*this);
}

// dostęp do ekwipunku BEZ MODYFIKACJI
const Player::Inventory &Player::getInventory() const
{
    return m_inventory;
}

// dostęp do ekwipunku z modifykacjami
Player::Inventory &Player::getInventory()
{
    return m_inventory;
}

// dodawanie przedmiotu
void Player::Inventory::addItem(const std::shared_ptr<Item> &item)
{
    m_items.push_back(item);
    Interface::updateInventorySection(*m_owner);
    Interface::updateOptionsSection(*m_owner);
}

// usuwanie przedmiotu
void Player::Inventory::removeItem(const std::shared_ptr<Item> &item)
{
    for (auto it = m_items.begin(); it != m_items.end(); ++it)
    {
        // UWAGA! sprawdza czy obiekt ma taką samą nazwę (czy jest TAKI sam), a nie czy jest TEN sam! (*it == item)
        // jeśli sprawdzałoby, czy jest TEN sam to usunęło by tylko jeśli ADRES BYŁBY TAKI SAM.
        if (**it == *item)
        {
            m_items.erase(it);
            Interface::updateInventorySection(*m_owner);
            Interface::updateOptionsSection(*m_owner);
            break; // przerywamy po usunięciu (czyli usunie tylko 1 item danego typu!)
        }
    }
}

// sprawdzanie czy przedmiot jest w ekwipunku
bool Player::Inventory::hasItem(const std::shared_ptr<Item> &item) const
{
    for (const auto &i : m_items)
    {
        if (*i == *item)
        {
            return true;
        }
    }
    return false;
}

// wypisanie wszystkich przedmiotów
void Player::Inventory::listItems() const
{
    std::cout << "Inventory items:\n";
    for (const auto &item : m_items)
    {
        std::cout << "- " << item->getItemName() << "\n";
    }
}

std::vector<std::shared_ptr<Item>> Player::Inventory::getItems() const
{
    return m_items;
}

// bierze decyzję gracza i jeśli kliknięto odpowiedni przycisk to wykonuje daną akcję (atakuje wroga, używa przedmiotu)
void Player::getPlayerChoice(Enemy &target, std::mt19937 &gen)
{
    char input;
    while (true)
    {
        input = _getch();

        // Scrollowanie dzienniczka
        if (input == 'j' || input == 'J')
        {
            Interface::scrollMessagesUp();
            continue; // scrollowanie nie przerywa
        }

        if (input == 'k' || input == 'K')
        {
            Interface::scrollMessagesDown();
            continue; // scrollowanie nie przerywa
        }

        // Przyciski 1-9: wybór opcji dialogowych
        if (input >= '1' && input <= '9')
        {
            int choice = input - '0';

            if (choice == 1)
            {
                this->attack(target, gen);
                return;
            }
            else if (choice >= 2)
            {
                int index = choice - 2; // zamiana na index zaczynający od 0

                const auto &items = this->getInventory().getItems();

                if (index < items.size())
                {
                    if (items[index]->getItemName() == "Healing")
                    {
                        items[index]->useItem(*this);
                        return;
                    }
                    items[index]->useItem(target);
                }
            }
        }

        // W, S, Strzałki w górę, w dół
        if (input == 27)
        {             // ESC key sequence
            _getch(); // Skip [
            char arrow = _getch();
            // Handle arrow keys if needed
        }

        // Handle Enter
        if (input == 13)
        {
            return;
        }
    }
}