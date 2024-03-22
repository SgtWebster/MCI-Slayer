// character.cpp
// Created by Oliver Weber on 23.02.2024.
//

#include <iostream>
#include <string>

#include "character.h"



Character::Character(const std::string& name, int health, int gold, int armorDefenseValue, int magicalDefenseValue) : name(name), health(health), gold(gold), armorDefenseValue(armorDefenseValue), magicalDefenseValue(magicalDefenseValue) {   //Parameterkonstruktor für Character //
    this->inventory = Inventory();
    this->weapon = Item("empty-constructor", 0, 0, false);
    this->armor = Item("empty", 0, 0, false);
    this->accessory = Item("empty", 0, 0, false);
}

Character::Character() : name("unkown"), health(0), gold(0), armorDefenseValue(0), magicalDefenseValue(0) {
    this->inventory = Inventory();
    this->weapon = Item("empty-constructor", 0, 0, false);
    this->armor = Item("empty-constructor", 0, 0, false);
    this->accessory = Item("empty-constructor", 0, 0, false);
}         //Standardkonstruktor

void Character::getDamage(int damage) {    //setter for health
    this->health -= damage;
}

void Character::earnGold(int goldValue) {   //setter for gold
    this->gold += goldValue;
}

void Character::addItemToInventory(const Item& item) {
    this->inventory.addItem(item);
}

void Character::equipWeapon(const Item &newWeapon) {
    if (newWeapon.getType() == 1) {

        if (this->weapon.getIsValid()) {   //wenn bereits eine Waffe ausgerüstet ist, wird diese wieder ins Inventar gelegt
            Item tempItem = Item(this->weapon);
            this->addItemToInventory(this->weapon);
            std::cout << "Die Waffe " << tempItem.getName() << " wurde wieder ins Inventar gelegt!" << std::endl;
        }
        this->weapon = newWeapon;
        std::cout << "Die Waffe " << newWeapon.getName() << " wurde ausgeruestet!" << std::endl;
    } else {
        std::cerr << "Ungueltiger Waffentyp!" << std::endl;
        }
}

void Character::equipArmor(const Item &newArmor) {
    if (newArmor.getType() == 2) {

        if (this->armor.getIsValid()) {   //wenn bereits eine Rüstung ausgerüstet ist, wird diese wieder ins Inventar gelegt
            Item tempItem = Item(this->armor);
            this->addItemToInventory(this->armor);
            std::cout << "Die Ruestung " << tempItem.getName() << " wurde wieder ins Inventar gelegt!" << std::endl;
        }
        this->armor = newArmor;
        std::cout << "Die Ruestung " << newArmor.getName() << " wurde ausgeruestet!" << std::endl;
    } else {
        std::cerr << "Ungueltiger Ruestungstyp!" << std::endl;
    }
}

void Character::equipAccessory(const Item &item) {
    if (item.getType() == 3) {

        if (this->accessory.getIsValid()) {   //wenn bereits ein Accessoire ausgerüstet ist, wird dieses wieder ins Inventar gelegt
            Item tempItem = Item(this->accessory);
            this->addItemToInventory(this->accessory);
            std::cout << "Das Accessoire " << tempItem.getName() << " wurde wieder ins Inventar gelegt!" << std::endl;
        }
        this->accessory = item;
        std::cout << "Das Accessoire " << item.getName() << " wurde ausgeruestet!" << std::endl;
    } else {
        std::cerr << "Ungueltiger Accessoiretyp!" << std::endl;
    }
}

void Character::silentWeaponEquip(const Item &item) {
    this->weapon = item;
}

void Character::silentArmorEquip(const Item &item) {
    this->armor = item;
}

void Character::silentAccessoryEquip(const Item &item) {
    this->accessory = item;
}

void Character::checkBackpack() {
    this->inventory.checkBackpack(this);
}

void Character::checkEquipment() {
    //Hilfsvariablen für die Ausgabe
    std::string magicAttackInfo = this->getWeaponMagic() > 0 ? " (Magieangriff: +" + std::to_string(this->getWeaponMagic()) + ")" : "";
    std::string magicDefenseInfo = this->getArmorMagic() > 0 ? " (Magieabwehr: +" + std::to_string(this->getArmorMagic()) + ")" : "";
    std::string magicAccessoryInfo = this->getAccessoryMagic() > 0 ? " (Magie: +" + std::to_string(this->getAccessoryMagic()) + ")" : "";

    if (this->getWeaponIsValid()) {
        std::cout << "[*] Waffe: " << this->getWeaponName() << " (Angriff: +"<< this->getWeaponStrength() <<")" << magicAttackInfo << std::endl;
    } else {
        std::cout << "[*] Waffe: keine (Faeuste)" << std::endl;
    }
    if (this->getArmorIsValid()) {
        std::cout << "[*] Ruestung: " << this->getArmorName() << " (Abwehr: +"<< this->getArmorStrength() <<")" << magicDefenseInfo << std::endl;
    } else {
        std::cout << "[*] Ruestung: keine (weisses T-Shirt)" << std::endl;
    }
    if (this->getAccessoryIsValid()) {
        std::cout << "[*] Accessoire: " << this->getAccessoryName() << " (Staerke: +"<< this->getAccessoryStrength() <<")" << magicAccessoryInfo<< std::endl;
    } else {
        std::cout << "[*] Accessoire: keine" << std::endl;
    }
}

void Character::setTheForceTrue() {
    std::cerr << "Die Macht ist nicht stark mit diesem hier!" << std::endl;   //sollte bei Character eigentlich nie vorkommen (daher ungenutzt)
}

