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

void Enemy::applySpecificDebuff(Player &target, std::mt19937 &gen)
{
    std::uniform_int_distribution<> dice(1, 6);
    int applyEffectRoll = dice(gen);
    if (applyEffectRoll > 4)
        target.addStatusEffect(StatusEffect(debuffType));
}

void Enemy::attack(Player &target, std::mt19937 &gen)
{
    // losowanie obrazen
    std::uniform_int_distribution<> damageDist(2, 5);
    int damage = damageDist(gen);

    // UI
    std::string attackerClassName = this->getClassName();

    std::string message = std::format("{} is attacking...     ", attackerClassName);
    Interface::addLogMessage(message);

    Interface::addLogMessage("[ \e[33mPress Enter to continue\e[0m ]");
    Interface::Pause();

    target.takeDamage(damage);

    message = std::format("{} hits you for: \e[1m{}\e[0m.", attackerClassName, damage);
    Interface::addLogMessage(message);

    // naklada specyficzny dla siebie debuff na gracza (jesli takowy posiada)
    if (debuffType != StatusEffectType::none)
        applySpecificDebuff(target, gen);

    // jesli jest podpalon to podpala tez gracza
    Entity::applyOnFireEffect(target);

    return;
}

void Enemy::takeFireDamage()
{
    // defaultowo damage to 4
    int fireDamage = 4;
    if (this->hasStatus(StatusEffectType::onFire))
    {
        // jesli potworek ma weakness do ognia to damage = 6
        if (weakness == StatusEffectType::onFire)
            fireDamage = 8;

        this->takeDamage(fireDamage);
        std::string message = std::format("Due to being on fire {} takes \e[1m{}\e[0m damage", this->getClassName(), fireDamage);
        Interface::addLogMessage(message);
        Interface::Pause();
    }
}

void Enemy::addStatusEffect(const StatusEffect &effect)
{
    Entity::addStatusEffect(effect);
    Interface::updateEnemySection(*this);
}

// usuwa efekt
void Enemy::removeStatusEffect(StatusEffectType type)
{
    Entity::removeStatusEffect(type);
    Interface::updateEnemySection(*this);
}

// nadpisuje czas trwania wszystkich posiadanych efektu
void Enemy::updateEffectTime(int deltaTime)
{
    Entity::updateEffectTime(deltaTime);
    Interface::updateEnemySection(*this);
}