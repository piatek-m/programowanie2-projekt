#ifndef EYESORE_H
#define EYESORE_H

#include "Enemy.h"

// klasa przeciwnika wrażliwego na światlo, uciekajacego przed nim
class Eyesore : public Enemy
{

public:
    // konstruktor tworzący klasę o nazwie Eyesore
    Eyesore(std::string className = "Eyesore", int hp = 25, int MAX_HP = 25, StatusEffectType weak = StatusEffectType::illumination, StatusEffectType debuff = StatusEffectType::confusion) : Enemy(className, hp, MAX_HP, weak, debuff) {};

    void takeIllumDamage();

    // void attack(Player &target, std::mt19937 &gen) override;

    void endTurnActions() override;
};

#endif
