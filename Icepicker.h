#ifndef ICEPICKER_H
#define ICEPICKER_H

#include "Enemy.h"
#include <memory>

class Icepicker : public Enemy {
public:
    Icepicker(std::string className, int hp, double ms, const std::string& weak, const std::string& debuff = "")
        : Enemy(className, hp, ms, weak, debuff) {}

    virtual std::unique_ptr<Icepicker> phaseChange() = 0; // zwraca nowy obiekt
    virtual ~Icepicker() = default;
};

#endif
