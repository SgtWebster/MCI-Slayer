// item.h
// Created by Oliver Weber on 23.02.2024.
//

#ifndef ITEM_H
#define ITEM_H

struct Item_t {       //Struct for Items
    std::string name;
    int value;
    bool isValid;
    int type;    //0 = consumable, 1 = weapon, 2 = armor
};


void initItem(Item_t* item, std::string *name, int gold);

#endif //ITEM_H
