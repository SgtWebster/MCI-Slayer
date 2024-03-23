// schurke.h
// Created by webo on 11.03.2024.
//

#ifndef SCHURKE_H
#define SCHURKE_H

#include <string>

#include "character.h"


class Hero;      //Forward declaration of Hero


class Schurke : public Character {
public:

    Schurke(const std::string& name, int health, int gold, int armorDefenseValue = 0, int magicalDefenseValue = 0); // : Character(name, health, armorDefenseValue, magicalDefenseValue) {}    //Parameterkonstruktor
    Schurke(); // : Character() {}        //Standardkonstruktor

    void attack(Hero* hero);   //Schurke greift Helden an

    void itemDrop(Hero *hero, const Item &defaultItem);
    void goldDrop(Hero *hero, int gold);

    virtual int requestPhysicalStrength() const {return 0;}

    virtual int requestMagicalPower() const {return 0;}

};


#endif //SCHURKE_H
