#ifndef ICEPICKER_PHASE2_H
#define ICEPICKER_PHASE2_H

#include "Icepicker.h"

// faza druga ma mniej zdrowia ale nakłada debuff wet
class IcepickerPhase2 : public Icepicker
{
public:
    IcepickerPhase2()
        : Icepicker("Icepicker Meltdown", 20, 12, StatusEffectType::onFire, StatusEffectType::wetness) {}

    std::unique_ptr<Icepicker> phaseChange() override
    {
        std::cout << "Icepicker kompletnie się rozpływa!" << std::endl;
        return nullptr; // nie ma już kolejnej fazy więc zwraca nullptr
    }
};

#endif
