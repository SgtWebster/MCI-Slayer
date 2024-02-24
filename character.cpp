// character.cpp
// Created by Oliver Weber on 23.02.2024.
//

#include <iostream>
#include <string>
#include "hero.h"
#include "character.h"
#include "item.h"
using namespace std;



void Character_t::attack(Character_t* character, Hero_t* hero) {
    int attackPower = rand() % 11 + 5;

    if (hero->equipment[1].isValid) {
        attackPower -= 5;
    }

    std::cout << character->name <<  " tifft " << hero->name << " fuer " << attackPower << " Lebenspunkte!" << std::endl;
    hero->health -= attackPower;
}



void initCharacter(Character_t* character, string *name, int health, int gold) {   //Initializes the character Caution: character and name must be a pointer!
    if (character == nullptr) {
        std::cerr << "Error: character is nullptr!" << endl;
        return;
    }
    character->name = *name;
    character->health = health;
    character->gold = gold;

    for (auto &i: character->inventory) {
        i.name = "empty";
        i.value = 0;
        i.isValid = false;
    }
}