#include "Item.h"

// getter nazwy
const std::string& Item::getItemName() const {
    return m_itemName;
}

// porównanie nazwy itemków
bool Item::operator==(const Item& other) const {
    return m_itemName == other.m_itemName;
}
