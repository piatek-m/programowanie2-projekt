#include "StatusEffectManager.h"
#include <algorithm>

void StatusEffectManager::addEffect(const StatusEffect &effect)
{
    // jeśli efekt jest już nałożony to tylko odświeża czas trwania

    // dla każdego efektu w wektorze aktywnych efektów
    for (auto &e : activeEffects)
    {
        // sprawdź, czy zawarty efekt jest tym samym co nakładany
        if (e.m_effectType == effect.m_effectType)
        {
            // jeśli tak to odswież czasu trwania zamiast nakładać na nowo
            e.remainingDuration = effect.remainingDuration;
            return;
        }
    }
    // jesli nie jest nałożony to dodaje efekt
    activeEffects.push_back(effect);
}