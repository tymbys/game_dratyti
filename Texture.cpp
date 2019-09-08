//
// Created by tymbys on 31.08.19.
//

#include "Texture.h"

Texture::Texture(){
}
Texture::~Texture(){
}
int  Texture::LoadTexture(std::string file){
    SDL_Surface *temSurfase = IMG_Load(file.c_str());

    if(temSurfase == NULL) {
        std::cerr << "SDL_Image error: " << IMG_GetError() << std::endl;
        return  0;

    }else{
        _texture = SDL_CreateTextureFromSurface(Renderer::get().GetRenderer() ,temSurfase);

        if (_texture == NULL) {

            std::cerr << "SDL_Image error: " << IMG_GetError() << std::endl;
            SDL_FreeSurface(temSurfase);
            return  0;
        } else {
            _width = temSurfase->w;
            _height = temSurfase->h;
        }
        SDL_FreeSurface(temSurfase);
        return 1;
    }
    return 0;

}

void Texture::InitTexture(int x, int y, double angle, SDL_Point *center, SDL_Rect *cliprecct, SDL_RendererFlip flipType){
    _x = x;
    _y = y;
    _angle = angle;
    _center = center;
    _cliprect = cliprecct;
    _flipType = flipType;
}

void Texture::RenderXYClip(int x, int y, SDL_Rect *cliprecct){
    if (_texture == NULL){
        std::cout << "Warning: passed texture was null!" << std::endl;
        return;
    }

    _x = x;
    _y = y;
    _cliprect = cliprecct;
    SDL_Rect qued = {_x, _y, _width, _height};

    if(_cliprect != NULL){
        qued.w = _cliprect->w;
        qued.h = _cliprect->h;
    }

    SDL_RenderCopyEx(Renderer::get().GetRenderer(), _texture, _cliprect, &qued, _angle, _center, _flipType);
}

void Texture::RenderXYClipScale( int x, int y, SDL_Rect *cliprect, float scale){
    float w,h;
    float diffx,diffy;
    SDL_Rect quad;
    w=(float)_width+1*scale;
    h=(float)_height+1*scale;

    diffx = (x*scale) - x;
    diffy = (y*scale) - y;

    _isoEngine.SetupRect(quad,(x*scale)-diffx,(y*scale)-diffy,w,h);

    _cliprect = cliprect;

    if(_cliprect != NULL){
        quad.w = (int)(_cliprect->w*scale);
        quad.h = (int)(_cliprect->h*scale);

        if(scale <1.0 || scale >1.0){
            quad.h +=1;
            quad.w +=1;
        }
    }
    SDL_RenderCopyEx(Renderer::get().GetRenderer(), _texture, _cliprect, &quad, _angle, _center, _flipType);

}