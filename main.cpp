// main.cpp
// MCI-Slayer by Oliver Weber 2024

#include <iostream>
#include <string>
#include <limits>
#include <array>

#include "npc.h"   //in schurke.h laufen alle fäden bzw includes zusammen
#include "hero.h"

#include "fighter.h"   //TODO - Struktur noch verbessern?
#include "sorcerer.h"   //""

#define DECONSTRUCT // hero.~Hero(); enemy.~Schurke(); fighter.~Fighter(); sorcerer.~Sorcerer();  //TODO - fuer Abgabe wichtig?

//#define DEBUG       //Debugmodus an
//#define HARD_DEBUG  //Hardcore-Debugmodus an  (hab ich gebraucht, als ich letztesmal alles zerschossen hab)
//#define CHEAT_MODE  //Cheatmodus an (natuerlich nur fuer Debug Zwecke)

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
    std::cout << "*  Willkommen zu >>MCI Slayer<< Version V0.5a! Ein Spiel von Oliver Ulrich Weber (c) 2024 " << std::endl;
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
    std::cout << "Bitte waehle den Namen deiner Heldin:" << std::endl << "_";
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

#ifndef CHEAT_MODE //Normal Mode wenn Cheat-Mode aus
    Hero hero(inputemp, DEFAULT_HERO_HEALTH, DEFAULT_HERO_GOLD, 0, 0);        //create a hero with the name from the input
#endif

#ifdef DEBUG
    std::cerr << "DEBUG-MODUS --- Erstellter Held: " << hero.getNameChar() << " hat " << hero.getHealth() << " Lebenspunkte und " << hero.getGold() << " Gold." << std::endl;
#endif

    //Basic Setup
    int position = 0;  //Position im Dungeon
    int inventarCount = 0;

    // enemy temps
    int enemyCount = 0;
    int enemyCountFighter = 0;
    int enemyCountSocecer = 0;
    int fightScenario;

    Schurke enemy;                                         //temp - default enemy
    std::string enemyName;  //temp enemy name
    //int enemyHealth;        //temp enemy health
    //int emenyGold;          //temp enemy gold

    Fighter fighter;        //temp fighter
    Sorcerer sorcerer;      //temp sorcerer
    std::string schurkenText;   //für Kampftext

    auto defaultFighterList = Fighter::createFighterList();    //Erstellt Liste der Standard-Fighter (ohne ausgerüstete Gegenstände)
    auto defaultSocererList = Sorcerer::createSorcererList();    //Erstellt Liste der Standard-Sorcerer (ohne ausgerüstete Gegenstände)


    // Erstellung Standard-Items
    std::array<Item, COUNT_OF_DEFAULT_ITEMS> items;        // Anzahl der möglichen Items (hat NICHTS mit max_Inventory zu tun!)
    auto defaultItems = createItemList();    //Erstellt Liste der Standard-Items

    #ifdef CHEAT_MODE  //Cheat Mode für Debug
        Hero hero(inputemp, DEFAULT_HERO_HEALTH, DEFAULT_HERO_GOLD, 9999, 9999);
        hero.addItemToInventory(defaultItems[18]);
    #endif

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
        std::cout << "[3] Status und Ausruestung pruefen" << std::endl;
        std::cout << "[4] Erkunde den Dungeon" << (position == 0 ? "" : " weiter") << std::endl;
        if(position==5) {
            std::cout << "[5] Untersuche die Statue" << std::endl;
        }
        std::cout << "[9] Dungeon verlassen" << std::endl;
        std::cout << "Deine Wahl: _";
        std::cin >> input_intemp;
        std::cin.ignore();            //ignore the newline in the input buffer
        hline();

        int countOfDropItems;
        switch (input_intemp) {
            case 1:
                //FIGHT!
                std::cout << "Du suchst fiese Schurken..." << std::endl;

                //Begin of the fight-------------------
                //Initalisieren des Gegners
                if (enemyCount == 0) {fightScenario = 0;} else if (enemyCount % 2 == 0) {fightScenario = 1;} else {fightScenario = 2;}

                //Kampszenarios -> 1) Erster Kampf (initalKampf 2) Kampf gegen Fighter 3) Kampf gegen Sorcerer

                switch (fightScenario) {
                    case 0: //Erster Kampf
                        fighter = defaultFighterList[enemyCountFighter];
                        enemyCountFighter++;
                        if (enemyCountFighter == COUNT_OF_DEFAULT_ENEMYS) {enemyCountFighter = 0;}
                        fighter.silentWeaponEquip(defaultItems[0]);   //Schwert
                        fighter.silentArmorEquip(defaultItems[11]);   //MCI-Hoodie
                        enemyName = fighter.getNameChar();
                        schurkenText = "Schurken Mann";
                        enemy = Schurke(reinterpret_cast<Schurke &>(fighter));
                        break;
                    case 1: //Kampf gegen Fighter
                        fighter = defaultFighterList[enemyCountFighter];
                        enemyCountFighter++;
                        if (enemyCountFighter == COUNT_OF_DEFAULT_ENEMYS) {enemyCountFighter = 0;}
                        enemyName = fighter.getNameChar();
                        schurkenText = "Kaempfer Schurke";
                        fighter.silentWeaponEquip(defaultItems[getRandomNumber(0,2)]);
                        fighter.silentArmorEquip(defaultItems[getRandomNumber(6,8)]);
                        if (getRandomNumber(0,10) > 8) {sorcerer.addItemToInventory(defaultItems[getRandomNumber(14,15)]);}
                        enemy = Schurke(reinterpret_cast<Schurke &>(fighter));
                        break;
                    case 2: //Kampf gegen Sorcerer
                        sorcerer = defaultSocererList[enemyCountSocecer];
                        enemyCountSocecer++;
                        enemyName = sorcerer.getNameChar();
                        schurkenText = "Magier Schurke";
                        if (getRandomNumber(0,1)==1) {sorcerer.silentWeaponEquip(defaultItems[3]);}
                        if (getRandomNumber(0,1)==1) {sorcerer.silentArmorEquip(defaultItems[9]);}
                        if (enemyCountSocecer == COUNT_OF_DEFAULT_ENEMYS-1) {sorcerer.silentWeaponEquip(defaultItems[4]); sorcerer.silentArmorEquip(defaultItems[10]); schurkenText = "Erzmagier Schurken Meister";}
                        if (getRandomNumber(0,10) > 7) {sorcerer.silentAccessoryEquip(defaultItems[getRandomNumber(12,13)]);}
                        if (getRandomNumber(0,10) > 9) {sorcerer.addItemToInventory(defaultItems[getRandomNumber(14,16)]);}
                        enemy = Schurke(reinterpret_cast<Schurke &>(sorcerer));
                        if (enemyCountSocecer == COUNT_OF_DEFAULT_ENEMYS-1) {enemyCountSocecer = 0;}
                        break;
                    default:
                        std::cerr << "Ungueltiges Kampfszenario!" << std::endl;
                        return 1;
                        break;
                }
                std::cout << "Oh nein! Ein fieser "<< schurkenText << " namens " << enemyName << " erscheint!" << std::endl;
                hlineAsterix(10);

                //enemy.silentWeaponEquip( Item("Holzstock", 1, 1, true, 1, 0, "So ein seltsamer Stock aber auch!"));  //Debug-Gegenstand

                if (fightScenario == 2 ? hero.startFight(&sorcerer) : hero.startFight(&fighter)) {    //FIGHT! FIGHT! FIGHT! bool: false = lost, true = won    //hero.startFight(&enemy)
                    std::cout << enemyName << " fiel in Ohnmacht! " << hero.getNameChar() << " hat noch " << hero.getHealth() << " Lebenspunkte uebrig!" << std::endl;
                    hero.battlecry();
                } else {
                    std::cout << hero.getNameChar() << " fiel in Ohnmacht!" << std::endl;
                    std::cout << "Du hast leider verloren." << std::endl;
                    DECONSTRUCT
                    return 0;
                }

                //End of the fight-------------------


                //Item drop
                hlineAsterix(10);
                countOfDropItems = 0;
                if ((getRandomNumber(0,2) > 0 || enemyCount == 0) && enemy.getWeaponIsValid()) {enemy.itemDrop(&hero, enemy.getWeapon()); inventarCount++; countOfDropItems++;}
                if ((getRandomNumber(0,2) > 0 || enemyCount == 0) && enemy.getArmorIsValid()) {enemy.itemDrop(&hero, enemy.getArmor()); inventarCount++; countOfDropItems++;}
                if ((getRandomNumber(0,2) > 0 || enemyCount == 0) && enemy.getAccessoryIsValid()) {enemy.itemDrop(&hero, enemy.getAccessory()); inventarCount++; countOfDropItems++;}
                if (enemy.isSomethingInInventory()) {enemy.itemDrop(&hero, enemy.getItemFromInventory(0)); inventarCount++; countOfDropItems++;}

                if ((getRandomNumber(0,10) == 10) && enemyCount == 0) {enemy.itemDrop(&hero, defaultItems[getRandomNumber(17,18)]); inventarCount++; countOfDropItems++;}


                if (inventarCount >= MAX_INVENTORY_SLOTS) {
                    std::cout << "Du hast nun schon so viele Items gefunden und gehst deswegen nach Hause." << std::endl;
                    std::cout << "Das Spiel ist somit vorbei." << std::endl;
                    DECONSTRUCT
                    return 0;
                }
                //End of item drop

                if (countOfDropItems > 0) { hlineAsterix(10); }

                //Gold drop
                enemy.goldDrop(&hero, enemy.getGold());
                //End of gold drop

//                enemy.~Schurke(); //delete the enemy
                enemyCount++;
                break;

            case 2:                                                             //SHOW INVENTORY-----------------------------------------------------
                hero.checkBackpack();
                //hline();
                break;

            case 3:                                                             //SHOW EQUIPMENT
                hero.checkStats();
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
                    DECONSTRUCT
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
                DECONSTRUCT
                return 0;
            case 5:                                                            //EXPLORE DUNGEON - just for position 5 - SPECIAL FIGHT
                if (position == 5 ) {
                    std::cout << "Du erkundest den Raum..." << std::endl;
                    //Begin of the fight-------------------   SPECIAL FIGHT!
                    enemyName = "Hausmeister";
                    sorcerer = defaultSocererList[COUNT_OF_DEFAULT_ENEMYS-1];    //Hausmeister ist der letzte in der Liste
                    sorcerer.silentWeaponEquip(Item("Mop", 1, 1, true, 1, 0, "Der Mop der Macht!"));

                    std::cout << "Oh nein! Ein fieser Schurken Meister namens " << enemyName << " erscheint hinter der Statue!" << std::endl;

                    hlineAsterix(3);
                    if (hero.startFight(&sorcerer)) {           //FIGHT! FIGHT! FIGHT! bool: false = lost, true = won
                        std::cout << enemyName << " fiel in Ohnmacht! Ein Wasserkuebel hinter der Statue kippt um. " << hero.getNameChar() << " hat noch " << hero.getHealth() << " Lebenspunkte uebrig!" << std::endl;
                    } else {
                        std::cout << hero.getNameChar() << " fiel in Ohnmacht!" << std::endl;
                        std::cout << "Du hast leider verloren. Vom " << enemyName << " geschlagen. Schade." << std::endl;
                        DECONSTRUCT
                        return 0;
                    }
                    hlineAsterix(3);
                    enemyCount++;
                    //End of the fight-------------------

                    //Special Item drop
                    sorcerer.itemDrop(&hero, defaultItems[COUNT_OF_DEFAULT_ITEMS-1]);
                    inventarCount++;
                    if (inventarCount >= MAX_INVENTORY_SLOTS) {
                        std::cout << "Du hast nun schon so viele Items gefunden... Sogar den ollen Mop! Nun gehst du endlich nach Hause." << std::endl;
                        std::cout << "Das Spiel ist somit vorbei." << std::endl;
                        DECONSTRUCT
                        return 0;
                    }
                    //End of special item drop

                    //Gold drop
                    sorcerer.goldDrop(&hero, sorcerer.getGold());
                    //End of gold drop
                    //enemy.~Schurke(); //delete the enemy
                    position++;

                    break;

                } else {
                    std::cout << "Ungueltige Eingabe!" << std::endl;
                    break;
                }
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