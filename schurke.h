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

//    Schurke() : Character("unkown", 0, 0, 0, 0) {}        //Standardkonstruktor

    void attack(Hero* hero);   //Schurke greift Helden an
//    void newEmeny(const std::string& name, int health, int gold, int armorDefenseValue=0, int magicalDefenseValue=0);   //neuer Schurke wird initialisiert
    void itemDrop(Hero *hero, const Item &defaultItem);
    void goldDrop(Hero *hero, int gold);

};


#endif //SCHURKE_H
