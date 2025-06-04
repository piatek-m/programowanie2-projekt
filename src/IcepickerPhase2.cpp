#include "IcepickerPhase2.h"
#include "Interface.h"

std::unique_ptr<Icepicker> IcepickerPhase2::phaseChange()
{
    Interface::addLogMessage("Icepicker diffuses completely!");
    Interface::addLogMessage("[ \e[33mPress Enter to continue\e[0m ]");
    Interface::Pause();
    return nullptr; // nie ma już kolejnej fazy więc zwraca nullptr
}