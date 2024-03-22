// item.h
// Created by Oliver Weber on 23.02.2024.
//

#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {       //Class for Items
public:
    //Konstruktoren
    Item(); // : name("empty"), value(0), type(0), isValid(false), strengh(0), magic(0), description("empty") {} //Standardkonstruktor (Platzhalter-Item)
    Item(Item const &); // = default;                                            //Copy-Konstruktor
    Item(const std::string& name, int value, int type, bool isValid = false, int strength = 0, int magic = 0, const std::string& description = "");   //Parameterkonstruktor

    //Destruktor
    ~Item() = default;

    //Methods - getter und setter
    std::string getName() const { return name; }
    int getValue() const { return value; }
    int getType() const { return type; }   //0 = consumable, 1 = weapon, 2 = armor, 3 = special
    bool getIsValid() const { return isValid; }
    int getStrengh() const { return strengh; }
    int getMagic() const { return magic; }
    std::string getDescription() const { return description; }

private:
    std::string name;
    int value{};    //Goldwert des Items
    int type{};    //0 = consumable, 1 = weapon, 2 = armor, 3 = special
    bool isValid{};    //true = Item ist gültig dh. der Slot im Inventar ist mit einem Item belegt
    int strengh{};   //Stärke des Items (z.B. Angriffspunkte, Rüstungspunkte, Lebenspunkte auffüllen...)
    int magic{};    //Magie des Items - verhaelt sich gleich wie die Stärke
    std::string description;    //Beschreibung des Items
};

#endif //ITEM_H
