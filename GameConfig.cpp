//
// Created by webo on 11.03.2024.
//

#include <iostream>
//#include <array>
#include "GameConfig.h"
//#include "item.h"

//Linien
void hline() {     //horizontal line (standard)
    for (int i = 0; i < 70; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

void hlineAsterix(int count) {     //horizontal line (with asterix and variable length)
    for (int i = 0; i < count; i++) {
        std::cout << "*";
    }
    std::cout << std::endl;
}


//Standard Items


std::array<Item, COUNT_OF_DEFAULT_ITEMS> createItemList() {
    std::array<Item, COUNT_OF_DEFAULT_ITEMS> items;
    std::array<std::string, COUNT_OF_DEFAULT_ITEMS> standardItemNames = {"Schwert", "Dolch", "Bogen", "Heiltrank", "Helm", "Ritterruestung", "Stiefel", "Ring", "Amulett", "Wischmop der Macht"};
    std::array<int, COUNT_OF_DEFAULT_ITEMS> standardItemValues = {50, 30, 40, 30, 25, 60, 20, 100, 75, 100};
    std::array<int, COUNT_OF_DEFAULT_ITEMS> standardItemTypes = {1, 1, 1, 0, 2, 2, 2, 2, 2, 3}; //0 = consumable, 1 = weapon, 2 = armor, 3 = special
    std::array<int, COUNT_OF_DEFAULT_ITEMS> standardItemsStrengh = {10, 5, 8, 10, 10, 10, 5, 7, 15, 100};

    for (size_t i = 0; i < COUNT_OF_DEFAULT_ITEMS; i++) {
        items[i] = Item(standardItemNames[i], standardItemValues[i], standardItemTypes[i], true, standardItemsStrengh[i]);
    }

    return items;
}