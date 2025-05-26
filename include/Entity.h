#ifndef ENTITY_H
#define ENTITY_H

#include "StatusEffectManager.h" // buffy i debuffy
#include <iostream>

// klasa bazowa dla wszystkich entity - gracza, przeciwników
class Entity
{
private:
    const std::string m_className; // nazwa danej klasy
    int healthPoints;              // punkty życia
    const int MAX_HEALTH_POINTS;   // maksymalne HP
    double moveSpeed;              // prędkość postaci

    StatusEffectManager statusManager; // obiekt odpowiedzialny za zarządzanie efektami

public:
    Entity(std::string className, int hp, double ms, int MAX_HP = 40) : m_className(className), healthPoints(hp), moveSpeed(ms), MAX_HEALTH_POINTS(MAX_HP) {};

    // getter nazwy klasy
    virtual const std::string &getClassName() const = 0;

    // setter HP, implementacja otrzymywania obrażeń
    virtual void setHealthPoints(int damage) = 0;

    // getter HP
    virtual int getHealthPoints() const = 0;

    // getter maksymalnegoHP
    virtual const int getMaxHEALTH() const = 0;

    // getter moveSpeeda
    virtual double getMoveSpeed() const = 0;

    // naklada efekt na target
    virtual void applyEffect(Entity &target) = 0;

    virtual ~Entity() = default;

    // zarządzanie efektami oddelegowane do StatusEffectManager

    // dodaje efekt
    void addStatusEffect(const StatusEffect &effect)
    {
        statusManager.addEffect(effect);
    }

    // usuwa efekt
    void removeStatusEffect(StatusEffectType type)
    {
        statusManager.removeEffect(type);
    }

    // sprawdza, czy ma dany efekt
    bool hasStatus(StatusEffectType type) const
    {
        return statusManager.hasEffect(type);
    }

    // nadpisuje czas trwania posiadanego efektu
    void updateEffectTime(int deltaTime)
    {
        statusManager.updateEffectTime(deltaTime);
    }

    // getter aktywnych efektow
    std::vector<StatusEffect> getActiveEffects() const
    {
        return statusManager.getActiveEffects();
    }
};

#endif