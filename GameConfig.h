//
// Created by webo on 11.03.2024.
//

#ifndef GAMECONFIG_H
#define GAMECONFIG_H
#include "item.h"

//max Inventory and Equipment Slots
constexpr int MAX_INVENTORY_SLOTS = 10;
constexpr int MAX_EQUIPMENT_SLOTS = 2;

constexpr int COUNT_OF_DEFAULT_ITEMS = 10;

//hero Defaults
constexpr int DEFAULT_HERO_HEALTH = 300;
constexpr int DEFAULT_HERO_GOLD = 0;


//linien
void hline();     //horizontal line (standard)
void hlineAsterix(int count);      //horizontal line (with asterix and variable length)

//config default items
std::array<Item, COUNT_OF_DEFAULT_ITEMS> createItemList();



#endif //GAMECONFIG_H
