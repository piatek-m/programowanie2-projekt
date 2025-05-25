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
    Player(std::string className, int hp, double ms, std::string playerName)
        : Entity(className, hp, ms), m_playerName(playerName) {}

    // getter wybranego imienia gracza
    const std::string &getPlayerName() const;

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
    };

    Inventory &getInventory(); // dostęp do ekwipunku

private:
    Inventory m_inventory; // prywatny ekwipunek dla gracza
};

#endif
