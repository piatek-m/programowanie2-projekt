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

void StatusEffectManager::removeEffect(StatusEffectType type)
{
    // usuń efekt danego typu
    activeEffects.erase(
        std::remove_if(activeEffects.begin(), activeEffects.end(), 
                       [type](const StatusEffect &e)
                       {
                           return e.m_effectType == type;
                       }),
        activeEffects.end());
}

bool StatusEffectManager::hasEffect(StatusEffectType type) const
{
    for (const auto &e : activeEffects)
    {
        if (e.m_effectType == type) // sprawdza czy obecnie ma jakiś efekt danego typu
        {
            return true;
        }
    }
    return false;
}

void StatusEffectManager::updateEffectTime(int deltaTime)
{
    // sprawdza czasy dla wszystkich aktywnych efektów
    for (auto &e : activeEffects)
    {
        e.remainingDuration -= deltaTime; // zmniejsza pozostały czas o deltaTime
    }

    // usuwa efekty dla których skończył się czas
    activeEffects.erase(
        std::remove_if(activeEffects.begin(), activeEffects.end(), // remove_if zostawia wszystkie aktywne efekty i usuwa te dla których czas się skończył
                       [](const StatusEffect &e)
                       {
                           return e.remainingDuration <= 0;
                       }),
        activeEffects.end());
}

std::vector<StatusEffect> StatusEffectManager::getActiveEffects() const
{
    return activeEffects; // zwraca aktywne efekty
}
