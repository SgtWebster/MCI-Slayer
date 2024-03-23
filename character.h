// character.h
// Created by Oliver Weber on 23.02.2024.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include "inventory.h"


//class Inventory;     //Forward declaration of Inventory

class Character {    //eltern class for Character, Hero, Schurken...
protected:
    std::string name;
    int health;
    int gold;
    Inventory inventory;

    Item weapon;
    Item armor;
    Item accessory;
    Item special;

    //new with ÜZ3:
    int armorDefenseValue;
    int magicalDefenseValue;

public:
    //Konstruktor
    Character(const std::string& name, int health, int gold, int armorDefenseValue = 0, int magicalDefenseValue = 0);    //Parameterkonstruktor
    Character();         //Standardkonstruktor
    Character(const Character &character); //Copy-Konstruktor (für deep copy von Inventory

    //Destruktor
    ~Character() = default;

    //Methods
    void getDamage(int damage); //setter for health
    void earnGold(int gold);    //setter for gold

    //getter
    std::string getNameChar() const { return name; }
    int getHealth() const { return health; }
    int getGold() const { return gold; }

    //setter -- nicht in Verwendung (nur via Konstruktor
//    void setName(std::string& newName) { this->name = newName; }
//    void setHealth(int newHealth) { this->health = newHealth; }
//    void setGold(int newGold) { this->gold = newGold; }

    //equipment
    void equipWeapon(const Item &item);   //setter for weapon
    void equipArmor(const Item &item);    //setter for armor
    void equipAccessory(const Item &item);    //setter for accessory

    void silentWeaponEquip(const Item &item);   //setter for silentWeapon (use for initial equip)
    void silentArmorEquip(const Item &item);    //setter for silentArmor (use for initial equip)
    void silentAccessoryEquip(const Item &item);    //setter for silentAccessory (use for initial equip)
    void silentSpecialEquip(const Item &item);    //setter for silentSpecial (use for initial equip)

    //getter for equipment - Weapon
    std::string getWeaponName() const { return this->weapon.getName(); }
    bool getWeaponIsValid() const { return this->weapon.getIsValid(); }
    int getWeaponStrength() const { return this->weapon.getStrengh(); }
    int getWeaponMagic() const { return this->weapon.getMagic(); }
    Item getWeapon() const { return this->weapon; }

    //getter for equipment - Armor
    std::string getArmorName() const { return this->armor.getName(); }
    bool getArmorIsValid() const { return this->armor.getIsValid(); }
    int getArmorStrength() const { return this->armor.getStrengh(); }
    int getArmorMagic() const { return this->armor.getMagic(); }
    Item getArmor() const { return this->armor; }

    //getter for equipment - Accessory
    std::string getAccessoryName() const { return this->accessory.getName(); }
    bool getAccessoryIsValid() const { return this->accessory.getIsValid(); }
    int getAccessoryStrength() const { return this->accessory.getStrengh(); }
    int getAccessoryMagic() const { return this->accessory.getMagic(); }
    Item getAccessory() const { return this->accessory; }

    //getter for equipment - Special
    std::string getSpecialName() const { return this->special.getName(); }
    bool getSpecialIsValid() const { return this->special.getIsValid(); }
    int getSpecialStrength() const { return this->special.getStrengh(); }
    int getSpecialMagic() const { return this->special.getMagic(); }
    Item getSpecial() const { return this->special; }

    //getter Force
    virtual void setTheForceTrue(); //setter for theForce

    //inventory handling
    void addItemToInventory(const Item &item);
    void checkBackpack();
    void checkEquipment() const;

    //new with ÜZ3:
    int getPhysicalBodyDefenseValue() const { return armorDefenseValue; }
    int getMagicalBodyDefenseValue() const { return magicalDefenseValue; }
    void setPhysicalBodyDefenseValue(int newArmorDefenseValue) { this->armorDefenseValue = newArmorDefenseValue; }
    void setMagicalBodyDefenseValue(int newMagicalDefenseValue) { this->magicalDefenseValue = newMagicalDefenseValue; }

    bool isSomethingInInventory() const;   //checken, ob das Inventar leer ist (true -> da is was da!)
    Item getItemFromInventory(int slot) const;   //Item aus dem Inventar holen



};


#endif //CHARACTER_H