#ifndef HEALING_ITEM_H
#define HEALING_ITEM_H

#include "Item.h"

class Entity;

// podklasa item dla przedmiotów leczących
class HealingItem : public Item
{
private:
    int m_healAmount;

public:
    HealingItem(const std::string &iname = "Potion of Healing", int heal = 10)
        : Item(iname), m_healAmount(heal) {}

    // zwraca ile punktów zdrowia leczy przedmiot
    int getHealAmount() const { return m_healAmount; }

    void useItem(Entity &entity) override
    {
        return;
    }

    // self-heal
    void useItem(Player &player) override;

    std::string getItemType() const override { return "Healing"; }
};

#endif
