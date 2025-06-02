#include "IcepickerPhase2.h"
#include "Interface.h"

std::unique_ptr<Icepicker> IcepickerPhase2::phaseChange()
{
    Interface::addLogMessage("Icepicker diffuses completely!");
    Interface::Pause();
    return nullptr; // nie ma już kolejnej fazy więc zwraca nullptr
}