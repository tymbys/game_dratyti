//
// Created by tymbys on 31.08.19.
//

#ifndef GAME1_TEXTURE_H
#define GAME1_TEXTURE_H

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "DisplaySDL.h"


class Texture {
public:
    int _x;
    int _y;
    int _width;
    int _height;
    double _angle;

    SDL_Point *_center;
    SDL_Rect *_cliprecct;
    SDL_RendererFlip _flipType;
    SDL_Texture *_texture;

    Texture();
    ~Texture();

    int  LoadTexture(std::string file);
    void InitTexture(int x, int y, double angle, SDL_Point *center, SDL_Rect *cliprecct, SDL_RendererFlip flipType);
    void RenderXYClip(int x, int y, SDL_Rect *cliprecct);

private:



};


#endif //GAME1_TEXTURE_H
