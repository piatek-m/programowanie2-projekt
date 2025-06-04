#include "HealingItem.h"
#include "Player.h"
#include "Interface.h"
#include "format"

void HealingItem::useItem(Player &player)
{
    int currentHP = player.getHealthPoints();
    int maxHP = player.getMaxHEALTH();

    // HP po uleczeniu, leczenie co najwyżej do maxHP
    int newHP = std::min(currentHP + m_healAmount, maxHP);
    // Otrzymywanie ujemnych obrażeń = leczenie
    player.takeDamage(-(newHP - currentHP));

    Interface::addLogMessage(std::format("Potion of healing used! You heal for \e[1m{}\e[0m.", m_healAmount));
}