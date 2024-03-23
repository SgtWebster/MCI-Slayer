// gameconfig.h
// Created by webo on 11.03.2024.
//

#ifndef GAMECONFIG_H
#define GAMECONFIG_H
#include "item.h"
#include <array>
#include <random>

//max Inventory and Equipment Slots
constexpr int MAX_INVENTORY_SLOTS = 20;
constexpr int COUNT_OF_DEFAULT_ITEMS = 20;

//hero Defaults
constexpr int DEFAULT_HERO_HEALTH = 300;
constexpr int DEFAULT_HERO_GOLD = 0;

//weitere Defaults
constexpr int COUNT_OF_DEFAULT_ENEMYS = 5;  // wenn 5 dann -> 5 Fighter und 5 Sorcerer


//linien
void hline();     //horizontal line (standard)
void hlineAsterix(int count);      //horizontal line (with asterix and variable length)

//config default items
std::array<Item, COUNT_OF_DEFAULT_ITEMS> createItemList();


//Random Number Generator
int getRandomNumber(int min, int max);


#endif //GAMECONFIG_H
