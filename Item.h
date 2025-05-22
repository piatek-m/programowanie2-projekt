#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
protected:
    std::string m_itemName;

public:
    Item(const std::string& iname): m_itemName(iname) {};

    // getter nazwy itemku
    const std::string& getItemName() const;

    // zwraca typ itemku np. itemki kluczowe można oznaczyć jako key, leczące jako healing itd.
    virtual std::string getItemType() const { return "Default"; }

    // przeciążenie operatora porównania, sprawdza czy nazwy itemków są identyczne
    bool operator==(const Item& other) const;

    // wirtualny dekonstruktor
    virtual ~Item() = default;
};

#endif
