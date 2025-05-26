#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Item.h"
#include <memory> // shared_ptr w wektorze items
#include <string>
#include <vector>

// klasa gracza
class Player : public Entity
{
private:
    const std::string m_playerName;

public:
    Player(std::string className, int hp, double ms, int MAX_HP = 100, std::string playerName = "Me")
        : Entity(className, hp, ms, MAX_HP), m_playerName(playerName) {}

    // getter wybranego imienia gracza
    const std::string &getPlayerName() const;

    // getter nazwy klasy, w przypadku gracza zwraca imie
    const std::string &getClassName() const override;

    // setter HP, implementacja otrzymywania obrażeń
    void takeDamage(int damage) override
    {
        return Entity::takeDamage(damage);
    }

    // getter HP
    int getHealthPoints() const override
    {
        return Entity::getHealthPoints();
    }

    // getter maksymalnegoHP
    const int getMaxHEALTH() const override
    {
        return Entity::getMaxHEALTH();
    }

    // getter moveSpeeda
    double getMoveSpeed() const override
    {
        return Entity::getMoveSpeed();
    }

    // naklada efekt na target
    void applyEffect(Entity &target) override
    {
        return Entity::applyEffect(target);
    }

    ~Player() = default;

    // klasa zagnieżdżona Inventory obsługująca ekwipunek gracza
    class Inventory
    {
    private:
        std::vector<std::shared_ptr<Item>> m_items; // smart pointer który pozwala na przechowywanie różnych podklas w wektorze

    public:
        void addItem(const std::shared_ptr<Item> &item);       // dodawanie przedmiotu do ekwipunku
        void removeItem(const std::shared_ptr<Item> &item);    // usuwanie przedmiotu z ekwipunku np. przy użyciu
        bool hasItem(const std::shared_ptr<Item> &item) const; // sprawdza czy przedmiot jest w ekwipunku
        void listItems() const;                                // wypisuje wszystkie przedmioty, które gracz obecnie posiada
        // getter itemów
        std::vector<std::shared_ptr<Item>> getItems() const;
    };

    const Inventory &getInventory() const; // dostęp do ekwipunku dla funkcji nie modifykujących go

    Inventory &getInventory(); // dostęp do ekwipunku

private:
    Inventory m_inventory; // prywatny ekwipunek dla gracza
};

#endif
