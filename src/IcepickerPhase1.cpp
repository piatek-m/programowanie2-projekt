#include "IcepickerPhase1.h"
#include "Interface.h"

std::unique_ptr<Icepicker> IcepickerPhase1::phaseChange()
{
    Interface::addLogMessage("Icepicker melts down and moves on to phase 2!");
    Interface::Pause();
    return std::make_unique<IcepickerPhase2>(); // zwraca nowy obiekt IcepickerPhase2
}