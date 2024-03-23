// fighter.h
// Created by webo on 19.03.2024.


#ifndef FIGHTER_H
#define FIGHTER_H

#include "schurke.h"

class Fighter : public Schurke {
public:
    Fighter(const std::string &name, int value, int type, bool isValid, int armorDefenseValue, int magicalDefenseValue,
            int physicalStrength =0);

    //getter
    int requestPhysicalStrength() const {return physicalStrength;}
    static int requestMagicalPower() {return 0;}

private:
    int physicalStrength;
};


#endif //FIGHTER_H
