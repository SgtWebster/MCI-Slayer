// sorcerer.h
// Created by webo on 19.03.2024.
//

#ifndef SORCERER_H
#define SORCERER_H

#include "schurke.h"

class Sorcerer : public Schurke {
    Sorcerer(const std::string &name, int value, int type, bool isValid, int armorDefenseValue, int magicalDefenseValue,
            int magicalStrength =0);

    //getter
    static int requestPhysicalStrength() {return 0;}
    int requestMagicalPower() const {return magicalStrenght;}

private:
    int magicalStrenght;
};


#endif //SORCERER_H
