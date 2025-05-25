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
    // .erase() usuwa elementy z wektora z zakresu [first; last), tu: od pierwszego elementu do usuniecia (zwroconego po przetasowaniu przez remove_if) do ostatniego elementu wektora (takze po przetasowaniu, takim, ze elementy do usuniecia sa na koncu wektora)
    activeEffects.erase(
        // remove_if() przenosi wszystkie elementy danego typu na koniec wektora, zwraca iterator do pierwszego elementu do usunięcia (i skraca zakres wektora [first; last), tak, że last jest ostatnim elementem NIE do usunięcia)
        std::remove_if(activeEffects.begin(), activeEffects.end(),
                       /* funkcja lambda (czyli bez nazwy, anonimowa)
                        [capture] pozwala lambdzie na kopie zmiennych z zewnątrz (takie dziedziczenie) w momencie jej tworzenia
                        (parameters) to przekazanie parametrów - podczas wywołania funkcji
                       */
                       [type](const StatusEffect &e)
                       {
                           // if(e.m_effectType==type) return true;
                           return e.m_effectType == type;
                       }),
        activeEffects.end());
}

bool StatusEffectManager::hasEffect(StatusEffectType type) const
{
    // dla wszystkich obiektów w activeEffects
    for (const auto &e : activeEffects)
    {
        // sprawdza czy obecnie ma jakiś efekt danego typu
        if (e.m_effectType == type)
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
        // zmniejsza pozostały czas o deltaTime
        e.remainingDuration -= deltaTime;
    }

    // usuwa efekty dla których skończył się czas (te wyrzucone poza zakres przez remove_if)
    activeEffects.erase(
        // remove_if zostawia wszystkie aktywne efekty i usuwa z zakresu wektora te dla których czas się skończył
        std::remove_if(activeEffects.begin(), activeEffects.end(),
                       // lambda jako parametr bierze obecnie iterowany efekt i sprawdza, czy jego czas trwania jest <=0
                       [](const StatusEffect &e)
                       {
                           return e.remainingDuration <= 0;
                       }),
        activeEffects.end());
}

std::vector<StatusEffect> StatusEffectManager::getActiveEffects() const
{
    // zwraca aktywne efekty
    return activeEffects;
}
