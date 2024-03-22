// hero.cpp
// Created by Oliver Weber on 23.02.2024.
//

#include <iostream>
#include <string>
#include <cstdlib>   // for rand()

#include "hero.h"
#include "schurke.h"


Hero::Hero(const std::string& name, int health, int gold, int armorDefenseValue, int magicalDefenseValue) : Character(name, health, gold, armorDefenseValue, magicalDefenseValue) {    //Parameterkonstruktor für Hero
    this->theForce = false;
    this->fight = false;
}

void Hero::attack(Schurke *emeny) {    //Hero greift Schurke an
    int attackPower = rand() % 11 + 15;    //TODO -> Levelabhängigkeit
    int attackPowerMagic = 0;
    std::string weaponName;
    weaponName = "";

    if (this->getWeaponIsValid()) {   //wenn eine Waffe ausgerüstet ist, wird der Schaden erhöht
        weaponName = this->getWeaponName();
    }
    attackPower = attackPower + this->getWeaponStrength() - emeny->getPhysicalBodyDefenseValue() - emeny->getArmorStrength();   //Schaden wird durch Rüstung des Gegners verringert;
    attackPowerMagic = attackPowerMagic + this->getWeaponMagic() - emeny->getMagicalBodyDefenseValue() - emeny->getArmorMagic();   //Schaden wird durch magische Rüstung des Gegners verringert;
    (attackPower < 0 ? attackPower = 0 : attackPower = attackPower);
    (attackPowerMagic < 0 ? attackPowerMagic = 0 : attackPowerMagic = attackPowerMagic);

    if (this->theForce) {    //wenn die Macht stark ist, wird der Schaden erhöht
        attackPower += 25;
    }

    attackPower += attackPowerMagic;

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