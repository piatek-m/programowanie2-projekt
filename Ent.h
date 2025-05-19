#ifndef ENT_H
#define ENT_H

//klasa przeciwnika wrażliwego na ogień
class Ent : public Enemy
{
public:
    //konstruktor tworzący klasę przeciwnika Ent
    Ent(std::string cl_Name, int hp, double ms, const std::string weak, const std::string debuff) : Enemy("Ent", 50, 10, "fire", "none") {};
};

#endif