#ifndef ICEPICKER_PHASE2_H
#define ICEPICKER_PHASE2_H

#include "Icepicker.h"

// faza druga ma mniej zdrowia ale nakłada debuff wet
class IcepickerPhase2 : public Icepicker
{
public:
    IcepickerPhase2()
        : Icepicker("icep;ccer", 10, 40, StatusEffectType::onFire, StatusEffectType::wetness) {}

    std::unique_ptr<Icepicker> phaseChange() override;
};

#endif
