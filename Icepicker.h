#ifndef ICEPICKER_H
#define ICEPICKER_H

//tworzy przeciwnika wrażliwego na ciepło
class Icepicker : public Enemy
{   
public:
    //konstruktor tworzący klasę przeciwnika Icepicker
    Icepicker(std::string cl_Name, int hp, double ms, const std::string weak, const std::string debuff) : Enemy("Icepicker", 40, 10, "heat", "wet") {};
};

#endif