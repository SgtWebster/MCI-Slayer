// sorcerer.cpp
// Created by webo on 19.03.2024.
//

#include "sorcerer.h"

//DEFAULT Sorcerer
#define SORCERER_NAMES {"Pascal", "Peter", "Reinhard", "Andreas", "Hausmeister"}
#define SORCERER_HEALTH {75, 125, 125, 200, 500}
#define SORCERER_GOLD_MIN {25, 40, 25, 100, 950}
#define SORCERER_GOLD_MAX {30, 50, 75, 200, 1050}
#define SORCERER_ARMOR_DEFENSE_VALUE {0, 1, 2, 3, 20}
#define SORCERER_MAGICAL_DEFENSE_VALUE {5, 10, 15, 20, 20}
#define SORCERER_MAGICAL_STRENGTH {5, 10, 1, 30, 20}


std::array<Sorcerer, COUNT_OF_DEFAULT_ENEMYS> Sorcerer::createSorcererList() {
    std::array<std::string, COUNT_OF_DEFAULT_ENEMYS> standardEnemyNames = {SORCERER_NAMES};
    std::array<int, COUNT_OF_DEFAULT_ENEMYS> standardEnemyHealth = {SORCERER_HEALTH};
    std::array<int, COUNT_OF_DEFAULT_ENEMYS> standardEnemyGoldMin = {SORCERER_GOLD_MIN};
    std::array<int, COUNT_OF_DEFAULT_ENEMYS> standardEnemyGoldMax = {SORCERER_GOLD_MAX};
    std::array<int, COUNT_OF_DEFAULT_ENEMYS> standardEnemyArmorDefenseValue = {SORCERER_ARMOR_DEFENSE_VALUE};
    std::array<int, COUNT_OF_DEFAULT_ENEMYS> standardEnemyMagicalDefenseValue = {SORCERER_MAGICAL_DEFENSE_VALUE};
    std::array<int, COUNT_OF_DEFAULT_ENEMYS> standardEnemyMagicalStrength = {SORCERER_MAGICAL_STRENGTH};

    std::array<Sorcerer, COUNT_OF_DEFAULT_ENEMYS> sorcerers;
    for (size_t i = 0; i < COUNT_OF_DEFAULT_ENEMYS; i++) {
        int standardEnemyGold;
        standardEnemyGold = getRandomNumber(standardEnemyGoldMin[i], standardEnemyGoldMax[i]);

        sorcerers[i] = Sorcerer(standardEnemyNames[i], standardEnemyHealth[i], standardEnemyGold, standardEnemyArmorDefenseValue[i], standardEnemyMagicalDefenseValue[i], standardEnemyMagicalStrength[i]);
    }

    return sorcerers;
}

