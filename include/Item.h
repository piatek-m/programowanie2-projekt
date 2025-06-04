#ifndef ITEM_H
#define ITEM_H

#include <string>

// forward declaration, potrzebne do useItem
class Player;
class Entity;

class Item
{
protected:
    std::string m_itemName;

public:
    Item(const std::string &iname) : m_itemName(iname) {};

    // getter nazwy itemku
    const std::string &getItemName() const;

    // zwraca typ itemku np. itemki kluczowe można oznaczyć jako key, leczące jako healing itd.
    virtual std::string getItemType() const { return "Default"; }

    // przeciążenie operatora porównania, sprawdza czy nazwy itemków są identyczne
    bool operator==(const Item &other) const;

    // użycie itemu, wykonuje daną akcję itemu zdefiniowaną w klasach dziedziczących oraz usuwa użyty przedmiot z inventory (implementować w dziedziczących)
    virtual void useItem(Entity &target) = 0;

    virtual void useItem(Player &player);

    // wirtualny dekonstruktor
    virtual ~Item() = default;
};

#endif
