#include <iostream>
//#include "DisplayGL.h"
//#include "DisplaySDL.h"
#include "Game.h"

int main(int argc, char **argv) {
//    IMG_Quit();
//    SDL_Quit();

    //DisplayGL _display(argc, argv);
//    DisplaySDL _displaySDL("Test GAME1");
    Game _game;

//    SDL_ShowCursor(0);
    SDL_SetWindowGrab(Renderer::get().GetWindow(),SDL_TRUE);
    SDL_WarpMouseInWindow(Renderer::get().GetWindow(),Renderer::get().GetWidth()/2,Renderer::get().GetHeight()/2);

while(!_game._loopDone){
    _game.Update();
    _game.UpdateInput();
    _game.Draw();
}


    std::cout << "Hello, World!" << std::endl;

//std::getchar();
    return 0;
}