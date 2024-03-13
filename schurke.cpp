// schurke.cpp
// Created by webo on 11.03.2024.
//

#include <iostream>
//#include "character.h"
#include "hero.h"
#include "schurke.h"
//#include "inventory.h"

void Schurke::newEmeny(const std::string& name, int health, int gold) {
    setName(const_cast<std::string &>(name));
    setHealth(health);
    setGold(gold);
}

void Schurke::attack(Hero* hero) {
    int attackPower = rand() % 11 + 5;

    if (hero->getArmorIsValid()) {   //...wenn Held eine Rüstung trägt... (wird der Angriff um Sträke-Wert der Rüstung verringert)
        attackPower -= hero->getArmorStrength();
    }
    if (attackPower < 0) {
        attackPower = 0;
    }

    std::string weaponName;
    weaponName = "";
    if (this->getWeaponIsValid()) {
        weaponName = this->getWeaponName();
        attackPower += this->getWeaponStrength();
    }

    std::cout << "Der Schurke " << this->getNameChar() << " tifft " << (this->getWeaponIsValid() ? " mit seinem " : "") << weaponName << "" << hero->getNameChar() << " fuer " << attackPower << " Lebenspunkte!" << std::endl;
    hero->getDamage(attackPower);
}

void Schurke::itemDrop(Hero* hero, const Item& defaultItem) {
    std::cout << "Der Schurke " << this->getNameChar() << " hat Zeugs fallen gelassen!" << std::endl;

    // Füge das Item zum Inventar des Helden hinzu
    hero->addItemToInventory(defaultItem);

    std::cout << "Gegenstand " << defaultItem.getName() << " wurde zum Inventar hinzugefuegt." << std::endl;
}

void Schurke::goldDrop(Hero *hero, int gold) {
    std::cout << "Der Schurke " << this->getNameChar() << " hat " << gold << " Gold fallen gelassen!" << std::endl;

    // Füge das Gold zum Inventar des Helden hinzu
    hero->earnGold(gold);

    std::cout << hero->getNameChar() << " hat nun " << hero->getGold() << " Gold." << std::endl;
}

