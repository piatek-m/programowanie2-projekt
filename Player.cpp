#include "Player.h"
#include <iostream>
#include <algorithm>

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
void Player::Inventory::addItem(const std::string &item)
{
    m_items.push_back(item);
}

// usuwanie przedmiotu
void Player::Inventory::removeItem(const std::string &item)
{
    auto it = std::find(m_items.begin(), m_items.end(), item);
    if (it != m_items.end())
    {
        m_items.erase(it);
    }
}

// sprawdzanie czy przedmiot jest w ekwipunku
bool Player::Inventory::hasItem(const std::string &item) const
{
    return std::find(m_items.begin(), m_items.end(), item) != m_items.end();
}

// wypisanie wszystkich przedmiotów
void Player::Inventory::listItems() const
{
    std::cout << "Inventory items:\n";
    for (const auto &item : m_items)
    {
        std::cout << "- " << item << "\n";
    }
}
