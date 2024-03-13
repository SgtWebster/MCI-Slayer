// main.cpp
// MCI-Slayer by Oliver Weber 2024

#include <iostream>
#include <string>
#include <limits>
#include <array>

//#include "character.h"
#include "hero.h"
//#include "schurke.h"
//#include "item.h"

#include "GameConfig.h"

//#define DEBUG //Debugmodus an
//#define HARD_DEBUG  //Hardcore-Debugmodus an

//using namespace std;


#ifdef HARD_DEBUG
int main() {
    std::cout << "DEBUG-MODUS!" << std::endl;
    Hero hero("test", 100, 100);        //create a hero with the name from the input
    std::cerr << "Erstellter Held: " << hero.getNameChar() << " hat " << hero.getHealth() << " Lebenspunkte und " << hero.getGold() << " Gold." << std::endl;
    std::cout << "Debug-Modus wird beendet..." << std::endl;
}
#endif

#ifndef HARD_DEBUG
//DEBUG-END

//START
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
    std::cout << "*  Willkommen zu >>MCI Slayer<< Version V0.4a! Ein Spiel von Oliver Ulrich Weber (c) 2024 " << std::endl;
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

    hline();
    std::cout << "Deine Heldin heisst " << inputemp << "!" << std::endl;
    hline();
    std::cout << inputemp << " betritt den MCI-Dungeon..." << std::endl;

    Hero hero(inputemp, DEFAULT_HERO_HEALTH, DEFAULT_HERO_GOLD);        //create a hero with the name from the input

#ifdef DEBUG
    std::cerr << "DEBUG-MODUS --- Erstellter Held: " << hero.getNameChar() << " hat " << hero.getHealth() << " Lebenspunkte und " << hero.getGold() << " Gold." << std::endl;
#endif


    int position = 0;
    int inventarCount = 0;

    // enemy temps
    int enemyCount = 0;

    Schurke emeny;                                         //temp character (empty) als Platzhalter
    std::string enemyName;  //temp enemy name
    int enemyHealth;        //temp enemy health
    int emenyGold;          //temp enemy gold

    // Erstellung Standard-Items
    std::array<Item, COUNT_OF_DEFAULT_ITEMS> items;        // Anzahl der möglichen Items (hat NICHTS mit max_Inventory zu tun!)
    auto defaultItems = createItemList();    //Erstellt Liste der Standard-Items

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
        std::cout << "Deine Wahl: _";
        std::cin >> input_intemp;
        std::cin.ignore();            //ignore the newline in the input buffer
        hline();

        switch (input_intemp) {
            case 1:                                                             //FIGHT!
                std::cout << "Du suchst fiese Schurken..." << std::endl;

                //Begin of the fight-------------------
                //Initalisieren des Gegners
                if (enemyCount % 2 == 0) {enemyName = "Matthias"; enemyHealth = 50; emenyGold = (rand() % 35 + 1);} else {enemyName = "Pascal"; enemyHealth = 100; emenyGold = (rand() % 30 + 1);}    //TODO - Randomizer

                std::cout << "Oh nein! Ein fieser Schurke namens " << enemyName << " erscheint!" << std::endl;
                hlineAsterix(3);
                emeny.newEmeny((std::string &) enemyName, enemyHealth, emenyGold);

                if (hero.startFight(&emeny)) {    //FIGHT! FIGHT! FIGHT! bool: false = lost, true = won
                    std::cout << emeny.getNameChar() << " fiel in Ohnmacht! " << hero.getNameChar() << " hat noch " << hero.getHealth() << " Lebenspunkte uebrig!" << std::endl;
                } else {
                    std::cout << hero.getNameChar() << " fiel in Ohnmacht!" << std::endl;
                    std::cout << "Du hast leider verloren." << std::endl;
                    return 0;
                }
                enemyCount++;
                //End of the fight-------------------


                //Item drop
                hlineAsterix(3);
                if (inventarCount == 0) {
                    emeny.itemDrop(&hero, defaultItems[0]);
                    inventarCount++;
                } else {
                    emeny.itemDrop(&hero, defaultItems[(rand() % 8 + 1)]);
                    inventarCount++;
                }
                if (emeny.getWeaponIsValid()) {emeny.itemDrop(&hero, emeny.getWeapon()); inventarCount++;}
                if (emeny.getArmorIsValid()) {emeny.itemDrop(&hero, emeny.getArmor()); inventarCount++;}

                if (inventarCount >= MAX_INVENTORY_SLOTS) {
                    std::cout << "Du hast nun schon so viele Items gefunden und gehst deswegen nach Hause." << std::endl;
                    std::cout << "Das Spiel ist somit vorbei." << std::endl;
                    return 0;
                }
                //End of item drop

                //Gold drop
                emeny.goldDrop(&hero, emeny.getGold());
                //End of gold drop

                enemyCount++;
                break;

            case 2:                                                             //SHOW INVENTORY-----------------------------------------------------
                hero.checkBackpack();
                //hline();
                break;

            case 3:                                                             //SHOW EQUIPMENT
                hero.checkEquipment();
                //hline();
                break;

            case 4:                                                             //EXPLORE DUNGEON   -- //TODO - für Zukunft in eigene Klasse einbauen
                std::cout << "Du erkundest den Dungeon" << (position > 0 ? " weiter" : "") << "..." << std::endl;
                position++;

                if (position >= 6) {
                    std::cout << hero.getNameChar() << " stolpert und faellt in einen endlosen Abgrund. Schade." << std::endl;
                    std::cout << "Du hast leider verloren." << std::endl;
                    if (hero.getTheForce()) {
                        std::cout << "Aber immerhin war die Macht war mit dir." << std::endl;
                    }
                    return 0;
                }

                break;

            case 42:                                                //EASTER EGG
                std::cout << "Du hast die Antwort auf alles gefunden!" << std::endl;
                std::cout << "Somit gibt es hier nichts noch wertvolleres zu entdecken..." << std::endl;

            case 9:                                                             //QUIT
                std::cout << hero.getNameChar() << " verlaesst den MCI-Dungeon samt ihrer Schaetze." << std::endl;
                std::cout << "Du hast " << hero.getGold() << " Gold und " << hero.getHealth() << " Lebenspunkte." << std::endl;
                if(hero.getTheForce()) {std::cout << "* * * Die Macht ist mit " << hero.getNameChar() << "! * * *" << std::endl;}       // The Force is with you!
                if(hero.getGold() == 0 || enemyCount == 0) {std::cerr << "Moment mal! Du hast kein einziges mal gekaempft?!" << std::endl;}    // No fight at all?
                std::cout << "Das Spiel wird beendet..." << std::endl;
                hlineAsterix(hlineLength);
                return 0;
            case 5:                                                            //EXPLORE DUNGEON - just for position 5 - SPECIAL FIGHT
                if (position == 5 ) {
                    std::cout << "Du erkundest den Raum..." << std::endl;
                    //Begin of the fight-------------------   SPECIAL FIGHT!
                    enemyName = "Hausmeister";
                    enemyHealth = 500;
                    emenyGold = 1000;

                    std::cout << "Oh nein! Ein fieser Schurke namens " << enemyName << " erscheint hinter der Statue!" << std::endl;
                    emeny.newEmeny((std::string &) enemyName, enemyHealth, emenyGold);
                    hlineAsterix(3);
                    if (hero.startFight(&emeny)) {           //FIGHT! FIGHT! FIGHT! bool: false = lost, true = won
                        std::cout << emeny.getNameChar() << " fiel in Ohnmacht! Ein Wasserkuebel hinter der Statue kippt um. " << hero.getNameChar() << " hat noch " << hero.getHealth() << " Lebenspunkte uebrig!" << std::endl;
                    } else {
                        std::cout << hero.getNameChar() << " fiel in Ohnmacht!" << std::endl;
                        std::cout << "Du hast leider verloren. Vom Hausmeister geschlagen. Schade." << std::endl;
                        return 0;
                    }
                    hlineAsterix(3);
                    enemyCount++;
                    //End of the fight-------------------

                    //Special Item drop
                    emeny.itemDrop(&hero, defaultItems[9]);
                    inventarCount++;
                    if (inventarCount >= MAX_INVENTORY_SLOTS) {
                        std::cout << "Du hast nun schon so viele Items gefunden... Sogar den ollen Mop! Nun gehst du endlich nach Hause." << std::endl;
                        std::cout << "Das Spiel ist somit vorbei." << std::endl;
                        return 0;
                    }
                    //End of special item drop

                    //Gold drop
                    emeny.goldDrop(&hero, emeny.getGold());
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
//END
#endif