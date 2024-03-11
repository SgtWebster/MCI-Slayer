// character.h
// Created by Oliver Weber on 23.02.2024.
//

#ifndef CHARACTER_H
#define CHARACTER_H

#include "item.h"
#include "hero.h"

class Hero;          //Forward declaration of Hero

class Character {    //class for Character (enemys)
public:
    //Konstruktor
    Character(std::string& name, int health, int gold);   //Parameterkonstruktor
    Character() : name("unkown"), health(0), gold(0) {}         //Standardkonstruktor

    //Destruktor
    ~Character() = default;

    //Methods
    void getDamage(int damage); //setter for health
    void earnGold(int gold);    //setter for gold

    //getter
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getGold() const { return gold; }

    //setter
    void setName(std::string& newName) { this->name = newName; }
    void setHealth(int newHealth) { this->health = newHealth; }
    void setGold(int newGold) { this->gold = newGold; }

    //getter for inventory         //TODO Inventory Handling -> siehe ChatGPT -> mittels Container/Vektor
    std::string getInventoryName(int itemIndex) const { return inventory[itemIndex].getName(); }
    int getInventoryValue(int itemIndex) const { return inventory[itemIndex].getValue(); }
    int getInventoryType(int itemIndex) const { return inventory[itemIndex].getType(); }
    bool getInventoryIsValid(int itemIndex) const { return inventory[itemIndex].getIsValid(); }
    int getInventoryStrengh(int itemIndex) const { return inventory[itemIndex].getStrengh(); }

    //inventory handling

private:
    std::string name;
    int health;
    int gold;
    Item inventory[10];

};
/////////////////////////////////////////////// Schurken-Angelegenheiten
class Schurke : public Character {
    public:
    void attack(Hero* hero);   //Schurke greift Helden an
    void newEmeny(std::string& name, int health, int gold);
};


#endif //CHARACTER_H
