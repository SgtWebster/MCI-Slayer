// sorcerer.h
// Created by webo on 19.03.2024.
//

#ifndef SORCERER_H
#define SORCERER_H

#include "schurke.h"

class Sorcerer : public Schurke {
public:
    Sorcerer(const std::string& name, int health, int gold, int armorDefenseValue, int magicalDefenseValue, int magicalStrenght) :
            Schurke(name, health, gold, armorDefenseValue,magicalDefenseValue), magicalStrenght(magicalStrenght) {}   //Parameterkonstruktor

    Sorcerer() : Schurke("", 0, 0, 0, 0), magicalStrenght(0) {}  //Standardkonstruktor

    //getter
    int requestPhysicalStrength() const override {return 0;}
    int requestMagicalPower() const override {return magicalStrenght;}

    static std::array<Sorcerer, COUNT_OF_DEFAULT_ENEMYS> createSorcererList();


private:
    int magicalStrenght;
};


#endif //SORCERER_H
