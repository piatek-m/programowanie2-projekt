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
    Enemy(std::string className, int hp, double ms, int MAX_HP, StatusEffectType weak, StatusEffectType debuff = StatusEffectType::none) : Entity(className, hp, ms, MAX_HP), weakness(weak), debuffType(debuff) {}

    /*
            Metody Entity, deklarowane tutaj, aby Enemy nie było abstrakcyjne jak Entity
            Mimo to korzystają z już podanych definicji metod dla Entity
    */

    // getter nazwy klasy
    const std::string &getClassName() const override
    {
        return Entity::getClassName();
    }

    // setter HP, implementacja otrzymywania obrażeń
    void takeDamage(int damage) override
    {
        return Entity::takeDamage(damage);
    }

    // getter HP
    int getHealthPoints() const override
    {
        return Entity::getHealthPoints();
    }

    // getter maksymalnegoHP
    const int getMaxHEALTH() const override
    {
        return Entity::getMaxHEALTH();
    }

    // getter moveSpeeda
    double getMoveSpeed() const override
    {
        return Entity::getMoveSpeed();
    }

    // naklada efekt na target
    void applyEffect(Entity &target) override
    {
        return Entity::applyEffect(target);
    }

    const StatusEffectType &getSelfWeakness() const; // getter podatności na dany typ obrażeń

    const StatusEffectType &getOnHitDebuffType() const; // getter typu nakładanego debuffa
};

#endif