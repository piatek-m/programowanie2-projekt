#include "Enemy.h"

const std::string &Enemy::getSelfWeakness() const
{
    return weakness;
}
const std::string &Enemy::getOnHitDebuffType() const
{
    return debuffType;
}