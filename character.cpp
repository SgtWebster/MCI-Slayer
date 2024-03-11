// character.cpp
// Created by Oliver Weber on 23.02.2024.
//

#include <iostream>
#include <string>
#include "hero.h"
#include "character.h"
#include "item.h"
//using namespace std;


Character::Character(std::string& name, int health, int gold) : name(name), health(health), gold(gold) {

    for (auto & item : this->inventory) {
        item = Item((std::string &) "empty", 0, 0, false);     // Direkte Zuweisung zu 'item', nicht 'inventory[i]'
    }
}

void Character::getDamage(int damage) {    //setter for health
    this->health -= damage;
}

void Character::earnGold(int goldValue) {   //setter for gold
    this->gold += goldValue;
}

/////////////////////////////////////////////// Schurken-Angelegenheiten

void Schurke::attack(Hero* hero) {
    int attackPower = rand() % 11 + 5;

    if (hero->getEquipmentIsValid(1)) {   //...wenn Held eine Rüstung trägt... (wird der Angriff um 5 verringert)
        attackPower -= hero->getEquipmentStrengh(1);
    }

    std::cout << "Der Schurke " << Schurke::getName() <<  " tifft " << hero->getName() << " fuer " << attackPower << " Lebenspunkte!" << std::endl;
    hero->getDamage(attackPower);
}

void Schurke::newEmeny(std::string& name, int health, int gold) {
    this->setName(name);
    this->setHealth(health);
    this->setGold(gold);
}
