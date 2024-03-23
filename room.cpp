// room.cpp
// Created by webo on 23.03.2024.
//

#include "room.h"

Room::Room() : roomName("empty"), roomDescription("empty"){

}

Room::Room(std::string& roomName, std::string& roomDescription) : roomName(roomName),roomDescription(roomDescription) {

}

