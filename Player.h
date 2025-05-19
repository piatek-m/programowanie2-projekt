#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "vector"         // efekty statusu
#include "StatusEffect.h" // efekty statusu

// klasa gracza
class Player : public Entity
{
private:
    const std::string m_playerName;
    std::vector<StatusEffect> status; // [vector] PRZEROBIC NA ENUM [StatusEffectType]+STRUCT [StatusEffect]; buffy, debuffy

public:
    Player(std::string className, int hp, double ms, std::string playerName, std::string pStatus) : Entity(className, hp, ms), m_playerName(playerName) {};

    const std::string &getPlayerName() const; // getter wybranego imienia Gracza

    void addStatusEffect(StatusEffect effect);          // dodaje efekt
    void removeStatusEffect(StatusEffectType type);     // usuwa efekt
    bool hasStatus(StatusEffectType type) const;        // sprawdza, czy ma dany efekt
    void updateStatusEffects(int deltaTime);            // zmienia remainingDuration
    std::vector<StatusEffect> getActiveEffects() const; // getter wszystkich buffow i debuffow
};

#endif