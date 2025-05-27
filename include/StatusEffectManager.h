// StatusEffectManager.h
#ifndef STATUSEFFECTMANAGER_H
#define STATUSEFFECTMANAGER_H

#include "StatusEffect.h"
#include <vector>

class Entity;

// manager efektów, dodaje, usuwa, sprawdza czy posiada, etc.
class StatusEffectManager
{
private:
    Entity *m_managedEntity; // wskaźnik na obiekt, którego efektami zarządza Manager

    std::vector<StatusEffect> activeEffects; // przetrzymuje aktywne efekty

public:
    StatusEffectManager(Entity *managedEntity) : m_managedEntity(managedEntity) {};

    // funkcja pomocnicza do wyciągania stringa z typu
    std::string statusEffectTypeToString(const StatusEffectType type) const;

    // dodaje efekt
    void addEffect(const StatusEffect &effect);

    // usuwa efekt
    void removeEffect(StatusEffectType type);

    // sprawdza czy ma efekt
    bool hasEffect(StatusEffectType type) const;

    // updatuje czas efektu
    void updateEffectTime(int deltaTime);

    // getter aktywnych efektow
    std::vector<StatusEffect> getActiveEffects() const;
};

#endif
