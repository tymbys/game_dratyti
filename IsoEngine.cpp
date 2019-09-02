//
// Created by tymbys on 01.09.19.
//


#include <iostream>
#include "IsoEngine.h"

IsoEngine::IsoEngine(): _mapHeight(0), _mapWidth(0), _scrollX(0), _scrollY(0){
}

void IsoEngine::SetTileSize(int tileSizeInPixel){
    _tileSize = tileSizeInPixel;
}

//int IsoEngine::GetTileSize(){}

void IsoEngine::SetMapSize(int width, int height){
    _mapWidth = width;
    _mapHeight = height;
}


void IsoEngine::Convert2dToIso(Point2D &point){

    int tmpX = point.x - point.y;
    int tmpY = (point.x + point.y)*0.5;
    point.x = tmpX;
    point.y = tmpY;

//    std::cout << "x: " << point.x << " y: " << point.y << "x: " << point.x << " y: " << point.y << std::endl;
}

void IsoEngine::ConvertIsoTo2D(Point2D &point){
    int tmpX = (2 * point.y + point.x)*0.5;
    int tmpY = (2 * point.y - point.x)*0.5;
    point.x = tmpX;
    point.y = tmpY;
}

void  IsoEngine::GetTileCoordinates(Point2D &point, Point2D &point2DCoord){
//    point2DCoord.x = (int) ((float)point.x / (float)_tileSize);
//    point2DCoord.y = (int) ((float)point.y / (float)_tileSize);

    float tempX = (float)point.x / (float)_tileSize;
    float tempY = (float)point.y / (float)_tileSize;

    //convert back to integer
    point2DCoord.x = (int)tempX;
    point2DCoord.y = (int)tempY;

//    std::cout << "x: " << point2DCoord.x << " y: " << point2DCoord.y << std::endl;
}