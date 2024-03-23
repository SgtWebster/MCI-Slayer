// fighter.h
// Created by webo on 19.03.2024.


#ifndef FIGHTER_H
#define FIGHTER_H

#include "schurke.h"

class Fighter : public Schurke {
public:
    Fighter(const std::string& name, int health, int gold, int armorDefenseValue, int magicalDefenseValue, int physicalStrength) :
            Schurke(name, health, gold, armorDefenseValue,magicalDefenseValue), physicalStrength(physicalStrength) {}   //Parameterkonstruktor

    Fighter() : Schurke("", 0, 0, 0, 0), physicalStrength(0) {}        //Standardkonstruktor

    //getter
    int requestPhysicalStrength() const override {return physicalStrength;}
    int requestMagicalPower() const override {return 0;}

    static std::array<Fighter, COUNT_OF_DEFAULT_ENEMYS> createFighterList();

private:
    int physicalStrength;
};


#endif //FIGHTER_H

