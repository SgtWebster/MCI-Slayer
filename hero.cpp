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
    //return false;   //Should never be reached (Backup)
}

void Hero::setTheForceTrue() {
    this->theForce = true;
}