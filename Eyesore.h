#ifndef EYESORE_H
#define EYESORE_H

#include "Enemy.h"

// klasa przeciwnika wrażliwego na światlo, uciekajacego przed nim
class Eyesore : public Enemy
{

public:
    // konstruktor tworzący klasę o nazwie Eyesore
    Eyesore(std::string cl_Name, int hp, double ms, const std::string weak, const std::string debuff) : Enemy("Eyesore", 40, 10, "light", "confusion") {};
};

#endif