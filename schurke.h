// schurke.h
// Created by webo on 11.03.2024.
//

#ifndef SCHURKE_H
#define SCHURKE_H

#include <string>
#include "character.h"
#include "item.h"
#include "hero.h"
//#include "inventory.h"
//#include "GameConfig.h"

//class Hero;      //Forward declaration of Hero
//class Character; //Forward declaration of Character

class Schurke : public Character {
public:
    void attack(Hero* hero);   //Schurke greift Helden an
    void newEmeny(std::string& name, int health, int gold);   //neuer Schurke wird initialisiert
    void itemDrop(Hero *hero, const Item &defaultItem);

};


#endif //SCHURKE_H
