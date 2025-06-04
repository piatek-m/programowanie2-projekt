#ifndef LIGHTITEM_H
#define LIGHTITEM_H

#include "StatusEffectItem.h"
// Klasa dla przedmiotów dających światło i nakładających debuff illumination
class LightItem : public StatusEffectItem
{
public:
    LightItem(const std::string &iname = "Flashlight", int duration = 1)
        : StatusEffectItem(iname, StatusEffectType::illumination, duration) {}
    // for now typem jest usableInCombat, możliwe do zmiany w przyszłości
    std::string getItemType() const override { return "usableInCombat"; }

    void useItem(Entity &target) override;
};

#endif
