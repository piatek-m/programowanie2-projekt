#include "Entity.h"
#include "Interface.h"

const std::string &Entity::getClassName() const
{
    return m_className;
}

int Entity::getHealthPoints() const
{
    return healthPoints;
}

const int Entity::getMaxHEALTH() const
{
    return MAX_HEALTH_POINTS;
}

void Entity::takeDamage(int damage)
{
    healthPoints -= damage;
    /*
    if (onUpdate)        // jeśli fun. onUpdate jest zdefiniowana
        onUpdate(*this); // wywołaj onUpdate biorąc jako argument siebie

        -> zamieniono metody interfejsu na static więc dla uproszczenia wyrzucono lambdy i callbacki z kodu, zostają skomentowane jako "notatki"
    */
}

/*
void Entity::setOnUpdateCallback(std::function<void(const Entity &)> callback)
{
    onUpdate = callback;
}
    -> zamieniono metody interfejsu na static więc dla uproszczenia wyrzucono lambdy i callbacki z kodu, zostają skomentowane jako "notatki"
*/

void Entity::applyOnFireEffect(Entity &target)
{
    if (this->hasStatus(StatusEffectType::onFire))
    {
        Interface::addLogMessage(std::format("Due to {} burning, {} catches fire too!", this->getClassName(), target.getClassName()));
        target.addStatusEffect(StatusEffect(StatusEffectType::onFire));
    }
}

void Entity::takeFireDamage()
{
    int fireDamage = 4;
    if (this->hasStatus(StatusEffectType::onFire))
    {
        this->takeDamage(4);
        this->takeDamage(fireDamage);
        std::string message = std::format("Due to being on fire {} takes \e[1m{}\e[0m damage", this->getClassName(), fireDamage);
        Interface::addLogMessage(message);
        Interface::addLogMessage("[ \e[33mEnter to continue\e[0m ]");
        Interface::Pause();
    }
}

void Entity::endTurnActions()
{
    takeFireDamage(); // reminder: otrzymuje obrażenia tylko jeśli jest podpalon
    updateEffectTime(1);
}