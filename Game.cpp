//
// Created by tymbys on 31.08.19.
//

#include "Game.h"

const  int NUM_ISOMETRIC_TITLES = 5;
SDL_Rect tilesRects[NUM_ISOMETRIC_TITLES];



int worldTest[MAP_HEIGHT][MAP_WIDTH] = {
        {1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,1},
        {1,1,1,1,2,1,1,2,1,1,2,2,2,2,2,1},
        {2,1,1,1,2,2,2,2,1,1,2,2,2,2,2,1},
        {2,1,1,2,2,1,1,2,1,1,2,2,2,2,2,1},
        {2,1,1,4,4,4,1,2,1,1,2,2,2,2,4,1},
        {2,1,1,4,4,4,1,2,1,1,2,2,2,2,2,1},
        {2,1,1,4,4,4,1,2,1,1,2,2,4,2,2,1},
        {2,2,2,4,4,4,2,1,2,3,3,3,4,2,2,1},
        {1,1,2,2,2,2,2,3,4,3,3,3,4,2,2,2},
        {1,1,1,1,2,1,1,2,1,3,3,3,2,2,2,3},
        {2,1,1,1,2,2,2,2,1,1,2,2,2,2,2,1},
        {2,1,1,2,2,1,1,2,1,1,3,2,2,2,4,4},
        {2,1,1,4,2,1,1,2,1,1,3,2,2,2,2,4},
        {2,1,1,1,2,1,1,2,1,1,3,3,3,3,3,4},
        {2,1,1,1,1,1,1,2,1,1,2,2,2,2,4,4},
        {2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,1}
};

Game::Game(): _loopDone(0){
    _displaySDL = std::make_shared<DisplaySDL>("Test GAME1");
    SDL_Init(SDL_INIT_JOYSTICK);
    if(SDL_NumJoysticks()<1)
        SDL_Log( "NO Joystick");
    else {
        SDL_Joystick *joystick = SDL_JoystickOpen(0);
        std::cout << "Joystick name:" << SDL_JoystickName(joystick) << std::endl;
        std::cout << "Num Axis:" << SDL_JoystickNumAxes(joystick) << std::endl;
        std::cout << "Num Buttons:" << SDL_JoystickNumButtons(joystick) << std::endl;
    }
    InitTitleClip();
    if (_texture.LoadTexture("data/isotiles.png") == 0){
        std::cerr << "Error: Could not load texture from dir data!" << std::endl;
        exit(1);
    }


    _isoEngine.SetTileSize(32);
    _isoEngine.SetMapSize(16, 16);
    _isoEngine._scrollX = 77;
    _isoEngine._scrollY = -77;

    _mapScroll2Dpos.x = -77;
    _mapScroll2Dpos.y = 0;

    _mapScrollSpead = 3;
    _lastTileClicked = -1;

}
Game::~Game(){}


void Game::DrawIsoMouse(){

    int correctX =(_mapScroll2Dpos.x%32)*2;
    int correctY = _mapScroll2Dpos.y%32;

    _mousePoint.x = (_mouseRect.x / _isoEngine._tileSize) * _isoEngine._tileSize;
    _mousePoint.y = (_mouseRect.y / _isoEngine._tileSize) * _isoEngine._tileSize;

    if((_mousePoint.x / _isoEngine._tileSize) % 2 ){
        _mousePoint.y += _isoEngine._tileSize * 0.5;
    }

    _texture.RenderXYClip(_mousePoint.x - correctX, _mousePoint.y + correctY, &tilesRects[0]);
}

void Game::DwawIsoMap(){
    Point2D point;
    int tile;
    for (int i=0; i < _isoEngine._mapHeight; ++i){
        for (int j=0; j < _isoEngine._mapWidth; ++j){
            point.x = (j * _isoEngine._tileSize) + _isoEngine._scrollX;
            point.y = (i * _isoEngine._tileSize) + _isoEngine._scrollY;

            tile = worldTest[i][j];

            _isoEngine.Convert2dToIso(point);
            _texture.RenderXYClip(point.x, point.y, &tilesRects[tile]);
        }
    }

}

void Game::Draw(){


    SDL_SetRenderDrawColor(Renderer::get().GetRenderer(), 0x3b, 0x3b, 0x3b, 0);

    SDL_RenderClear(Renderer::get().GetRenderer());

//    _texture.RenderXYClip(_mouseRect.x, _mouseRect.y, &tilesRects[0]);

    DwawIsoMap();
    DrawIsoMouse();

    if(_lastTileClicked!=-1){
        _texture.RenderXYClip(0,0,&tilesRects[_lastTileClicked]);
    }

    SDL_RenderPresent(Renderer::get().GetRenderer());
    SDL_Delay(10);
}

void Game::Update(){
    SDL_GetMouseState(&_mouseRect.x, &_mouseRect.y);
}
void Game::InvertMap(int world[MAP_HEIGHT][MAP_WIDTH], int button){
    static int8_t delta = 0;
    if(delta != 0) return;
    if(button == 4) delta = 1;
    if(button == 5) delta = -1;
    for(int i=0; i< MAP_HEIGHT; i++)
    {
       for (int k = 0; k < MAP_WIDTH; k++)
        {
           world[i][k] = world[i][k] + delta;
           if( world[i][k] == 5 ) world[i][k] = 1;
           if( world[i][k] == 0 ) world[i][k] = 4;
        }
    }
    delta = 0;

}
void Game::UpdateInput(){
    const Uint8  *keystate = SDL_GetKeyboardState(NULL);
    static  uint8_t  move = 0;
    while (SDL_PollEvent(&_event) != 0){
        switch (_event.type){
            case SDL_QUIT:
                _loopDone = 1;
                break;
            case SDL_KEYUP:
                switch (_event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        _loopDone = 1;
                        break;
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                if(_event.button.button == SDL_BUTTON_LEFT)
                {
                    GetMouseTileClick();
                }
                break;
            case SDL_JOYAXISMOTION:
                if(_event.jaxis.which == 0)
                    std::cout<< (int) _event.jaxis.axis <<" : "<< _event.jaxis.value << std::endl;
                    if((int)_event.jaxis.value==0){
                        //stop move 0
                        move = 0;
                    }
                    if((int) _event.jaxis.axis ==1 &&(_event.jaxis.value>0)){
                        //move down 1
                        move = 1;
                    }
                    if((int) _event.jaxis.axis ==1 &&(_event.jaxis.value<0)){
                        //move up 2
                        move = 2;
                    }
                    if((int) _event.jaxis.axis ==0 &&(_event.jaxis.value>0)){
                        //move right 3
                        move = 3;
                    }
                    if((int) _event.jaxis.axis ==0 &&(_event.jaxis.value<0)){
                        //move left 4
                        move = 4;
                    }
                break;
            case SDL_JOYBUTTONDOWN:
                    std::cout<< (int)_event.jbutton.button << std::endl;
                InvertMap(worldTest, (int) _event.jbutton.button);
                break;
            default:
                break;
        }
    }
    JoystickMove(move);
    if (keystate[SDL_SCANCODE_W]){
        _isoEngine._scrollX += _mapScrollSpead;
        _isoEngine._scrollY += _mapScrollSpead;
        _mapScroll2Dpos.y +=  _mapScrollSpead;
//        if(_mapScroll2Dpos.y > 0 ) {
//            _mapScroll2Dpos.y = 0;
//            _isoEngine._scrollX = _mapScrollSpead;
//            _isoEngine._scrollY = _mapScrollSpead;
//        }
    }

    if (keystate[SDL_SCANCODE_A]){
        _isoEngine._scrollX += _mapScrollSpead;
        _isoEngine._scrollY -= _mapScrollSpead;
        _mapScroll2Dpos.x -=  _mapScrollSpead;
    }

    if (keystate[SDL_SCANCODE_S]){
        _isoEngine._scrollX -= _mapScrollSpead;
        _isoEngine._scrollY -= _mapScrollSpead;
        _mapScroll2Dpos.y -=  _mapScrollSpead;
    }

    if (keystate[SDL_SCANCODE_D]){
        _isoEngine._scrollX -= _mapScrollSpead;
        _isoEngine._scrollY += _mapScrollSpead;
        _mapScroll2Dpos.x +=  _mapScrollSpead;
    }

}

void Game::JoystickMove(int8_t move){
    switch(move) {
        case 1:
            _isoEngine._scrollX += _mapScrollSpead;
            _isoEngine._scrollY += _mapScrollSpead;
            _mapScroll2Dpos.y +=  _mapScrollSpead;
            break;
        case 2:
            _isoEngine._scrollX -= _mapScrollSpead;
            _isoEngine._scrollY -= _mapScrollSpead;
            _mapScroll2Dpos.y -=  _mapScrollSpead;
            break;
        case 3:
            _isoEngine._scrollX += _mapScrollSpead;
            _isoEngine._scrollY -= _mapScrollSpead;
            _mapScroll2Dpos.x -=  _mapScrollSpead;
            break;
        case 4:
            _isoEngine._scrollX -= _mapScrollSpead;
            _isoEngine._scrollY += _mapScrollSpead;
            _mapScroll2Dpos.x +=  _mapScrollSpead;
            break;
        default:
            break;
    }

}
void Game::SetupRect(SDL_Rect *rect, int x, int y, int w, int h){
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
}

void Game::InitTitleClip(){
    int x=0, y=0;
    int i;

    _texture.InitTexture(0,0,0, NULL, NULL, SDL_FLIP_NONE);
    for (i=0; i < NUM_ISOMETRIC_TITLES; ++i){
        SetupRect(&tilesRects[i], x,y,64,80);
        x+=64;
    }
}


void Game::GetMouseTileClick(){
    Point2D point;
    Point2D tileShift, mouseIsoPoint;

    int correctX =(_mapScroll2Dpos.x%32)*2;
    int correctY = _mapScroll2Dpos.y%32;

    mouseIsoPoint = _mousePoint;

    _isoEngine.ConvertIsoTo2D(mouseIsoPoint);
    _isoEngine.GetTileCoordinates(mouseIsoPoint, point);

    tileShift.x = correctX;
    tileShift.y = correctY;
    _isoEngine.Convert2dToIso(tileShift);

    point.x-=((float)_isoEngine._scrollX+(float)tileShift.x)/(float)_isoEngine._tileSize;
    point.y-=((float)_isoEngine._scrollY-(float)tileShift.y)/(float)_isoEngine._tileSize;

    if(point.x>=0 && point.y>=0 && point.x<MAP_WIDTH && point.y<MAP_HEIGHT){
        _lastTileClicked = worldTest[point.y][point.x];
    }


}

