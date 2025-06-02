#ifndef ICEPICKER_H
#define ICEPICKER_H

#include "Enemy.h"
#include <memory>

class Icepicker : public Enemy
{
public:
    Icepicker(std::string className, int hp, int MAX_HP, StatusEffectType weak = StatusEffectType::onFire, StatusEffectType debuff = StatusEffectType::none)
        : Enemy(className, hp, MAX_HP, weak, debuff) {}

    virtual std::unique_ptr<Icepicker> phaseChange() = 0; // zwraca nowy obiekt

    void startTurnActions() override
    {
        Entity::startTurnActions();
    }

    virtual ~Icepicker() = default;
};

#endif
