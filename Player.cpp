#include "Player.h"
#include <iostream>
#include <algorithm>
#include "Item.h"

// getter imienia
const std::string &Player::getPlayerName() const
{
    return m_playerName;
}

// dostęp do ekwipunku
Player::Inventory &Player::getInventory()
{
    return m_inventory;
}

// dodawanie przedmiotu
void Player::Inventory::addItem(const Item &item)
{
    m_items.push_back(item);
}

// usuwanie przedmiotu
void Player::Inventory::removeItem(const Item &item)
{
    for (auto it = m_items.begin(); it != m_items.end(); ++it)
    {
        if (*it == item)
        {
            m_items.erase(it);
            break; // przerywamy po usunięciu
        }
    }
}

// sprawdzanie czy przedmiot jest w ekwipunku
bool Player::Inventory::hasItem(const Item &item) const
{
    for (const auto &i : m_items)
    {
        if (i == item)
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
        std::cout << "- " << item.getItemName() << "\n";
    }
}
