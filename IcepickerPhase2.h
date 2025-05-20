#ifndef ICEPICKER_PHASE2_H
#define ICEPICKER_PHASE2_H

#include "Icepicker.h"

// faza druga, ma mniej zdrowia ale za to nakłada debuff wet
class IcepickerPhase2 : public Icepicker {
public:
    IcepickerPhase2()
        : Icepicker("Icepicker Meltdown", 20, 12, "heat","wet") {}

    void phaseChange() override {
        std::cout << "Icepicker kompletnie się rozpływa!" << std::endl; // tu nic się nie dzieje nie ma kolejnej fazy
    }
};

#endif
