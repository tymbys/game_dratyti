//
// Created by tymbys on 01.09.19.
//

#ifndef GAME1_ISOENGINE_H
#define GAME1_ISOENGINE_H

#include <SDL2/SDL_events.h>

struct Point2D{
    float x;
    float y;
};

class IsoEngine {
public:
    int _tileSize;
    int _scrollX;
    int _scrollY;
    int _mapHeight;
    int _mapWidth;

    IsoEngine();
    void SetTileSize(int tileSizeInPixel);
//    int GetTileSize();
    void SetMapSize(int width, int height);
    void SetupRect(SDL_Rect &rect, int x, int y, int w, int h);
    void Convert2dToIso(Point2D &point);
    void ConvertIsoTo2D(Point2D &point);
    void GetTileCoordinates(Point2D &point, Point2D &point2DCoord);
    void ConvertIsoCameraToCartesian(Point2D &cartesianCamPos);
    void ConvertCartesianCameraToIsometric(Point2D &cartesianCamPos);

private:


//    int _tileSize;

};


#endif //GAME1_ISOENGINE_H
