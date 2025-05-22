#ifndef ENTITY_H
#define ENTITY_H

#include "StatusEffectAggregator.h" // buffy i debuffy
#include <iostream>

// klasa bazowa dla wszystkich entity - gracza, przeciwników
class Entity
{
private:
    const std::string m_className; // nazwa danej klasy
    int healthPoints;              // punkty życia
    double moveSpeed;              // prędkość postaci

    StatusEffectManager statusManager; // obiekt odpowiedzialny za zarządzanie efektami

public:
    Entity(std::string className, int hp, double ms) : m_className(className), healthPoints(hp), moveSpeed(ms) {};

    // getter nazwy klasy
    const std::string &getClassName() const;

    // setter HP, implementacja otrzymywania obrażeń
    void setHealthPoints(int damage);

    // getter HP
    int getHealthPoints() const;

    // getter moveSpeeda
    double getMoveSpeed() const;

    // naklada efekt na target
    void applyEffect(Entity &target);

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