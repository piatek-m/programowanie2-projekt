#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>

// klasa bazowa dla wszystkich entity - gracza, przeciwników
class Entity
{
private:
    const std::string m_className; // nazwa danej klasy
    int healthPoints;              // punkty życia
    double moveSpeed;              // prędkość postaci

public:
    Entity(std::string className, int hp, double ms) : m_className(className), healthPoints(hp), moveSpeed(ms) {};

    const std::string &getClassName() const; // getter nazwy klasy

    void setHealthPoints(int damage); // setter HP, implementacja otrzymywania obrażeń

    int getHealthPoints() const; // getter HP

    double getMoveSpeed() const; // getter moveSpeeda

    virtual ~Entity() = default;
};

#endif