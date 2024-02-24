// hero.h
// Created by Oliver Weber on 23.02.2024.
//

#ifndef HERO_H
#define HERO_H

#include "item.h"
#include "character.h"

struct Character_t;      //Forward declaration of Character_t

struct Hero_t {           //Struct for Hero
    std::string name;
    int health;
    int gold;
    Item_t inventory[10];
    Item_t equipment[2];   // equipment[0] = weapon, equipment[1] = armor
    bool theForce;

    void attack(Hero_t* hero, Character_t* enemy);
    void sellItem(Hero_t* hero, int index);
    void useItem(Hero_t* hero, int index);
    bool fight(Hero_t* hero, Character_t* enemy);
};

void initHero(Hero_t* hero, std::string* name, int health, int gold);


#endif //HERO_H
