#ifndef STATUSEFFECT_H
#define STATUSEFFECT_H

#include <string>

// typy efektow
enum class StatusEffectType
{
    none,         // nie jest nakladany zaden debuff, dla zachowania spójności w konstruktorze Enemy
    confusion,    // nakladany przez Eyesore
    wetness,      // nakladany przez Icepicker w 2. fazie
    onFire,       // nakladane przez gracza (przedmiot) oraz Enta jezeli jest podpalony
    illumination, // nakladane przez gracza (przedmiot)
};

// poszczegolny efekt statusu, zawiera w sobie typ efektu i pozostaly czas trwania
struct StatusEffect
{
    StatusEffectType m_effectType; // typ efektu
    int remainingDuration;         // pozostaly czas trwania efektu (w turach)

    StatusEffect(StatusEffectType effectType, int remDur = 2) : m_effectType(effectType), remainingDuration(remDur) {};

    // getter nazwy efektu - używane w interfejsie
    const std::string getStatusEffectName() const
    {
        switch (m_effectType)
        {
        case StatusEffectType::confusion:
            return "Confusion";
        case StatusEffectType::wetness:
            return "Wetness";
        case StatusEffectType::onFire:
            return "On Fire";
        case StatusEffectType::illumination:
            return "Illumination";
        default:
            return "";
        }
    }
};

#endif
