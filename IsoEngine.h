//
// Created by tymbys on 01.09.19.
//

#ifndef GAME1_ISOENGINE_H
#define GAME1_ISOENGINE_H

struct Point2D{
    int x;
    int y;
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
    void Convert2dToIso(Point2D &point);
    void ConvertIsoTo2D(Point2D &point);
    void GetTileCoordinates(Point2D &point, Point2D &point2DCoord);

private:


//    int _tileSize;

};


#endif //GAME1_ISOENGINE_H
