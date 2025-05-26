#include "HealingItem.h"
#include "Player.h"

void HealingItem::useItem(Player &player)
{
    int currentHP = player.getHealthPoints();
    int maxHP = player.getMaxHEALTH();

    // HP po uleczeniu, leczenie co najwyżej do maxHP
    int newHP = std::min(currentHP + m_healAmount, maxHP);
    // Otrzymywanie ujemnych obrażeń = leczenie
    player.takeDamage(-(newHP - currentHP));

    player.getInventory().removeItem(std::make_shared<HealingItem>(*this));
}