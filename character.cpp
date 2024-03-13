// character.cpp
// Created by Oliver Weber on 23.02.2024.
//

#include <iostream>
#include <string>
//#include "hero.h"
#include "character.h"
//#include "item.h"
//using namespace std;


Character::Character(const std::string& name, int health, int gold) : name(name), health(health), gold(gold) {
    this->inventory = Inventory();
    this->weapon = Item("empty", 0, 0, false);
    this->armor = Item("empty", 0, 0, false);
}

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
    if (newArmor.getType() == 1) {

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
void Character::silentWeaponEquip(const Item &item) {
    this->weapon = item;
}

void Character::silentArmorEquip(const Item &item) {
    this->armor = item;
}

void Character::checkBackpack() {
    this->inventory.checkBackpack(this);
}

void Character::checkEquipment() {
    //hline();
    if (this->getWeaponIsValid()) {
        std::cout << "[*] Waffe: " << this->getWeaponName() << " (Angriff: +"<< this->getWeaponStrength() <<")" << std::endl;
    } else {
        std::cout << "[*] Waffe: keine (Faeuste)" << std::endl;
    }
    if (this->getArmorIsValid()) {
        std::cout << "[*] Ruestung: " << this->getArmorName() << " (Abwehr: +"<< this->getArmorStrength() <<")" << std::endl;
    } else {
        std::cout << "[*] Ruestung: keine" << std::endl;
    }
}


void Character::setTheForceTrue() {
    std::cerr << "Die Macht ist nicht stark mit diesem hier!" << std::endl;   //sollte bei Character eigentlich nie vorkommen (daher ungenutzt)
}
/////////////////////////////////////////////// Schurken-Angelegenheiten
//class Schurke in eigne .h/.cpp ausgelagert