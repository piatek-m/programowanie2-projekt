#ifndef ICEPICKER_PHASE1_H
#define ICEPICKER_PHASE1_H

#include "Icepicker.h"
#include "IcepickerPhase2.h"

// faza pierwsza, która ma więcej zdrowia ale nie daje żadnych debuffów
class IcepickerPhase1 : public Icepicker {
public:
    IcepickerPhase1()
        : Icepicker("Icepicker", 40, 10, "heat") {}

    void phaseChange() override {
        std::cout << "Icepicker topi się!" << std::endl; // informacja o zmianie fazy
        return new IcepickerPhase2(); // zwraca obiekt IcepickerPhase2
    }
};

#endif
