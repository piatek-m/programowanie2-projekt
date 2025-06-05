#include "IcepickerPhase1.h"
#include "Interface.h"

std::unique_ptr<Icepicker> IcepickerPhase1::phaseChange()
{
    Interface::addLogMessage("Icepicker melts down and moves on to phase 2!");
    Interface::addLogMessage("[ \e[33mPress Enter to continue\e[0m ]");
    Interface::Pause();
    return std::make_unique<IcepickerPhase2>(); // zwraca nowy obiekt IcepickerPhase2
}

void IcepickerPhase1::takeDamage(int damage)
{
    Enemy::takeDamage(damage);
    if (this->getHealthPoints() <= (this->getMaxHEALTH() / 2) && !shouldPhaseChange)
    {
        shouldPhaseChange = true;
    }
}