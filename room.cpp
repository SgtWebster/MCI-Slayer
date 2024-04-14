// room.cpp
// Created by webo on 23.03.2024.
//

#include "room.h"

Room::Room() : roomName("empty"), roomDescription("empty Room"), roomMapSymbol(" . ") {  //Standardkonstruktor for empty room

}

Room::Room(std::string& roomName, std::string& roomDescription, std::string& roomMapSymbol) : roomName(roomName),roomDescription(roomDescription), roomMapSymbol(roomMapSymbol) {

}

//void Room::setRoomExit(std::string &direction, Room *room) {
//    roomExits[direction] = room;
//}


Gang::Gang() {
    this->roomName = "Gang";
    this->roomDescription = "Du befindest dich in einem Gang.";
    this->roomMapSymbol = " O ";

}

VerticalGang::VerticalGang() {
    this->roomName = "Verticaler Gang";
    this->roomDescription = "Du befindest dich in einem Gang.";
    this->roomMapSymbol = " - ";
}


HorizontalGang::HorizontalGang() {
    this->roomName = "Horizontaler Gang";
    this->roomDescription = "Du befindest dich in einem Gang.";
    this->roomMapSymbol = " | ";
}

