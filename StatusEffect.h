#ifndef STATUSEFFECT_H
#define STATUSEFFECT_H

// typy efektow
enum class StatusEffectType
{
    psychosis, // nakladany przez Eyesore
    lifedrain, // nakladany przez Lifestealer
    freezing,  // nakladany przez Icepicker w 1. fazie
    wet,       // nakladany przez Icepicker w 2. fazie
    fire,      // nakladane przez gracza oraz Enta jezeli jest podpalony
};

// poszczegolny efekt statusu, zawiera w sobie typ efektu i pozostaly czas trwania
struct StatusEffect
{
    StatusEffectType m_effectType; // typ efektu
    int remainingDuration;         // pozostaly czas trwania efektu (w turach)

    StatusEffect(StatusEffectType effectType, int remDur) : m_effectType(effectType), remainingDuration(remDur) {};
};

#endif