// GameConfig.cpp
// Created by webo on 11.03.2024.
//

#include <iostream>
#include "GameConfig.h"


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


int getRandomNumber(int min, int max) {    //den Code hab ich von ChatGPT, ich versteh kein Wort davon... aber anscheinend machts mehr Sinn als rand() % 11 + 5;
    static std::random_device rd;  // Wird nur einmal initialisiert
    static std::mt19937 gen(rd()); // Standardmäßig seedet mit rd()
    std::uniform_int_distribution<> distr(min, max); // Gleichmäßige Verteilung
    return distr(gen); // Generiere und liefere zufälligen Wert
}


//Standard Items
std::array<Item, COUNT_OF_DEFAULT_ITEMS> createItemList() {
    std::array<Item, COUNT_OF_DEFAULT_ITEMS> items;
    std::array<std::string, COUNT_OF_DEFAULT_ITEMS> standardItemNames = {"Schwert",  "Dolch",  "Bogen", "Magisches Schwert", "Erzmagier-Stab", "Lachs der Zweifel", "Lederruestung", "Kettenhemd", "Stahlruestung", "Mantel", "Erzmagier-Mantel", "Blauer MCI Hoodie",  "Ring",  "Amulett",  "Heiltrank", "Grosser Heiltrank", "Zaubertrank", "Flasche Tiroler Bier", "Heilige Handgranate von Antiochia",  "Wischmop der Macht"};
    std::array<int, COUNT_OF_DEFAULT_ITEMS> standardItemValues = {50, 30, 40, 120, 150, 5, 20, 25, 60, 60, 150, 39, 100, 75, 30, 60, 40, 9, 666, 100};
    std::array<int, COUNT_OF_DEFAULT_ITEMS> standardItemTypes = {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 0, 0, 0, 0, 4, 5}; //0 = consumable, 1 = weapon, 2 = armor, 3 = accessory, 4 = special, 5 = wischmop
    std::array<int, COUNT_OF_DEFAULT_ITEMS> standardItemsStrengh = {10, 5, 8, 5, 10, 1, 5, 10, 15, 0, 10, 1, 0, 0, 150, 250, 50, 50, 666, 100};
    std::array<int, COUNT_OF_DEFAULT_ITEMS> standardItemMagic = {0, 0, 0, 10, 15, 0, 0, 0, 0, 15, 20, 1, 0, 10, 0, 0, 10, 50, 666, 100};
    std::array<std::string, COUNT_OF_DEFAULT_ITEMS> standardItemDescription = {"Ein einfaches Stahlschwert", "Ein einfacher Dolch", "Ein Bogen mit Pfeilen", "Ein Schwert, das blau leuchtet wenn Schurken in der Naehe sind", "Ein langer und robuster Stab eines Erzmagiers, der sowohl physisch, als auch psychisch schmerzt", "Wer von einem Lachs geschlagen wird, der hinterfragt sein Leben.", "Eine einfache und leichte Lederruestung", "Ein robustes Kettenhemd, das einiges einstecken kann", "Eine maechtige Stahlruestung, fuer wahre Ritterinnen", "Ein Mantel aus robustem Stoff mit vielen Stickereien, die schimmern", "Ein gepanzerter Mantel, wie ihn nur die maechtigsten Magier besitzen", "Ein blauer Hoodie, mit einem MCI Schriftzug", "Wird auf der Schwerthand getragen und erhoet den magischen Angriff", "Ein ziemlich zaches Amulett", "Eine kleine Flasche mit rotem Heiltrank", "Eine grosse Flasche mit rotem Heiltrank", "Eine kleine Flasche mit blauem Zaubertrank", "Eine 1 Liter Flasche mit koestlichem Tiroler Bier", "Eine goettliche Waffe, die beim Zaehlen bis drei (nicht vier, fuenf oder gar zwei, es sei denn, es folgt unmittelbar die Fortfuehrung zu drei) eine explosive Heiligkeit entfacht", "Ein Wischmop? Er lumisziert seltsam..."};

    for (size_t i = 0; i < COUNT_OF_DEFAULT_ITEMS; i++) {
        items[i] = Item(standardItemNames[i], standardItemValues[i], standardItemTypes[i], true, standardItemsStrengh[i], standardItemMagic[i], standardItemDescription[i]);
    }

    return items;
}

