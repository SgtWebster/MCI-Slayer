// inventory.h
// Created by webo on 11.03.2024.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <optional>
#include "item.h"
//#include "character.h"

class Character; //Forward declaration of Character

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

private:
    std::vector<Item> items;
};


// not needed for the moment  (replaced by character attributes)
//class Equipment : public Inventory {
//public:
//    void equipItem(int index);                          // Rüste ein Item aus
//    void unequipItem(int index);                        // Entferne ein Item aus der Ausrüstung
//
//    //TDOO: Erweitere diese Methode, um eine Liste aller ausgerüsteten Items zu erhalten usw
//};


#endif //INVENTORY_H
