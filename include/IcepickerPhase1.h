#ifndef ICEPICKER_PHASE1_H
#define ICEPICKER_PHASE1_H

#include "Icepicker.h"
#include "IcepickerPhase2.h"
// klasa przeciwnika która ma więcej zdrowia ale nie daje debuffów
class IcepickerPhase1 : public Icepicker
{
private:
    bool shouldPhaseChange = false;

public:
    IcepickerPhase1()
        : Icepicker("Icepicker", 40, 40) {}

    std::unique_ptr<Icepicker> phaseChange() override;

    bool needsPhaseChange() const
    {
        return shouldPhaseChange;
    }

    void takeDamage(int damage) override;
};

#endif
