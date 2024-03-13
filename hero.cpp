// hero.cpp
// Created by Oliver Weber on 23.02.2024.
//

#include <iostream>
#include <string>
#include <cstdlib>   // for rand()
#include "hero.h"
//#include "item.h"
//#include "character.h"
//#include "schurke.h"
//using namespace std;



Hero::Hero(const std::string& name, int health, int gold) : Character(name, health, gold) {    //Parameterkonstruktor für Hero
    this->theForce = false;
    this->fight = false;
}

void Hero::attack(Schurke *emeny) {    //Hero greift Schurke an
    int attackPower = rand() % 11 + 15;
    std::string weaponName;
    weaponName = "";
    if (this->getWeaponIsValid()) {
        weaponName = this->getWeaponName();
        attackPower += this->getWeaponStrength();
    }
    if (this->theForce) {
        attackPower += 25;
    }
    std::cout << this->getNameChar() << " tifft" << (this->getWeaponIsValid() ? " mit ihrem " : "") << weaponName << " " << emeny->getNameChar() << " fuer " << attackPower << " Lebenspunkte!" << (this->getTheForce() ? " Die Macht ist stark mit dieser da!" : "") << std::endl;
    emeny->getDamage(attackPower);
}

bool Hero::startFight(Schurke* emeny) {                     //FIGHT-Modus! Läuft so lange bis der Kampf zu ende ist! false = lost, true = won
    std::cout << this->getNameChar() << " greift " << emeny->getNameChar() << " an!" << std::endl;

    while (true) {
        this->attack(emeny);
        if (emeny->getHealth() <= 0) {
            return true;
        }
        emeny->attack(this);
        if (this->getHealth() <= 0) {
            return false;
        }
    }
    return false;   //Should never be reached (Backup)
}

void Hero::setTheForceTrue()  {
    this->theForce = true;
//    std::cout << this->getNameChar() << " spuert eine Erschuetterung in der Macht!" << std::endl;
//    std::cout << "Die Macht ist mit " << this->getNameChar() << "!" << std::endl;
}


// folgendes wurde in Inventar und Character bereits implementiert
//void Hero::sellItem(int index) {
//
//    Item* item = &(this->getItem[index]);
//
//    if (item->getIsValid()) {
//        this->gold += item->value;
//        std::cout << "Gegenstand " << item->name << " wurde verkauft. " << this->name << " besitzt nun " << this->gold << " Gold." << std::endl;
//        item->isValid = false;
//        item->name = "empty";
//        item->value = 0;
//    } else {
//        std::cout << "Der Slot ist leer!" << std::endl;
//
//    }
//return;
//
//}
//
//void Hero::useItem(int index) {
//    if (hero == nullptr || index < 0 || index >= 10) {
//        std::cout << "Ungueltige Eingabe: Slot-Platz nicht gueltig!" << std::endl;
//        return;
//    }
//
//    Item* item = &(this->inventory[index]);
//
//    if (item->isValid) {
//
//        //0 = consumable, 1 = weapon, 2 = armor
//        switch (item->type) {
//            case 0:
//                this->health += 50;
//                std::cout << "Gegenstand " << item->name << " wurde benutzt. " << this->name << " besitzt nun " << this->health << " Lebenspunkte." << std::endl;
//                item->isValid = false;
//                item->name = "empty";
//                item->value = 0;
//                break;
//            case 1:
//                this->equipment[0] = *item;
//                std::cout << "Waffe " << item->name << " wurde angelegt. " << this->name << " besitzt nun " << this->equipment[0].name << " als Waffe." << std::endl;
//                item->isValid = false;
//                item->name = "empty";
//                item->value = 0;
//                break;
//            case 2:
//                this->equipment[1] = *item;
//                std::cout << "Ruestung " << item->name << " wurde angelegt. " << this->name << " besitzt nun " << this->equipment[1].name << " als Ruestung." << std::endl;
//                item->isValid = false;
//                item->name = "empty";
//                item->value = 0;
//                break;
//            case 3:
//                std::cout << "Gegenstand " << item->name << " wurde benutzt. " << this->name << " spuert eine Erschuetterung in der Macht!" << std::endl;
//                std::cout << "Die Macht ist mit " << this->name << "!" << std::endl;
//                this->theForce = true;
//                item->isValid = false;
//                item->name = "empty";
//                item->value = 0;
//                break;
//            default:
//                std::cout << "Ungueltige Eingabe!" << std::endl;
//                break;
//        }
//
//    } else {
//        std::cout << "Der Slot ist leer!" << std::endl;
//    }
//}



//void getDamage(int damage) {
//    this->health -= damage;
//    std::cout << this->name << " hat " << damage << " Schaden erlitten. " << this->name << " hat nun " << this->health << " Lebenspunkte." << std::endl;
//}