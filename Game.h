//
// Created by tymbys on 31.08.19.
//

#ifndef GAME1_GAME_H
#define GAME1_GAME_H


#include <SDL2/SDL_events.h>
#include "DisplaySDL.h"
#include "Texture.h"
#include "IsoEngine.h"

class Game {
public:
    int _loopDone;
    SDL_Rect _mouseRect;
    Point2D _mousePoint;
    IsoEngine _isoEngine;

    Point2D _mapScroll2Dpos;
    int _mapScrollSpead;
    int _lastTileClicked;

    Game();
    ~Game();
    void DrawIsoMouse();
    void DwawIsoMap();
    void Draw();
    void Update();
    void UpdateInput();
    void SetupRect(SDL_Rect *rect, int x, int y, int w, int h);
    void InitTitleClip();
    void GetMouseTileClick();

private:
    SDL_Event _event;


    std::shared_ptr<DisplaySDL> _displaySDL;

    Texture _texture;
};


#endif //GAME1_GAME_H
