#ifndef EYESORE_H
#define EYESORE_H

#include "Enemy.h"

// klasa przeciwnika wrażliwego na światlo, uciekajacego przed nim
class Eyesore : public Enemy
{

public:
    // konstruktor tworzący klasę o nazwie Eyesore
    Eyesore(std::string cl_Name, int hp, int MAX_HP, StatusEffectType weak, StatusEffectType debuff) : Enemy("Eyesore", 40, 40, StatusEffectType::illumination, StatusEffectType::confusion) {};
     
    void applyIlluminationEffect() {
        // sprawdzenie czy ma efekt illumination
        for (const auto& effect : m_statusEffects) {
            if (effect.m_effectType == StatusEffectType::illumination) {
                    int damage = 5; 
                    takeDamage(damage);
                }
                break;
            }
        }
};

#endif
