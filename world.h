// world.h
// Created by webp on 23.03.2024.
//

#ifndef WORLD_H
#define WORLD_H

#include "GameConfig.h"
#include "room.h"

//#include <string>
//#include <array>
#include <iostream>


class World {
public:
    World() = default;
    World(int weightMap, int hightMap) : weightMap(weightMap), hightMap(hightMap) {this->positionPlayerX = 2; this->positionPlayerY = 2;}
    ~World() = default;

    static void printMap(World& world);

    void setPlayerPosition(int x, int y) {
        positionPlayerX = x;
        positionPlayerY = y;
    }

    int getPlayerPositionX() const {return positionPlayerX;}
    int getPlayerPositionY() const {return positionPlayerY;}
    int getWeightMap() const {return weightMap;}
    int getHightMap() const {return hightMap;}

private:
    int weightMap;
    int hightMap;
    int positionPlayerX;
    int positionPlayerY;
};

#endif //WORLD_H
