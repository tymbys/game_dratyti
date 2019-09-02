//https://www.youtube.com/watch?v=8xf_ouTpd1c
// 52:00
// 1:50:53

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

while(!_game._loopDone){
    _game.Update();
    _game.UpdateInput();
    _game.Draw();
}


    std::cout << "Hello, World!" << std::endl;

//std::getchar();
    return 0;
}