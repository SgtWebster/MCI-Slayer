// gameconfig.h
// Created by webo on 11.03.2024.
//

#ifndef GAMECONFIG_H
#define GAMECONFIG_H
#include "item.h"
//#include "schurke.h"
#include <array>

//max Inventory and Equipment Slots
constexpr int MAX_INVENTORY_SLOTS = 20;
constexpr int COUNT_OF_DEFAULT_ITEMS = 20;

//hero Defaults
constexpr int DEFAULT_HERO_HEALTH = 300;
constexpr int DEFAULT_HERO_GOLD = 0;

//weitere Defaults
constexpr int COUNT_OF_DEFAULT_ENEMYS = 10;


//linien
void hline();     //horizontal line (standard)
void hlineAsterix(int count);      //horizontal line (with asterix and variable length)

//config default items
std::array<Item, COUNT_OF_DEFAULT_ITEMS> createItemList();

//config default Emenys
//std::array<Schurke, COUNT_OF_DEFAULT_ENEMYS> createEnemyList();  //TODO: implement


#endif //GAMECONFIG_H
