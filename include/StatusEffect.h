#ifndef STATUSEFFECT_H
#define STATUSEFFECT_H

#include <string>

// typy efektow
enum class StatusEffectType
{
    none,         // nie jest nakladany zaden debuff, dla zachowania spójności w konstruktorze Enemy
    confusion,    // nakladany przez Eyesore
    lifedrain,    // nakladany przez Lifestealer
    freezing,     // nakladany przez Icepicker w 1. fazie
    wetness,      // nakladany przez Icepicker w 2. fazie
    onFire,       // nakladane przez gracza (przedmiot) oraz Enta jezeli jest podpalony
    illumination, // nakladane przez gracza (przedmiot)
};

// poszczegolny efekt statusu, zawiera w sobie typ efektu i pozostaly czas trwania
struct StatusEffect
{
    StatusEffectType m_effectType;  // typ efektu
    const std::string m_effectName; // nazwa efektu
    int remainingDuration;          // pozostaly czas trwania efektu (w turach)

    StatusEffect(StatusEffectType effectType, int remDur) : m_effectType(effectType), remainingDuration(remDur) {};
};

#endif