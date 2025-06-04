#include "LightItem.h"
#include "Player.h"
#include "Interface.h"
#include "format"

void LightItem::useItem(Entity &target)
{
    target.addStatusEffect(StatusEffect(StatusEffectType::illumination, m_duration));

    Interface::addLogMessage(std::format("Flashlight shines light on {} mercilessly!", target.getClassName()));
}