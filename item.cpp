// item.cpp
// Created by Oliver Weber on 23.02.2024.
//

//#include <iostream>
#include <string>
#include "item.h"


//Item::Item(const std::string& name, int value, int type, bool isValid, int strengh ) : name(name), value(value), type(type), isValid(isValid), strengh(strengh) {}

Item::Item() : name("empty"), value(0), type(0), isValid(false), strengh(0), magic(0), description("empty - standardkonstruktor") {}   //Standardkonstruktor (Platzhalter-Item)

Item::Item(const std::string &name, int value, int type, bool isValid, int strength, int magic, const std::string &description)
        : name(name), value(value), type(type), isValid(isValid), strengh(strength), magic(magic), description(description) {}


Item::Item(Item const &) = default;                                                                          //Copy-Konstruktor


