#ifndef ICEPICKER_H
#define ICEPICKER_H

#include "Enemy.h"
#include <string>

// Interfejs/bazowa klasa Icepicker
class Icepicker : public Enemy {
public:
    Icepicker(std::string className, int hp, double ms, const std::string weak, const std::string debuff)
        : Enemy(className, hp, ms, weak, debuff) {}

    virtual void phaseChange() = 0; // zmiana fazy, zmiana statystyk icepickera
    virtual ~Icepicker() = default;
};

#endif
