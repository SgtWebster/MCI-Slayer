// world.cpp
// Created by webo on 23.03.2024.
//

#include "world.h"


//World::World() = default;


void World::printMap(World& world) {

    std::cout << "Du schaust auf die Karte..." << std::endl;
    hline();
    std::vector<std::vector<Room>> map(world.getHightMap(), std::vector<Room>(world.getWeightMap()), Room());
    bool hozontalGang = false;
    bool verticalGang = false;


    for (int y = 0; y < map.size(); ++y) {
        for (int x = 0; x < map[y].size(); ++x) {
            // Prüfe, ob die aktuelle Position der Heldenposition entspricht
            if (x == world.getPlayerPositionX() && y == world.getPlayerPositionY()) {
                std::cout << "-X-" << " "; // Helden-Symbol
            } else {
                std::cout << map[y][x].getRoomMapSymbol() << " ";
            }
        }
        std::cout << std::endl;

    }
    hline();
    std::cout << "Legende: [ ] leerer Raum | -x- Position der Heldin | [?] Raum noch nicht aufgedeckt" << std::endl;
}


