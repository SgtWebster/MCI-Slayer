// hero.h
// Created by Oliver Weber on 23.02.2024.
//

#ifndef HERO_H
#define HERO_H


#include "character.h"
//#include "schurke.h"


//class Schurke;         //Forward declaration of Schurke


class Hero : public Character {           //class for hero - inherits from Character

public:
    //Konstruktor
    Hero(const std::string& name, int health, int gold, int armorDefenseValue, int magicalDefenseValue);

    //Destruktor
    ~Hero() = default;

    void attack(Schurke *enemy);

    bool startFight(Schurke *enemy);    //FIGHT-Modus! Läuft so lange bis der Kampf zu ende ist! false = lost, true = won

    //setter/getter for fight -- dzt nicht notwendig
//    void setFightStart() { this->fight = true; }
//    bool getFightStatus() const { return fight; }
//    void setFightEnd() { this->fight = false; }

    //getter+setter for theForce
    bool getTheForce() const { return this->theForce; }
    void setTheForceTrue() override;


private:
    bool fight;
    bool theForce;
};


#endif //HERO_H
