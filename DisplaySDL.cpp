//
// Created by tymbys on 31.08.19.
//

#include "DisplaySDL.h"

DisplaySDL::DisplaySDL(std::string windowsName){
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cerr << "SDL error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    SDL_SetHint(SDL_HINT_WINDOWS_DISABLE_THREAD_NAMING, "1");

    if(SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0")){
        std::cout << "Warning: Linear texture wos not enable!" << std::endl;
    }

    Renderer::get().Init(windowsName, 1024, 768);

//    _renderer = new Renderer(windowsName, 800, 600);

    if (!(IMG_Init(IMG_INIT_PNG)) & IMG_INIT_PNG){
        std::cerr << "SDL error: " << SDL_GetError() << std::endl;
        exit(1);
    }


}

DisplaySDL::~DisplaySDL(){
//    delete _renderer;
    Renderer::get().DeInit();
    IMG_Quit();
    SDL_Quit();
}

//Renderer* DisplaySDL::GetRender(){
//    return _renderer;
//}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Renderer::Init(std::string windowCap, int width, int height){
    _width = width;
    _height = height;
    _renderer = NULL;
    _window = NULL;

    _window = SDL_CreateWindow(windowCap.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            _width,
            _height,
            SDL_WINDOW_RESIZABLE
            );
    if(_window == NULL) {
        std::cerr << "SDL error: " << SDL_GetError() << std::endl;
    }

    _renderer = SDL_CreateRenderer(_window,-1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC);
    if(_renderer == NULL) {
        std::cerr << "SDL error: " << SDL_GetError() << std::endl;
    }
}

void Renderer::DeInit(){
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    _renderer=NULL;
    _window=NULL;
}


SDL_Renderer *Renderer::GetRenderer(){
    return _renderer;
}
SDL_Window *Renderer::GetWindow(){
    return _window;
}

int Renderer::GetWidth(){
    return _width;

}
int Renderer::GetHeight(){
    return _height;
}