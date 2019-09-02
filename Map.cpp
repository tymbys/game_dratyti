//
// Created by tymbys on 31.08.19.
//

#include "Map.h"

Map::Map(const unsigned int width, const unsigned int height): _heightMap(width), _widthMap(height){
    this->_dataMap.resize(width*height);
}

Map::~Map(){

}