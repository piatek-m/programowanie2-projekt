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
        Interface::addLogMessage("\e[31..!!gOoOD LOOordD!!..\e[0m");
        std::string message = std::format("Due to being illuminated Eyesore takes \e[1m{}\e[0m damage", illumDamage);
        Interface::addLogMessage(message);
        Interface::addLogMessage("[ \e[31mEnter to continue\e[0m ]");
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