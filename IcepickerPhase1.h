#ifndef ICEPICKER_PHASE1_H
#define ICEPICKER_PHASE1_H

#include "Icepicker.h"
#include "IcepickerPhase2.h"
// klasa przeciwnika która ma więcej zdrowia ale nie daje debuffów
class IcepickerPhase1 : public Icepicker
{
public:
    IcepickerPhase1()
        : Icepicker("Icepicker", 40, 10, 50) {}

    std::unique_ptr<Icepicker> phaseChange() override
    {
        std::cout << "Icepicker topi się i przechodzi do fazy 2!" << std::endl;
        return std::make_unique<IcepickerPhase2>(); // zwraca nowy obiekt IcepickerPhase2
    }
};

#endif
