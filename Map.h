//
// Created by tymbys on 31.08.19.
//

#ifndef GAME1_MAP_H
#define GAME1_MAP_H

#include <vector>
#include "Room.h"


class Map {
public:
    Map(const unsigned int width, const unsigned int height);
    ~Map();

private:
    unsigned int _widthMap, _heightMap;
    std::vector<Room> _room;
    std::vector<int> _dataMap;


};


#endif //GAME1_MAP_H
