#include "Enemy.h"

const StatusEffectType &Enemy::getSelfWeakness() const
{
    return weakness;
}
const StatusEffectType &Enemy::getOnHitDebuffType() const
{
    return debuffType;
}