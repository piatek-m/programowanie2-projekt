#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

// klasa gracza
class Player : public Entity
{
private:
    const std::string m_playerName;

public:
    Player(std::string className, int hp, double ms, std::string playerName) : Entity(className, hp, ms), m_playerName(playerName) {};

    // getter wybranego imienia gracza
    const std::string &getPlayerName() const;
};

#endif