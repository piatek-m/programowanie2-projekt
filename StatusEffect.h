#ifndef STATUSEFFECT_H
#define STATUSEFFECT_H

enum class StatusEffectType
{
    PSYCHOSIS
    // dodawac dalsze
};

struct StatusEffect
{
    StatusEffectType effectType;
    int remainingDuration;

    StatusEffect(StatusEffectType e_Type, int remDur) : effectType(e_Type), remainingDuration(remDur) {};
};

#endif