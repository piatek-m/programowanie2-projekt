#ifndef LIFESTEALER_H
#define LIFESTEALER_H

#include "Enemy.h"
#include <random>

// klasa przeciwnika kradnącego życie gracza
class Lifestealer : public Enemy
{

public:
    // konstruktor tworzący klasę przeciwnika Lifestealer
    Lifestealer(std::string className, int hp, int MAX_HP, StatusEffectType weak, StatusEffectType debuff) : Enemy("Lifestealer", 20, 20, StatusEffectType::none, StatusEffectType::none) {};

    int attack(Entity &target, std::mt19937 &gen) override;
};

#endif
