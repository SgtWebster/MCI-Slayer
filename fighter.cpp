// fighter.cpp
// Created by webo on 19.03.2024.


#include "fighter.h"


//DEFAULT Fighters
#define FIGHTER_NAMES {"Matthias", "Stephan", "Willemijn", "Theresa", "Gundula"}
#define FIGHTER_HEALTH {50, 100, 150, 175, 100}

#define FIGHTER_GOLD_MIN {15, 30, 50, 25, 25}
#define FIGHTER_GOLD_MAX {30, 40, 70, 75, 75}
#define FIGHTER_ARMOR_DEFENSE_VALUE {0, 5, 10, 15, 20}
#define FIGHTER_MAGICAL_DEFENSE_VALUE {0, 1, 2, 3, 4}
#define FIGHTER_PHYSICAL_STRENGTH {5, 10, 15, 25, 20}


std::array<Fighter, COUNT_OF_DEFAULT_ENEMYS> Fighter::createFighterList() {
    std::array<std::string, COUNT_OF_DEFAULT_ENEMYS> standardEnemyNames = {FIGHTER_NAMES};
    std::array<int, COUNT_OF_DEFAULT_ENEMYS> standardEnemyHealth = {FIGHTER_HEALTH};
    std::array<int, COUNT_OF_DEFAULT_ENEMYS> standardEnemyGoldMin = {FIGHTER_GOLD_MIN};
    std::array<int, COUNT_OF_DEFAULT_ENEMYS> standardEnemyGoldMax = {FIGHTER_GOLD_MAX};
    std::array<int, COUNT_OF_DEFAULT_ENEMYS> standardEnemyArmorDefenseValue = {FIGHTER_ARMOR_DEFENSE_VALUE};
    std::array<int, COUNT_OF_DEFAULT_ENEMYS> standardEnemyMagicalDefenseValue = {FIGHTER_MAGICAL_DEFENSE_VALUE};
    std::array<int, COUNT_OF_DEFAULT_ENEMYS> standardEnemyPhysicalStrength = {FIGHTER_PHYSICAL_STRENGTH};

    std::array<Fighter, COUNT_OF_DEFAULT_ENEMYS> fighters;
    for (size_t i = 0; i < COUNT_OF_DEFAULT_ENEMYS; i++) {
        int standardEnemyGold;
        standardEnemyGold = getRandomNumber(standardEnemyGoldMin[i], standardEnemyGoldMax[i]);

        fighters[i] = Fighter(standardEnemyNames[i], standardEnemyHealth[i], standardEnemyGold, standardEnemyArmorDefenseValue[i], standardEnemyMagicalDefenseValue[i], standardEnemyPhysicalStrength[i]);
    }

    return fighters;
}

