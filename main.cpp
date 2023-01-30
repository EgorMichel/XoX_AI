//
// Created by egorich on 26.01.23.
//

#include "src/XoX/Game/Game.hpp"


int main(){
    Game game;

    while (game.isRunning()){
        game.Draw();
        game.Events();
        game.AI_Move();
    }

    return 0;
}