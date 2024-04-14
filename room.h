// room.h
// Created by webo on 23.03.2024.
//

#ifndef ROOM_H
#define ROOM_H

#include "GameConfig.h"
#include <map>

class Room {
protected:
    std::string roomName;
    std::string roomDescription;
    std::string roomMapSymbol;
//    std::map <std::string, Room*> roomExits;   //fuer spaetere Implementierung

public:
    Room(); //Standardkonstruktor
    Room(std::string& roomName, std::string& roomDescription, std::string& roomMapSymbol); //Parameterkonstruktor
    ~Room() = default;

    //getter
    std::string getRoomName() const {return roomName;}
    std::string getRoomDescription() const {return roomDescription;}
    std::string getRoomMapSymbol() const {return roomMapSymbol;}


//    void setRoomExit(std::string& direction, Room* room);   //fuer spaetere Implementierung
};


class Gang : public Room {
public:
    Gang();
};


#endif //ROOM_H

class VerticalGang : public Room {
public:
    VerticalGang();
};

class HorizontalGang : public Room {
public:
    HorizontalGang();
};