//
// Created by JoachimWagner on 21.10.2024.
//

#pragma once
#include "../game/Game.h"
using namespace atlas::game;

namespace client {

    class Client {
    private:
        Game & game;

    public:
        explicit Client(Game &game) : game(game) {}
        void go() {
            game.play();
        }
    };

} // client
