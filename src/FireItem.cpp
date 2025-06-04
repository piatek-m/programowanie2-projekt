#include "FireItem.h"
#include "Player.h"
#include "Interface.h"
#include "format"

void FireItem::useItem(Entity &target)
{
    target.addStatusEffect(StatusEffect(StatusEffectType::onFire, m_duration));

    Interface::addLogMessage(std::format("Match stick thrown! It makes the {} catch \e[1mfire\e[0m.", target.getClassName()));
}