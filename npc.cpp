// schurke.cpp
// Created by webo on 11.03.2024.
//

#include <iostream>

#include "npc.h"
#include "hero.h"



Schurke::Schurke(const std::string& name, int health, int gold, int armorDefenseValue, int magicalDefenseValue) : Character(name, health, gold, armorDefenseValue, magicalDefenseValue) {   //Parameterkonstruktor für Character //
//        this->inventory = Inventory();   //wird in Character-Konstruktor initialisiert
//        this->weapon = Item("empty-constructor", 0, 0, false);
//        this->armor = Item("empty-constructor", 0, 0, false);
//        this->accessory = Item("empty-constructor", 0, 0, false);
}

Schurke::Schurke() : Character("unknown", 0, 0, 0, 0) {
    // Initialisierungslogik für den Standardkonstruktor
//    this->weapon = Item("empty-constructor", 0, 0, false);
//    this->armor = Item("empty-constructor", 0, 0, false);
//    this->accessory = Item("empty-constructor", 0, 0, false);
}

//void Schurke::newEmeny(const std::string& name, int health, int gold, int armorDefenseValue, int magicalDefenseValue) {
//    setName(const_cast<std::string &>(name));
//    setHealth(health);
//    setGold(gold);
//    setPhysicalBodyDefenseValue(armorDefenseValue);
//    getMagicalBodyDefenseValue(magicalDefenseValue);
//}

void Schurke::attack(Hero* hero) {
    int attackPower = getRandomNumber(5,15);            //rand() % 11 + 5;
    int attackPowerMagic = 0;

    std::string weaponName;
    weaponName = "";

    if (this->getWeaponIsValid()) {   //wenn eine Waffe ausgerüstet ist, wird der Schaden erhöht
        weaponName = this->getWeaponName();
    }
    attackPower = attackPower + this->requestPhysicalStrength() + this->getWeaponStrength() - hero->getPhysicalBodyDefenseValue() - hero->getArmorStrength();   //Schaden wird durch Rüstung des Gegners verringert;
    attackPowerMagic = attackPowerMagic + this->requestMagicalPower() + this->getWeaponMagic() - hero->getMagicalBodyDefenseValue() - hero->getArmorMagic() - hero->getAccessoryMagic();   //Schaden wird durch magische Rüstung des Gegners verringert;
    (attackPower < 0 ? attackPower = 0 : attackPower = attackPower);
    (attackPowerMagic < 0 ? attackPowerMagic = 0 : attackPowerMagic = attackPowerMagic);

    attackPower = attackPower + attackPowerMagic;

    std::cout << "Der Schurke " << this->getNameChar() << " tifft" << (this->getWeaponIsValid() ? " mit seinem " : "") << weaponName << " " << hero->getNameChar() << " fuer " << attackPower << " Lebenspunkte!" << std::endl;
    hero->getDamage(attackPower);
    if (attackPower == 0) {
        std::cout << "(*) Die Heldin " << hero->getNameChar() << " hat den Angriff abgewehrt! Hurra!" << std::endl;
        hero->dodgecry();
    }
}

void Schurke::itemDrop(Hero* hero, const Item& defaultItem) {
    std::cout << "(*) Der Schurke " << this->getNameChar() << " hat etwas fallen gelassen! ";
    //Text in main() eingebaut
    // Füge das Item zum Inventar des Helden hinzu
    hero->addItemToInventory(defaultItem);

    std::cout << "Gegenstand " << defaultItem.getName() << " wurde zum Inventar hinzugefuegt." << std::endl;
}

void Schurke::goldDrop(Hero *hero, int gold) {
    std::cout << "(*) Der Schurke " << this->getNameChar() << " hat " << gold << " Gold fallen gelassen! ";

    // Füge das Gold zum Inventar des Helden hinzu
    hero->earnGold(gold);

    std::cout << hero->getNameChar() << " hat nun " << hero->getGold() << " Gold." << std::endl;
}

