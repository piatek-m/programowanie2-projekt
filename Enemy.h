#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

// klasa bazowa przeciwników
class Enemy : public Entity
{
private:
    const StatusEffectType weakness;   // słabość przeciwnika, ten typ zadaje więcej obrażeń
    const StatusEffectType debuffType; // debuff przy zadaniu obrażeń graczowi

public:
    Enemy(std::string className, int hp, double ms, StatusEffectType weak, StatusEffectType debuff = StatusEffectType::none) : Entity(className, hp, ms), weakness(weak), debuffType(debuff) {}

    const StatusEffectType &getSelfWeakness() const; // getter podatności na dany typ obrażeń

    const StatusEffectType &getOnHitDebuffType() const; // getter typu nakładanego debuffa
};

#endif