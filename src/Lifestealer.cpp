#include "Lifestealer.h"
#include "Interface.h"
#include "Player.h"
#include <format>
#include <random>

void Lifestealer::attack(Player &target, std::mt19937 &gen)
{
    std::uniform_int_distribution<> damageDist(2, 5);
    int damage = damageDist(gen);

    Interface::addLogMessage("Lifestealer is attacking...     ");
    Interface::addLogMessage("[ \e[33mPress Enter to continue\e[0m ]");
    Interface::Pause();

    std::string message = std::format("Lifestealer hits you for: \e[1m{}\e[0m damage.", damage);
    Interface::addLogMessage(message);

    Entity::applyOnFireEffect(target);

    target.takeDamage(damage);

    // leczenie
    int healAmount = damage / 2;
    int currentHP = this->getHealthPoints();
    int maxHP = this->getMaxHEALTH();
    int newHP = std::min(currentHP + healAmount, maxHP);

    message = std::format("Lifestealer heals itself for: \e[1m{}\e[0m HP.", healAmount);
    Interface::addLogMessage(message);

    this->setHealthPoints(newHP);
    Interface::updateEnemySection(*this);

    return;
}
