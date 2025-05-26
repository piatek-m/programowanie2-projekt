// StatusEffectManager.h
#ifndef STATUSEFFECTMANAGER_H
#define STATUSEFFECTMANAGER_H

#include "StatusEffect.h"
#include <vector>

// manager efektów, dodaje, usuwa, sprawdza czy posiada, etc.
class StatusEffectManager
{
private:
    std::vector<StatusEffect> activeEffects; // przetrzymuje aktywne efekty

public:
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
