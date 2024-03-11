// hero.cpp
// Created by Oliver Weber on 23.02.2024.
//

#include <iostream>
#include <string>
#include <cstdlib>   // for rand()
#include "hero.h"
#include "item.h"
#include "character.h"
//using namespace std;



Hero::Hero(std::string& name, int health, int gold) : name(name), health(health), gold(gold) {    //Parameterkonstruktor für Hero
    this->theForce = false;
    this->fight = false;

    for (auto & item : this->equipment) {
        item = Item((std::string &) "empty", 0, 0, false); // Direkte Zuweisung zu 'item', nicht 'equipment[i]'
    }

}

void Hero::startFight(Schurke *enemy) {
//TODO
}


void Hero::attack(Schurke *emeny) {
    int attackPower = rand() % 11 + 15;
    std::string weaponName;
    weaponName = "";
    if (this->getEquipmentIsValid(0)) {
        weaponName = this->getEquipmentName(0); //equipment index 0 = weapon
        attackPower += this->getEquipmentStrengh(0);
    }
    if (this->theForce) {
        attackPower += 25;
    }
    std::cout << this->getName() <<  " tifft"<< (this->equipment[0].getIsValid() ? " mit ihrem ": "") << weaponName << " " << emeny->getName() << " fuer " << attackPower << " Lebenspunkte!" << (this->getTheForce() ? " Die Macht ist stark mit dieser da!" :"") << std::endl;
    emeny->getDamage(attackPower);
}


void Hero::sellItem(int index) {

//    if (hero == nullptr || index < 0 || index >= 10) {
//        std::cerr << "Ungueltige Eingabe: Slot-Platz nicht gueltig!" << std::endl;
//        return;
}

    Item* item = &(this->inventory[index]);

    if (item->isValid) {
        this->gold += item->value;
        std::cout << "Gegenstand " << item->name << " wurde verkauft. " << this->name << " besitzt nun " << this->gold << " Gold." << std::endl;
        item->isValid = false;
        item->name = "empty";
        item->value = 0;
        return;
    } else {
        std::cout << "Der Slot ist leer!" << std::endl;
        return;
    }

}

void Hero::useItem(int index) {
//    if (hero == nullptr || index < 0 || index >= 10) {
//        std::cout << "Ungueltige Eingabe: Slot-Platz nicht gueltig!" << std::endl;
//        return;
//    }

    Item* item = &(this->inventory[index]);

    if (item->isValid) {

        //0 = consumable, 1 = weapon, 2 = armor
        switch (item->type) {
            case 0:
                this->health += 50;
                std::cout << "Gegenstand " << item->name << " wurde benutzt. " << this->name << " besitzt nun " << this->health << " Lebenspunkte." << std::endl;
                item->isValid = false;
                item->name = "empty";
                item->value = 0;
                break;
            case 1:
                this->equipment[0] = *item;
                std::cout << "Waffe " << item->name << " wurde angelegt. " << this->name << " besitzt nun " << this->equipment[0].name << " als Waffe." << std::endl;
                item->isValid = false;
                item->name = "empty";
                item->value = 0;
                break;
            case 2:
                this->equipment[1] = *item;
                std::cout << "Ruestung " << item->name << " wurde angelegt. " << this->name << " besitzt nun " << this->equipment[1].name << " als Ruestung." << std::endl;
                item->isValid = false;
                item->name = "empty";
                item->value = 0;
                break;
            case 3:
                std::cout << "Gegenstand " << item->name << " wurde benutzt. " << this->name << " spuert eine Erschuetterung in der Macht!" << std::endl;
                std::cout << "Die Macht ist mit " << this->name << "!" << std::endl;
                this->theForce = true;
                item->isValid = false;
                item->name = "empty";
                item->value = 0;
                break;
            default:
                std::cout << "Ungueltige Eingabe!" << std::endl;
                break;
        }

    } else {
        std::cout << "Der Slot ist leer!" << std::endl;
    }
}


bool Hero::fight(Character* character) {                     //FIGHT! FIGHT! FIGHT! false = lost, true = won
    std::cout << this-> name << " greift " << character->name << " an!" << std::endl;

    while (true) {
        this->attack(this, character);
        if (character->health <= 0) {
            return true;
        }
        character->attack(character, this);
        if (this->health <= 0) {
            return false;
        }
    }
    return false;   //Should never be reached (Backup)
}


void getDamage(int damage) {
    this->health -= damage;
    std::cout << this->name << " hat " << damage << " Schaden erlitten. " << this->name << " hat nun " << this->health << " Lebenspunkte." << std::endl;
}