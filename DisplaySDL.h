//
// Created by tymbys on 31.08.19.
//

#ifndef GAME1_DISPLAYSDL_H
#define GAME1_DISPLAYSDL_H

#include <iostream>
#include <string>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Renderer{
public:
    static Renderer& get() {
        static Renderer instance;
        return instance;
    }

    void Init(std::string windowCap, int width, int height);
    void DeInit();
//    Renderer(std::string windowCap, int width, int height);
//    ~Renderer();


    SDL_Renderer    *GetRenderer();
    SDL_Window      *GetWindow();

private:
    SDL_Window *_window;
    SDL_Renderer *_renderer;

    int _width;
    int _height;

};

class DisplaySDL {
public:
    DisplaySDL(std::string windowsName);
    ~DisplaySDL();

    Renderer *GetRender();

private:
//    Renderer *_renderer;
};




#endif //GAME1_DISPLAYSDL_H
