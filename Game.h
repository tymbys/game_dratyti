//
// Created by tymbys on 31.08.19.
//

#ifndef GAME1_GAME_H
#define GAME1_GAME_H


#include <SDL2/SDL_events.h>
#include "DisplaySDL.h"
#include "Texture.h"
#include "IsoEngine.h"
enum GAME_MODE{
    GAME_MODE_OVERVIEW = 0,
    GAME_MODE_OBJECT_FOCUS = 1
};


enum PLAYER_DIR{
    PLAYER_DIR_UP_LEFT      =0,
    PLAYER_DIR_UP           =1,
    PLAYER_DIR_UP_RIGHT     =2,
    PLAYER_DIR_RIGHT        =3,
    PLAYER_DIR_DOWN_RIGHT   =4,
    PLAYER_DIR_DOWN         =5,
    PLAYER_DIR_DOWN_LEFT    =6,
    PLAYER_DIR_LEFT         =7
};

class Game {
public:
    int _loopDone;
    SDL_Rect _mouseRect;
    Point2D _mousePoint;
    IsoEngine _isoEngine;

    Point2D _mapScroll2Dpos;
    int _mapScrollSpeed;
    int _lastTileClicked;
    float _zoomLevel;

    Point2D _tilePos;

    GAME_MODE _gameMode;

    Point2D _charPoint;
    int _charDirection;

    Game();
    ~Game();
    void PrintCoordinats();
    void DrawIsoMouse();
    void DrawIsoMap();
    void Draw();
    void Update();
    void UpdateInput();
//    void SetupRect(SDL_Rect *rect, int x, int y, int w, int h);
    void InitTitleClip();
    void getMouseTilePos(Point2D &mouseTilePos);
    void GetMouseTileClick();
    void CenterMapToTileUnderMouse();
    void CenterMap(Point2D objectPoint);
    void ScrollMapWithMouse();
    void InitCharClip();
    void DrawCharacter();

private:
    SDL_Event _event;


    std::shared_ptr<DisplaySDL> _displaySDL;

    Texture _texture;
    Texture _characterTexture;
};


#endif //GAME1_GAME_H
