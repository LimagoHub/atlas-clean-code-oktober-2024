//
// Created by JoachimWagner on 21.10.2024.
//

#pragma once

namespace atlas::game {

    class Game {
    protected:
        Game() = default;
    public:
        virtual ~Game() = default;
        virtual void play()=0;

    };

} // game
