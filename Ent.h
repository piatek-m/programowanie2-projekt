#ifndef ENT_H
#define ENT_H

#include "Enemy.h"

// klasa przeciwnika wrażliwego na ogień
class Ent : public Enemy
{
public:
    // konstruktor tworzący klasę przeciwnika Ent
    Ent(std::string className, int hp, double ms, int MAX_HP, StatusEffectType weak, StatusEffectType debuff) : Enemy("Ent", 50, 10, 50, StatusEffectType::onFire) {};
};

#endif