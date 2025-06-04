#ifndef STATUSEFFECTITEM_H
#define STATUSEFFECTITEM_H

#include "Item.h"
#include "StatusEffect.h"

// Klasa pośrednia dla itemów nakładających debuffy
class StatusEffectItem : public Item
{
protected:
    StatusEffectType m_effectType;
    int m_duration;

public:
    StatusEffectItem(const std::string &iname, StatusEffectType effectType, int duration = 2)
        : Item(iname), m_effectType(effectType), m_duration(duration) {}

    virtual std::string getItemType() const override { return "StatusEffect"; }

    StatusEffect getStatusEffect() const
    {
        return StatusEffect(m_effectType, m_duration);
    }
};

#endif
