#ifndef LIFESTEALER_H
#define LIFESTEALER_H

#include "Enemy.h"
#include <random>

class Player;

// klasa przeciwnika kradnącego życie gracza
class Lifestealer : public Enemy
{

public:
    // konstruktor tworzący klasę przeciwnika Lifestealer
    Lifestealer(std::string className, int hp, int MAX_HP, StatusEffectType weak, StatusEffectType debuff) : Enemy("Lifestealer", 20, 20, StatusEffectType::none, StatusEffectType::none) {};

    void attack(Player &target, std::mt19937 &gen) override;

    void startTurnActions() override
    {
        Entity::startTurnActions();
    }
};

#endif
