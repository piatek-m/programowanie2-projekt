#include "Eyesore.h"
#include "Interface.h"
#include "Player.h"
#include "Entity.h"

void Eyesore::takeIllumDamage()
{
    int illumDamage = 10;
    if (this->hasStatus(StatusEffectType::illumination))
    {
        this->takeDamage(illumDamage);
        std::string message = std::format("Due to being illuminated eyesore takes {} damage", illumDamage);
        Interface::addLogMessage(message);
        Interface::Pause();
    }
}

/*
void Eyesore::attack(Player &target, std::mt19937 &gen)
{
    // normalny atak
    Enemy::attack(target, gen);

    // potem szansa na nalozenie confusion
    std::uniform_int_distribution<> dice(1, 6);
    int applyEffectRoll = dice(gen);
    if (applyEffectRoll > 2)
    {
        target.addStatusEffect(StatusEffect(StatusEffectType::confusion));
        Interface::addLogMessage("You receive the effect confusion!");
    }
}
*/

void Eyesore::startTurnActions()
{
    takeIllumDamage();
    takeFireDamage();
    updateEffectTime(1);
}