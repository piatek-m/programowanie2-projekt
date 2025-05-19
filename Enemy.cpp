#include "Enemy.h"

const std::string &Enemy::getEnemyWeakness() const
{
    return weakness;
};
const std::string &Enemy::getOnHitDebuffType() const
{
    return debuffType;
}