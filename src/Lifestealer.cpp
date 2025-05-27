#include "Lifestealer.h"
#include <random>

int Lifestealer::attack(Entity &target, std::mt19937 &gen) {
    std::uniform_int_distribution<> damageDist(2, 5);
    int damage = damageDist(gen);

    target.takeDamage(damage);

    int healAmount = damage / 2;
    int currentHP = this->getHealthPoints();
    int maxHP = this->getMaxHEALTH();
    int newHP = std::min(currentHP + healAmount, maxHP);

    this->setHealthPoints(newHP); 

    return damage;
}
