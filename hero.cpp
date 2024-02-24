// hero.cpp
// Created by Oliver Weber on 23.02.2024.
//

#include <iostream>
#include <string>
#include <cstdlib>   // for rand()
#include "hero.h"
#include "item.h"
#include "character.h"
using namespace std;


void Hero_t::attack(Hero_t* hero, Character_t* character) {
    int attackPower = rand() % 11 + 15;
    std::string weaponName;
    weaponName = "";
    if (hero->equipment[0].isValid) {
        weaponName = hero->equipment[0].name;
        attackPower += 10;
    }
    if (hero->theForce) {
        attackPower += 25;
    }
    std::cout << hero->name <<  " tifft"<< (hero->equipment[0].isValid ? " mit ihrem ": "") << weaponName << " " << character->name << " fuer " << attackPower << " Lebenspunkte!" << (hero->theForce ? " Die Macht ist stark mit dieser da!" :"") << std::endl;
    character->health -= attackPower;
}


void Hero_t::sellItem(Hero_t* hero, int index) {

    if (hero == nullptr || index < 0 || index >= 10) {
        std::cerr << "Ungueltige Eingabe: Slot-Platz nicht gueltig!" << std::endl;
        return;
    }

    Item_t* item = &(hero->inventory[index]);

    if (item->isValid) {
        hero->gold += item->value;
        std::cout << "Gegenstand " << item->name << " wurde verkauft. " << hero->name << " besitzt nun " << hero->gold << " Gold." << std::endl;
        item->isValid = false;
        item->name = "empty";
        item->value = 0;
        return;
    } else {
        std::cout << "Der Slot ist leer!" << std::endl;
        return;
    }

}

void Hero_t::useItem(Hero_t* hero, int index) {
    if (hero == nullptr || index < 0 || index >= 10) {
        std::cout << "Ungueltige Eingabe: Slot-Platz nicht gueltig!" << std::endl;
        return;
    }

    Item_t* item = &(hero->inventory[index]);

    if (item->isValid) {

        //0 = consumable, 1 = weapon, 2 = armor
        switch (item->type) {
            case 0:
                hero->health += 50;
                std::cout << "Gegenstand " << item->name << " wurde benutzt. " << hero->name << " besitzt nun " << hero->health << " Lebenspunkte." << std::endl;
                item->isValid = false;
                item->name = "empty";
                item->value = 0;
                break;
            case 1:
                hero->equipment[0] = *item;
                std::cout << "Waffe " << item->name << " wurde angelegt. " << hero->name << " besitzt nun " << hero->equipment[0].name << " als Waffe." << std::endl;
                item->isValid = false;
                item->name = "empty";
                item->value = 0;
                break;
            case 2:
                hero->equipment[1] = *item;
                std::cout << "Ruestung " << item->name << " wurde angelegt. " << hero->name << " besitzt nun " << hero->equipment[1].name << " als Ruestung." << std::endl;
                item->isValid = false;
                item->name = "empty";
                item->value = 0;
                break;
            case 3:
                std::cout << "Gegenstand " << item->name << " wurde benutzt. " << hero->name << " spuert eine Erschuetterung in der Macht!" << std::endl;
                std::cout << "Die Macht ist mit " << hero->name << "!" << std::endl;
                hero->theForce = true;
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

bool Hero_t::fight(Hero_t* hero, Character_t* character) {                     //FIGHT! FIGHT! FIGHT! false = lost, true = won
    std::cout << hero-> name << " greift " << character->name << " an!" << std::endl;

    while (true) {
        hero->attack(hero, character);
        if (character->health <= 0) {
            return true;
        }
        character->attack(character, hero);
        if (hero->health <= 0) {
            return false;
        }
    }
    return false;   //Should never be reached (Backup)
}

void initHero(Hero_t* hero, std::string* name, int health, int gold) {   //Initializes the hero Caution: hero and name must be a pointer!
    if (hero == nullptr) {
        std::cerr << "Error: hero is nullptr!" << std::endl;
        return;
    }
    hero->name = *name;
    hero->health = health;
    hero->gold = gold;

    for (auto & i : hero->inventory) {
        i.name = "empty";
        i.value = 0;
        i.isValid = false;
    }

    for (auto & i : hero->equipment) {
        i.name = "empty";
        i.value = 0;
        i.isValid = false;
    }
    hero->theForce = false;
}