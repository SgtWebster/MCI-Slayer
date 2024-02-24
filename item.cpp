// item.cpp
// Created by Oliver Weber on 23.02.2024.
//

#include <iostream>
#include <string>
#include "item.h"
using namespace std;

void initItem(Item_t* item, string *name, int gold) {   //Initializes the item Caution: item and name must be a pointer!
    if (item == nullptr) {
        std::cerr << "Error: item is nullptr!" << std::endl;
        return;
    }
    item->name = *name;
    item->value = gold;
    item->isValid = true;
}

