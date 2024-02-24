// character.h
// Created by Oliver Weber on 23.02.2024.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include "item.h"
#include "hero.h"

struct Hero_t;          //Forward declaration of Hero_t

struct Character_t {    //Struct for Character (enemys)
    std::string name;
    int health;
    int gold;
    Item_t inventory[10];

    void attack(Character_t* character, Hero_t* hero);
};

void initCharacter(Character_t* character, std::string *name, int health, int gold);

#endif //CHARACTER_H
