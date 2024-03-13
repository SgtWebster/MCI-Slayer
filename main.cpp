// main.cpp

#include <iostream>
#include <string>
#include <limits>
#include <array>

//#include "character.h"
#include "hero.h"
#include "schurke.h"
#include "item.h"

#include "GameConfig.h"
//using namespace std;



//preparations for game-start

Schurke emeny; //temp character (empty) als Platzhalter
std::array<Item, COUNT_OF_DEFAULT_ITEMS> items;   // Anzahl der möglichen Items (hat NICHTS mit max_Inventory zu tun!)
auto defaultItems = createItemList();    //Erstellt Liste der Standard-Items

//void createItemList() {    //in GameConfig.cpp überstellt
//    std::string standardItemNames[COUNT_OF_DEFAULT_ITEMS] = {"Schwert", "Dolch", "Bogen", "Heiltrank", "Helm", "Ritterruestung", "Stiefel", "Ring", "Amulett", "Wischmop der Macht"};
//    int standardItemValues[COUNT_OF_DEFAULT_ITEMS] = {50, 30, 40, 30, 25, 60, 20, 100, 75, 100};
//    int standardItemTypes[COUNT_OF_DEFAULT_ITEMS] = {1, 1, 1, 0, 2, 2, 2, 2, 2, 3};    //0 = consumable, 1 = weapon, 2 = armor, 3 = special
//    int standardItemsStrengh[COUNT_OF_DEFAULT_ITEMS] = {10, 5, 8, 10, 10, 25, 5, 10, 15, 100};
//    for (int i = 0; i < COUNT_OF_DEFAULT_ITEMS; i++) {
//            items[i] = Item(standardItemNames[i], standardItemValues[i], standardItemTypes[i]), true, standardItemsStrengh[i];
//    }
//}



void itemDrop(Character* character, Hero* hero, int itemIndex, int inventarCout) {
    std::cout << "Der Schurke " << character->getNameChar() << " hat ein Item fallen gelassen!" << std::endl;
    hero->inventory[inventarCout] = items[itemIndex];    //TODO POINTER
    std::cout << "Gegenstand " << items[itemIndex].name << " wurde zum Inventar der Heldin hinzugefuegt." << std::endl;
}


void goldDrop(Character* character, Hero* hero, int gold) {
    std::cout << "Der Schurke " << character->name << " hat " << gold << " Gold fallen gelassen!" << std::endl;
    hero->gold += gold;
    std::cout << "Gold wurde zum Inventar der Heldin hinzugefuegt. " << hero->name << " besitzt nun " << hero->gold << " Gold." << std::endl;
}

int main() {
//    Hero hero;  //create a "empty" hero
    std::string inputemp;    //temp string for text-input
    int hlineLength = 90;

    hlineAsterix(hlineLength);
    std::cout << R"(*
*             ___  ________ _____      _____ _       _____   _____________
*             |  \/  /  __ \_   _|    /  ___| |     / _ \ \ / /  ___| ___ \
*             | .  . | /  \/ | |      \ `--.| |    / /_\ \ V /| |__ | |_/ /
*             | |\/| | |     | |       `--. \ |    |  _  |\ / |  __||    /
*             | |  | | \__/\_| |_     /\__/ / |____| | | || | | |___| |\ \
*             \_|  |_/\____/\___/     \____/\_____/\_| |_/\_/ \____/\_| \_|
*    )" << std::endl;
    hlineAsterix(hlineLength);
    std::cout << "*  Willkommen zu >>MCI Slayer<< Version UEZ_2! Ein Spiel von Oliver Ulrich Weber (c) 2024 " << std::endl;
    hlineAsterix(hlineLength);
    std::cout << "* Traust du dich in die Tiefen des Dungeons? Und kannst du den Wischmop der Macht finden? " << std::endl;
    hlineAsterix(hlineLength);
    std::cout << R"(*
*                        /| _______________________________________
*               O|======|* >______________________________________/
*                        \|
*)" <<std::endl;
    hlineAsterix(hlineLength);
    std::cout << "" << std::endl;
    std::cout << "Bitte waehle den Namen deiner Heldin:" << std::endl;
    std::getline(std::cin, inputemp);

    if (inputemp.empty()) {
        std::cout << "Wenn du keinen Namen eingeben willst, dann koennen wir es auch gleich bleiben lassen." << std::endl;
        hlineAsterix(hlineLength);
        return 0;
    }
    hero = Hero(inputemp, DEFAULT_HERO_HEALTH, DEFAULT_HERO_GOLD);
    //initHero(&hero, &inputemp, std Health 300, std Gold 0);

    hline();
    std::cout << "Deine Heldin heisst " << inputemp << "!" << std::endl;
    hline();
    std::cout << inputemp << " betritt den MCI-Dungeon..." << std::endl;


    int position = 0;
    int inventarCout = 0;

    // enemy temps
    int enemyCount = 0;

    std::string enemyName;
    int enemyHealth;


    // Erstellung Standard-Items
    createItemList();

    while(true) {
        int input_intemp = 0;
        if (position == 0) {
            std::cout << "Du befindest dich im Hauptraum des Dungeons. Was moechtest du tun?" << std::endl;
        } else if (position == 5) {
            std::cout << "Du befindest dich in einem Raum mit seltsamer Statue. Irgendwie stinkt es hier. Was moechtest du tun?" << std::endl;
        } else {
            std::cout << "Du befindest dich in einem schaurigen Gang im Dungeon. Was moechtest du tun?" << std::endl;
        }
        std::cout << "[1] Suche fiese Schurken" << std::endl;
        std::cout << "[2] Inventar ansehen" << std::endl;
        std::cout << "[3] Ausruestung pruefen" << std::endl;
        std::cout << "[4] Erkunde den Dungeon" << (position == 0 ? "" : " weiter") << std::endl;
        if(position==5) {
            std::cout << "[5] Untersuche die Statue" << std::endl;
        }
        std::cout << "[9] Dungeon verlassen" << std::endl;
        std::cout << "Deine Wahl:";
        std::cin >> input_intemp;
        std::cin.ignore();  //ignore the newline in the input buffer
        hline();

        switch (input_intemp) {
            case 1:                                                             //FIGHT!
                std::cout << "Du suchst fiese Schurken..." << std::endl;

                //Begin of the fight-------------------
                if (enemyCount % 2 == 0) {enemyName = "Matthias"; enemyHealth = 50;} else {enemyName = "Pascal"; enemyHealth = 100;}


                std::cout << "Oh nein! Ein fieser Schurke namens " << enemyName << " erscheint!" << std::endl;
                initCharacter(&character, &enemyName, enemyHealth, rand() % 30 + 1);

                if (hero.fight(&hero, &character)) {    //FIGHT! FIGHT! FIGHT! bool: false = lost, true = won
                    std::cout << character.name << " fiel in Ohnmacht! " << hero.name << " hat noch " << hero.health << " Lebenspunkte uebrig!" << std::endl;
                } else {
                    std::cout << hero.name << " fiel in Ohnmacht!" << std::endl;
                    std::cout << "Du hast leider verloren. Vom Hausmeister geschlagen. Schade." << std::endl;
                    return 0;
                }
                //End of the fight-------------------


                //Item drop
                itemDrop(&character, &hero, (enemyCount == 0 ? 0 : rand() % 8 + 1), inventarCout);
                inventarCout++;
                if (inventarCout >= MAX_INVENTORY_SLOTS) {
                    std::cout << "Du hast nun schon so viele Items gefunden und gehst deswegen deswegen nach Hause." << std::endl;
                    std::cout << "Das Spiel ist somit vorbei." << std::endl;
                    return 0;
                }
                //End of item drop

                //Gold drop
                goldDrop(&character, &hero, character.gold);
                //End of gold drop

                enemyCount++;
                break;

            case 2:                                                             //SHOW INVENTORY-----------------------------------------------------
                std::cout << "Du pruefst deinen Rucksack..." << std::endl;

                int foundItems;
                foundItems = 0;
                hline();
                for (auto & i : hero.inventory) {       //for each item in the inventory    //TODO: check
                    if (i.isValid) {
                        foundItems++;
                        std::cout << "[*] " << i.name << " (Wert: " << i.value << ")" << std::endl;
                    }

                }
                if (foundItems == 0) {
                    std::cout << "Dein Inventar ist leer." << std::endl;
                } else {
                    hline();
                    std::cout << "Was moechtest du tun?" << std::endl;
                    std::cout << "[1] Item verkaufen" << std::endl;
                    std::cout << "[2] Item verwenden oder ausruesten" << std::endl;
                    std::cout << "[9] Hab genug vom Inventar" << std::endl;
                    std::cout << "Deine Wahl:";
                    std::cin >> input_intemp;
                    std::cin.ignore();  //ignore the newline in the input buffer
                    switch (input_intemp) {
                        case 1:
                            std::cout << "Welches Item moechtest du verkaufen?" << std::endl;
                            hline();
                            for (int i = 0; i < 10; i++) {
                                if (hero.inventory[i].isValid) {
                                    std::cout << "[Inventar-Slot ("<< i+1 << ") ] " << hero.inventory[i].name << " (Wert: " << hero.inventory[i].value << ")" << std::endl;
                                }
                            }
                            hline();
                            std::cout << "Slotnummer:";
                            std::cin >> input_intemp;
                            input_intemp--;
                            std::cin.ignore();        //ignore the newline in the input buffer

                            hline();
                            hero.sellItem(&hero, input_intemp);

                            break;
                        case 2:
                            //{"Schwert", "Schild", "Bogen", "Zaubertrank", "Helm", "Rüstung", "Stiefel", "Ring", "Amulett", "Wischmop der Macht"};
                            std::cout << "Welches Item moechtest du verwenden?" << std::endl;
                            hline();
                            for (int i = 0; i < MAX_INVENTORY_SLOTS; i++) {
                                if (hero.inventory[i].isValid) {
                                    std::cout << "[Inventar-Slot ("<< i+1 << ") ] " << hero.inventory[i].name << std::endl;
                                }
                            }
                            hline();
                            std::cout << "Slotnummer:";
                            std::cin >> input_intemp;
                            input_intemp--;
                            std::cin.ignore();        //ignore the newline in the input buffer

                            hline();
                            hero.useItem(&hero, input_intemp);

                            break;
                        case 9:
                            break;
                        default:
                            std::cout << "Ungueltige Eingabe!" << std::endl;
                            std::cin.clear();                // Fehlerzustand zurücksetzen
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Eingabepuffer leeren
                            break;
                    }

                }

                break;                                          //END OF SHOW INVENTORY-----------------------------------------------------

            case 3:                                                             //SHOW EQUIPMENT

                std::cout << "Du pruefst deine Ausruestung..." << std::endl;
                hline();
                if (hero.equipment[0].isValid) {
                    std::cout << "[*] Waffe: " << hero.equipment[0].name << " (Angriff: +10)" << std::endl;
                } else {
                    std::cout << "[*] Waffe: keine (Faeuste)" << std::endl;
                }
                if (hero.equipment[1].isValid) {
                    std::cout << "[*] Ruestung: " << hero.equipment[1].name << " (Abwehr: +10)" << std::endl;
                } else {
                    std::cout << "[*] Ruestung: keine" << std::endl;
                }
                break;


            case 4:                                                             //EXPLORE DUNGEON
                std::cout << "Du erkundest den Dungeon" << (position > 0 ? " weiter" : "") << "..." << std::endl;
                position++;

                if (position >= 6) {
                    std::cout << hero.name << " stolpert und faellt in einen endlosen Abgrund. Schade." << std::endl;
                    std::cout << "Du hast leider verloren." << std::endl;
                    if (hero.theForce) {
                        std::cout << "Aber immerhin war die Macht war mit dir." << std::endl;
                    }
                    return 0;
                }

                break;

            case 42:                                                //EASTER EGG
                std::cout << "Du hast die Antwort auf alles gefunden!" << std::endl;
                std::cout << "Somit gibt es hier nichts noch wertvolleres zu entdecken..." << std::endl;

            case 9:                                                             //QUIT
                std::cout << hero.name << " verlaesst den MCI-Dungeon samt ihrer Schaetze." << std::endl;
                std::cout << "Du hast " << hero.gold << " Gold und " << hero.health << " Lebenspunkte." << std::endl;
                if(hero.theForce) {std::cout << "* * * Die Macht ist mit " << hero.name << "! * * *" << std::endl;}       // The Force is with you!
                if(hero.gold == 0 || enemyCount == 0) {std::cerr << "Moment mal! Du hast kein einziges mal gekaempft?!" << std::endl;}    // No fight at all?
                std::cout << "Das Spiel wird beendet..." << std::endl;
                hlineAsterix(hlineLength);
                return 0;
            case 5:                                                            //EXPLORE DUNGEON - just for position 5 - SPECIAL FIGHT
                if (position == 5 ) {
                    std::cout << "Du erkundest den Raum..." << std::endl;
                    //Begin of the fight-------------------   SPECIAL FIGHT!
                    enemyName = "Hausmeister";
                    enemyHealth = 500;
                    std::cout << "Oh nein! Ein fieser Schurke namens " << enemyName << " erscheint hinter der Statue!" << std::endl;
                    initCharacter(&character, &enemyName, enemyHealth, 200);


                    if (hero.fight(&hero, &character)) { //FIGHT! FIGHT! FIGHT! bool: false = lost, true = won
                        std::cout << character.name << " fiel in Ohnmacht! Ein Wasserkuebel hinter der Statue kippt um. " << hero.name << " hat noch " << hero.health << " Lebenspunkte uebrig!" << std::endl;
                    } else {
                        std::cout << hero.name << " fiel in Ohnmacht!" << std::endl;
                        std::cout << "Du hast leider verloren." << std::endl;
                        return 0;
                    }
                    //End of the fight-------------------

                    //Item drop
                    itemDrop(&character, &hero, 9, inventarCout);
                    inventarCout++;
                    if (inventarCout >= MAX_INVENTORY_SLOTS) {
                        std::cout << "Du hast nun schon so viele Items gefunden und gehst deswegen deswegen nach Hause." << std::endl;
                        std::cout << "Das Spiel ist somit vorbei." << std::endl;
                        return 0;
                    }
                    //End of item drop

                    //Gold drop
                    goldDrop(&character, &hero, character.gold);
                    //End of gold drop

                    position++;
                    enemyCount++;
                    break;

                } else {continue;}
            default:                                                            //INVALID INPUT
                std::cout << "Ungueltige Eingabe!" << std::endl;
                std::cin.clear();                // Fehlerzustand zurücksetzen
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Eingabepuffer leeren
                break;
        }
        hline();
        //break;
    }

}
