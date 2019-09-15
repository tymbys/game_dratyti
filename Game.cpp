//
// Created by tymbys on 31.08.19.
//

#include "Game.h"

const  int NUM_ISOMETRIC_TITLES = 5;
SDL_Rect tilesRects[NUM_ISOMETRIC_TITLES];

const  int NUM_CHARACTER_SPRITES = 8;
SDL_Rect charRects[NUM_CHARACTER_SPRITES];


//#define MAP_HEIGHT 16
//#define MAP_WIDTH 16
//const int worldTest[MAP_HEIGHT][MAP_WIDTH] = {
//        {1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,1},
//        {1,1,1,1,2,1,1,2,1,1,2,2,2,2,2,1},
//        {2,1,1,1,2,2,2,2,1,1,2,2,2,2,2,1},
//        {2,1,1,2,2,1,1,2,1,1,2,2,2,2,2,1},
//        {2,1,1,4,4,4,1,2,1,1,2,2,2,2,4,1},
//        {2,1,1,4,4,4,1,2,1,1,2,2,2,2,2,1},
//        {2,1,1,4,4,4,1,2,1,1,2,2,4,2,2,1},
//        {2,2,2,4,4,4,2,1,2,3,3,3,4,2,2,1},
//        {1,1,2,2,2,2,2,3,4,3,3,3,4,2,2,2},
//        {1,1,1,1,2,1,1,2,1,3,3,3,2,2,2,3},
//        {2,1,1,1,2,2,2,2,1,1,2,2,2,2,2,1},
//        {2,1,1,2,2,1,1,2,1,1,3,2,2,2,4,4},
//        {2,1,1,4,2,1,1,2,1,1,3,2,2,2,2,4},
//        {2,1,1,1,2,1,1,2,1,1,3,3,3,3,3,4},
//        {2,1,1,1,1,1,1,2,1,1,2,2,2,2,4,4},
//        {2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,1}
//};


#define MAP_HEIGHT 32
#define MAP_WIDTH 32
const int worldTest[MAP_HEIGHT][MAP_WIDTH] = {
        {1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,1, 1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,1},
        {1,1,1,1,2,1,1,2,1,1,2,2,2,2,2,1, 1,1,1,1,2,1,1,2,1,1,2,2,2,2,2,1},
        {2,1,1,1,2,2,2,2,1,1,2,2,2,2,2,1, 2,1,1,1,2,2,2,2,1,1,2,2,2,2,2,1},
        {2,1,1,2,2,1,1,2,1,1,2,2,2,2,2,1, 2,1,1,2,2,1,1,2,1,1,2,2,2,2,2,1},
        {2,1,1,4,4,4,1,2,1,1,2,2,2,2,4,1, 2,1,1,4,4,4,1,2,1,1,2,2,2,2,4,1},
        {2,1,1,4,4,4,1,2,1,1,2,2,2,2,2,1, 2,1,1,4,4,4,1,2,1,1,2,2,2,2,2,1},
        {2,1,1,4,4,4,1,2,1,1,2,2,4,2,2,1, 2,1,1,4,4,4,1,2,1,1,2,2,4,2,2,1},
        {2,2,2,4,4,4,2,1,2,3,3,3,4,2,2,1, 2,2,2,4,4,4,2,1,2,3,3,3,4,2,2,1},
        {1,1,2,2,2,2,2,3,4,3,3,3,4,2,2,2, 1,1,2,2,2,2,2,3,4,3,3,3,4,2,2,2},
        {1,1,1,1,2,1,1,2,1,3,3,3,2,2,2,3, 1,1,1,1,2,1,1,2,1,3,3,3,2,2,2,3},
        {2,1,1,1,2,2,2,2,1,1,2,2,2,2,2,1, 2,1,1,1,2,2,2,2,1,1,2,2,2,2,2,1},
        {2,1,1,2,2,1,1,2,1,1,3,2,2,2,4,4, 2,1,1,2,2,1,1,2,1,1,3,2,2,2,4,4},
        {2,1,1,4,2,1,1,2,1,1,3,2,2,2,2,4, 2,1,1,4,2,1,1,2,1,1,3,2,2,2,2,4},
        {2,1,1,1,2,1,1,2,1,1,3,3,3,3,3,4, 2,1,1,1,2,1,1,2,1,1,3,3,3,3,3,4},
        {2,1,1,1,1,1,1,2,1,1,2,2,2,2,4,4, 2,1,1,1,1,1,1,2,1,1,2,2,2,2,4,4},
        {2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,1, 2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,1},

        {1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,1, 1,1,2,2,2,2,2,2,1,1,2,2,2,2,2,1},
        {1,1,1,1,2,1,1,2,1,1,2,2,2,2,2,1, 1,1,1,1,2,1,1,2,1,1,2,2,2,2,2,1},
        {2,1,1,1,2,2,2,2,1,1,2,2,2,2,2,1, 2,1,1,1,2,2,2,2,1,1,2,2,2,2,2,1},
        {2,1,1,2,2,1,1,2,1,1,2,2,2,2,2,1, 2,1,1,2,2,1,1,2,1,1,2,2,2,2,2,1},
        {2,1,1,4,4,4,1,2,1,1,2,2,2,2,4,1, 2,1,1,4,4,4,1,2,1,1,2,2,2,2,4,1},
        {2,1,1,4,4,4,1,2,1,1,2,2,2,2,2,1, 2,1,1,4,4,4,1,2,1,1,2,2,2,2,2,1},
        {2,1,1,4,4,4,1,2,1,1,2,2,4,2,2,1, 2,1,1,4,4,4,1,2,1,1,2,2,4,2,2,1},
        {2,2,2,4,4,4,2,1,2,3,3,3,4,2,2,1, 2,2,2,4,4,4,2,1,2,3,3,3,4,2,2,1},
        {1,1,2,2,2,2,2,3,4,3,3,3,4,2,2,2, 1,1,2,2,2,2,2,3,4,3,3,3,4,2,2,2},
        {1,1,1,1,2,1,1,2,1,3,3,3,2,2,2,3, 1,1,1,1,2,1,1,2,1,3,3,3,2,2,2,3},
        {2,1,1,1,2,2,2,2,1,1,2,2,2,2,2,1, 2,1,1,1,2,2,2,2,1,1,2,2,2,2,2,1},
        {2,1,1,2,2,1,1,2,1,1,3,2,2,2,4,4, 2,1,1,2,2,1,1,2,1,1,3,2,2,2,4,4},
        {2,1,1,4,2,1,1,2,1,1,3,2,2,2,2,4, 2,1,1,4,2,1,1,2,1,1,3,2,2,2,2,4},
        {2,1,1,1,2,1,1,2,1,1,3,3,3,3,3,4, 2,1,1,1,2,1,1,2,1,1,3,3,3,3,3,4},
        {2,1,1,1,1,1,1,2,1,1,2,2,2,2,4,4, 2,1,1,1,1,1,1,2,1,1,2,2,2,2,4,4},
        {2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,1, 2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,1}
};

Game::Game(): _loopDone(0){
    _displaySDL = std::make_shared<DisplaySDL>("Test GAME1");

    InitTitleClip();
    if (_texture.LoadTexture("data/isotiles.png") == 0){
        std::cerr << "Error: Could not load texture from dir data!" << std::endl;
        exit(1);
    }

    InitCharClip();

    if(_characterTexture.LoadTexture("data/character.png")==0){
        std::cerr << "Error, could not load texture: data/character.png" << std::endl;
        exit(1);
    }


    _isoEngine.SetTileSize(32);
    _isoEngine.SetMapSize(MAP_WIDTH, MAP_HEIGHT);
    _isoEngine._scrollX = 0;
    _isoEngine._scrollY = 0;

    _mapScroll2Dpos.x = 0;
    _mapScroll2Dpos.y = 0;

    _mapScrollSpeed = 6;
    _lastTileClicked = -1;

    _charPoint.x = 0;
    _charPoint.y = 0;

    _zoomLevel = 1;//   1.23;

    _charDirection = PLAYER_DIR_DOWN;
    _gameMode = GAME_MODE_OVERVIEW;

}
Game::~Game(){}

//ДОДЕЛАТЬ!!!!
void Game::DrawIsoMouse(){

    int modulusX = _isoEngine._tileSize*_zoomLevel;
    int modulusY = _isoEngine._tileSize*_zoomLevel;

    int correctX =(((int)_mapScroll2Dpos.x) % modulusX)*2;
    int correctY = (int)(((int)_mapScroll2Dpos.y) % modulusY);

    _mousePoint.x = (_mouseRect.x / _isoEngine._tileSize) * _isoEngine._tileSize;
    _mousePoint.y = (_mouseRect.y / _isoEngine._tileSize) * _isoEngine._tileSize;

    if(((int)_mousePoint.x / _isoEngine._tileSize) % 2 ){
        _mousePoint.y += _isoEngine._tileSize * 0.5;
    }

    _texture.RenderXYClipScale((_zoomLevel * _mousePoint.x )- correctX, (_zoomLevel * _mousePoint.y) + correctY, &tilesRects[0], _zoomLevel);
}

//void Game::DwawIsoMap(){
//    Point2D point;
//    int tile;
//    for (int i=0; i < _isoEngine._mapHeight; ++i){
//        for (int j=0; j < _isoEngine._mapWidth; ++j){
//            point.x = (j * _isoEngine._tileSize * _zoomLevel) + _isoEngine._scrollX;
//            point.y = (i * _isoEngine._tileSize * _zoomLevel) + _isoEngine._scrollY;
//
//            tile = worldTest[i][j];
//
//            _isoEngine.Convert2dToIso(point);
////            _texture.RenderXYClip(point.x, point.y, &tilesRects[tile]);
//            _texture.RenderXYClipScale(point.x, point.y, &tilesRects[tile], _zoomLevel);
//        }
//    }
//
//}

void Game::DrawIsoMap(){
    int i,j;
    int x,y;
    int tile = 4;
    Point2D point;
    int w =Renderer::get().GetWidth();
    int h =Renderer::get().GetHeight();

    int startX = -3/_zoomLevel +(_mapScroll2Dpos.x/_zoomLevel/_isoEngine._tileSize)*2;
    int startY = -20/_zoomLevel + abs((_mapScroll2Dpos.y/_zoomLevel/_isoEngine._tileSize))*2;
    int numTilesInWidth = ((w/_isoEngine._tileSize)/_zoomLevel);
    int numTilesInHeight = ((h/_isoEngine._tileSize)/_zoomLevel)*2;

    for(i=startY;i<startY+numTilesInHeight+26;++i){
        for(j=startX;j<startX+numTilesInWidth+5;++j){

            //only draw when both x & y is equal, so we skip here
            if((j&1) != (i&1)){
                continue;
            }
            x = (i+j)/2;
            y = (i-j)/2;

            if(x>=0 && y>=0 && x<MAP_WIDTH && y<MAP_HEIGHT){
                tile = worldTest[y][x];
                point.x = ((x*_zoomLevel *_isoEngine._tileSize) + _isoEngine._scrollX);
                point.y = ((y*_zoomLevel *_isoEngine._tileSize) + _isoEngine._scrollY);
                _isoEngine.Convert2dToIso(point);
                _texture.RenderXYClipScale(point.x,point.y,&tilesRects[tile],_zoomLevel);
            }
        }
    }
}



void Game::Draw(){


    SDL_SetRenderDrawColor(Renderer::get().GetRenderer(), 0x3b, 0x3b, 0x3b, 0);

    SDL_RenderClear(Renderer::get().GetRenderer());

//    _texture.RenderXYClip(_mouseRect.x, _mouseRect.y, &tilesRects[0]);

    DrawIsoMap();
    DrawCharacter();
    DrawIsoMouse();

    if(_lastTileClicked!=-1){
        _texture.RenderXYClip(0,0,&tilesRects[_lastTileClicked]);
    }

    SDL_RenderPresent(Renderer::get().GetRenderer());
    SDL_Delay(10);
}

void Game::Update(){
    SDL_GetMouseState(&_mouseRect.x, &_mouseRect.y);
    _mouseRect.x = _mouseRect.x/_zoomLevel;
    _mouseRect.y = _mouseRect.y/_zoomLevel;

//    std::cout<< "_mouseRect.x: " << _mouseRect.x<< ", _mouseRect.y: " << _mouseRect.y << std::endl;
    //std::cout<< "_mouseRect.x: " << _mouseRect.x<< ", _mouseRect.y: " << _mouseRect.y << std::endl;

    if(_gameMode == GAME_MODE_OBJECT_FOCUS){
        CenterMap(_charPoint);
    }
    else if(_gameMode == GAME_MODE_OVERVIEW){
        ScrollMapWithMouse();
    }
}

void Game::UpdateInput(){
    const Uint8  *keystate = SDL_GetKeyboardState(NULL);

    while (SDL_PollEvent(&_event) != 0){
        switch (_event.type){
            case SDL_QUIT:
                _loopDone = 1;
                break;
            case SDL_KEYUP:
                switch (_event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        _loopDone=1;

                        if(_gameMode == GAME_MODE_OVERVIEW){
                            _gameMode = GAME_MODE_OBJECT_FOCUS;
                        }
                        else{
                            _gameMode =  GAME_MODE_OVERVIEW;
                        }

                        break;

                    case SDLK_SPACE:

                        if(_gameMode == GAME_MODE_OVERVIEW){
                            _gameMode = GAME_MODE_OBJECT_FOCUS;
                        }
                        else{
                            _gameMode =  GAME_MODE_OVERVIEW;
                        }
                        break;
                }

                break;
            case SDL_MOUSEBUTTONDOWN:
                if(_event.button.button == SDL_BUTTON_LEFT)
                {
                    if(_gameMode==GAME_MODE_OVERVIEW){
                        CenterMapToTileUnderMouse();

                    }
                    if(_gameMode == GAME_MODE_OBJECT_FOCUS){
                        GetMouseTileClick();
                    }
                }
                break;

            case SDL_MOUSEWHEEL:
                //If the user scrolled the mouse wheel up
                if(_event.wheel.y>=1)
                {
                    if(_zoomLevel<3.0){
                        _zoomLevel+=0.25;
                        if(_gameMode==GAME_MODE_OVERVIEW)
                        {
                            CenterMap(_tilePos);
                        }
                        if(_gameMode == GAME_MODE_OBJECT_FOCUS){
                            CenterMap(_charPoint);
                        }
                    }
                }
                    //If the user scrolled the mouse wheel down
                else{
                    if(_zoomLevel>1.0){
                        _zoomLevel-=0.25;
                        if(_gameMode==GAME_MODE_OVERVIEW)
                        {
                            CenterMap(_tilePos);
                        }
                        if(_gameMode == GAME_MODE_OBJECT_FOCUS){
                            CenterMap(_charPoint);
                        }
                    }
                }
                break;

            default:
                break;
        }
    }

    if(keystate[SDL_SCANCODE_S] && !keystate[SDL_SCANCODE_D] && !keystate[SDL_SCANCODE_A] && !keystate[SDL_SCANCODE_W])
    {
        _charPoint.x+=5;
        _charPoint.y+=5;
        _charDirection = PLAYER_DIR_DOWN;
    }
    else if(!keystate[SDL_SCANCODE_S] && !keystate[SDL_SCANCODE_D] && !keystate[SDL_SCANCODE_A] && keystate[SDL_SCANCODE_W])
    {
        _charPoint.x-=5;
        _charPoint.y-=5;
        _charDirection = PLAYER_DIR_UP;
    }
    else if(!keystate[SDL_SCANCODE_S] && keystate[SDL_SCANCODE_D] && !keystate[SDL_SCANCODE_A] && keystate[SDL_SCANCODE_W])
    {
        _charPoint.y-=5;
        _charDirection = PLAYER_DIR_UP_RIGHT;
    }
    else if(!keystate[SDL_SCANCODE_S] && !keystate[SDL_SCANCODE_D] && keystate[SDL_SCANCODE_A] && keystate[SDL_SCANCODE_W])
    {
        _charPoint.x-=5;
        _charDirection = PLAYER_DIR_UP_LEFT;
    }
    else if(!keystate[SDL_SCANCODE_S] && keystate[SDL_SCANCODE_D] && !keystate[SDL_SCANCODE_A] && !keystate[SDL_SCANCODE_W])
    {
        _charPoint.x+=3;
        _charPoint.y-=3;
        _charDirection = PLAYER_DIR_RIGHT;
    }
    else if(!keystate[SDL_SCANCODE_S] && !keystate[SDL_SCANCODE_D] && keystate[SDL_SCANCODE_A] && !keystate[SDL_SCANCODE_W])
    {
        _charPoint.x-=3;
        _charPoint.y+=3;
        _charDirection = PLAYER_DIR_LEFT;
    }
    else if(keystate[SDL_SCANCODE_S] && !keystate[SDL_SCANCODE_D] && keystate[SDL_SCANCODE_A] && !keystate[SDL_SCANCODE_W])
    {
        _charPoint.y+=5;
        _charDirection = PLAYER_DIR_DOWN_LEFT;
    }
    else if(keystate[SDL_SCANCODE_S] && keystate[SDL_SCANCODE_D] && !keystate[SDL_SCANCODE_A] && !keystate[SDL_SCANCODE_W])
    {
        _charPoint.x+=5;
        _charDirection = PLAYER_DIR_DOWN_RIGHT;
    }

}

void Game::InitTitleClip(){
    int x=0, y=0;
    int i;

    _texture.InitTexture(0,0,0, NULL, NULL, SDL_FLIP_NONE);
    for (i=0; i < NUM_ISOMETRIC_TITLES; ++i){
        _isoEngine.SetupRect(tilesRects[i], x,y,64,80);
        x+=64;
    }
}


void Game::getMouseTilePos(Point2D &mouseTilePos)
{
    Point2D point;
    Point2D tileShift, mouse2IsoPOint;


    int modulusX = _isoEngine._tileSize * _zoomLevel;
    int modulusY = _isoEngine._tileSize*_zoomLevel;
    int correctX =(((int)_mapScroll2Dpos.x)%modulusX)*2;
    int correctY = ((int)_mapScroll2Dpos.y)%modulusY;

    mouse2IsoPOint = _mousePoint;
    _isoEngine.ConvertIsoTo2D(mouse2IsoPOint);

    _isoEngine.GetTileCoordinates(mouse2IsoPOint,point);

    tileShift.x = correctX;
    tileShift.y = correctY;
    _isoEngine.Convert2dToIso(tileShift);

    if(_mapScroll2Dpos.y>0){
        point.y -= (((float)_isoEngine._scrollY-tileShift.y)/(float)_isoEngine._tileSize)/_zoomLevel;
        point.y+=1;
    }
    else{
        point.y -= (((float)_isoEngine._scrollY-tileShift.y)/(float)_isoEngine._tileSize)/_zoomLevel;
    }

    if(_mapScroll2Dpos.x>0)
    {
        point.x -= (((float)_isoEngine._scrollX+(float)tileShift.x)/(float)_isoEngine._tileSize)/_zoomLevel;
        point.x+=1;
    }
    else{
        point.x -= (((float)_isoEngine._scrollX+(float)tileShift.x)/(float)_isoEngine._tileSize)/_zoomLevel;
    }
    mouseTilePos.x = (int)point.x;
    mouseTilePos.y = (int)point.y;
}



void Game::GetMouseTileClick(){
    Point2D point;
    Point2D tileShift, mouseIsoPoint;

//    int correctX =(_mapScroll2Dpos.x%32)*2;
//    int correctY = _mapScroll2Dpos.y%32;
//    mouseIsoPoint = _mousePoint;
//    _isoEngine.ConvertIsoTo2D(mouseIsoPoint);
//    _isoEngine.GetTileCoordinates(mouseIsoPoint, point);

//    tileShift.x = correctX;
//    tileShift.y = correctY;
//    _isoEngine.Convert2dToIso(tileShift);

//    point.x-=((float)_isoEngine._scrollX+(float)tileShift.x)/(float)_isoEngine._tileSize;
//    point.y-=((float)_isoEngine._scrollY-(float)tileShift.y)/(float)_isoEngine._tileSize;

    getMouseTilePos(point);

    if(point.x>=0 && point.y>=0 && point.x<MAP_WIDTH && point.y<MAP_HEIGHT){
        _lastTileClicked = worldTest[(int)point.y][(int)point.x];
    }


}

void Game::CenterMapToTileUnderMouse(){
    Point2D mouseIsoTilePos;
    int width = Renderer::get().GetWidth();
    int height = Renderer::get().GetHeight();

    //calculate the offset of the center of the screen
    int offsetX = width/_zoomLevel/2;
    int offsetY = height/_zoomLevel/2;

    //get the tile under the mouse
    getMouseTilePos(mouseIsoTilePos);

    _tilePos.x = mouseIsoTilePos.x*_isoEngine._tileSize;
    _tilePos.y = mouseIsoTilePos.y*_isoEngine._tileSize;

    //convert to isometric coordinates
    _isoEngine.Convert2dToIso(mouseIsoTilePos);

    //move the x position
    _mapScroll2Dpos.x = ((mouseIsoTilePos.x*_isoEngine._tileSize)*_zoomLevel)/2;
    _mapScroll2Dpos.x -= (offsetX*_zoomLevel)/2;

    //move the y position
    _mapScroll2Dpos.y = -((mouseIsoTilePos.y*_isoEngine._tileSize)*_zoomLevel);
    _mapScroll2Dpos.y += offsetY*_zoomLevel;

    //convert the map 2d camera to isometric camera
    _isoEngine.ConvertCartesianCameraToIsometric(_mapScroll2Dpos);
}

void Game::CenterMap(Point2D objectPoint){
    Point2D pointPos = objectPoint;
    int w =Renderer::get().GetWidth();
    int h =Renderer::get().GetHeight();

    //calculate the offset of the center of the screen
    int offsetX = w/_zoomLevel/2;
    int offsetY = h/_zoomLevel/2;

    _tilePos.x = objectPoint.x;
    _tilePos.y = objectPoint.y;

    _isoEngine.Convert2dToIso(pointPos);

    _mapScroll2Dpos.x = floor((pointPos.x)*_zoomLevel)/2;
    _mapScroll2Dpos.x -= offsetX*_zoomLevel/2;

    if(_gameMode == GAME_MODE_OBJECT_FOCUS){
        _mapScroll2Dpos.x +=45*_zoomLevel/2;
    }

    _mapScroll2Dpos.y = -floor((pointPos.y)*_zoomLevel);
    _mapScroll2Dpos.y += offsetY*_zoomLevel;

    if(_gameMode == GAME_MODE_OBJECT_FOCUS){
        _mapScroll2Dpos.y -= 51*_zoomLevel;
    }

    _isoEngine.ConvertCartesianCameraToIsometric(_mapScroll2Dpos);
}


void Game::ScrollMapWithMouse(){
    int w =Renderer::get().GetWidth();
    int h =Renderer::get().GetHeight();

    int zoomEdgeX = (w*_zoomLevel)-(w);
    int zoomEdgeY = (h*_zoomLevel)-(h);

    if(_mouseRect.x<2){
        _mapScroll2Dpos.x-=_mapScrollSpeed;
        _isoEngine.ConvertCartesianCameraToIsometric(_mapScroll2Dpos);
    }
    if(_mouseRect.x > (w-(zoomEdgeX/_zoomLevel)-2)){
        _mapScroll2Dpos.x+=_mapScrollSpeed;
        _isoEngine.ConvertCartesianCameraToIsometric(_mapScroll2Dpos);

    }
    if(_mouseRect.y<2){
        _mapScroll2Dpos.y+=_mapScrollSpeed;
        _isoEngine.ConvertCartesianCameraToIsometric(_mapScroll2Dpos);

    }
    if(_mouseRect.y > (h-(zoomEdgeY/_zoomLevel)-2)){
        _mapScroll2Dpos.y-=_mapScrollSpeed;
        _isoEngine.ConvertCartesianCameraToIsometric(_mapScroll2Dpos);

    }


}


void Game::InitCharClip(){
    int x=0,y=0;
    int i;
    _characterTexture.InitTexture(0,0,0,NULL,NULL,SDL_FLIP_NONE);
    for(i=0;i<NUM_CHARACTER_SPRITES;++i)
    {
        _isoEngine.SetupRect(charRects[i],x,y,70,102);
        x+=70;
    }
}

void Game::DrawCharacter(){
    Point2D point;
    point.x = (int)(_charPoint.x*_zoomLevel)+ _isoEngine._scrollX;
    point.y = (int)(_charPoint.y*_zoomLevel)+ _isoEngine._scrollY;
    _isoEngine.Convert2dToIso(point);
    _characterTexture.RenderXYClipScale(point.x,point.y,&charRects[_charDirection],_zoomLevel);
}

