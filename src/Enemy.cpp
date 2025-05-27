#include "Enemy.h"
#include "Interface.h"
#include "Player.h"
#include <random> // std::mt19937

const StatusEffectType &Enemy::getSelfWeakness() const
{
    return weakness;
}
const StatusEffectType &Enemy::getOnHitDebuffType() const
{
    return debuffType;
}

void Enemy::takeDamage(int damage)
{
    return Entity::takeDamage(damage);
    Interface::updateEnemySection(*this);
}

int Enemy::attack(Player &target, std::mt19937 &gen)
{
    std::uniform_int_distribution<> damageDist(2, 5);
    int damage = damageDist(gen);
    target.takeDamage(damage);

    std::string message = std::format("{} is attacking...     ", this->getClassName());
    Interface::addLogMessage(message);

    message = std::format("They hit you for: {} damage.", damage);
    Interface::addLogMessage(message);

    target.takeDamage(damage);

    return damage;
}