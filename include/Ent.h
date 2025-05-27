#ifndef ENT_H
#define ENT_H

#include "Enemy.h"

// klasa przeciwnika wrażliwego na ogień
class Ent : public Enemy
{
public:
    // konstruktor tworzący klasę przeciwnika Ent
    Ent(std::string className = "Ent", int hp = 50, int MAX_HP = 50, StatusEffectType weak = StatusEffectType::onFire, StatusEffectType debuff = StatusEffectType::none) : Enemy(className, hp, MAX_HP, weak) {};
};

#endif