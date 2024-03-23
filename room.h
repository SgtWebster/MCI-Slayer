// room.h
// Created by webo on 23.03.2024.
//

#ifndef ROOM_H
#define ROOM_H

#include "GameConfig.h"
//#include <iostream>   //später prüfen, ob durch die Anbindung an andere Klassen das noch benötigt wird...
//#include <string>
//#include <array>
#include <map>

class Room {
private:
    std::string roomName;
    std::string roomDescription;

public:
    Room(); //Standardkonstruktor
    Room(std::string& roomName, std::string& roomDescription); //Parameterkonstruktor
    ~Room() = default;
};


#endif //ROOM_H
