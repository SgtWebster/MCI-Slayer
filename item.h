// item.h
// Created by Oliver Weber on 23.02.2024.
//

#ifndef ITEM_H
#define ITEM_H

class Item {       //Class for Items
public:
    //Konstruktor
    Item() : name("empty"), value(0), type(0), isValid(false), strengh(0) {} //Standardkonstruktor (Platzhalter-Item)
    Item(std::string& name, int value, int type, bool isValid = false, int strengh = 0); //Parameterkonstruktor

    //Destruktor
    ~Item() = default;

    //Methods - getter und setter
    std::string getName() const { return name; }
    int getValue() const { return value; }
    int getType() const { return type; }
    bool getIsValid() const { return isValid; }
    int getStrengh() const { return strengh; }

private:
    std::string name;
    int value;
    int type;    //0 = consumable, 1 = weapon, 2 = armor, 3 = special
    bool isValid;
    int strengh;
};


//void initItem(Item* item, std::string *name, int gold);

#endif //ITEM_H
