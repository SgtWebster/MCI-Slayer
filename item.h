// item.h
// Created by Oliver Weber on 23.02.2024.
//

#ifndef ITEM_H
#define ITEM_H

class Item {       //Class for Items
public:
    //Konstruktoren
    Item() : name("empty"), value(0), type(0), isValid(false), strengh(0) {} //Standardkonstruktor (Platzhalter-Item)
    Item(Item const &) = default;                                           //Copy-Konstruktor
    Item(std::string& name, int value, int type, bool isValid = false, int strengh = 0); //Parameterkonstruktor

    //Destruktor
    ~Item() = default;

    //Methods - getter und setter
    std::string getName() const { return name; }
    int getValue() const { return value; }
    int getType() const { return type; }   //0 = consumable, 1 = weapon, 2 = armor, 3 = special
    bool getIsValid() const { return isValid; }
    int getStrengh() const { return strengh; }

private:
    std::string name;
    int value;    //Goldwert des Items
    int type;    //0 = consumable, 1 = weapon, 2 = armor, 3 = special
    bool isValid;    //true = Item ist gültig dh. der Slot im Inventar ist mit einem Item belegt
    int strengh;   //Stärke des Items (z.B. Angriffspunkte, Rüstungspunkte, Lebenspunkte auffüllen...)
};

#endif //ITEM_H
