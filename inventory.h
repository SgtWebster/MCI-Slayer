// inventory.h
// Created by webo on 11.03.2024.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <optional>
#include "GameConfig.h"

#include "schurke.h"


//class Character; //Forward declaration of Character

class Inventory {
public:
    //Konstruktor
    Inventory() = default; //Standardkonstruktor
    ~Inventory() = default; //Destruktor

    //Methods
    void addItem(const Item& item);                     // Füge ein Item hinzu
    bool isSlotValid(int index) const;                  // Prüfe, ob ein Slot ein gültiges Item enthält
    void removeItem(int index);                         // Entferne ein Item aus einem bestimmten Slot

    const Item* getItem(int index) const;           // Hole ein Item aus einem bestimmten Slot (weiterverwendung für getter/setter

    void checkBackpack(Character* thisCharacter);                     //Ausgabe des Inventars
    int listItems(bool nummernAnzeigen) const;
    void sellItem(Character* thisCharacter);                                    // Verkaufe ein Item
    void useItem(Character* thisCharacter);                                     // Benutze ein Item
    void checkItem(Character* thisCharacter);

private:
    std::vector<Item> items;
};

#endif //INVENTORY_H
