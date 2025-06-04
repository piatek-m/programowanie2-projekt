#include "Item.h"
#include <stdexcept>

// getter nazwy
const std::string &Item::getItemName() const
{
    return m_itemName;
}

// porównanie nazwy itemków
bool Item::operator==(const Item &other) const
{
    return m_itemName == other.m_itemName;
}

void Item::useItem(Player &player)
{
    throw std::logic_error("This item cannot be used on the player.");
}