// hero.h
// Created by Oliver Weber on 23.02.2024.
//

#ifndef HERO_H
#define HERO_H

#include "item.h"
#include "character.h"

//class Character;      //Forward declaration of Character
//class Item;           //Forward declaration of Item

class Hero : public Character {           //class for hero - inherits from Character

public:
    //Konstruktor
    Hero(std::string& name, int health, int gold);


    //Destruktor
    ~Hero() = default;

    void attack(Schurke *enemy);
    void sellItem(int index);
    void useItem(int index);

    void startFight(Schurke *enemy);

    //getter for equipment
    std::string getEquipmentName(int itemIndex) { return equipment[itemIndex].getName(); }
    int getEquipmentValue(int itemIndex) { return equipment[itemIndex].getValue(); }
    int getEquipmentType(int itemIndex) { return equipment[itemIndex].getType(); }
    bool getEquipmentIsValid(int itemIndex) { return equipment[itemIndex].getIsValid(); }
    int getEquipmentStrengh(int itemIndex) { return equipment[itemIndex].getStrengh(); }

    //setter/getter for fight
    void setFightStart() { this->fight = true; }
    bool getFightStatus() const { return fight; }
    void setFightEnd() { this->fightEnd = false; }

    //getter+setter for theForce
    bool getTheForce() const { return this->theForce; }
    void setTheForceTrue(bool) { this->theForce = true; }


private:
    Item equipment[2];   // equipment[0] = weapon, equipment[1] = armor
    bool fight;
    bool theForce;
};


#endif //HERO_H
