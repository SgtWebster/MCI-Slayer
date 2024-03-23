// hero.cpp
// Created by Oliver Weber on 23.02.2024.
//

#include <iostream>
#include <string>
//#include <cstdlib>   // for rand() -> durch random abgelöst (GameConfig)

#include "hero.h"
#include "schurke.h"


Hero::Hero(const std::string& name, int health, int gold, int armorDefenseValue, int magicalDefenseValue) : Character(name, health, gold, armorDefenseValue, magicalDefenseValue) {    //Parameterkonstruktor für Hero
    this->theForce = false;
    this->fight = false;
    //stats
    this->statsANG = 15; //basic-Angriffswert
    this->statsDEF = armorDefenseValue;
    this->statsMANG = 0;
    this->statsMDEF = magicalDefenseValue;
    this->statsEXP = 0;
    this->statsLVL = 1;
}

void Hero::attack(Schurke *emeny) {    //Hero greift Schurke an
    int attackPower = getRandomNumber(statsANG,statsANG+10);     //rand() % 11 + 15;    //TODO -> Levelabhängigkeit
    int attackPowerMagic = statsMANG;

    std::string weaponName;
    weaponName = "";

    if (this->getWeaponIsValid()) {   //wenn eine Waffe ausgerüstet ist, wird der Schaden erhöht
        weaponName = this->getWeaponName();
    }
    attackPower = attackPower + this->getWeaponStrength() - emeny->getPhysicalBodyDefenseValue() - emeny->getArmorStrength();   //Schaden wird durch Rüstung des Gegners verringert;
    attackPowerMagic = attackPowerMagic + this->getWeaponMagic() + this->getAccessoryStrength() - emeny->getMagicalBodyDefenseValue() - emeny->getArmorMagic();   //Schaden wird durch magische Rüstung des Gegners verringert;
    (attackPower < 0 ? attackPower = 0 : attackPower = attackPower);
    (attackPowerMagic < 0 ? attackPowerMagic = 0 : attackPowerMagic = attackPowerMagic);

    if (this->theForce) {    //wenn die Macht stark ist, wird der Schaden erhöht
        attackPower += getRandomNumber(20,30);
    }

    attackPower += attackPowerMagic;

    std::cout << this->getNameChar() << " tifft" << (this->getWeaponIsValid() ? " mit ihrem " : "") << weaponName << " " << emeny->getNameChar() << " fuer " << attackPower << " Lebenspunkte!" << (this->getTheForce() ? " Die Macht ist stark mit dieser da!" : "") << std::endl;
    emeny->getDamage(attackPower);
    if (attackPower == 0) {
        std::cout << "(*) Der Schurke " << emeny->getNameChar() << " hat den Angriff abgewehrt! Mist!" << std::endl;
    }
    this->setStatsEXP(this->getStatsEXP() + attackPower);
}


bool Hero::startFight(Schurke* emeny) {                     //FIGHT-Modus! Läuft so lange bis der Kampf zu ende ist! false = lost, true = won
    std::cout << this->getNameChar() << " greift " << emeny->getNameChar() << " an!" << std::endl;
    hlineAsterix(10);
    int rounds = 0;
    while (true) {
        if (this->getSpecialIsValid()) {   //Granaten-Special
            this->granate(this->getSpecial());
            std::cout << emeny->getNameChar() << " wurde von der " << this->getSpecialName() << " getroffen!" << std::endl;
            this->special = Item("empty-constructor", 0, 0, false);
            return true;
        }


        this->attack(emeny);
        if (emeny->getHealth() <= 0) {
            return true;
        }
        emeny->attack(this);
        if (this->getHealth() <= 0) {
            return false;
        }
        std::cout << std::endl;
        rounds++;
        if (rounds > 25) {
            std::cout << "(*) Wieso dauert das so lange? " << emeny->getNameChar() << " faengt vor Uebermuedung und Unterzucker zu schwanken an." << std::endl;
            return true;
        }
    }
    //return false;   //Should never be reached (Backup)
}

void Hero::setTheForceTrue() {
    this->theForce = true;
}

void Hero::checkStats() {
    std::cout << "[NAME:] " << this->getNameChar() << std::endl;
    std::cout << "[LEBEN:] " << this->getHealth() << std::endl;
    std::cout << "[GOLD:] " << this->getGold() << std::endl;
    if (this->getTheForce()) {std::cout << "[MACHT:] Die Macht ist stark mit dieser hier!" << std::endl;}
    std::cout << "[ERFAHRUNGSPUNKTE:] " << statsEXP << std::endl;
    std::cout << "[LEVEL:] " << statsLVL << std::endl;
    hline();
    std::cout << "[ANGRIFFSKRAFT:] "<< statsANG + this->getWeaponStrength() << std::endl;
    std::cout << "[ABWEHRLRAFT:] " << statsDEF + this->getArmorStrength() << std::endl;
    std::cout << "[MAGIEANGRIFF:] " << statsMANG + this->getWeaponMagic() + this->getAccessoryStrength() << std::endl;
    std::cout << "[MAGIEABWEHR:] " << statsMDEF + this-> getArmorMagic() + this->getAccessoryMagic() << std::endl;
    hline();
}



void Hero::battlecry() {
    int cryTry = getRandomNumber(0,50);
    if(cryTry > 15) {return;}
    hlineAsterix(10);
    std::cout << this->getNameChar() << " schreit: \"";
    switch (cryTry) {
        case 0: std::cout << "So schauts aus im Schneckenhaus!"; break;
        case 1: if (this->getTheForce()) {std::cout << "Ich bin deine Mutter!"; break;} else {std::cout << "Ha! Schurke!"; break;}
        case 2: std::cout << "Haha Schurke, das hast du davon!"; break;
        case 3: std::cout << "Nicht schlecht fuer einen Tag im Leben einer Heldin!"; break;
        case 4: std::cout << "Friss meine 42er!"; break;
        case 5: std::cout << "Warum bekomme ich eigentliche keine Erfahrungspunkte? Wird das noch gepatchet?"; break;
        case 6: std::cout << "Bumm! Zack! Krach!"; break;
        case 7: std::cout << "Wolltest du gegen mich antreten, oder nur mein Autogramm?"; break;
        case 8: std::cout << "Schurken besiegen - mein Lieblingssport!"; break;
        case 9: std::cout << "Nichtmal mit einem Cheat-Code haettest du gegen mich gewonnen, Schurke!"; break;
        case 10: std::cout << "Mein Koerper ist stark vom vielen Kaffee!"; break;
        case 11: std::cout << "Aus dem Weg, du Schufft!"; break;
        case 12: std::cout << "Damit hast du wohl nicht gerechnet, als du heute aufgestanden bist!"; break;
        case 13: std::cout << "Im Licht der Gerechtigkeit wirst du immer im Schatten stehen, du Schurke!"; break;
        case 14: std::cout << "Schon vorbei?"; break;
        case 15: std::cout << "Und so endet ein weiteres Kapitel in der Legende meiner Taten!"; break;
        default: std::cout << "Verschwinde, elender Bug!"; break;
    }
    std::cout << "\"" << std::endl;
}

void Hero::dodgecry() {
    int cryTry = getRandomNumber(0,30);
    if(cryTry > 10) {return;}
    std::cout << "(*) " << this->getNameChar() << " schreit: \"";

    switch (cryTry) {
        case 0: std::cout << "Haha, verfehlt!"; break;
        case 1: std::cout << "Du hast mich nicht getroffen, Schurke!"; break;
        case 2: std::cout << "Zu langsam, Schurke!"; break;
        case 3: std::cout << "Du hast mich nicht erwischt!"; break;
        case 4: std::cout << "Haha, daneben!"; break;
        case 5: std::cout << "Du wirst mich nicht besiegen!"; break;
        case 6: std::cout << "Ich koennte noch stundenlang so weitermachen!"; break;
        case 7: std::cout << "Du solltest lieber mal deinen Spinat aufessen!"; break;
        case 8: std::cout << "Du bist so langsam wie ein Schneckenrennen!"; break;
        case 9: std::cout << "Ich brauche Gegner, keine Opfer!"; break;
        case 10: std::cout << "Satz mit X, das war wohl nix! Haha!"; break;
        default: std::cout << "Verschwinde, elender Bug!"; break;
    }
    std::cout << "\"" << std::endl;
}

void Hero::granate(const Item& granate) {
    //std::cout << this->getNameChar() << " wirft " << granate.getName() << std::endl;
    std::cout << "(*) " << this->getNameChar() << " schreit: \"";
    std::cout << "Wir haben die Heillige Handgranate von Antiochia! Natuerlich! Sie ist eine der Reliquien die sich an meinem Guertel befindet!" << std::endl;
    std::cout << "Oh HERR, ich bitte dich, segne diese deine Handgranate! Moege sie deine Feinde in die Luft sprengen, in deinem Erbarmen!"<< std::endl;
    std::cout << std::endl;
    std::cout << "Zuerst ziehe die heilige Zuendnadel aus dem Gehause. Sodann sollst du zaehlen bis drei, nicht mehr und nicht weniger."<< std::endl ;
    std::cout << "Drei alleine soll die Nummer sein, die du zaehlst und die Nummer, die du zaehlst, soll Drei und nur Drei sein."<< std::endl;
    std::cout << "Weder sollst du bis Vier zaehlen, noch sollst du nur bis zur Zwei zaehlen, es sei denn, dass du fortfaehrst zu zaehlen bis zur Drei."<< std::endl;
    std::cout << "Die Fuenf scheidet voellig aus."<< std::endl;
    std::cout << std::endl;
    std::cout << "Wenn dann die Nummer Drei, welches ist die dritte Nummer von vorne, erreicht ist,"<< std::endl;
    std::cout << "dann schleudere mit Kraft deine Heilige Handgranate von Antiochia gegen deinen Feind."<< std::endl;
    std::cout << "Wer sich schuldig macht in meinen Augen, soll sehen was er davon hat. Amen."<< std::endl;
    std::cout << std::endl;
    std::cout << "...Na dann! Eins... Zwei... Fuenf! ...eh... Drei!";
    std::cout << "\"" << std::endl;
    std::cout << std::endl;
    std::cout << "(*) " << this->getNameChar() << " wirft die Heilige Handgranate von Antiochia!" << std::endl;
    std::cout << "BOOM!" << std::endl;
}

