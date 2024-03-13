// character.h
// Created by Oliver Weber on 23.02.2024.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include "item.h"
//#include "hero.h"
//#include "schurke.h"
#include "inventory.h"
#include "GameConfig.h" //max Inventory


class Hero;          //Forward declaration of Hero

class Character {    //class for Character (enemys)
public:
    //Konstruktor
    Character(std::string& name, int health, int gold);   //Parameterkonstruktor
    Character() : name("unkown"), health(0), gold(0) {}         //Standardkonstruktor

    //Destruktor
    ~Character() = default;

    //Methods
    void getDamage(int damage); //setter for health
    void earnGold(int gold);    //setter for gold

    //getter
    std::string getNameChar() const { return name; }
    int getHealth() const { return health; }
    int getGold() const { return gold; }

    //setter
    void setName(std::string& newName) { this->name = newName; }
    void setHealth(int newHealth) { this->health = newHealth; }
    void setGold(int newGold) { this->gold = newGold; }

    //getter for inventory slots
    std::string getInventoryName(int itemSlot) const { return inventory.getItem(itemSlot)->getName(); }
    int getInventoryValue(int itemSlot) const { return inventory.getItem(itemSlot)->getValue(); }
    int getInventoryType(int itemSlot) const { return inventory.getItem(itemSlot)->getType(); }
    bool getInventoryIsValid(int itemSlot) const { return inventory.getItem(itemSlot)->getIsValid(); }
    int getInventoryStrengh(int itemSlot) const { return inventory.getItem(itemSlot)->getStrengh(); }

    //equipment
    void equipWeapon(const Item &item);   //setter for weapon
    void equipArmor(const Item &item);    //setter for armor

    void silentWeaponEquip(const Item &item);   //setter for silentWeapon (use for initial equip)
    void silentArmorEquip(const Item &item);    //setter for silentArmor (use for initial equip)

    //getter for equipment - Weapon
    std::string getWeaponName() const { return this->weapon.getName(); }
    bool getWeaponIsValid() const { return this->weapon.getIsValid(); }
    int getWeaponStrength() const { return this->weapon.getStrengh(); }

    //getter for equipment - Armor
    std::string getArmorName() const { return this->armor.getName(); }
    bool getArmorIsValid() const { return this->armor.getIsValid(); }
    int getArmorStrength() const { return this->armor.getStrengh(); }


    //getter Force
    void setTheForceTrue(); //setter for theForce

    //inventory handling
    void addItemToInventory(const Item &item);

private:
    std::string name;
    int health;
    int gold;
    Inventory inventory;

    Item weapon;
    Item armor;


};
/////////////////////////////////////////////// Schurken-Angelegenheiten
//class Schurke in eigne .h/.cpp ausgelagert

#endif //CHARACTER_H