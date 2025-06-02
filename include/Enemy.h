#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include <random> // std::mt19937

class Player;

// klasa bazowa przeciwników
class Enemy : public Entity
{
private:
    const StatusEffectType weakness;   // słabość przeciwnika, ten typ zadaje więcej obrażeń
    const StatusEffectType debuffType; // debuff przy zadaniu obrażeń graczowi

public:
    Enemy(std::string className, int hp, int MAX_HP, StatusEffectType weak, StatusEffectType debuff = StatusEffectType::none) : Entity(className, hp, MAX_HP), weakness(weak), debuffType(debuff) {}

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
    void takeDamage(int damage) override;

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

    /* DEBUG HERE
    // naklada efekt na target
    void applyEffect(Entity &target) override
    {
        return Entity::applyEffect(target);
    }
    */

    // defaultowy atak dla wszystkich przeciwnikow
    virtual void attack(Player &target, std::mt19937 &gen);

    const StatusEffectType &getSelfWeakness() const; // getter podatności na dany typ obrażeń

    const StatusEffectType &getOnHitDebuffType() const; // getter typu nakładanego debuffa

    void takeFireDamage() override;

    // naklada efekt (debuff) wlasciwy dla siebie na gracza
    void applySpecificDebuff(Player &target, std::mt19937 &gen);
};

#endif