#ifndef LIFESTEALER_H
#define LIFESTEALER_H

//klasa przeciwnika kradnącego życie gracza
class Lifestealer : public Enemy 
{

public:
    //konstruktor tworzący klasę przeciwnika Lifestealer
    Lifestealer(std::string cl_Name, int hp, double ms, const std::string weak, const std::string debuff) : Enemy("Lifestealer", 30, 10, "none", "lifedrain") {};
};

#endif