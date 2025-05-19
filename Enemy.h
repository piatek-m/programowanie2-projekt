#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

// klasa bazowa przeciwników
class Enemy : public Entity
{
private:
    const std::string weakness;   // słabość przeciwnika, ten typ zadaje więcej obrażeń
    const std::string debuffType; // debuff przy zadaniu obrażeń graczowi

public:
    Enemy(std::string cl_Name, int hp, double ms, const std::string weak, const std::string debuff) : Entity(cl_Name, hp, ms), weakness(weak), debuffType(debuff) {}

    const std::string &getEnemyWeakness() const; // getter podatności na dany typ obrażeń

    const std::string &getOnHitDebuffType() const; // getter typu nakładanego debuffa
};

#endif