// hero.h
// Created by Oliver Weber on 23.02.2024.
//

#ifndef HERO_H
#define HERO_H

#include "item.h"
#include "character.h"
#include "GameConfig.h" //max Inventory
#include "schurke.h"


//class Character;      //Forward declaration of Character
//class Item;           //Forward declaration of Item

class Hero : public Character {           //class for hero - inherits from Character

public:
    //Konstruktor
    Hero(const std::string& name, int health, int gold);


    //Destruktor
    ~Hero() = default;

    void attack(Schurke *enemy);
    //void sellItem(int index);
    //void useItem(int index);

    bool startFight(Schurke *enemy);    //FIGHT-Modus! Läuft so lange bis der Kampf zu ende ist! false = lost, true = won

    //setter/getter for fight
    void setFightStart() { this->fight = true; }
    bool getFightStatus() const { return fight; }
    void setFightEnd() { this->fight = false; }

    //getter+setter for theForce
    bool getTheForce() const { return this->theForce; }
    void setTheForceTrue() override;


private:
    bool fight;
    bool theForce;
};


#endif //HERO_H
