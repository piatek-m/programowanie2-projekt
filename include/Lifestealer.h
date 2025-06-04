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
    Lifestealer(std::string className = "Lifestealer", int hp = 30, int MAX_HP = 30, StatusEffectType weak = StatusEffectType::none, StatusEffectType debuff = StatusEffectType::none) : Enemy(className, hp, MAX_HP, weak, debuff) {};

    void attack(Player &target, std::mt19937 &gen) override;

    void startTurnActions() override
    {
        Entity::startTurnActions();
    }
};

#endif
