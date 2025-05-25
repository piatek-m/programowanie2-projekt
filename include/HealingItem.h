#ifndef HEALING_ITEM_H
#define HEALING_ITEM_H

#include "Item.h"

// podklasa item dla przedmiotów leczących
class HealingItem : public Item {
private:
    int m_healAmount;

public:
    HealingItem(const std::string& iname, int heal)
        : Item(iname), m_healAmount(heal) {}

    // zwraca ile punktów zdrowia leczy przedmiot
    int getHealAmount() const { return m_healAmount; }

    std::string getItemType() const override { return "Healing"; }
};

#endif
