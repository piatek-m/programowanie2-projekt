#ifndef FIREITEM_H
#define FIREITEM_H

#include "StatusEffectItem.h"
// Klasa dla przedmiotów podpadalących i nakładających status onFire
class FireItem : public StatusEffectItem
{
public:
    FireItem(const std::string &iname = "Matchstick", int duration = 3)
        : StatusEffectItem(iname, StatusEffectType::onFire, duration) {}
    // for now typem jest usableInCombat, możliwe do zmiany w przyszłości
    std::string getItemType() const override { return "usableInCombat"; }

    void useItem(Entity &target) override;
};

#endif
