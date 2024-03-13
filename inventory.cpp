//
// Created by webo on 11.03.2024.
//

#include "inventory.h"
#include "GameConfig.h"
#include "character.h"
//#include "hero.h"
#include <limits>
#include <iostream>

void Inventory::addItem(const Item& item) {     // Füge das Item hinzu, wenn das Limit noch nicht erreicht ist
    if (items.size() < MAX_INVENTORY_SLOTS) {
        items.push_back(item);
    }
}
bool Inventory::isSlotValid(int index) const {
    return index >= 0 && index < items.size() && items[index].getIsValid();
}

void Inventory::removeItem(int index) {         // Überprüfe, ob der Index gültig ist
    if (index >= 0 && index < items.size()) {
        items.erase(items.begin() + index);
    }
}

const Item* Inventory::getItem(int index) const {
    if (index >= 0 && index < items.size()) {
        return &items[index];
    }
    return nullptr;
}


///////////////////////////////////////////////////////////////////////////////// <Inventar-Handling>
int Inventory::listItems(bool nummernAnzeigen) const {    // Das ganze Inventar ausgeben
    int foundItems = 0;
    for (int i = 0; i < items.size(); ++i) {
        if (items[i].getIsValid()) {
            foundItems++;

            std::cout << "["<< (nummernAnzeigen ? std::to_string(i+1)  : "*") << "] " << items[i].getName() << " (Wert: " << items[i].getValue() << ") ";  //
            if (items[i].getType() == 0) {                            // Type // 0 = consumable, 1 = weapon, 2 = armor, 3 = special
                std::cout << "- Verbrauchsgegenstand";
            }
            if (items[i].getType() == 1) {
                std::cout << "- Waffe ";
            } else if (items[i].getType() == 2) {
                std::cout << "- Ruestung";
            }
            if (items[i].getType() == 1 || items[i].getType() == 2) {
                std::cout << "mit Staerke " << items[i].getStrengh();
            }
            if (items[i].getType() == 3) {
                std::cout << "- Was ist das? Er scheint irgendwie zu lumineszieren...";
            }
            std::cout << std::endl;
        }
    }
    return foundItems;
}


void Inventory::sellItem(Character* thisCharacter) {
    std::cout << "Welches Item moechtest du verkaufen?" << std::endl;
    int input_intTemp;
    if (listItems(true) == 0) {
        std::cout << "Dein Rucksack ist leer." << std::endl;
        return;
    }

    std::cout << "Slotnummer: _";
    std::cin >> input_intTemp;
    std::cin.ignore();  //ignore the newline in the input buffer
    if (isSlotValid(input_intTemp - 1)) {
        std::cout << "Du hast " << items[input_intTemp - 1].getName() << " verkauft." << std::endl;
        std::cout << items[input_intTemp - 1].getValue() << " Goldstuecke erhalten!" << std::endl;
        thisCharacter->earnGold( items[input_intTemp - 1].getValue() );
        removeItem(input_intTemp - 1);
    } else {
        std::cout << "Ungueltige Eingabe!" << std::endl;
        std::cin.clear();                                                   // Fehlerzustand zurücksetzen
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Eingabepuffer leeren
    }
}

void Inventory::useItem(Character* thisCharacter) {
    std::cout << "Welches Item moechtest du verwenden?" << std::endl;
    int input_intTemp;

    if (listItems(true) == 0) {
        std::cout << "Dein Rucksack ist leer." << std::endl;
        return;
    }
    std::cout << "Slotnummer: _";
    std::cin >> input_intTemp;
    std::cin.ignore();  //ignore the newline in the input buffer
    if (Inventory::isSlotValid(input_intTemp - 1)) {

        switch(items[input_intTemp - 1].getType()) {    // Type // 0 = consumable, 1 = weapon, 2 = armor, 3 = special
            case 0:
                std::cout << "Du hast " << items[input_intTemp - 1].getName() << " verwendet." << std::endl;    //consumable
                std::cout << items[input_intTemp - 1].getStrengh() << " Lebenspunkte erhalten!" << std::endl;
                thisCharacter->getDamage( (items[input_intTemp - 1].getStrengh()) * (-1));
                removeItem(input_intTemp - 1);
                break;
            case 1:
                std::cout << "Du hast die Waffe " << items[input_intTemp - 1].getName() << " ausgeruestet." << std::endl;     //weapon
                thisCharacter->equipWeapon(items[input_intTemp - 1]);
                removeItem(input_intTemp - 1);
                break;
            case 2:
                std::cout << "Du hast den Ruestungsgegenstand " << items[input_intTemp - 1].getName() << " ausgeruestet." << std::endl;     //armor
                thisCharacter->equipArmor(items[input_intTemp - 1]);
                removeItem(input_intTemp - 1);
                break;
            case 3:
                std::cout << "Du hast " << items[input_intTemp - 1].getName() << " verwendet." << std::endl;
                std::cout << "Gegenstand " << items[input_intTemp - 1].getName() << " wurde benutzt. " << thisCharacter->getNameChar() << " spuert eine Erschuetterung in der Macht!" << std::endl;   //special
                std::cout << "Die Macht ist mit " << thisCharacter->getNameChar() << "!" << std::endl;
                thisCharacter->setTheForceTrue();
                removeItem(input_intTemp - 1);
                break;
            default:
                std::cout << "Ungueltige Eingabe!" << std::endl;
                std::cin.clear();                                                   // Fehlerzustand zurücksetzen
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Eingabepuffer leeren
                break;
        }
            } else {
        std::cout << "Ungueltige Eingabe!" << std::endl;
        std::cin.clear();                                                   // Fehlerzustand zurücksetzen
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Eingabepuffer leeren
    }
    //return;

}

void Inventory::checkBackpack(Character* thisCharacter) {
    std::cout << "Du pruefst deinen Rucksack..." << std::endl;
    hline();
    int foundItemsInInventar = listItems(false);
    hline();
    if (foundItemsInInventar == 0) {
        std::cout << "Dein Rucksack ist leer." << std::endl;
    } else {
        int input_intemp = 0;
        std::cout << "Was moechtest du tun?" << std::endl;
        std::cout << "[1] Item verkaufen" << std::endl;
        std::cout << "[2] Item verwenden oder ausruesten" << std::endl;
        std::cout << "[9] Hab genug vom Inventar" << std::endl;
        std::cout << "Deine Wahl: _";
        std::cin >> input_intemp;

        std::cin.ignore();  //ignore the newline in the input buffer

        switch (input_intemp) {
            case 1:
                sellItem(thisCharacter);
                break;
            case 2:
                useItem(thisCharacter);
                break;
            case 9:
                std::cout << "Du hast genug vom Inventar..." << std::endl;
                break;
            default:
                std::cout << "Ungueltige Eingabe!" << std::endl;
                std::cin.clear();                                                   // Fehlerzustand zurücksetzen
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Eingabepuffer leeren
                break;

        }


    }
}
