#include "Player.h"
#include <algorithm>

// getter imienia
const std::string &Player::getPlayerName() const
{
    return m_playerName;
}

const std::string &Player::getClassName() const
{
    return Player::getPlayerName();
}

// dostęp do ekwipunku
Player::Inventory &Player::getInventory()
{
    return m_inventory;
}

// dodawanie przedmiotu
void Player::Inventory::addItem(const std::shared_ptr<Item> &item)
{
    m_items.push_back(item);
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
