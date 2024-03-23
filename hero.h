// hero.h
// Created by Oliver Weber on 23.02.2024.
//

#ifndef HERO_H
#define HERO_H


#include "character.h"
//#include "schurke.h"


class Schurke;         //Forward declaration of Schurke


class Hero : public Character {           //class for hero - inherits from Character

public:
    //Konstruktor
    Hero(const std::string& name, int health, int gold, int armorDefenseValue, int magicalDefenseValue);

    //Destruktor
    ~Hero() = default;

    void attack(Schurke *enemy);

    bool startFight(Schurke *enemy);    //FIGHT-Modus! Läuft so lange bis der Kampf zu ende ist! false = lost, true = won

    //schoener Wohnen: Kampfschreie und co:
    void battlecry();  //Kampfschrei
    void dodgecry();   //Ausweichschrei
    void granate(const Item& granate);     //Granate werfen

    void checkStats();  //checkt Stats

    //setter/getter for fight -- dzt nicht notwendig
//    void setFightStart() { this->fight = true; }
//    bool getFightStatus() const { return fight; }
//    void setFightEnd() { this->fight = false; }

    //getter+setter for theForce
    bool getTheForce() const { return this->theForce; }
    void setTheForceTrue() override;

    //getter & setter fuer Sats
    int getStatsANG() const { return this->statsANG; }
    int getStatsDEF() const { return this->statsDEF; }
    int getStatsMANG() const { return this->statsMANG; }
    int getStatsMDEF() const { return this->statsMDEF; }
    int getStatsEXP() const { return this->statsEXP; }
    int getStatsLVL() const { return this->statsLVL; }
    void setStatsANG(int newANG) { this->statsANG = newANG; }
    void setStatsDEF(int newDEF) { this->statsDEF = newDEF; }
    void setStatsMANG(int newMANG) { this->statsMANG = newMANG; }
    void setStatsMDEF(int newMDEF) { this->statsMDEF = newMDEF; }
    void setStatsEXP(int newEXP) { this->statsEXP = newEXP; }
    void setStatsLVL(int newLVL) { this->statsLVL = newLVL; }


private:
    bool fight;
    bool theForce;

    //Hero-Stats
    int statsANG;
    int statsDEF;
    int statsMANG;
    int statsMDEF;
    int statsEXP;
    int statsLVL;
};


#endif //HERO_H
